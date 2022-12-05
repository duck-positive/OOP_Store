#pragma once
#include <string>
class Cart;

using namespace std;

class Menu
{
private:
	int store_id;
	int menu_count;
	int option_count;

public:
	Menu();
	Menu(int, std::string, std::string, int, int, std::string[], bool[], int[]);
	void add_cart(Cart*);
	void init_option_info(std::string[], int[]);
	void init_option_check();
	void print_menu();
	void print_menu_option();
	int get_store_id();
	
	std::string menu_name;
	std::string menu_explanation;
	int menu_price;
	std::string option_list[10];
	bool option_check[10];
	int option_price[10];
};



