#include "Menu.h"
#include "Cart.h"
#include "User.h"
#include "store.h"
#include "Payment.h"
#include <iostream>
using namespace std;

void print_store_list(Store* store_list[], int list_size, Cart* cart) {
	while (true) {
		cout << "가게 목록 출력" << endl;
		for (int i = 0; i < list_size; i++) {

			if (store_list[i]->store_name != "") {
				cout << i + 1 << ". " << store_list[i]->store_name << endl;
			}
			else break;
		}

		int input = 0;
		cin >> input;
		//장바구니로 가기
		if (input == 0) {
			break;
		}
		store_list[input]->print_menu();
		int select = 0;
		cin >> select;
		store_list[input]->menu_list[select].add_cart(cart);
		cout << "success" << endl;
	}
}


int main() {
	User* user = new User("user_id", "user_name", "1234", "01012345678", "서울시");
	Payment* payment = new Payment(user, 10, 0, 0, 1234, 2345, 12, 34);
	
	Cart* cart = new Cart();
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
	Store* store2 = new Store(1, "서울시", "교촌치킨2", "0100000", kyochon_menu_list, "서울시", 1000, 3000);
	Store* store3 = new Store(1, "서울시", "교촌치킨3", "0100000", kyochon_menu_list, "서울시", 1000, 3000);
	Store* store4 = new Store(1, "서울시", "교촌치킨4", "0100000", kyochon_menu_list, "서울시", 1000, 3000);
	Store* store5 = new Store(1, "서울시", "교촌치킨5", "0100000", kyochon_menu_list, "서울시", 1000, 3000);
	Store* store6 = new Store(1, "서울시", "교촌치킨6", "0100000", kyochon_menu_list, "서울시", 1000, 3000);
	Store* store7 = new Store(1, "서울시", "교촌치킨7", "0100000", kyochon_menu_list, "서울시", 1000, 3000);
	Store* store8 = new Store(1, "서울시", "교촌치킨8", "0100000", kyochon_menu_list, "서울시", 1000, 3000);
	Store* store9 = new Store(1, "서울시", "교촌치킨9", "0100000", kyochon_menu_list, "서울시", 1000, 3000);
	Store* store10 = new Store(1, "서울시", "교촌치킨10", "0100000", kyochon_menu_list, "서울시", 1000, 3000);

	Store* store_list[10] = { store, store2, store3, store4, store5, store6, store7, store8, store9, store10};
	print_store_list(store_list, 10, cart);
	payment->payment(cart);
	
	int input = 0;
	
	Menu* fried = new Menu(1, "chicken", "light", 3, 3, option, option_cnt, option_price);
	
	//cout << cart->cart_menu_list << endl;
	

	return 0;
}