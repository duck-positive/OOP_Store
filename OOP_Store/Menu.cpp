#pragma once
#include "Menu.h"
#include "Cart.h"
#include <iostream>
#include <algorithm>
using namespace std;

Menu::Menu() {
	this->store_id = 0;
	this->menu_name = "";
	this->menu_explanation = "";
	this->menu_price = 0;
	this->menu_count = 0;
}

Menu::Menu(int store_id, std::string menu_name, std::string menu_explanation, int menu_price, int option_count, std::string option_list[], int option_price[]){
	//menu initialization
	this->store_id = store_id;
	this->menu_name = menu_name;
	this->menu_explanation = menu_explanation;
	this->menu_price = menu_price;
	this->menu_count = 0;
	this->option_count = option_count;
	init_option_info(option_list, option_price);
	init_option_check();
}

int Menu::get_store_id() {
	return this->store_id;
}

int Menu::get_menu_price() {
	return this->menu_price;
}

int Menu::get_menu_count() {
	return this->menu_count;
}

string Menu::get_menu_name() {
	return this->menu_name;
}

string Menu::get_menu_explanation() {
	return this->menu_explanation;
}

//void Menu::set_store_id(int store_id) {
//	this->store_id = store_id;
//}
//
//void Menu::set_menu_price(int menu_price) {
//	this->menu_price = menu_price;
//}

void Menu::set_menu_count(int menu_count) {
	this->menu_count = menu_count;
}

//void Menu::set_menu_name(string menu_name) {
//	this->menu_name = menu_name;
//}
//
//void Menu::set_option_check(bool option_check[]) {
//	for (int option_list_index = 0; option_list_index < 5; option_list_index++) {
//		this->option_check[option_list_index] = option_check[option_list_index];
//	}
//}
//
//void Menu::set_option_list(string option_list[]) {
//	for (int option_list_index = 0; option_list_index < 5; option_list_index++) {
//		this->option_list[option_list_index] = option_list[option_list_index];
//	}
//}
//
//void Menu::set_option_price(int option_price[]) {
//	for (int option_list_index = 0; option_list_index < 5; option_list_index++) {
//		this->option_price[option_list_index] = option_price[option_list_index];
//	}
//}
//


void Menu::add_cart(Cart* cart) {
	int select_action = 0;
	for (int menu_list_in_cart_index = 0; menu_list_in_cart_index < 10; menu_list_in_cart_index++) {
		if (cart->cart_menu_list[menu_list_in_cart_index].store_id == 0) {
			cart->cart_menu_list[menu_list_in_cart_index] = *this;
			/*cart->cart_menu_list[menu_list_in_cart_index].set_menu_count(this->get_menu_count());
			cart->cart_menu_list[menu_list_in_cart_index].set_store_id(this->get_store_id());
			cart->cart_menu_list[menu_list_in_cart_index].set_menu_price(this->get_menu_price());
			cart->cart_menu_list[menu_list_in_cart_index].set_menu_name(this->get_menu_name());
			cart->cart_menu_list[menu_list_in_cart_index].set_option_check(this->option_check);
			cart->cart_menu_list[menu_list_in_cart_index].set_option_list(this->option_list);
			cart->cart_menu_list[menu_list_in_cart_index].set_option_price(this->option_price);*/
			break;
		}
		else if (cart->cart_menu_list[menu_list_in_cart_index].store_id != this->store_id) {
			while (true) {
				cout << "???? ?????? ???? ?????? ?????? ???????? ?????? ?????? ???????????????" << endl;
				cout << "1. ??" << endl;
				cout << "2. ??????" << endl;
				cin >> select_action;
				if (select_action == 1) {
					cart->delete_all();
					cart->cart_menu_list[menu_list_in_cart_index] = *this;
					break;
				}
				else if (select_action == 2) {
					break;
				}
				else {
					cout << "?????? ??????????????." << endl;
				}
				break;
			}
			if (select_action == 1 || select_action == 2) {
				break;
			}
		}
	}

}

void Menu::init_option_info(string option_list[], int option_price[]) {
	if (this->option_count > 0) {
		for (int option_index = 0; option_index < this->option_count; option_index++) {
			this->option_list[option_index] = option_list[option_index];
			this->option_price[option_index] = option_price[option_index];
		}
	}
}
void Menu::init_option_check() {
	for (int option_list_index = 0; option_list_index < 5; option_list_index++) {
		this->option_check[option_list_index] = false;
	}
}

void Menu::print_menu() {
	cout << this->menu_name << "  ||  ???? : " << this->menu_price << endl;
	cout << "\t???? : " << this->menu_explanation << endl;
}

void Menu::print_menu_option() {
	system("cls");
	cout << endl << "?????? ???? : " << this->menu_name << endl << endl;
	cout << "=================================" << endl;
	cout << "0. ???? ???????? ???? ????" << endl;
	for (int option_list_index = 0; option_list_index < this->option_count; option_list_index++) {
		cout<< option_list_index +1 << ". ???? ???? : " << this->option_list[option_list_index] << "  || ???? ???? : " << this->option_price[option_list_index] << endl;
	}
	cout << "=================================" << endl;
	cout << "?????? ???? ?????? ????????????(???? : 8) : ";
}



