#include<iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "menu.h"

using namespace std;
/************************Menu Option*********************/

menu_option::menu_option(string title)
{
    this->title = title;
}
string menu_option::get_title()
{
    return this->title;
}

void menu_option::on_select()
{
    //cout<<"On_Select >> Menu_Option"<<endl;
}

/************************Sub Menu*********************/	
sub_menu::sub_menu(string title) : menu_option(title), index(0)
{
    //
}

sub_menu::~sub_menu()
{
    for(int i = 0; i < index; i++)
    {  
         if (menu_list[i])
        delete menu_list[i];
    }
}

void sub_menu::add_option(menu_option* newItem)
{  
    if(this->get_index() <=9 )
    {
        this->menu_list[this->index] = newItem;
        this->index =  this->get_index() + 1;
    }
    else
    {
        cout<<"index overflow"<<endl;
    }
}

int sub_menu::get_index()
{
    return this->index;
}

/*---display sub menu-----*/
void sub_menu::display()
{
    int position;
    cout << endl;
    cout<<">>"<<this->get_title()<<" << "<<endl;


    for(position=0; position<index; position++)
    {
        cout << position << " : " << menu_list[position]->get_title() << endl;
    }
    cout << position << " : Return " << endl;
    cout << "Please enter your choice: ";
}

/*-----select sub menu sub class of sub menu----*/
void sub_menu::on_select()
{
    this->display();

    int input;
    cin >> input;
    cout<<endl;
    while(input != index)
    {
        if(input < 0 || input > index)
            break;
        menu_list[input]->on_select();//selects the menu list
        this->display();
        cin >> input;

    }

}

/************************Print Database***************/
print_database::print_database(string title, database* mydatabase): menu_option(title)
{
    this->mydatabase = mydatabase;
}
void print_database::on_select()
{
    cout << "The database contain items:" << endl;
    mydatabase->print_all();
    cout << endl;

}


/************************Add Book*********************/

add_book::add_book(string title, database* mydatabase): menu_option(title)
{
    this->mydatabase = mydatabase;
}

void add_book::on_select()
{

    int p;
    string auth,tit;

    cout<<"Please enter book information."<<endl;
    cout<<"price : ";
    cin>>p;
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"title : ";
    getline(cin,tit);
    cout<<"author : ";
    getline(cin,auth);

    Book* new_book=new Book(tit, p , auth);
    mydatabase->add_product(new_book);
}

/************************Add Movie********************/
add_movie::add_movie(string title, database* mydatabase): menu_option(title)
{
    //cout<<"Add Movie called"<<endl;
    //this->title = title;
    this->mydatabase = mydatabase;
}

void add_movie::on_select()
{

    int p,rtime;
    string tit;
    cout << endl;
    cout<<"Please enter movie information."<<endl;
    cout<<"price : ";
    cin>>p;
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"title : ";
    getline(cin , tit);
    cout<<"runtime : ";
    cin>>rtime;

    Movie* new_movie = new Movie(tit, p , rtime);
    mydatabase->add_product(new_movie);

}
/************************Add Grocery******************/
add_grocery::add_grocery(string title, database* mydatabase): menu_option(title)
{
    //cout<<"Add Grocery called"<<endl;
    //this->title = title;
    this->mydatabase = mydatabase;
}

void add_grocery::on_select()
{
    int p;
    string tit, eco;
    bool status;
    cout << endl;
    cout<<"Please enter grocery information."<<endl;
    cout<<"price   : ";
    cin>>p;
    cin.clear();
    cin.ignore(1000,'\n');

    cout<<"variety : ";
    getline(cin , tit);
    cout<<"ecofood : ";
    getline(cin , eco);

    if(eco == "yes")
        status = true;
    else
        status = false;

    Grocery* new_grocery=new Grocery(tit, p , status);
    mydatabase->add_product(new_grocery);

}

