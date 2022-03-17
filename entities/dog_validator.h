//
// Created by Emanuel on 4/7/2021.
//

#ifndef A67_915_POP_EMANUEL_ADRIAN_DOG_VALIDATOR_H
#define A67_915_POP_EMANUEL_ADRIAN_DOG_VALIDATOR_H
#include "dog.h"

struct ValidatorException : public std::exception
{
    const char * what() const throw()
    {
        return "entity is not valid";
    }
};

class dog_validator {
public:
    static void validate(const dog &dog1);
};


#endif //A67_915_POP_EMANUEL_ADRIAN_DOG_VALIDATOR_H
