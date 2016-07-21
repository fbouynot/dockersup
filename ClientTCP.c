#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */

int Client()
{
    // Création de titi, dont le type est une structure sockaddr_in, contenant entre autres l'ip et le port
    struct sockaddr_in titi;
    int num_socket;
    char tmp_msg[256];

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
    titi.sin_port = htons(5001);
    // inet_addr transforme en table[4]
    titi.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connexion au Serveur
    // num_socket est le numero du socket
    // titi est la structure contenant ip, port, protocole
    int connexion = connect(num_socket, (struct sockaddr*)&titi, sizeof(titi));
    if (connexion == -1)
    {
        printf("Erreur de connexion au socket distant.\n");
        exit(-1);
    }

    char var_msg[256] = "Salut, je suis le client.";

    // num_socket est le numero du socket
    // var_msg est une chaine de charactere contenant le message à envoyer
    send(num_socket, var_msg, strlen(var_msg), 0);

    ssize_t taille = recv(num_socket, tmp_msg, 256, 0);

    // Pour une chaine de n charactere, on ajoute \0 au charactere n+1 pour ne lire que ce qui est necessaire
    tmp_msg[taille] = 0;

    // Affichage en local du message recu
    printf("Le serveur a envoye le message suivant : \n%s\n\n", tmp_msg);

    return 0;
}