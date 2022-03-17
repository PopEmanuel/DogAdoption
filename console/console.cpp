//
// Created by Emanuel on 3/19/2021.
//

#include <iostream>
#include "console.h"
#include <fstream>

console::console() {
    std::cout << "Chose the mode you want to open the app in : \n 1 - Txt file\n 2 - Csv file\n 3 - Html file\n";
    int choice;
    bool ok = true;
    while(ok)
    {
        std::cin >> choice;
        switch (choice) {
            case 1:
                this->service = new service_database(txt);
                ok = false;
                break;
            case 2:
                this->service = new service_database(csv);
                ok = false;
                break;
            case 3:
                this->service = new service_database(html);
                ok = false;
                break;
        }
        if(ok)
            std::cout << "Chose a valid way\n";
    }
}

void console::start_console() {

    this->service->read_from_file();

    int way_of_open = -1;

    while(way_of_open == -1)
    {
        std::cout << "Chose the way to open the application : \n    1 - Administrator mode\n    2 - Client mode\n";
        std:: cin >> way_of_open;
        if(way_of_open == 1)
            start_administrator_mode(), way_of_open = -1;
        else
        if(way_of_open == 2)
            start_client_mode(), way_of_open = -1;
        else
        {
            std::cout << "The options are either 1 or 2";
            way_of_open = -1;
        }
    }

}

void console::print_menu_administrator() {
    std::cout << "1 - Add a dog\n"
                 "2 - Remove a dog\n"
                 "3 - Update a dog\n"
                 "4 - Exit\n";
}

void console::print_menu_client() {
    std::cout << "1 - Start showing dogs one by one\n"
                 "2 - Show all dogs of a given breed with an age less than a given number\n"
                 "3 - Show adoption list\n"
                 "4 - Open adoption list\n"
                 "5 - Exit\n";
}

void console::start_administrator_mode() {
    bool ok = true;
    while(ok)
    {
        int choice;
        print_available_dogs();
        print_adopted_dogs();
        print_menu_administrator();
        std::cin >> choice;
        switch (choice) {
            case 1:
                ui_add_dog();
                break;
            case 2:
                ui_delete_dog();
                break;
            case 3:
                ui_update_dog();
                break;
            case 4:
                ok = false;

        }
        this->service->write_to_file();
    }



}

void console::start_client_mode() {
    bool ok = true;

    while(ok) {
        print_menu_client();

        int choice;

        std::cin >> choice;

        switch (choice) {
            case 1:
                ui_show_dogs_one_by_one();
                break;
            case 2:
                ui_show_dogs_with_given_breed();
                break;
            case 3:
                print_adopted_dogs();
                break;
            case 4:
                this->service->open_list_of_adoption();
                break;
            case 5:
                ok = false;
                break;
        }
        this->service->write_to_file();
    }


}

void console::ui_show_dogs_one_by_one()
{
    auto dogs = this->service->get_begin_iterator(available);
    int length = this->service->get_length_available_dogs();

    if (length == 0) {
        std::cout << "No more dogs left\n";
        return;
    }

    auto dog = dogs;
    int i = 0;

    bool ok = false;
    while(!ok)
    {
        if(i == this->service->get_length_available_dogs())
            i = 0;

        if(this->service->get_length_available_dogs() == 0)
            ok = true;

        dog = dogs + i;

        std::cout << "id : " << dog->get_id() << ", name : " << dog->get_name() << ", breed : "
                  <<  dog->get_breed() << ", age : " << dog->get_age() << ", photo : " << dog->get_photograph() << '\n';

        std::cout << "Do you want to adopt this dog? \n"
                     "1 - Yes\n"
                     "2 - No\n"
                     "3 - Exit\n";

        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
            {
                this->service->add_dog(adopted, dog->get_id(), dog->get_breed(), dog->get_name(), dog->get_age(), dog->get_photograph());
                this->service->remove_dog(available, dog->get_id());
                break;
            }
            case 2:
            {
                i++;
                break;
            }
            case 3:
                ok = true;
                break;

        }
        if(this->service->get_length_available_dogs() == 0)
            ok = true;
    }

}

