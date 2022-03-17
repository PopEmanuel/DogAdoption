//
// Created by Emanuel on 5/2/2021.
//

#include "MainWindow.h"
#include "QGradient"
#include <string>
#include <QTableWidgetItem>
#include <QDebug>
#include <iostream>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
:   QMainWindow(parent)
{
    //service = new service_database(txt);
    //service->read_from_file();
    //QLinearGradient gradient(QPointF(100, 100), QPointF(200, 200));
    QGradient gradient(QGradient::OldHat);
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(1, Qt::blue);
    QPalette p;
    p.setBrush(QPalette::Window, QBrush(gradient));
    this->setPalette(p);
    this->service = new service_database(txt);
    this->width = 1000;
    this->height = 800;
    this->setGeometry(100, 100, this->width, this->height);

    prog_state = main;

    p.setColor(QPalette::Button, QColor(Qt::yellow));
    btn_back = new QPushButton(this);
    btn_back->setPalette(p);
    btn_back->setStyleSheet("color='blue'");
    btn_back->setGeometry(this->width - 120, 20, 100, 100);
    btn_back->setText("<-- Back");
    btn_back->show();
    connect(btn_back, SIGNAL(clicked(bool)), this, SLOT(go_back()));

    table_adopted = new QTableWidget(this);
    QHeaderView *header = table_adopted->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    table_adopted->setGeometry(100, 400, this->width - 200, 200);
    table_adopted->setColumnCount(5);
    auto *list = new QStringList();
    list->append("id");
    list->append("name");
    list->append("breed");
    list->append("age");
    list->append("photo");
    table_adopted->setHorizontalHeaderLabels(*list);
    table_adopted->hide();

    table_available = new QTableWidget(this);
    QHeaderView *header2 = table_available->horizontalHeader();
    header2->setSectionResizeMode(QHeaderView::Stretch);
    table_available->setGeometry(100, 150, this->width - 200, 200);
    table_available->setColumnCount(5);
    delete list;
    list = new QStringList();
    list->append("id");
    list->append("name");
    list->append("breed");
    list->append("age");
    list->append("photo");
    table_available->setHorizontalHeaderLabels(*list);
    table_available->hide();

    btn_admin = new QPushButton(this);
    btn_admin->setText("Admin");
    p.setColor(QPalette::Button, QColor(Qt::cyan));
    btn_admin->setPalette(p);
    btn_admin->setGeometry(this->width / 2 - 150, this->height / 2, 300, 100);
    btn_admin->show();
    connect(this->btn_admin, SIGNAL(clicked(bool)), this, SLOT(click_admin()));

    rd_txt = new QRadioButton(this);
    rd_txt->setText("Text file");
    rd_txt->setGeometry(100, 250, 100, 100);
    rd_txt->show();

    rd_html = new QRadioButton(this);
    rd_html->setText("html file");
    rd_html->setGeometry(100, 300, 100, 100);
    rd_html->show();

    rd_csv = new QRadioButton(this);
    rd_csv->setText("csv file");
    rd_csv->setGeometry(100, 350, 100, 100);
    rd_csv->show();

    rd_txt->setChecked(true);

    btn_user = new QPushButton(this);
    btn_user->setText("User");
    btn_user->setGeometry(this->width / 2 - 150, this->height / 2 - 200, 300, 100);
    btn_user->setPalette(p);
    btn_user->show();
    connect(this->btn_user, SIGNAL(clicked(bool)), this, SLOT(click_user()));

    this->lbl_chose = new QLabel(this);
    this->lbl_chose->setGeometry(this->width / 2 - 150, this->height / 2 - 400, 300, 100);
    this->lbl_chose->setText("Chose in which way you want to open the application : ");
    this->lbl_chose->show();

    txt_add_dog_name = new QTextEdit(this);
    lbl_add_dog_name = new QLabel(this);
    txt_add_dog_breed = new QTextEdit(this);
    lbl_add_dog_breed = new QLabel(this);
    txt_add_dog_age = new QTextEdit(this);
    lbl_add_dog_age = new QLabel(this);
    txt_add_dog_photo = new QTextEdit(this);
    lbl_add_dog_photo = new QLabel(this);
    txt_id = new QTextEdit(this);
    lbl_id = new QLabel(this);
    btn_add_dog = new QPushButton(this);
    btn_delete_dog = new QPushButton(this);
    btn_update_dog = new QPushButton(this);

    lbl_link = new QLabel(this);
    lbl_present_dog = new QLabel(this);
    btn_open_list = new QPushButton(this);
    btn_adopt_dog = new QPushButton(this);
    btn_next_dog = new QPushButton(this);
    btn_search_breed_age = new QPushButton(this);
    txt_search_breed = new QTextEdit(this);
    txt_search_age = new QTextEdit(this);
    lbl_search_breed = new QLabel(this);
    lbl_search_age = new QLabel(this);

    connect(this->btn_add_dog, SIGNAL(clicked(bool)), this, SLOT(add_dog()));
    connect(this->btn_delete_dog, SIGNAL(clicked(bool)), this, SLOT(delete_dog()));
    connect(this->btn_update_dog, SIGNAL(clicked(bool)), this, SLOT(update_dog()));
    connect(btn_adopt_dog, SIGNAL(clicked(bool)), this, SLOT(adopt_dog()));
    connect(btn_search_breed_age, SIGNAL(clicked(bool)), this, SLOT(search_breed()));
    connect(btn_next_dog, SIGNAL(clicked(bool)), this, SLOT(next_dog()));

    table_adopted->hide();
    lbl_present_dog->hide();
    lbl_link->hide();
    btn_search_breed_age->hide();
    txt_search_breed->hide();
    txt_search_age->hide();
    lbl_search_age->hide();
    lbl_search_breed->hide();
    btn_adopt_dog->hide();
    btn_next_dog->hide();
    btn_open_list->hide();
    table_available->hide();
    table_adopted->hide();
    txt_id->hide();
    txt_add_dog_photo->hide();
    txt_add_dog_age->hide();
    txt_add_dog_breed->hide();
    txt_add_dog_name->hide();
    lbl_id->hide();
    lbl_add_dog_breed->hide();
    lbl_add_dog_name->hide();
    lbl_add_dog_age->hide();
    lbl_add_dog_photo->hide();
    btn_add_dog->hide();
    btn_delete_dog->hide();
    btn_update_dog->hide();



    //populate_tables();


}

