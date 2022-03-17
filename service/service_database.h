//
// Created by Emanuel on 3/19/2021.
//

#ifndef A45_915_POP_EMANUEL_ADRIAN_SERVICE_DATABASE_H
#define A45_915_POP_EMANUEL_ADRIAN_SERVICE_DATABASE_H
#include "../repository/database_repository_files.h"
#include "../repository/RepositoryInterface.h"

typedef enum{
    txt, csv, html
}file_type;

class service_database {
public:
    service_database(file_type type);
    void add_dog(list list_type, int id, const std::string& breed, const std::string& name, int age, const std::string& photograph);
    void remove_dog(list list_type, int id);
    void update_dog(list list_type, int id, const dog& dog);
    int find_dog(list list_type, int id);
    int get_length_available_dogs();
    int get_length_adopted_dogs();
    void read_from_file();
    std::vector<dog>::iterator get_begin_iterator(list list_type);
    std::vector<dog>::iterator get_end_iterator(list list_type);
    void write_to_file();
    void open_list_of_adoption();

private:
    RepositoryInterface *repository;

};


#endif //A45_915_POP_EMANUEL_ADRIAN_SERVICE_DATABASE_H
