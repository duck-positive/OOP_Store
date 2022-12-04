#pragma once
#include "Menu.h"
#include<iostream>
#include <string>
using namespace std;

class store {
protected:
	int store_id;
	string store_address;
	string store_name;
	string store_phno;
	string menu_name;
	int menu_price;
	string user_address;
	int min_price;
	int tip;

public:
	
	store();
	store(int store_id, string store_address, string store_name, string store_phno,
		string menu_name, int menu_price, string user_address, int min_price, int tip);
	void add_menu(const Menu& M);
	void delete_menu(const Menu& M);
	bool confirm_order(string, string, string, string);
	bool confirm_deliver();
	~store();
	Menu* menu_list;
};