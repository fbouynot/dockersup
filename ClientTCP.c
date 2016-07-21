#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */

char * Client(char * ip)
{
    // Création de titi, dont le type est une structure sockaddr_in, contenant entre autres l'ip et le port
    struct sockaddr_in titi;
    int num_socket;
    //char tmp_msg[1024];
    char * tmp_msg = malloc(sizeof(char) * 1024);
    char var_msg[1024] = "Salut, je suis le client !";

    // Création d'un socket, dont on stocke le numero dans num_socket
    num_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (num_socket == -1)
    {
        // Erreur lors de la creation du socket
        printf("Erreur lors de la creation du socket cote client.\n");
        exit(-1);
    }

    // Création de la structure
    titi.sin_family = AF_INET; //AF_INET pour socket IP, AF_UNIX pour socket Unix
    titi.sin_port = htons(5009);
    // inet_addr transforme un string en table[4]
    titi.sin_addr.s_addr = inet_addr(ip);

    // Connexion au Serveur
    // num_socket est le numero du socket
    // titi est la structure contenant ip, port, protocole
    int connexion = connect(num_socket, (struct sockaddr*)&titi, sizeof(titi));
    if (connexion == -1)
    {
        printf("Erreur de connexion au socket distant.\n");
        exit(-1);
    }

    // num_socket est le numero du socket
    // var_msg est une chaine de charactere contenant le message à envoyer
    send(num_socket, var_msg, strlen(var_msg), 0);

    // tmp_msg stocke le message recu
    ssize_t taille = recv(num_socket, tmp_msg, 1024, 0);

    // Pour une chaine de n charactere, on ajoute \0 au charactere n+1 pour ne lire que ce qui est necessaire
    tmp_msg[taille] = 0;

    // Affichage en local du message recu
    printf("\nLe serveur a envoye le message suivant : \n%s\n\n", tmp_msg);

    close(num_socket);
    //free(tmp_msg);
    return tmp_msg;
}