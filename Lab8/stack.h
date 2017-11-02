//TDDD33 Lab8- Templates and Exceptions(stack.h)
//Medhanie Weldemariam (medwe277)

#ifndef _STACK_H_
#define _STACK_H_

#include <exception>

#define SIZE 20

using namespace std;

// Add stack (template) class declaration here

template <class Template>
class Stack
{   
public:
    Stack();
    void push(Template item);
    Template pop();
    Template top() const;
    bool is_empty() const;
    bool is_full() const;
private:
    Template data[SIZE];
    int index;
};

class stack_error : public exception
{
public:
    stack_error(string const& m) noexcept:exception(),err_msg(m){};

    ~stack_error() noexcept{};

    virtual const char* what() const noexcept
    {
        return err_msg.c_str();
    };
private:
    string err_msg;
};
//exception handeler class definition for empty stack
class stack_empty_error : public  stack_error
{
public:
    stack_empty_error() noexcept: stack_error("The stack is empty!!"){};

    ~stack_empty_error() noexcept{};
};
//exception handeler class definition for full stack
class stack_full_error : public  stack_error
{
public:
    stack_full_error() noexcept: stack_error("The stack is full!!"){};

    ~stack_full_error() noexcept{};
};
/* Templates can not be compiled until the actual template types are
 * known, thus the implementation must be included whenever used.*/
#include "stack.template.cc"

#endif
