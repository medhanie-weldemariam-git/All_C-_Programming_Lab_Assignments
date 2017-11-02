#include "database.h"
//#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;


database::database()
{
  this->productIndex = 0;
  cout<<endl;

}
database::~database()
{
  for(int i = 0; i < productIndex; i ++)
  {
    delete product_list[i];
  }
}

void database::add_product(product* item)
{
  product_list[productIndex] = item;
  productIndex++;
}

void database::print_all()
{
  for(int i=0; i< productIndex; i++)
    {
      cout << endl;
      cout<< "Item " << i << " is a " << typeid(*product_list[i]).name() << std::endl;
      product_list[i]->print();
    }


}
