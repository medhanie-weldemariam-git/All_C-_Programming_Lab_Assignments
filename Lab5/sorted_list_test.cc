#include <iostream>
#include <iomanip>

#include "sorted_list.h"

using namespace std;

// N.B.
// You are recommended to create your own interactive test program to
// test each function as you implement it

int main()
{
    //-------------------------------------------------------------------------
    const int SIZE = 10; // Must be a power of 2
    int choice, key, new_size;

    sorted_list sl;

    sorted_list sl2;

    while (1)

    {

        cout<<endl<<"---------------------------------"<<endl;

        cout<<endl<<"Operations on Single linked list"<<endl;

        cout<<endl<<"---------------------------------"<<endl;

        cout<<"1.Insertion()"<<endl;

        cout<<"2.Find()"<<endl;

        cout<<"3.Deletion()"<<endl;

        cout<<"4.Display()"<<endl;

        cout<<"5.Contains()"<<endl;

        cout<<"6.Exit..."<<endl;

        cout<<"Enter your choice : "<<endl;

        cin>>choice;

        switch(choice)

        {

        case 1:

            cout << "You have successfully insert " << SIZE << " key value pairs in to the link" << endl;
            for (int i = 0; i <= SIZE; ++i)
            {
                int j = ( (i + SIZE/2) * 7 ) % SIZE;
                sl.insert(j, i);
            }

            cout<<endl;

            break;

        case 2:

            cout << "Enter the key to search from the list" << endl;

            cin>> key;

            if (sl.find(key))
            {
                cout << endl <<"The Key has been found!!" << endl;
            }
            else
            {
                cout << endl <<"Sorry key is not found!!" << endl;
            }

            cout<<endl;

            break;


        case 3:

            cout << "All key value pairs has been successfully removed from the link" << endl;

            for (int i = 0; i <= SIZE; ++i)
            {
                int j = ( (i + SIZE/2) * 7 ) % SIZE;
                sl.remove(j);
            }

            cout<<endl;

            break;

        case 4:

            cout<<"Displaying the linked list...:"<<endl;

            sl.print(cout);

            cout<<endl;

            break;

        case 5:

            cout<<"Enter the size for the second list"<<endl;

            cin>> new_size;

            for (int i = 0; i < new_size; ++i)
            {
                int j = ( (i + new_size/2) * 7 ) % new_size;
                sl2.insert(j, i);
            }

            cout<<"A second link with" << new_size << "has been created to check for contains() function...:"<<endl;

            if (sl.contains(sl2))
            {
                cout<<"TRUE is returned, so the old link contains the new link!!"<<endl;
            }
            else
            //{
                cout<<"FALSE is returned, so the old link does not contains the new link!!"<<endl;
            //}

            cout<<endl;

            break;

        case 6:

            cout<<"Exiting..."<<endl;

            exit(1);

            break;

        default:

            cout<<"Wrong choice"<<endl;

        }

    }

}
//------------------------------------------------------------------------------------------------------------
