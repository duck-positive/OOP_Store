#pragma once
#include "Menu.h"
using namespace std;

class Cart {
public : 
	Cart();
	int sum_price(Menu[]);
	void show_cart();
	void delete_select_menu();
	void delete_all();

	Menu cart_menu_list[10];
};