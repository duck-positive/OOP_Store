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
	this->sum_price();
	cout << "장바구니 목록 출력" << endl;
	cout << "총액 : " << this->total_price << endl;
	
	for (int i = 0; i < 10; i++) {
		cout << this->cart_menu_list[i].menu_name << endl;
	}
}
void Cart::sum_price() {
	int total_price = 0;
	for (int i = 0; i < 10; i++) {
		if (this->cart_menu_list[i].menu_price != 0) {
			total_price += this->cart_menu_list[i].menu_price;
			for (int j = 0; j < 10; j++) {
				if (this->cart_menu_list[i].option_check[j] == true) {
					total_price += this->cart_menu_list[i].option_price[j];
				}
			}
		}
		else break;
	}
	this->total_price = total_price;
}