//
// Created by Emanuel on 3/19/2021.
//

#include "service_database.h"
#include "../repository/database_repository_csv.h"
#include <iostream>
#include "../entities/dog_validator.h"
#include "../repository/database_repository_html.h"

service_database::service_database(file_type type) {
    if(type == txt)
        this->repository = new database_repository_files();
    else
        if(type == csv)
            this->repository = new database_repository_csv();
        else
            if(type == html)
                this->repository = new database_repository_html();
}

void service_database::add_dog(list list_type, int id, const std::string& breed, const std::string& name, int age, const std::string& photograph) {
    if(list_type == available || list_type == adopted)
        repository->add_dog(list_type, id, breed, name, age, photograph);
}

void service_database::remove_dog(list list_type, int id) {
    if(list_type == available || list_type == adopted)
        repository->remove_dog(list_type, id);
}

int service_database::find_dog(list list_type, int id) {
    return repository->find_dog(list_type, id);
}

void service_database::update_dog(list list_type, int id, const dog& dog) {
    if(list_type == available || list_type == adopted)
        repository->update_dog(list_type, id, dog);
}

int service_database::get_length_available_dogs() {
    return repository->get_length_available_dogs();
}

int service_database::get_length_adopted_dogs() {
    return repository->get_length_adopted_dogs();
}

std::vector<dog>::iterator service_database::get_begin_iterator(list list_type) {
    return repository->get_begin_it(list_type);
}

std::vector<dog>::iterator service_database::get_end_iterator(list list_type) {
    return repository->get_end_it(list_type);
}

void service_database::read_from_file() {
    this->repository->read_from_file();
}

void service_database::write_to_file() {
    this->repository->write_to_file();
}

void service_database::open_list_of_adoption() {
    this->repository->open_list_of_adoption();
}
