#pragma once
#include <string>
class Cart;

using namespace std;

class Menu
{
private:
	int store_id;
	int menu_count;
	int menu_price;
	int option_count;

	string menu_name;
	string menu_explanation;
	
public:
	Menu();
	Menu(int, string, string, int, int, string[], int[]);
	
	int get_store_id();
	int get_menu_price();
	int get_menu_count();
	string get_menu_name();
	string get_menu_explanation();
	void set_menu_count(int menu_count);
	/*void set_store_id(int store_id);
	void set_menu_price(int menu_price);
	
	void set_menu_name(string menu_name);
	void set_option_check(bool option_list[]);
	void set_option_list(string option_list[]); 
	void set_option_price(int option_price[]);*/

	void add_cart(Cart*);
	void init_option_info(std::string[], int[]);
	void init_option_check();
	void print_menu();
	void print_menu_option();
	
	std::string option_list[5];
	bool option_check[5];
	int option_price[5];
};



