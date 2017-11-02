//TDDD33 Lab3, Assignment 2 - Line based reading (stock_market_line.cc)
//Medhanie Weldemariam (medwe277)

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

void process_all_transactions( istream& in, ostream& err, double& total_profit, int& share_count)
{

    int share = 0;
    double price = 0.0;
    string user_input_all = "";

    while ( getline(in, user_input_all, '\n') )
    {
        istringstream iss;
        iss.str(user_input_all);

        iss >> share;
        iss >> price;

        if (!iss)
        {
            err << "Faulty data, ignoring line" << endl;
            in.clear();
            iss.clear();
        }
        else if(share < -share_count)
        {
            err << "You do not have that many shares, ignoring line." << endl;
            in.clear();
            iss.clear();
        }
        else if(price < 0)
        {
            err << "The price may not be negative, ignoring line." << endl;
            in.clear();
            iss.clear();
        }
        else
        {
            total_profit = total_profit + (price*share);
            share_count = share_count + share;
            share=0;
            price=0;
            //break;
        }

    }
}

int main()
{
    int share_count = 0;

    double total_profit = 0;

    cout << "This Program calculates your profit/loss for all your \ninvestment in one share." << endl;
    cout << "Use a positive number for purchase, and a negative for sell." << endl;
    cout << "Enter one transaction per line as COUNT PRICE COMMENT" << endl << endl;


        process_all_transactions( cin, cerr, total_profit, share_count);

        cout << "Your total spending amount to $" << fixed<< setprecision(2) << total_profit <<" and you own " << share_count <<" shares." <<endl ;

        cout << "Bye. Have a nice day" << endl;
        exit (0);

}






