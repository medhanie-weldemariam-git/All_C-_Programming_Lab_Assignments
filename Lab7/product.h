#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>


using namespace std;

class product
{
protected://accable to member functions of friends class
    string name;
    int price;

public:
    product(string name, int price);
    virtual void print() const{}
};

/*------Class Book inherits product------*/
class Book: public product
{
protected:
    string author;

public:
    Book(string name, int price , string author);
    void print() const;
};
/*----Class Movie inherits product----*/
class Movie: public product
{
protected:
    int runtime;

public:
    Movie(string name, int price, int runtime);
    void print() const;
};
/*-----Class Grocery inherits product-----*/
class Grocery: public product
{
protected:
    bool ecologic;

public:
    Grocery(string name, int price, bool ecologic );
    void print() const;
};
#endif





