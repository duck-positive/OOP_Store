#pragma once
#include "Menu.h"
#include<iostream>
#include <string>
using namespace std;

class Store {
protected:
	int store_id;
	string store_address;
	string store_phno;
	string user_address;
	int min_price;
	int tip;

public:
	
	Store();
	Store(int store_id, string store_address, string store_name, string store_phno, Menu menu_list[], string user_address, int min_price, int tip);
	void initialize_menu_list(Menu menu_list[]);
	void print_menu();
	bool confirm_order(string, string, string, string);
	bool confirm_deliver();
	~Store();
	Menu menu_list[10];
	string store_name;
	
};