//
// Created by Emanuel on 3/19/2021.
//

#include "dog.h"

/**
 * default constructor;
 */
dog::dog()
{

}

/**
 * class main constructor
 * @param id
 * @param breed
 * @param name
 * @param age
 * @param photograph
 */
dog::dog(int id, std::string breed, std::string name, int age, std::string photograph) {
    this->id = id;
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photograph = photograph;
}

/**
 * gets the id of the dog
 * @return id
 */
int dog::get_id() const {
    return this->id;
}

/**
 * gets the breed of the dof
 * @return breed
 */
std::string dog::get_breed() const {
    return this->breed;
}

/**
 * gets the name of the dog
 * @return name
 */
std::string dog::get_name() const {
    return this->name;
}

/**
 * gets the age of the dog
 * @return age
 */
int dog::get_age() const {
    return this->age;
}

/**
 * gets the photograph of the dog
 * @return photograph
 */
std::string dog::get_photograph() const {
    return this->photograph;
}

dog &dog::operator=(const dog& dog1) {
    if(this == &dog1)
        return *this;

    this->name = dog1.name;
    this->age = dog1.age;
    this->photograph = dog1.photograph;
    this->breed = dog1.breed;
    this->id = dog1.id;

    return *this;
}

std::istream &operator>>(std::istream &is, dog &dog1) {

    is >> dog1.id >> dog1.name >> dog1.breed >> dog1.age >> dog1.photograph;

    return is;
}

std::ostream &operator<<(std::ostream &os, dog &dog1) {

    os <<  "id : " << dog1.get_id() << ", name : " << dog1.get_name() << ", breed : "
          <<  dog1.get_breed() << ", age : " << dog1.get_age() << ", photo : " << dog1.get_photograph() << '\n';

    return os;
}


