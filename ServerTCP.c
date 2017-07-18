//
// Created by felix on 21/07/16.
//

#include "ServerTCP.h"
#include "Getinfo.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int Server(uint16_t port)
{
    struct sockaddr_in toto;
    int num_socket;
    int num_bind;
    int num_service;

    // Création d'un socket, domaine internet, protocole TCP
    // AF_INET indique le protocole TCP/IP
    // SOCK_STREAM indique un protocole connecté : TCP (au contraire d'UDP)
    num_socket = socket(AF_INET, SOCK_STREAM, 0);
    int reuse = 1;
    if (num_socket == -1)
    {
        // Erreur lors de la creation du socket
        printf("Erreur lors de la creation du socket\n");
        exit(-1);
    }
    if (setsockopt(num_socket, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");

#ifdef SO_REUSEPORT
    if (setsockopt(num_socket, SOL_SOCKET, SO_REUSEPORT, (const char*)&reuse, sizeof(reuse)) < 0)
        perror("setsockopt(SO_REUSEPORT) failed");
#endif

    // Création de la structure
    toto.sin_family = AF_INET; //AF_INET pour socket IP, AF_UNIX pour socket Unix
    toto.sin_port = htons(port);
    // inet_addr transforme un string en table[4], INADDR_ANY accepte toutes les IP
    toto.sin_addr.s_addr = htonl(INADDR_ANY); //inet_addr("127.0.0.1") pour local uniquement;

    // Création du bind, dont on stocke le numero dans num_bind
    // num_socket est le numero du socket
    // toto est la variable de type sockaddr_in, contenant ip, port, et protocole
    // (struct sockaddr*) va transformer notre structure de type sockaddr_in en une structure de type sockaddr, requise par la fonction
    // &toto indique que l'on passe l'adresse de l'objet
    num_bind = bind(num_socket, (struct sockaddr*) &toto, sizeof(toto));
    if (num_bind == -1)
    {
        // Erreur lors du bind
        perror("Erreur lors du bind");
        exit(-1);
    }

    // 5 est le nombre de connexions mises en attente
    if (listen(num_socket, 5) == -1)
    {
        // Erreur lors de l'écoute
        printf("Erreur lors de l'ecoute\n");
        exit(-1);
    }

    // Pour accept, nous avons besoin d'une variable avec la taille de la structure toto
    int tutu = sizeof(toto);

    // Boucle d'attente de nouvelles connexions
    while(1)
    {
        // On extrait la connexion vers le port de service
        // num_service stocke la numero do socket de service, réservé à cette connexion
        // num_socket est le numero du socket original
        num_service = accept(num_socket, (struct sockaddr *) &toto, (socklen_t *) &tutu);
        // INVALID_SOCKET vaut -1
        if (num_service != -1)
        {
            char * var_msg = malloc(sizeof(char) * 1024);
            var_msg = GetInfo();
            send(num_service, var_msg, strlen(var_msg), 0);
            free(var_msg);
        }
        num_service = -1;
    }

    return 0;
}