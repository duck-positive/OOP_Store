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
	std::string menu_name;
	std::string menu_explanation;
	int menu_price;
public:
	Menu();
	Menu(int, std::string, std::string, int, int, std::string[], int[]);
	void add_cart(Cart*);
	void init_option_info(std::string[], int[]);
	void init_option_check();
	void print_menu();
	void print_menu_option();
	int get_store_id();
	string get_menu_name();
	string get_menu_explanation();
	int get_menu_price();
	int get_menu_count();
	void set_menu_count(int);
	
	std::string option_list[5];
	bool option_check[5];
	int option_price[5];
};



