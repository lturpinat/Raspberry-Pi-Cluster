#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>

class FileWriter
{
    std::string hostname;

    std::ofstream outputFile;
    std::ofstream errorFile;

public:
    FileWriter();
    void open(std::string id);
    void write(std::string message, std::string password);
    void write(std::string message);
    void writeError(std::string message);

    ~FileWriter();
};

#endif // FILEWRITER_H
