#pragma once
#include "Cart.h"
#include <iostream>
using namespace std;

Cart::Cart() {
	for (int cart_menu_index = 0; cart_menu_index < 10; cart_menu_index++) {
		this->cart_menu_list[cart_menu_index] = Menu();
	}
	this->total_price = 0;
}

void Cart::show_cart(){
	this->sum_price();
	cout << "장바구니 목록 출력" << endl;
	
	for (int cart_menu_list_index = 0; cart_menu_list_index < 10; cart_menu_list_index++) {
		if (this->cart_menu_list[cart_menu_list_index].menu_name == "")
			break;
		cout << this->cart_menu_list[cart_menu_list_index].menu_name << endl;
	}
}

int Cart::get_menu_store_id() {
	if (this->cart_menu_list[0].get_store_id() == 0) {
		cout << "장바구니가 비어있습니다" << endl;
		return 0;
	}
	else {
		return this->cart_menu_list[0].get_store_id();
	}
}

void Cart::sum_price() {
	int total_price = 0;
	for (int cart_menu_list_index = 0; cart_menu_list_index < 10; cart_menu_list_index++) {
		if (this->cart_menu_list[cart_menu_list_index].menu_price != 0) {
			total_price += this->cart_menu_list[cart_menu_list_index].menu_price;
			for (int j = 0; j < 10; j++) {
				if (this->cart_menu_list[cart_menu_list_index].option_check[j] == true) {
					total_price += this->cart_menu_list[cart_menu_list_index].option_price[j];
				}
			}
		}
		else break;
	}
	this->total_price = total_price;
}
void Cart::delete_select_menu(int select_item_index) {
	if (this->cart_menu_list[select_item_index-1].menu_price == 0) {
		cout << "잘못된 번호입니다" << endl;
	}
	else {
		this->cart_menu_list[select_item_index - 1].init_option_check();
		this->cart_menu_list[select_item_index - 1] = Menu();
	}
	this->sum_price();
}

void Cart::delete_all() {
	for (int menu_list_index = 0; menu_list_index < 10; menu_list_index++) {
		this->cart_menu_list[menu_list_index].init_option_check();
		this->cart_menu_list[menu_list_index] = Menu();
	}
	this->total_price = 0;
}