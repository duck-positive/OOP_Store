#pragma once
#include "Menu.h"
using namespace std;

class Cart {
public : 
	Cart();
	
	void show_cart();
	//void delete_select_menu();
	//void delete_all();
	void sum_price();
	int total_price;
	Menu cart_menu_list[10];
};