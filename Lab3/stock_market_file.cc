//TDDD33 Lab3, Assignment 3 - Text file streams (stock_market_file.cc)
//Medhanie Weldemariam (medwe277)

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

double total_profit = 0;
int share_count = 0;

void process_all_transactions( istream& in, ostream& err, double& total_profit, int& share_count)
{

  int shares = 0;
  double price = 0.0;
  string comment;
  string user_input_all = " ";

  while ( getline(in, user_input_all) )
    {
      istringstream iss;
      iss.str(user_input_all);
      
     if (!(iss >> shares) || !(iss >> price))
	{
	  err << "Faulty data, ignoring line." << endl;
	  in.clear();
	  iss.clear();
	}

      else if((share_count + shares < 0))
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
	  total_profit = total_profit + (price*shares);
	  share_count = share_count + shares;
	}
   }
}

int main()
{
  string file_name = "";
  ifstream file_input;

  cout << "This program calculates your profit/loss for all your" << endl
       << "investments in one share." << endl;

  cout << "Enter the file with transactions: ";

  cin >> file_name;

  file_input.open(file_name.c_str());
 
  if ( !(file_input) )
    {
      cout << "invalid file" << endl;
      exit(0);
    }
  
  ofstream file_output{"transaction.log", ios::app};

  process_all_transactions(file_input, file_output, total_profit, share_count);

  file_output.close();
  file_input.close();
  
  cout << "Appending error messages to 'transaction.log'" << endl;

  cout << "Your Total " << (total_profit >= 0 ? "spendings ":"profit ");
      cout << "amount to  $" << fixed << setprecision(2) 
       << fabs(total_profit) << " and you own " << share_count << " shares." << endl;
      cout << endl;
  cout << "Bye. Have a nice day." << endl;
  return 0;	
}




