#pragma once
#include "Menu.h"
#include "Cart.h"
#include <iostream>
#include <algorithm>
using namespace std;

Menu::Menu() {
	this->store_id = 0;
}

Menu::Menu(int stroe_id, std::string menu_name, std::string menu_explanation, int menu_price, int option_count, std::string option_list[], bool option_check[], int option_price[]){
	//menu initialization
	this->store_id = store_id;
	this->menu_name = menu_name;
	this->menu_explanation = menu_explanation;
	this->menu_price = menu_price;
	this->menu_count = 0;


	//need copy process
	this->option_count = option_count;
	add_option(option_list, option_price);
}

void Menu::add_option(string option_list[], int option_price[]) {
	if (this->option_count > 0) {
		for (int option_index = 0; option_index < this->option_count; option_index++) {
			this->option_list[option_index] = option_list[option_index];
			this->option_price[option_index] = option_price[option_index];
		}
	}
}

void Menu::print_info() {
	cout << this->menu_name << endl;
	for (int i = 0; i < this->option_count; i++) {
		cout << "option name : " << this->option_list[i] << "  || option price : " << this->option_price[i] << endl;
	}
}

void Menu::add_cart(Cart* cart) {
	for (int cart_list_index = 0; cart_list_index < 10; cart_list_index++) {
		if (cart->cart_menu_list[cart_list_index].store_id == 0) {
			cart->cart_menu_list[cart_list_index] = *this;
		}
	}
	
}


