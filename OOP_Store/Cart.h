#pragma once
#include "Menu.h"
using namespace std;

class Cart {
public : 
	//constructor
	Cart();
	Cart(string);
	
	//getter
	int get_menu_store_id();
	
	//function
	void show_cart();
	void delete_select_menu(int);
	void delete_all();
	void sum_price();

	string cart_user_id;
	int total_price;
	Menu cart_menu_list[10];
};