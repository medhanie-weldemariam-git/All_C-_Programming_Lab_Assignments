#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include<iostream>
#include<string>

using namespace std;

class sorted_list
{
private:
    class list_link // Inner class in sorted_list
    {
    public:
        int key;
        float value;
        list_link* next;

        list_link(int key, double value, list_link* next);
        ~list_link();

        list_link(list_link const&);
        list_link& operator=(list_link const&);
    };
    list_link* first;

public:
    sorted_list():first(nullptr){} //Constructor
    ~sorted_list(); //Destructor

    void insert(int key, double value);
    void remove(int key) ;
    void print(ostream& os);
    int size() const;
    bool find(int key) const;
    bool contains(sorted_list& straws) const;

    //New method for copy Constructor
    sorted_list(sorted_list const& original);
    //New header method for operator overloading
    sorted_list& operator=(sorted_list const& rhs);
    sorted_list operator+(sorted_list const& rhs);
    double operator[](int key);
    friend ostream& operator <<(ostream& os,sorted_list const& rhs);
};

#endif

