//TDDD33 Lab8- Templates and Exceptions(stack.template.cc)
//Medhanie Weldemariam (medwe277)

#include<iostream>


#include "stack.h"

using namespace std;

template <class Temp>

Stack<Temp>::Stack():index(0){ }
//--------------------------------------------------
template <class Temp>
Temp Stack<Temp>::pop()
{
    if (this->is_empty() ) throw stack_empty_error();
    return (this->data[--this->index]);
}
//--------------------------------------------------
template <class Temp>
void Stack<Temp>::push(Temp item) 
{  
    if (this->is_full() ) throw stack_full_error();
    this->data[this->index++] = item;
}
//--------------------------------------------------
template <class Temp>
Temp Stack<Temp>::top() const
{
    if (this->is_empty() ) throw stack_empty_error();
    return (this->data[this->index - 1]);
}
//--------------------------------------------------
template <class Temp>
bool Stack<Temp>::is_empty() const
{
    return (this->index == 0);
}
//--------------------------------------------------
template <class Temp>
bool Stack<Temp>::is_full() const
{
    return (this->index == SIZE);
}
