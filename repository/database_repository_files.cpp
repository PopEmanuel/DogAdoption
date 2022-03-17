//
// Created by Emanuel on 3/19/2021.
//

#include "database_repository_files.h"
#include <iostream>

/**
 * remove a dog from one of the lists
 * @param list_type : enum, the type of the list in which to operate
 * @param id : the id of the dog to be removed
 */
void database_repository_files::remove_dog(list list_type, int id) {

    int index = this->find_dog(list_type, id);
    if(index == -1)
        return;
    if(list_type == available)
        this->available_dogs.erase(this->available_dogs.begin() + index);
    else
        this->adopted_dogs.erase(this->adopted_dogs.begin() + index);
}

/**
 * finds a dog by id
 * @param list_type : enum, the type of the list in which to operate
 * @param id : the id of the dog
 * @return the id if the dog exists or -1 otherwise
 */
int database_repository_files::find_dog(list list_type, int id) {
    if(list_type == available)
        for(int i = 0; i < this->available_dogs.size(); ++i)
        {
            if(this->available_dogs[i].get_id() == id)
                return i;
        }
    else
        for(int i = 0; i < this->adopted_dogs.size(); ++i)
        {
            if(this->adopted_dogs[i].get_id() == id)
                return i;
        }
    return -1;
}

/**
 *
 * @param list_type : enum, the type of the list in which to operate
 * @param id
 * @param breed
 * @param name
 * @param age
 * @param photograph
 */
void database_repository_files::add_dog(list list_type, int id, const std::string& breed, const std::string& name, int age,
                                        const std::string& photograph) {
    if (list_type == available)
        available_dogs.emplace_back(dog(id, breed, name, age, photograph));
    else
        adopted_dogs.emplace_back(dog(id, breed, name, age, photograph));
}

/**
 * updates the dog with the id id
 * @param list_type  : enum, the type of the list in which to operate
 * @param id
 * @param dog : the second dog with all the updated information
 */
void database_repository_files::update_dog(list list_type, int id, const dog& dog1) {
    int index = find_dog(list_type, id);
    if(list_type == available)
    {
        available_dogs[index] = dog1;
    }
    else
        adopted_dogs[index] = dog1;
}

/**
 *
 * @return length of available dogs
 */
int database_repository_files::get_length_available_dogs() {
    return available_dogs.size();
}

/**
 *
 * @return length of adopted dogs
 */
int database_repository_files::get_length_adopted_dogs() {
    return adopted_dogs.size();
}

/**
 *
 * @param list_type : enum, the type of the list in which to operate
 * @return the list of elements depended on list_type
 */
std::vector<dog>::iterator database_repository_files::get_begin_it(list list_type) {
    if(list_type == available)
        return this->available_dogs.begin();
    else
        return this->adopted_dogs.begin();
}

std::vector<dog>::iterator database_repository_files::get_end_it(list list_type) {
    if(list_type == available)
        return this->available_dogs.end();
    else
        return this->adopted_dogs.end();
}

void database_repository_files::read_from_file() {
    std::ifstream fin(R"(E:\Ema info\Clion\a89-915-Pop-Emanuel-Adrian\read_write.txt)");

    int nr_available = 0, nr_adopted = 0;

    fin >> nr_available >> nr_adopted;

    std::cout << nr_available << ' ' << nr_adopted;

    for(int i = 0 ; i < nr_available; ++i)
    {
        dog dog1;
        fin >> dog1;
        this->add_dog(available, dog1.get_id(), dog1.get_breed(), dog1.get_name(), dog1.get_age(), dog1.get_photograph());
    }

    for(int i = 0; i < nr_adopted; ++i)
    {
        dog dog1;
        fin >> dog1;
        this->add_dog(adopted, dog1.get_id(), dog1.get_breed(), dog1.get_name(), dog1.get_age(), dog1.get_photograph());
    }
}

void database_repository_files::write_to_file() {
    std::ofstream fout(R"(E:\Ema info\Clion\a89-915-Pop-Emanuel-Adrian\read_write.txt)");

    int available_length = this->get_length_available_dogs();
    int adopted_length = this->get_length_adopted_dogs();
    fout << available_length << ' ';
    fout << adopted_length << '\n';

    for(auto it = this->get_begin_it(available); it != this->get_end_it(available); ++it)
        fout << it->get_id() << ' ' << it->get_name() << ' ' <<it->get_breed() << ' ' <<it->get_age() << ' ' <<it->get_photograph() << '\n';

    for(auto it = this->get_begin_it(adopted); it != this->get_end_it(adopted); ++it)
        fout << it->get_id() << ' ' << it->get_name() << ' ' <<it->get_breed() << ' ' <<it->get_age() << ' ' <<it->get_photograph() << '\n';
}

void database_repository_files::open_list_of_adoption() {
    system(R"(notepad.exe E:\Ema info\Clion\a89-915-Pop-Emanuel-Adrian\read_write.txt)");
}


