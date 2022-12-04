#pragma once
#include "Cart.h"
#include <iostream>
using namespace std;

Cart::Cart() {
	for (int i = 0; i < 10; i++) {
		this->cart_menu_list[i] = Menu();
	}
}
void Cart::show_cart(){
	for (int i = 0; i < 10; i++) {
		if (this->cart_menu_list[i].store_id != 0) {
			cout << this->cart_menu_list[i].menu_name << endl;
		}
	}
}
void sum_price() {
	int total_price = 0;
	
}