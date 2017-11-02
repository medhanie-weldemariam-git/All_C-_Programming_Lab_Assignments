#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include "product.h"

using namespace std;
class database
{
 private:
  product* product_list[1000];
  int productIndex;

 public:
  database();
  ~database();
  void add_product(product* item);//Adds another product to the list
  virtual void print_all();//Print the list of products.
};
#endif
