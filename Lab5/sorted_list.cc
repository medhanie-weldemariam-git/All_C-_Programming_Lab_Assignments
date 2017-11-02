#include"sorted_list.h"
#include<sstream>

using namespace std;


//--- In the implementation file
// Sorted_List::
//means that the following function is
// a member of the Sorted_List class (“internal” code)

sorted_list::sorted_list(sorted_list const&)
{
    // Constructor implementation

    cout << "Constructor called" << endl;
    this->first=0;
}
//-----------------------------------------------------
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
//-----------------------------------------------------
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

        cout << "Sorry, the Key does not exist!" << endl;

}
//-----------------------------------------------------
sorted_list::~sorted_list()
{
    cout << "Destructor called" << endl;
    delete this->first;
}
//-----------------------------------------------------
void sorted_list::print(ostream& os)
{
    list_link * link = this->first;
    if (link != 0)
    {
        do
        {
            os << (link->key) <<endl;

            if (link->next !=0)
                link = link->next;
            else
                link = 0;
        }
        while(link->next != 0);
        if (link != 0)
        {
            os << (link->key);
        }
        os << endl;
    }
    else
    {
        cout << "Sorry the linked list is empty!" << endl;
    }
}
//-----------------------------------------------------
int sorted_list::size() const
{
    list_link * link = this->first;
    int size = 0;
    if (link != 0)
    {
        do
        {
            ++size;
            link = link->next;
        }
        while(link->next != 0);

        if (size !=0)
            ++size;
    }
    return size;
}
//-----------------------------------------------------
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
//-----------------------------------------------------
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
//-----------------------------------------------------
sorted_list::list_link::list_link(int key, double value, list_link* next)
{
    this->key = key;
    this->value = value;
    this->next = next;
}
//-----------------------------------------------------
sorted_list::list_link::~list_link()
{
    delete this->next;

}


