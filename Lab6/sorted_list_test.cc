#include <iostream>
#include <iomanip>

#include "sorted_list.h"

using namespace std;

// N.B.
// You are recommended to create your own interactive test program to
// test each function as you implement it

int main()
{
    sorted_list l;

    int SIZE; // Must be a power of 2

    cout<<"Please insert the size of the linked list"<<endl;

    cin>>SIZE;

    cout<<endl;

    cout << endl << "Inserting " << SIZE << " key value pairs." << endl;
    cout<<endl;
    for (int i = 0; i < SIZE; ++i)
    {
        int j = ( (i + SIZE/2) * 7 ) % SIZE;
        l.insert(j, i);
    }

    cout << "Contents after inserts:" << endl;
    l.print(cout);

    // LAB 6
    sorted_list copy(l);

    cout << "Removing the key value pairs from the link..." << endl;
    cout<<endl;
    for (int i = 0; i < SIZE; ++i)
    {
        int j = ( (i + SIZE/2) * 7 ) % SIZE;
        l.remove(j);
    }

    cout << "Contents after removes:" << endl;
    cout<<endl;
    l.print(cout);

    // LAB 6
    cout << "Contents of original after remove in copy:" << endl;
    cout<<endl;
    copy.print(cout);
    //
    l.insert(6, 12.0);
    copy = l;
    cout << "Contents after inserting (6, 12.0)" << endl;
    cout<<endl;
    l.print(cout);
    cout << "Contents after removing the key (6) from original list" << endl;
    l.remove(6);
    cout<<endl;
    l.print(cout);
    cout << "Contents of the assigned copy" << endl;
    cout<<endl;
    copy.print(cout);
    //
    // Add more tests for your assignment operator!!
    return 0;
}
