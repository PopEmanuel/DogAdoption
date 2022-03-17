//
// Created by Emanuel on 3/19/2021.
//

#ifndef A45_915_POP_EMANUEL_ADRIAN_DATABASE_REPOSITORY_H
#define A45_915_POP_EMANUEL_ADRIAN_DATABASE_REPOSITORY_H
#include "../entities/dog.h"
#include <cstring>
#include <vector>
#include "RepositoryInterface.h"

class database_repository_files : public RepositoryInterface{

public:
    void add_dog(list list_type, int id, const std::string& breed, const std::string& name, int age, const std::string& photograph) override;
    void remove_dog(list list_type, int id) override;
    void update_dog(list list_type, int id, const dog& dog) override;
    int find_dog(list list_type, int id) override;
    int get_length_available_dogs() override;
    int get_length_adopted_dogs() override;
    std::vector<dog>::iterator get_begin_it(list list_type) override;
    std::vector<dog>::iterator get_end_it(list list_type) override;
    void read_from_file() override;
    void write_to_file() override;
    void open_list_of_adoption() override;
};


#endif //A45_915_POP_EMANUEL_ADRIAN_DATABASE_REPOSITORY_H
