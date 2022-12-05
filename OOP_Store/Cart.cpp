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
	cout << "장바구니 목록 출력" << endl;
	for (int i = 0; i < 10; i++) {
		cout << this->cart_menu_list[i].menu_name << endl;
	}
}
void Cart::sum_price() {
	int total_price = 0;
	for (int i = 0; i < 10; i++) {
		total_price += this->cart_menu_list[i].menu_price;
	}
	this->total_price = total_price;
}