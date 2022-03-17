//
// Created by Emanuel on 4/15/2021.
//
#include "QDesktopServices"
#include "database_repository_html.h"
#include "QUrl"

void database_repository_html::write_to_file() {
    std::ofstream fout(R"(E:\Ema info\Clion\a89-915-Pop-Emanuel-Adrian\write.html)");

    fout << "<!DOCTYPE html>\n<html>\n<head>\n\t<title>Adoption List</title>\n";
    fout << "</head>\n<body>\n<table_adopted border=\"1\">\n\t<tr>\n\t\t<td>Name</td>\n\t\t";
    fout << "<td>Breed</td>\n\t\t<td>Age</td>\n\t\t<td>Photo</td>\n\t</tr>\n";

    for(auto it = get_begin_it(available); it != get_end_it(available); ++it)
    {
        fout << "\t<tr>\n";
        fout << "\t\t<td>" << it->get_name() << "</td>\n";
        fout << "\t\t<td>" << it->get_breed() << "</td>\n";
        fout << "\t\t<td>" << it->get_age() << "</td>\n";
        fout << "\t\t<td><a href=\"" << it->get_photograph() << "\">Link</a></td>\n";
        fout << "\t</tr>";

    }

    fout << "</table_adopted>\n</body>\n</html>\n";
}

void database_repository_html::open_list_of_adoption() {
    //system(R"(start chrome ../write.html)");
    QDesktopServices::openUrl(QUrl::fromLocalFile(R"(E:\Ema info\Clion\a89-915-Pop-Emanuel-Adrian\write.html)"));
}
