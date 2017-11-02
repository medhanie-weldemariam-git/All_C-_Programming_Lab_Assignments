#include<iostream>
#include <string>
#include "product.h"
using namespace std;

product::product(string name, int price)
{
   this->name = name;
   this->price = price;
}
//------------------------------------------------
//void product::print() const{}
//------------------------------------------------
Book::Book(string name, int price , string author):product(name, price)
{
   this->author = author;
}
//print book store data
void Book::print() const
{
   cout<<"Name  : "<<this->name<<endl;
   cout<<"Price : "<<this->price<<endl;
   cout<<"Author:"<<this->author<<endl<<endl;
}
//------------------------------------------------
Movie::Movie(string name, int price, int runtime):product(name, price)
{
   this->runtime = runtime;
}
//print movie data
void Movie::print() const
{
   cout<<"Name    : "<<this->name<<endl;
   cout<<"Price   : "<<this->price<<endl;
   cout<<"Run Time:"<<this->runtime<<endl<<endl;
}
//------------------------------------------------
Grocery::Grocery(string name, int price, bool ecologic):product(name, price)
{
   this->ecologic = ecologic;
}
//print grocery data
void Grocery::print() const
{
   cout<<"Name    : "<<this->name<<endl;
   cout<<"Price   : "<<this->price<<endl;
   cout<<"Ecologic:"<<this->ecologic<<endl<<endl;
}