void MainWindow::populate_tables() {

    auto it = service->get_begin_iterator(available);
    int length = service->get_length_available_dogs();
    int cnt = 0;
    table_available->setRowCount(0);
    table_adopted->setRowCount(0);

    for(it; it != service->get_end_iterator(available); ++it)
    {
        //qDebug() << "123";
        table_available->insertRow(cnt);

        QString name = QString::fromStdString(it->get_name());
        table_available->setItem(cnt, 1, new QTableWidgetItem(name));
        name = QString::number(it->get_id());
        table_available->setItem(cnt, 0, new QTableWidgetItem(name));
        name = QString::fromStdString(it->get_breed());
        table_available->setItem(cnt, 2, new QTableWidgetItem(name));
        name = QString::number(it->get_age());
        table_available->setItem(cnt, 3, new QTableWidgetItem(name));
        name = QString::fromStdString(it->get_photograph());
        table_available->setItem(cnt, 4, new QTableWidgetItem(name));
        cnt++;
    }
    cnt = 0;
    it = service->get_begin_iterator(adopted);
    length = service->get_length_available_dogs();

    for(it; it != service->get_end_iterator(adopted); ++it)
    {
        table_adopted->insertRow(cnt);

        QString name = QString::fromStdString(it->get_name());
        table_adopted->setItem(cnt, 1, new QTableWidgetItem(name));
        name = QString::number(it->get_id());
        table_adopted->setItem(cnt, 0, new QTableWidgetItem(name));
        name = QString::fromStdString(it->get_breed());
        table_adopted->setItem(cnt, 2, new QTableWidgetItem(name));
        name = QString::number(it->get_age());
        table_adopted->setItem(cnt, 3, new QTableWidgetItem(name));
        name = QString::fromStdString(it->get_photograph());
        table_adopted->setItem(cnt, 4, new QTableWidgetItem(name));
        cnt++;
    }
}

