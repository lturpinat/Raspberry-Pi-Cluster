#define HOSTNAME_SIZE 255

#define CRACK_RESULT_FOLDER "/srv/shared/"
#define ERROR_LOG_FILE "/srv/shared/log/error.log"

#define ARGUMENT_ERROR "Argument error."
#define NOT_IMPLEMENTED "Not implemented yet."
#define UNEXPECTED_ERROR "Unexpected error."

#include "filewriter.h"
#include <mutex>

using namespace std;

FileWriter::FileWriter()
{
    char host[HOSTNAME_SIZE];

    if(gethostname(host, HOSTNAME_SIZE) != 0)
    {
        cerr << "gethostname : " << UNEXPECTED_ERROR << endl; //Mettre les erreurs dans un fichier error.txt et lire à chaque fin de task ?
        throw string(UNEXPECTED_ERROR);
    }

    hostname = host;
}

void FileWriter::open(string id)
{
    stringstream ss;

    ss << CRACK_RESULT_FOLDER << hostname << "_" << id;
    string path = ss.str();

    outputFile.open(path.c_str());
}

void FileWriter::write(string message, string password)
{
    outputFile << message << endl << password << endl;
}

void FileWriter::write(string message)
{
    outputFile << message << endl;
}

void FileWriter::writeError(string message)
{
    mutex mutex;
    mutex.lock();

    string path = ERROR_LOG_FILE;
    errorFile.open(path.c_str(), ios_base::in | ios_base::app | ios_base::ate );

    errorFile << hostname << " : " << message << endl;

    errorFile.close();
    mutex.unlock();
}

FileWriter::~FileWriter()
{
    outputFile.close();
}
