//
// Created by Emanuel on 3/19/2021.
//

#ifndef A45_915_POP_EMANUEL_ADRIAN_CONSOLE_H
#define A45_915_POP_EMANUEL_ADRIAN_CONSOLE_H

#include "../service/service_database.h"

class console {
public:

    console();
    void start_console();
    void read_from_file();
    void write_to_file();
    static void print_menu_administrator();
    static void print_menu_client();
    void print_available_dogs();
    void print_adopted_dogs();
    void start_administrator_mode();
    void start_client_mode();
    void ui_add_dog();
    void ui_delete_dog();
    void ui_update_dog();
    void ui_show_dogs_one_by_one();
    void ui_show_dogs_with_given_breed();

private:
    service_database *service;
};


#endif //A45_915_POP_EMANUEL_ADRIAN_CONSOLE_H
