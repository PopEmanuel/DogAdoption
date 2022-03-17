//
// Created by Emanuel on 4/7/2021.
//

#include "dog_validator.h"

void dog_validator::validate(const dog &dog1) {
    if(dog1.get_id() < 0)
        throw ValidatorException();
}
