#include "Menu.h"
#include "Cart.h"
#include "User.h"
#include "store.h"
#include <iostream>
using namespace std;

void initialization() {

}


int main() {
	std::string option[10] = { "add side", "dd", "dd", "dd", "dd", "dd", "dd", "dd", "dd", "dd" };
	bool option_cnt[10] = { false, };
	int option_price[10] = { 10, };
	Menu kyochon_menu_list[5] = {
		Menu(1, "chicken", "light", 3, 3, option, option_cnt, option_price), 
		Menu(1, "honey", "light", 3, 3, option, option_cnt, option_price), 
		Menu(1, "red", "light", 3, 3, option, option_cnt, option_price), 
		Menu(1, "black", "light", 3, 3, option, option_cnt, option_price),
		Menu(1, "dsa", "light", 3, 3, option, option_cnt, option_price) };
	Store* store = new Store(1, "서울시", "교촌치킨", "0100000", kyochon_menu_list, "서울시", 1000, 3000);
	store->print_menu();
	Menu* fried = new Menu(1, "chicken", "light", 3, 3, option, option_cnt, option_price);
	fried->print_info();
	Cart* cart = new Cart();
	//cout << cart->cart_menu_list << endl;
	User* user = new User("user_id", "user_name","1234", "01012345678", "서울시");

	return 0;
}