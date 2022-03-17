//
// Created by Emanuel on 3/19/2021.
//

#ifndef A45_915_POP_EMANUEL_ADRIAN_DOG_H
#define A45_915_POP_EMANUEL_ADRIAN_DOG_H
#include <string>
#include <fstream>

class dog {
public:

    dog(int id, std::string breed, std::string name, int age, std::string photograph);

    dog();

     int get_id() const;

     std::string get_breed() const;

     std::string get_name() const;

     int get_age() const;

     std::string get_photograph() const;

     dog &operator =(const dog& dog1);

     friend std::istream &operator>>(std::istream &is, dog &dog1);
     friend std::ostream &operator<<(std::ostream &os, dog &dog1);

private:
    int id;
    std::string breed;
    std::string name;
    int age;
    std::string photograph;
};


#endif //A45_915_POP_EMANUEL_ADRIAN_DOG_H