void console::ui_show_dogs_with_given_breed()
{
    std::string breed;
    std::cout << "Chose a breed : ";
    std::cin >> breed;
    std::cout << "\n";

    int age;
    std::cout << "Chose the age : ";
    std::cin >> age;
    std::cout << "\n";

    auto dogs = this->service->get_begin_iterator(available);
    int length = this->service->get_length_available_dogs();

    for(int i = 0; i < length; ++i)
    {
        if((dogs + i)->get_breed() == breed && (dogs+i)->get_age() <= age)
        {
            std::cout << *(dogs+i);
        }

    }
}

void console::ui_add_dog() {
    std::cout << "Chose the name : ";
    std::string name;
    std::cin >> name;
    std::cout << '\n';

    std::cout << "Chose the breed : ";
    std::string breed;
    std::cin >> breed;
    std::cout << '\n';

    std::cout << "Chose the age : ";
    int age;
    std::cin >> age;

    if(std::cin.fail())
    {
        std::cout << "Wrong input\n";
        std::cin.clear();
        std::string ignoreLine;
        std::getline(std::cin, ignoreLine);
        return;
    }

    std::cout << '\n';

    std::cout << "Chose the photograph : ";
    std::string photograph;
    std::cin >> photograph;
    std::cout << '\n';

    int length = service->get_length_available_dogs();

    int id = 0;
    for(auto it = this->service->get_begin_iterator(available); it != this->service->get_end_iterator(available); ++it)
        if(it->get_id() > id)
            id = it->get_id();

    service->add_dog(available, id + 1,breed, name, age, photograph);

}

void console::ui_delete_dog() {
    std::cout << "Chose the id : ";
    int id;
    std::cin >> id;
    if(std::cin.fail())
    {
        std::cout << "Wrong input\n";
        std::cin.clear();
        std::string ignoreLine;
        std::getline(std::cin, ignoreLine);
        return;
    }

    service->remove_dog(available, id);
}

void console::ui_update_dog() {
    std::cout << "Chose the id of the dog : ";
    int id;
    std::cin >> id;
    if(std::cin.fail())
    {
        std::cout << "Wrong input\n";
        std::cin.clear();
        std::string ignoreLine;
        std::getline(std::cin, ignoreLine);
        return;
    }

    std::cout << "Chose the name : ";
    std::string name;
    std::cin >> name;
    std::cout << '\n';

    std::cout << "Chose the breed : ";
    std::string breed;
    std::cin >> breed;
    std::cout << '\n';

    std::cout << "Chose the age : ";
    int age;
    std::cin >> age;
    std::cout << '\n';
    if(std::cin.fail())
    {
        std::cout << "Wrong input\n";
        std::cin.clear();
        std::string ignoreLine;
        std::getline(std::cin, ignoreLine);
        return;
    }

    std::cout << "Chose the photograph : ";
    std::string photograph;
    std::cin >> photograph;
    std::cout << '\n';

    int validate = this->service->find_dog(available, id);
    if (validate == -1)
    {
        std::cout << "This id doesn't exist! \n\n";
        return;
    }

    service->update_dog(available, id, dog(id ,breed, name, age, photograph));
}

void console::print_available_dogs() {
    std::cout << "available\n";
    auto it = service->get_begin_iterator(available);
    int length = service->get_length_available_dogs();

    for(it; it != service->get_end_iterator(available); ++it)
    {
        std::cout << *it;
    }
    std::cout << '\n';

}

void console::print_adopted_dogs() {
    std::cout << "adopted";
    auto it = service->get_begin_iterator(adopted);
    int length = service->get_length_available_dogs();

    for(it; it != service->get_end_iterator(adopted); ++it)
    {
        std::cout << *it;
        //std::cout << "id : " << it->get_id() << ", name : " << it->get_name() << ", breed : "
          //        <<  it->get_breed() << ", age : " << it->get_age() << ", photo : " << it->get_photograph() << '\n';
    }
    std::cout << '\n';
}

void console::write_to_file() {

}

void console::read_from_file() {

}