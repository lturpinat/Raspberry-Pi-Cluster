#ifndef FANCYBRUTEFORCEALGORITHM_H
#define FANCYBRUTEFORCEALGORITHM_H

#include "bruteforcealgorithm.h"

class FancyBruteforceAlgorithm : public BruteforceAlgorithm
{
    const std::string firstLetters;
public:
    explicit FancyBruteforceAlgorithm(const std::string & firstLetters);
    bool crack(const std::string & password) const;
    ~FancyBruteforceAlgorithm() { }
};

#endif // FANCYBRUTEFORCEALGORITHM_H
