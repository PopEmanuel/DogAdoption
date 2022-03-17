//
// Created by Emanuel on 5/2/2021.
//

#ifndef A89_915_POP_EMANUEL_ADRIAN_MAINWINDOW_H
#define A89_915_POP_EMANUEL_ADRIAN_MAINWINDOW_H
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QTableWidget>
#include "../service/service_database.h"
#include <QTextEdit>
#include <QRadioButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    enum state{
        main, client, admin
    };
    int width, height;
    QPushButton *btn_user;
    QPushButton *btn_admin;
    QLabel *lbl_chose;
    QTableWidget *table_adopted;
    QTableWidget *table_available;
    service_database *service;
    QTextEdit *txt_add_dog_name;
    QTextEdit *txt_add_dog_breed;
    QTextEdit *txt_add_dog_age;
    QTextEdit *txt_add_dog_photo;
    QTextEdit *txt_id;
    QLabel *lbl_id;
    QLabel *lbl_add_dog_name;
    QLabel *lbl_add_dog_breed;
    QLabel *lbl_add_dog_age;
    QLabel *lbl_add_dog_photo;
    QPushButton *btn_add_dog;
    QPushButton *btn_delete_dog;
    QPushButton *btn_update_dog;
    QPushButton *btn_adopt_dog;
    QPushButton *btn_next_dog;
    std::vector<dog>::iterator iterator;
    QLabel *lbl_present_dog;
    QLabel *lbl_link;
    int index_iterator;
    QPushButton *btn_search_breed_age;
    QTextEdit *txt_search_age;
    QTextEdit *txt_search_breed;
    QLabel *lbl_search_breed;
    QLabel *lbl_search_age;
    QRadioButton *rd_html;
    QRadioButton *rd_txt;
    QRadioButton *rd_csv;
    state prog_state;
    QPushButton *btn_back;
    QPushButton *btn_open_list;
private slots:
    void click_admin();
    void click_user();
    void search_breed();
    void go_back();
    void add_dog();
    void delete_dog();
    void update_dog();
    void adopt_dog();
    void next_dog();
    void populate_tables();
    void open_list();
    void set_lbl_dog();
};


#endif //A89_915_POP_EMANUEL_ADRIAN_MAINWINDOW_H
