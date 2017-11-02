#ifndef MENU_H
#define MENU_H

#include <string>

#include "product.h"
#include "database.h"

using namespace std;

class menu_option
{
    //accable to member functions of friends class
protected:
    string title;
public:
    menu_option(string title);
    virtual void on_select();
    virtual ~menu_option() {}
    string get_title();//Returns the title of this menu
};
/*-------Class sub_menu inherites menu_option------*/
class sub_menu : public menu_option
{
private:
    menu_option* menu_list[15];
    int index;

public:
    sub_menu(string title);
    ~sub_menu();
    virtual void add_option(menu_option* new_item);//Adds a menu option to the menu.
    void display();//Presents the list of menu options to the user
    void on_select();
    int get_index();
};
/*-----Class print_database inherites menu_option-----*/
class print_database : public menu_option
{
public:
    database* mydatabase;
    print_database(string title, database* mydatabase);
    void on_select();
    ~print_database() {}
};
/*-----Class add_book inherites menu_option-----*/
class add_book : public menu_option
{
public:
    database* mydatabase;
    add_book(string title, database* mydatabase);
    void on_select();
    ~add_book() {}
};
/*------Class add_grocery inherites menu_option------*/
class add_grocery : public menu_option
{
public:
    database* mydatabase;
    add_grocery(string title, database* mydatabase);
    void on_select();
    ~add_grocery() {}
};
/*-----Class add_movie inherites menu_option-----*/
class add_movie : public menu_option
{
public:
    database* mydatabase;
    add_movie(string title, database* mydatabase);
    void on_select();
    ~add_movie() {}
};
#endif

