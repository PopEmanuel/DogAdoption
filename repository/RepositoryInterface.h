//
// Created by Emanuel on 4/15/2021.
//

#ifndef A67_915_POP_EMANUEL_ADRIAN_REPOSITORYINTERFACE_H
#define A67_915_POP_EMANUEL_ADRIAN_REPOSITORYINTERFACE_H
#include <vector>
#include "../entities/dog.h"

typedef enum{
    available, adopted
}list;

class RepositoryInterface {
public:
    virtual void add_dog(list list_type, int id, const std::string& breed, const std::string& name, int age, const std::string& photograph) = 0;
    virtual void remove_dog(list list_type, int id) = 0;
    virtual void update_dog(list list_type, int id, const dog& dog) = 0;
    virtual int find_dog(list list_type, int id) = 0;
    virtual int get_length_available_dogs() = 0;
    virtual int get_length_adopted_dogs() = 0;
    virtual std::vector<dog>::iterator get_begin_it(list list_type) = 0;
    virtual std::vector<dog>::iterator get_end_it(list list_type) = 0;
    virtual void read_from_file() = 0;
    virtual void write_to_file() = 0;
    virtual void open_list_of_adoption() = 0;

protected:
    std::vector<dog> available_dogs;
    std::vector<dog> adopted_dogs;
};


#endif //A67_915_POP_EMANUEL_ADRIAN_REPOSITORYINTERFACE_H
