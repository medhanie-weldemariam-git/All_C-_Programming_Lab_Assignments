#include <iostream>
#include "menu.h"


using namespace std;

/* Illustrates how to build a menu froum our menu-options classes.
 */

int main()
{
  database* mydatabase = new database();
  /* A good principle is that the one allocating memory have the
   * responsibility to free that memory.
   *
   * In this code memory is allocated (with new), but it is not
   * apparent where it is released (with delete).
   *
   * You have to make sure it is really released.
   */

  /* The following becomes the main menu */
  sub_menu* main_menu = new sub_menu("Warehouse Store Menu");
  /* This is a sub-menu with options to add products */
  sub_menu* product_menu = new sub_menu("Add product menu");

  /* The main menu have two options (one is a sub-menu) */
  main_menu->add_option(new print_database("Print database", mydatabase));
  main_menu->add_option(product_menu);
  
  /* And three options are added to the sub-menu */
  product_menu->add_option(new add_book("Add book", mydatabase));
  product_menu->add_option(new add_movie("Add movie", mydatabase));
  product_menu->add_option(new add_grocery("Add grocery", mydatabase));

  main_menu->on_select();

  delete main_menu;
  delete mydatabase;
  
   cout << endl;
   return 0;
}
