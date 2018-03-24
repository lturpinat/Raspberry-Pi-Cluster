#include <cstring>

#include <iostream>

#include "filewriter.h"
#include "fancybruteforcealgorithm.h"


#define NOT_IMPLEMENTED "Not implemented yet."
#define UNEXPECTED_ERROR "Unexpected error."


using namespace std;


int main(int argc, char* argv[])
{
    Algorithm *algo;
    string password;
    string id;

    FileWriter writer;

    {
        if(argc == 1)
        {
            writer.writeError("Aucun arguments détectés.");
            cerr << "usage : ./crack <algorithm> <algorithm parameters> <id>" << endl;
            return -1;
        }

        if(strcmp(argv[1],"fancybruteforce") == 0 && argc == 5) ///./crack fancybruteforce pi pikachu <id>
        {
            password = argv[3];
            id = argv[4];
            writer.open(id);

            try
            {
                algo = new FancyBruteforceAlgorithm(argv[2]);
            }
            catch(string e)
            {
                writer.writeError(e);
                cerr << e << endl;
                return -1;
            }
        }
        else if(strcmp(argv[1], "extremebruteforce") == 0 && argc == 6) ///./crack extremebruteforce pi pe pikachu <id>
        {
            writer.writeError("Fonction pas encore implémentée.");
            cerr << "Fonction pas encore implémentée " << endl;
            return -1;
        }
        else if(strcmp(argv[1],"dictionnary") == 0 && argc == 4) ///./crack dictionnary pikachu <id>
        {
            writer.writeError("Fonction pas encore implémentée.");
            cerr << "Fonction pas encore implémentée " << endl;
            return -1;
        }
        else
        {
            writer.writeError("Mauvais arguments détectés.");
            cerr << "usage : ./crack <algorithm> <algorithm parameters> <id>" << endl;
            return -1;
        }
    }

    try
    {
        if(algo->crack(password))
        {
            writer.write("OK", password);
        }
        else
        {
            writer.write("KO");
        }
    }
    catch(string e)
    {
        writer.writeError(e);
        cerr << e << endl;
        return -1;
    }



    return 0;
}
