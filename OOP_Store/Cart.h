#pragma once
#include "Menu.h"
#include "User.h"
using namespace std;

class Cart {
public : 
	//constructor
	Cart();
	Cart(User*);
	
	//getter
	int get_menu_store_id();
	
	//function
	void show_cart();
	void delete_select_menu(int);
	void delete_all();
	void sum_price();

	User* user_own_cart;
	int total_price;
	Menu cart_menu_list[10];
};