MainWindow::~MainWindow() {
    delete txt_add_dog_name;
    delete lbl_add_dog_name;
    delete txt_add_dog_breed;
    delete lbl_add_dog_breed;
    delete txt_add_dog_age;
    delete lbl_add_dog_age;
    delete txt_add_dog_photo;
    delete  lbl_add_dog_photo;
    delete  txt_id;
    delete   lbl_id;
    delete   btn_add_dog;
    delete   btn_delete_dog;
    delete   btn_update_dog;
    delete lbl_link;
    delete  lbl_present_dog;
    delete  btn_open_list;
    delete btn_adopt_dog;
    delete  btn_next_dog;
    delete btn_search_breed_age;
    delete txt_search_breed;
    delete txt_search_age;
    delete lbl_search_breed;
    delete lbl_search_age;

}

void MainWindow::click_admin() {
    delete this->service;
    if(rd_txt->isChecked())
        this->service = new service_database(txt);
    if(rd_html->isChecked())
        this->service = new service_database(html);
    if(rd_csv->isChecked())
        this->service = new service_database(csv);
    service->read_from_file();
    populate_tables();
    prog_state = admin;
    rd_csv->hide();
    rd_txt->hide();
    rd_html->hide();
    this->btn_admin->hide();
    this->btn_user->hide();
    this->lbl_chose->hide();
    table_adopted->show();
    table_available->show();

    txt_add_dog_name->setGeometry(table_available->x(), table_available->y() - 55, 100, 20);
    txt_add_dog_name->show();

    lbl_add_dog_name->setGeometry(table_available->x(), table_available->y() - 85, 100, 20);
    lbl_add_dog_name->show();
    lbl_add_dog_name->setText("Name :");


    txt_add_dog_breed->setGeometry(table_available->x() + 150, table_available->y() - 55, 100, 20);
    txt_add_dog_breed->show();

    lbl_add_dog_breed->setGeometry(table_available->x() + 150, table_available->y() - 85, 100, 20);
    lbl_add_dog_breed->show();
    lbl_add_dog_breed->setText("Breed :");


    txt_add_dog_age->setGeometry(table_available->x() + 300, table_available->y() - 55, 100, 20);
    txt_add_dog_age->show();

    lbl_add_dog_age->setGeometry(table_available->x() + 300, table_available->y() - 85, 100, 20);
    lbl_add_dog_age->show();
    lbl_add_dog_age->setText("Age :");


    txt_add_dog_photo->setGeometry(table_available->x() + 450, table_available->y() - 55, 100, 20);
    txt_add_dog_photo->show();

    lbl_add_dog_photo->setGeometry(table_available->x() + 450, table_available->y() - 85, 100, 20);
    lbl_add_dog_photo->show();
    lbl_add_dog_photo->setText("Photo :");

    txt_id->setGeometry(table_available->x() - 80, table_available->y() - 55, 50, 20);
    txt_id->show();

    lbl_id->setGeometry(table_available->x() - 80, table_available->y() - 85, 50, 20);
    lbl_id->show();
    lbl_id->setText("Id :");


    btn_add_dog->setGeometry(table_available->x() + 600, table_available->y() - 55, 100, 20);
    btn_add_dog->setText("add dog");
    btn_add_dog->show();


    btn_delete_dog->setGeometry(table_available->x() + 600, table_available->y() - 85, 100, 20);
    btn_delete_dog->setText("delete dog");
    btn_delete_dog->show();


    btn_update_dog->setGeometry(table_available->x() + 600, table_available->y() - 25, 100, 20);
    btn_update_dog->setText("update dog");
    btn_update_dog->show();





}

