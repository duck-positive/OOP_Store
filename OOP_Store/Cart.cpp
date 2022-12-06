#pragma once
#include "Cart.h"
#include <iostream>
using namespace std;

Cart::Cart() {
	for (int cart_menu_index = 0; cart_menu_index < 10; cart_menu_index++) {
		this->cart_menu_list[cart_menu_index] = Menu();
	}
	this->cart_user_id = "";
	this->total_price = 0;
}

Cart::Cart(string user_id) : Cart() {
	this->cart_user_id = user_id;
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

void Cart::show_cart(){
	this->sum_price();
	cout << "장바구니 목록 출력" << endl;
	for (int cart_menu_list_index = 0; cart_menu_list_index < 10; cart_menu_list_index++) {
		if (this->cart_menu_list[cart_menu_list_index].get_menu_name() == "")
			break;
		cout<< cart_menu_list_index+1 << ". " << this->cart_menu_list[cart_menu_list_index].get_menu_name() << endl;
	}
}

void Cart::delete_select_menu(int select_item_index) {
	if (this->cart_menu_list[select_item_index - 1].get_menu_price() == 0) {
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

void Cart::sum_price() {
	int total_price = 0;
	for (int cart_menu_list_index = 0; cart_menu_list_index < 10; cart_menu_list_index++) {
		if (this->cart_menu_list[cart_menu_list_index].get_menu_price() != 0) {
			Menu menu = this->cart_menu_list[cart_menu_list_index];
			total_price += menu.get_menu_price()*menu.get_menu_count();
			for (int option_index = 0; option_index < 5; option_index++) {
				if (this->cart_menu_list[cart_menu_list_index].option_check[option_index] == true) {
					total_price += this->cart_menu_list[cart_menu_list_index].option_price[option_index];
				}
			}
		}
		else break;
	}
	this->total_price = total_price;
}
