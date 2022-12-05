#pragma once
#include "Menu.h"
using namespace std;

class Cart {
public : 
	Cart();
	//user 와 연관관계 추가 ex.user_id
	void show_cart();
	//void delete_select_menu();
	//void delete_all();
	void sum_price();
	int total_price;
	Menu cart_menu_list[10];
};