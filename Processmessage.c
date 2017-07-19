#include <string.h>
#include "Processmessage.h"

char * Processmessage(char * msg, char** login, int * identified, int * try)
{
    char * pwd;

    /* Si le client n'est pas autentifié */
    if (identified == 0) {
        /* Si le message est BONJOUR */
        if (strcmp(msg,"BONJ") == 0) {
            return "WHO";
        }
            /* Si on ne connait pas encore le login de l'utilisateur */
        else if (strcmp(*login,"") == 0) {
            *login = msg;
            return "PASSWD";
        }
            /* Si on connait déjà le login, msg est un mot de passe */
        else {
            /*lire le fichier*/
            /* compare log pwd */
            pwd = "toto";
            /* Si le pwd est faux */
            if (strcmp(msg,pwd) != 0) {
                /* Si nb essai < 3 */
                if (*try < 3) {
                    *try += 1;
                    return "PASSWD";
                }
                    /* Si nb essai > 3 */
                else {
                    *try = 0;
                    *login = "";
                    return "BYE";
                }
            }
                /* Si le pwd est bon */
            else {
                *try = 0;
                return "WELC";
            }
        }
    }
        /* Si utilisateur connecté et msg est rls */
    else if (strcmp(msg,"rls") == 0) {
        /* do ls */
    }
        /* Si utilisateur connecté et msg est rc */
    else if (strcmp(msg,"rcd") == 0) {
        /* do cd */
    }
        /* Si utilisateur connecté et msg est rpwd */
    else if (strcmp(msg,"rpwd") == 0) {
        /* do pwd */
    }
    else {
        return "Commande non reconnue.\n";
    }
    return "";
}