void MainWindow::click_user() {
//    delete txt_add_dog_name;
//    delete lbl_add_dog_name;
//    delete txt_add_dog_breed;
//    delete lbl_add_dog_breed;
//    delete txt_add_dog_age;
//    delete lbl_add_dog_age;
//    delete txt_add_dog_photo;
//    delete  lbl_add_dog_photo;
//    delete  txt_id;
//    delete   lbl_id;
//    delete   btn_add_dog;
//    delete   btn_delete_dog;
//    delete   btn_update_dog;

    delete this->service;
    if(rd_txt->isChecked())
        this->service = new service_database(txt);
    if(rd_html->isChecked())
        this->service = new service_database(html);
    if(rd_csv->isChecked())
        this->service = new service_database(csv);
    service->read_from_file();
    populate_tables();
    prog_state = client;
    rd_csv->hide();
    rd_txt->hide();
    rd_html->hide();
    this->btn_admin->hide();
    this->btn_user->hide();
    this->lbl_chose->hide();
    table_available->hide();
    table_adopted->show();

    lbl_present_dog->setGeometry(table_adopted->x(), 100, 400, 200);
    lbl_present_dog->show();
    lbl_present_dog->setFont(QFont("Helvetica", 20, 0, true));
    iterator = service->get_begin_iterator(available);
    index_iterator = 0;
    set_lbl_dog();

    btn_open_list->setGeometry(btn_back->x() - 150, btn_back->y(), 100, 100);
    btn_open_list->setText("Open adoption list");
    btn_open_list->show();
    connect(btn_open_list, SIGNAL(clicked(bool)), this, SLOT(open_list()));


    lbl_link->setGeometry(table_adopted->x() + 400, 200, 300, 30);
    lbl_link->setFont(QFont("Helvetica", 20, 0, true));
    lbl_link->setTextFormat(Qt::RichText);
    lbl_link->setTextInteractionFlags(Qt::TextBrowserInteraction);
    lbl_link->setOpenExternalLinks(true);
    lbl_link->setText("<a href=\"" + QString::fromStdString(iterator->get_photograph()) + "\">Click here for photo!</a>");
    lbl_link->show();

    btn_adopt_dog->setGeometry(table_adopted->x(), 300, 100, 50);
    btn_adopt_dog->setText("Adopt this dog");
    btn_adopt_dog->show();

    btn_next_dog->setGeometry(table_adopted->x() + 150, 300, 100, 50);
    btn_next_dog->setText("Next dog");
    btn_next_dog->show();



    btn_search_breed_age->setGeometry(table_adopted->x() + 450, 700, 300, 30);
    btn_search_breed_age->show();
    btn_search_breed_age->setText("Show dogs with this breed and under this age");



    txt_search_breed->setGeometry(table_adopted->x(), 700, 150, 30);
    txt_search_breed->show();


    txt_search_age->setGeometry(table_adopted->x() + 200, 700, 150, 30);
    txt_search_age->show();


    lbl_search_breed->setGeometry(table_adopted->x(), 650, 150, 30);
    lbl_search_breed->setText("Breed :");
    lbl_search_breed->show();


    lbl_search_age->setGeometry(table_adopted->x() + 200, 650, 150, 30);
    lbl_search_age->setText("Age :");
    lbl_search_age->show();


}

void MainWindow::set_lbl_dog() {
    QString string = "Name : " + QString::fromStdString((iterator + index_iterator)->get_name()) + " \nBreed : " + QString::fromStdString(
            (iterator + index_iterator)->get_breed()) + "\nAge : " +
                     QString::number((iterator + index_iterator)->get_age()) + "\nPhoto : ";
    lbl_present_dog->setText(string);
    lbl_link->setText("<a href=\"" + QString::fromStdString((iterator + index_iterator)->get_photograph()) + "\">Click here for photo!</a>");
}

void MainWindow::add_dog() {
    QString name = txt_add_dog_name->toPlainText();
    QString breed = txt_add_dog_breed->toPlainText();
    QString age = txt_add_dog_age->toPlainText();
    QString photo = txt_add_dog_photo->toPlainText();
    int id = 0;
    for(auto it = this->service->get_begin_iterator(available); it != this->service->get_end_iterator(available); ++it)
        if(it->get_id() > id)
            id = it->get_id();

    for(auto it = this->service->get_begin_iterator(adopted); it != this->service->get_end_iterator(adopted); ++it)
        if(it->get_id() > id)
            id = it->get_id();

    this->service->add_dog(available, id + 1, breed.toStdString(), name.toStdString(), age.toInt(), photo.toStdString());
    populate_tables();
    service->write_to_file();
}

void MainWindow::delete_dog() {
    int id = txt_id->toPlainText().toInt();
    qDebug() << id;
    if(id != 0)
        this->service->remove_dog(available, id);

    populate_tables();
    service->write_to_file();

}

