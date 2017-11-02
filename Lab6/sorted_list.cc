#include"sorted_list.h"
#include<sstream>
#include <utility>
#include<iomanip>

using namespace std;

//--- In the implementation file
// Sorted_List::
//means that the following function is
// a member of the Sorted_List class (“internal” code)


void sorted_list::insert(int key, double value)
{
    list_link * link;

    if (this->first !=0)
    {
        if(key<(this->first->key))
        {
            link = new list_link(key,value,this->first);
            this->first = link;
        }
        else if (key==(this->first->key))
        {
            //cout << "Key exist" << endl;
        }
        else
        {
            list_link * temp = this->first;
            list_link * tempnext = this->first->next;
            bool isInsert = false;

            while((tempnext != 0)&&(!isInsert))
            {

                if (tempnext->key == key)
                {
                    //cout << "Key exist" << endl;
                    isInsert = true;
                    break;
                }
                else if (key<(tempnext->key))
                {
                    link = new list_link(key,value,tempnext);
                    temp->next = link;
                    isInsert = true;
                }

                temp = tempnext;
                tempnext = tempnext->next;

            }
            if((!isInsert)&&(key>(temp->key)))
            {
                link = new list_link(key,value,0);
                temp->next = link;
            }
        }

    }
    else
    {
        link = new list_link(key,value,0);
        this->first = link;
    }
}
//-----------------------------------------------------------------
void sorted_list::remove(int key)
{
    list_link * front = 0;
    list_link * back = 0;
    bool isRemoved = false;

    if (find(key))
    {
        if (key ==this->first->key)
        {
            back = this->first;
            this->first = back->next;
            back->next = 0;
            delete back;
            isRemoved = true;
        }

        else
        {
            back = this->first;
            front = this->first->next;

            while(front != 0)
            {
                if (key == front->key)
                {
                    back->next=front->next;

                    front->next = 0;
                    delete front;
                    isRemoved = true;
                    break;
                }
                back = front;
                front = front->next;
            }
        }
    }
    if (!isRemoved)
    {
        cout << "Sorry, the Key does not exist!" << endl;
    }
}


sorted_list::~sorted_list()
{
    //cout << "Destructor called" << endl;
    delete this->first;
}

//-------------------------------------------------------------------------------
void sorted_list::print(ostream& os)
{
    list_link * link = this->first;
    if (link != 0)
    {
        do
        {
            os << (link->key)  <<endl;

            if (link->next !=0)
                link = link->next;
            else
                link = 0;
        }
        while(link != 0);
        if (link != 0)
        {
            os << (link->key);
        }
        os << endl;
    }
    else
    {
        cout << "----Sorry the linked list is empty!----" << endl;
        cout<<endl;
    }
}
//-------------------------------------------------------------------------
int sorted_list::size() const
{
    list_link * link = this->first;
    int size = 0;
    if (link != nullptr)
    {
        do
        {
            ++size;
            link = link->next;
        }
        while(link->next != nullptr);

        if (size !=0)
            ++size;
    }
    return size;
}
//-----------------------------------------------------------------------
bool sorted_list::find(int key) const
{
    list_link * link = this->first;
    bool found = false;
    while((link != nullptr) && (!found))
    {
        if(link->key == key)
        {
            found = true;
        }
        else
        {
            link = link->next;
        }
    }
    return found;
}
//-------------------------------------------------------------------
bool sorted_list::contains(sorted_list& straws) const
{
    if(this->size()< straws.size())
    {
        return false;
    }
    else
    {
        list_link * link = straws.first;
        while((link != nullptr))
        {
            if(this->find(link->key))
                link = link->next;
            else return false;
        }
        return true;
    }
}
//------------------------------------------------------------------------
sorted_list::list_link::list_link(int key, double value, list_link* next)
{
    this->key = key;
    this->value = value;
    this->next = next;
}

sorted_list::list_link::~list_link()
{
    delete this->next;

}

//------------------------------------------------------------------------------------------------

ostream& operator <<(ostream& os,sorted_list const& sorted)
{

    sorted_list::list_link * link = sorted.first;
    os << "{" << endl;
    while (link != nullptr)
    {
        os << setw(6) << link->key << setw(6) << link->value << endl;
        link = link->next;
    }
    os << "}" << endl;
    return os;
}
//------------------------------------------------------------------------------------
double sorted_list::operator[](int key)
{
    list_link * link = this->first;
    while(link != nullptr)
    {
        if(link->key == key)
        {
            return link->value;
        }
        else
        {
            link = link->next;
        }
    }
    return -1;
}
//--------------------------------------------------------------------------
sorted_list sorted_list::operator+(sorted_list const& rhs)
{

    sorted_list copy;

    list_link * link = first;

    while(link !=nullptr)
    {
        copy.insert(link->key,link->value);
        link = link->next;
    }
    link = rhs.first;
    while(link !=nullptr)
    {
        copy.insert(link->key,link->value);
        link = link->next;
    }
    return copy;
}
//--------------------------------------------------------------------------------
sorted_list::sorted_list(sorted_list const& rhs):first(new list_link(0,0,nullptr))
{
        list_link * temp_link = first;
        list_link * link = rhs.first;
        list_link * newlink = nullptr;
        temp_link->key = link->key;
        temp_link->value = link->value;

        link = link->next;

        while(link != nullptr)
            {
                newlink = new list_link(link->key,link->value,nullptr);
                temp_link->next = newlink;
                temp_link = newlink,
                link = link->next;
            }
}
//-----------------------------------------------------------------------
sorted_list& sorted_list::operator=(sorted_list const& sorted)
{

    if (this != &sorted)
    {
        sorted_list copy(sorted);
        swap(first,copy.first);
    }
    return *this;
}
