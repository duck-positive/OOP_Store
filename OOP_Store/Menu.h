#pragma once
#include <string>
class Cart;

using namespace std;

class Menu
{
private:
	std::string menu_explanation;
	int menu_count;
	int option_count;
	std::string option_list[10];
	bool option_check[10];
	int option_price[10];

public:
	
	
	Menu();
	Menu(int, std::string, std::string, int, int, std::string[], bool[], int[]);
	void add_cart(Cart*);
	void add_option(std::string[], int[]);
	void print_info();
	int store_id;
	std::string menu_name;
	int menu_price;
};