void MainWindow::update_dog() {
    int id = txt_id->toPlainText().toInt();
    std::string name = txt_add_dog_name->toPlainText().toStdString();
    std::string breed = txt_add_dog_breed->toPlainText().toStdString();
    int age = txt_add_dog_age->toPlainText().toInt();
    std::string photo = txt_add_dog_photo->toPlainText().toStdString();

    this->service->update_dog(available, id, dog(id, breed, name, age, photo));
    populate_tables();
    service->write_to_file();
}

void MainWindow::adopt_dog() {
    if(service->get_length_available_dogs() == 0)
    {
        lbl_present_dog->setText("");
        return;
    }
    if(service->get_length_available_dogs() - 1 == index_iterator)
        index_iterator = 0;

    service->add_dog(adopted, (iterator + index_iterator)->get_id(), (iterator + index_iterator)->get_breed(),
                     (iterator + index_iterator)->get_name(), (iterator + index_iterator)->get_age(), (iterator + index_iterator)->get_photograph());
    service->remove_dog(available, (iterator + index_iterator)->get_id());
    populate_tables();

    set_lbl_dog();
    service->write_to_file();
}

void MainWindow::next_dog() {
    if(service->get_length_available_dogs() == 0)
    {
        lbl_present_dog->setText("");
        return;
    }
    if(service->get_length_available_dogs() - 1 == index_iterator)
        index_iterator = 0;
    else
        index_iterator++;
    set_lbl_dog();
}

void MainWindow::search_breed() {
    if(txt_search_age->toPlainText().isEmpty() && txt_search_breed->toPlainText().isEmpty()) {
        populate_tables();
        return;
    }
    table_adopted->setRowCount(0);
    int cnt = 0;
    auto it = service->get_begin_iterator(available);
    for(it; it != service->get_end_iterator(available); ++it)
    {
        //std::cout << it->get_breed() << txt_search_breed->toPlainText().toStdString() << "c " << it->get_age() <<  txt_search_age->toPlainText().toInt() << 'c';
        if(it->get_breed() == txt_search_breed->toPlainText().toStdString() && it->get_age() <= txt_search_age->toPlainText().toInt())
        {
            std::cout << "da";
            table_adopted->insertRow(cnt);

            QString name = QString::fromStdString(it->get_name());
            table_adopted->setItem(cnt, 1, new QTableWidgetItem(name));
            name = QString::number(it->get_id());
            table_adopted->setItem(cnt, 0, new QTableWidgetItem(name));
            name = QString::fromStdString(it->get_breed());
            table_adopted->setItem(cnt, 2, new QTableWidgetItem(name));
            name = QString::number(it->get_age());
            table_adopted->setItem(cnt, 3, new QTableWidgetItem(name));
            name = QString::fromStdString(it->get_photograph());
            table_adopted->setItem(cnt, 4, new QTableWidgetItem(name));
            cnt++;
        }
    }
}

void MainWindow::go_back() {
    switch (prog_state) {
        case main:
            break;
        case admin:
            table_available->hide();
            table_adopted->hide();
            txt_id->hide();
            txt_add_dog_photo->hide();
            txt_add_dog_age->hide();
            txt_add_dog_breed->hide();
            txt_add_dog_name->hide();
            lbl_id->hide();
            lbl_add_dog_breed->hide();
            lbl_add_dog_name->hide();
            lbl_add_dog_age->hide();
            lbl_add_dog_photo->hide();
            btn_add_dog->hide();
            btn_delete_dog->hide();
            btn_update_dog->hide();

            btn_user->show();
            btn_admin->show();
            lbl_chose->show();
            rd_csv->show();
            rd_html->show();
            rd_txt->show();
            break;
        case client:
            table_adopted->hide();
            lbl_present_dog->hide();
            lbl_link->hide();
            btn_search_breed_age->hide();
            txt_search_breed->hide();
            txt_search_age->hide();
            lbl_search_age->hide();
            lbl_search_breed->hide();
            btn_adopt_dog->hide();
            btn_next_dog->hide();
            btn_open_list->hide();

            btn_user->show();
            btn_admin->show();
            lbl_chose->show();
            rd_csv->show();
            rd_html->show();
            rd_txt->show();
            break;

    }
}

void MainWindow::open_list() {
    this->service->open_list_of_adoption();
}
