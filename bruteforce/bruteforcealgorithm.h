#ifndef BRUTEFORCEALGORITHM_H
#define BRUTEFORCEALGORITHM_H

#include "algorithm.h"
#include <iostream>

class BruteforceAlgorithm : public Algorithm
{
public:
    bool crack(const std::string & password) const = 0;
    virtual ~BruteforceAlgorithm() { }
};

#endif // BRUTEFORCEALGORITHM_H
