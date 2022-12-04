#include "Menu.h"

int main() {
	std::string option[10] = { "add side", "dd", "dd", "dd", "dd", "dd", "dd", "dd", "dd", "dd"};
	bool option_cnt[10] = { false, };
	int option_price[10] = { 10, };
	Menu* test = new Menu(1, "chicken", "light", 3, 3, option, option_cnt, option_price);
	test->print_info();
	Cart* cart = new Cart();
	cout << cart->cart_menu_list << endl;

	return 0;
}