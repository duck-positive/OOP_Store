#pragma once
#include "Menu.h"
using namespace std;

class Cart {
public : 
	Cart();
	//user �� �������� �߰� ex.user_id
	void show_cart();
	void delete_select_menu(int);
	int get_menu_store_id();
	void delete_all();
	void sum_price();
	int total_price;
	Menu cart_menu_list[10];
};