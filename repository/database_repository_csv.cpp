//
// Created by Emanuel on 4/15/2021.
//

#include "database_repository_csv.h"
#include "fstream"

void database_repository_csv::write_to_file() {
    std::ofstream fout(R"(E:\Ema info\Clion\a89-915-Pop-Emanuel-Adrian\write.csv)");
    for(auto it = get_begin_it(available); it != get_end_it(available); ++it)
    {
        fout << it->get_name() << ',' << it->get_breed() << ',' << it->get_age() << ',' << it->get_photograph() << '\n';
    }

    fout.close();
}

void database_repository_csv::open_list_of_adoption() {
    system(R"(notepad.exe E:\Ema info\Clion\a89-915-Pop-Emanuel-Adrian\write.csv)");
}
