#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include<iostream>

using namespace std;

class sorted_list
{

private:
    class list_link
    {
    public:

        int key;
        float value;

        list_link(int key, double value, list_link* next);
        ~list_link();

        list_link(list_link const&);
        list_link& operator=(list_link const&);
        list_link* next;

    };
    list_link* first;
    sorted_list(sorted_list const&);
    sorted_list& operator=(sorted_list const&);

public:
    sorted_list():first(nullptr){} //Constructor declaration
    ~sorted_list(); // Destructor declaration
    void insert(int key, double value);
    void remove(int key);//  void copy(sorted_list* destination, sorted_list* source);
    void print(ostream& os);
    int size() const;
    bool find(int key) const;
    bool contains(sorted_list& straws) const;
};

#endif



