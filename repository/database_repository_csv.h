//
// Created by Emanuel on 4/15/2021.
//

#ifndef A67_915_POP_EMANUEL_ADRIAN_DATABASE_REPOSITORY_CSV_H
#define A67_915_POP_EMANUEL_ADRIAN_DATABASE_REPOSITORY_CSV_H
#include "database_repository_files.h"

class database_repository_csv : public database_repository_files{
public:
    void write_to_file() override;
    void open_list_of_adoption() override;
};


#endif //A67_915_POP_EMANUEL_ADRIAN_DATABASE_REPOSITORY_CSV_H
