//TDDD33 Lab3, Assignment 1 - Handling stream errors (stock_market_safe.cc)
//Medhanie Weldemariam (medwe277)


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>


using namespace std;


float user_input_reader(string hint_message, int lower_limit, string error_message)
{
  int user_input;
  
  while( (cout << hint_message) && !(cin >> user_input))
    {
      cout << "Not a valid Number." << endl;
      
      if ( cin.eof() )
	{
	  cin.clear(); 
	}
      else
	{
	  cin.clear();
	  cin.ignore(1000, '\n');
      }
    }
  
  
  if (user_input < lower_limit)
    {
      cout << error_message << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      return user_input_reader(hint_message, lower_limit, error_message);
    }
  return user_input;
  
}


int main()
{

  float balance = 0.0;
  int total_share = 0;
  int transaction = 1;
int price_share = -1;

   
  cout << "This program calculates your profit/loss for all your" << endl
       << "investments in one share." << endl
       << "Use a positive number for purchase, and a negative for sell"<< endl
       << "Enter zero (0) shares to exit the program." << endl << endl;

  cout << "Enter data for transaction " << transaction << endl;
  
  do
    {
      int price;
  
      price_share = user_input_reader("Number of shares : ", -total_share , "You do not have that many shares, try again.");
      
      if (price_share == 0)
	{
	  cout << "Bye. Have a nice day" << endl;
	  exit (0);
	}
      
      cin.ignore(1000, '\n');
      
      price = user_input_reader("Price per share : ", 0 , "The Price may not be nagative, try again");
      cin.ignore(1000, '\n');


      total_share = total_share + price_share;
      balance = balance + ( price_share * price);
  
      cout << "You " << (price_share < 0 ? "gained $ ":"spent $" ) << fixed << setprecision(2) << fabs (price_share*price) << " on this transaction." << endl;
      cout << "Your Total " << (balance >= 0 ? "spendings ":"profit ");
      cout << "amount to  $" << fixed << setprecision(2) << fabs(balance) << " and you own " << total_share << " Shares." << endl;
      cout << endl;
      cout << "Enter data for transaction " << ++transaction << endl;
      
    }while(price_share !=0);
}

