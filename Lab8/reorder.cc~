//TDDD33 Lab8- Templates and Exceptions(reorder.cc)
//Medhanie Weldemariam (medwe277)

#include <iostream>
#include <sstream>

#include "stack.h"

using namespace std;

int main()
{
    string line;

    while ( getline(cin, line) )
    {
        // Add stack declarations here

        Stack<double> number;// a stack that stores numbers
        Stack<string> initial_string;// a stack that stores string or words or characters together with the separator (_?_) when numbers come
        Stack<string> final_string;//a stack to store the above string in reverse order

        istringstream iss(line);
        string str;
        double n;


        try
        {
            do
            {
                if ( iss >> n )
                {
                    // Successfully read a number
                    // Do something clever...

                    number.push(n);
                    final_string.push("_?_");
                }
                else
                {
                    iss.clear();
                    if ( iss >> str )
                    {
                        // Successfully read a word
                        // Do something clever...

                        final_string.push(str);
                    }
                }
            }
            while ( ! iss.eof() );

            // Code to print the line with words in original order and numbers
            // in revers order - see example

            while( ! final_string.is_empty() )

                initial_string.push(final_string.pop());

            while(1) // output
            {
                if ( initial_string.is_empty() )
                    break;
                if ( initial_string.top() == "_?_" )
                {
                    cout << number.pop() << " ";
                    initial_string.pop();
                }
                else
                {
                    cout << initial_string.pop() << " ";
                }
            }
            cout << endl;
        }
        catch(const stack_error& error)
        {
            cout << error.what() << endl;
        }

    }
    return 0;
}

