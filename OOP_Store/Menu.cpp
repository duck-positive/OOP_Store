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

Menu::Menu(int store_id, std::string menu_name, std::string menu_explanation, int menu_price, int option_count, std::string option_list[], bool option_check[], int option_price[]){
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

void Menu::init_option_info(string option_list[], int option_price[]) {
	if (this->option_count > 0) {
		for (int option_index = 0; option_index < this->option_count; option_index++) {
			this->option_list[option_index] = option_list[option_index];
			this->option_price[option_index] = option_price[option_index];
		}
	}
}
void Menu::init_option_check() {
	for (int option_list_index = 0; option_list_index < 10; option_list_index++) {
		this->option_check[option_list_index] = false;
	}
}

void Menu::print_menu() {
	cout << this->menu_name << "  ||  ���� : " << this->menu_price << endl;
	cout << "\t���� : " << this->menu_explanation << endl;
}

void Menu::print_menu_option() {
	system("cls");
	cout << endl << "������ �޴� : " << this->menu_name << endl << endl;
	for (int i = 0; i < this->option_count; i++) {
		cout<< i+1 << ". �߰� �ɼ� : " << this->option_list[i] << "  || �߰� ���� : " << this->option_price[i] << endl;
	}

	cout << "�߰��� �ɼ� ��ȣ�� �Է����ּ���(īƮ ��� 0, ��� 8) : ";
}

int Menu::get_store_id() {
	return this->store_id;
}

void Menu::add_cart(Cart* cart) {
	
	for (int menu_list_in_cart_index = 0; menu_list_in_cart_index < 10; menu_list_in_cart_index++) {
		if (cart->cart_menu_list[menu_list_in_cart_index].store_id == 0) {
			cart->cart_menu_list[menu_list_in_cart_index] = *this;
			break;
		}
		else if (cart->cart_menu_list[menu_list_in_cart_index].store_id != this->store_id) {
			cart->delete_all();
			cart->cart_menu_list[menu_list_in_cart_index] = *this;
			break;
		}
	}
	
}


