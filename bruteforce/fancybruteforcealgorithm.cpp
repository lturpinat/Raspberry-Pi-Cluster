
#include "fancybruteforcealgorithm.h"
#include "bruteforcealgorithm.h"
#include "algorithm.h"
#include <cstring>

using namespace std;

FancyBruteforceAlgorithm::FancyBruteforceAlgorithm(const string & firstLetters)
    : firstLetters(firstLetters)
{
    if(firstLetters.length() != 2)
    {
        throw string("Premières lettres incorrectes dans FancyBruteforce.");
    }
}

bool FancyBruteforceAlgorithm::crack(const string & password) const
{
    string currentPassword = "a";

    char* tmp = new char(firstLetters[0]);

    ///Vérifie que la première lettre ne soit pas le mot de passe
    if(strcmp(password.c_str(), tmp) == 0)
    {
        cout << tmp << endl;
        return true;
    }
    delete tmp;

    ///Vérifie que les 2 premières lettres ne soient pas le mot de passe
    if(password.compare(firstLetters) == 0)
    {
        cout << firstLetters << endl;
        return true;
    }
    ///Vérifie la longueur totale du mot de passe, si supérieure à 7 charactères : on ne teste pas
    if(password.length() > 7)
    {
        throw string("Mot de passe trop long.");
    }
    ///Boucle de comparaison
    while(password.compare(firstLetters + currentPassword) != 0)
    {
        ///Vérifie que le mot de passe de recherche soit inférieur à 7 (taille max)
        if(currentPassword.length() > 5)
        {
            return false;
        }

        //cout << firstLetters + currentPassword << endl;

        ///Si le dernier caractère est un z
        if(currentPassword[currentPassword.length() -1 ] == 'z')
        {
            ///Parcours les autres caractères
            for(long i = currentPassword.length() -1; i >= 0; i-- )
            {
                ///Si le caractère est aussi un z
                if (currentPassword[i] == 'z')
                {   ///Le remplace par un a
                    currentPassword[i] = 'a';
                    ///Si tout le mot de passe est composé de Z, ajoute un 0
                    if(i == 0)
                    {
                        currentPassword += "a";
                    }
                }
                ///Sinon, passe a la lettre suivante et sort de la boucle
                else
                {
                    currentPassword[i] += 1;
                    break;
                }
            }

        }
        ///Si le dernier caractère n'est pas un z, passe au suivant
        else
        {
            currentPassword[currentPassword.length()-1] += 1;
        }
    }

    cout << firstLetters + currentPassword << endl;
    return true;
}
