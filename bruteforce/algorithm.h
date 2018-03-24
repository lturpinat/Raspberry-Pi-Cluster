#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>

class Algorithm
{
public:
    virtual bool crack(const std::string & password) const = 0;
    virtual ~Algorithm() { }
};

#endif // ALGORITHM_H
