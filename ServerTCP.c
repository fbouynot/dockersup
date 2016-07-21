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

int Server()
{
    struct sockaddr_in toto;
    int num_socket;
    int num_bind;
    int num_service;
    char tmp_msg[1024];
    char * var_msg;

    // Création d'un socket, domaine internet, protocole TCP
    // AF_INET indique le protocole TCP/IP
    // SOCK_STREAM indique un protocole connecté : TCP (au contraire d'UDP)
    num_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (num_socket == -1)
    {
        // Erreur lors de la creation du socket
        printf("Erreur lors de la creation du socket\n");
        exit(-1);
    }

    // Création de la structure
    toto.sin_family = AF_INET; //AF_INET pour socket IP, AF_UNIX pour socket Unix
    toto.sin_port = htons(5003);
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
        num_service = accept(num_socket, &toto, (socklen_t*)&tutu);
        // INVALID_SOCKET vaut -1
        if (num_service != -1)
        {
            // recv renvoie la taille du message, on la stocke dans taille
            // On stocke le message recu dans tmp_message

            ssize_t taille = recv(num_service, tmp_msg, 256, 0);

            // Pour une chaine de n charactere, on ajoute \0 au charactere n+1 pour ne lire que ce qui est necessaire
            tmp_msg[taille] = 0;
            printf("%s\n", tmp_msg);

            var_msg = "Toto\nTata";
            //var_msg = TestPopen();
            send(num_service, var_msg, strlen(var_msg), 0);
        }
    }

    return 0;
}