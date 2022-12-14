#include "Menu.h"
#include "Cart.h"
#include "User.h"
#include "store.h"
#include "Payment.h"
#include <iostream>
using namespace std;

void print_store_list(Store* store_list[], int list_size, Cart* cart) {
	while (true) {
		system("cls");
		cout << "가게 목록" << endl;
		for (int store_list_index = 0; store_list_index < list_size; store_list_index++) {
			if (store_list[store_list_index]->store_name != "") {
				cout << store_list_index + 1 << ". " << store_list[store_list_index]->store_name << endl;
			}
			else break;
		}
		int input = 0;
		int select = 0;
		int option_select = 0;
		int menu_count = 0;
		cout << "=================================" << endl;
		cout << "0. 장바구니 보기" << endl;
		cout << "=================================" << endl;
		cout << "선택할 행동의 번호를 입력해주세요 : ";
		cin >> input;
		//장바구니로 가기
		if (input == 0) {
			system("cls");
			break;
		}
		
		//메뉴 계속 선택하기 선택 시 반복
		while (true) {
			store_list[input - 1]->print_store_info();
			cout << "선택할 행동의 번호를 입력해주세요 : ";
			cin >> select;
			//상점 목록으로 돌아가기
			if (select == 0) {
				break;
			}
			else {
				if (input != 0) {
					store_list[input-1]->menu_list[select-1].print_menu_option();
					cin >> option_select;
				}
			}
			if (option_select == 8) {
				break;
			}
			else {
				store_list[input-1]->menu_list[select - 1].option_check[option_select - 1] = true;
			}
			while (true) {
				cout << "메뉴 수량 선택 : ";
				cin >> menu_count;
				cout << endl;
				if (menu_count == 0) {
					cout << "수량은 최소 1개 이상이어야 합니다" << endl;
				}
				else {
					store_list[input - 1]->menu_list[select - 1].set_menu_count(menu_count);
					store_list[input - 1]->menu_list[select - 1].add_cart(cart);
					store_list[input - 1]->menu_list[select - 1].option_check[option_select - 1] = false;
					break;
				}
			}

			cout << "메뉴를 계속 선택하시겠습니까?(상점 선택 화면: 0, 메뉴 선택 화면: 1)" << endl;
			cin >> select;
			if (select == 0) break;
		}
	}
}


int main() {
	User* user = new User("user_id", "user_name", "1234", "01012345678", "서울시");
	Payment* payment = new Payment(user, 10, 1234, 2345, 3456, 4567);
	
	Cart* cart = new Cart(user);
	std::string kyochon_option[5] = { "치즈볼 3개 추가", "떡볶이 추가", "샐러드 추가", "", "" };
	int kyochon_option_price[5] = { 3500, 9000, 5500, 0, 0 };
	std::string bhc_option[5] = { "케이준 프라이", "뿌링 치즈볼", "뿌링소떡", "", ""  };
	int bhc_option_price[5] = { 3500, 9000, 5500, 0, 0 };
	std::string jaws_option[5] = { "튀김 추가", "사이다 추가", "콜라 추가", "", "" };
	int jaws_option_price[5] = { 3500, 1500, 1500, 0, 0 };

	Menu kyochon_menu_list[5] = {
		Menu(1, "허니콤보", "달콤한 맛에 날개와 다리를 즐길 수 있는 메뉴", 20000, 3, kyochon_option, kyochon_option_price), 
		Menu(1, "레드콤보", "매콤한 맛에 날개와 다리를 즐길 수 있는 메뉴", 20000, 3, kyochon_option, kyochon_option_price),
		Menu(1, "허니오리지날", "달콤한 맛의 한마리 치킨", 16000, 3, kyochon_option, kyochon_option_price),
		Menu(1, "레드오리지날", "매콤한 맛의 한마리 치킨", 17000, 3, kyochon_option, kyochon_option_price) };

	Menu bhc_menu_list[5] = {
		Menu(2, "뿌링클", "세상에 없던 맛, 뿌링클", 18000, 3, bhc_option, bhc_option_price),
		Menu(2, "맛초킹", "매콤짭잘한 맛의 치킨", 18000, 3, bhc_option, bhc_option_price),
		Menu(2, "레드킹", "화끈매콤한 맛의 치킨", 19000, 3, bhc_option, bhc_option_price),
		Menu(2, "커리퀸", "커리 파우더와 갈릭 시즈닝을 더한 치킨", 18000, 3, bhc_option, bhc_option_price) };

	Menu jaws_menu_list[5] = {
		Menu(3, "죠스 떡볶이", "죠스 떡볶이", 3500, 3, jaws_option, jaws_option_price),
		Menu(3, "치즈 떡볶이", "치즈를 더한 떡볶이", 5000, 3, jaws_option, jaws_option_price),
		Menu(3, "죠스 찰순대", "죠스 순대", 4000, 3, jaws_option, jaws_option_price),
		Menu(3, "부산 어묵", "어묵", 3500, 3, jaws_option, jaws_option_price) };

	Menu sincham_menu_list[5] = {
		Menu(4, "떡볶이", "떡볶이", 4000, 3, jaws_option, jaws_option_price),
		Menu(4, "라볶이", "라볶이", 5500, 3, jaws_option, jaws_option_price),
		Menu(4, "찰순대", "찰순대", 3500, 3, jaws_option, jaws_option_price),
		Menu(4, "모듬 튀김", "모듬 튀김", 4000, 3, jaws_option, jaws_option_price) };

	Store* kyochon_chicken = new Store(1, "서울시", "교촌치킨 상도터널점", "0100000", kyochon_menu_list, "user_address", 16000, 4000);
	Store* bhc_chicken = new Store(2, "서울시", "BHC 상도점", "0100000", bhc_menu_list, "서울시", 16000, 3000);
	Store* jaws_tteokbokki = new Store(3, "서울시", "죠스떡볶이 중앙대점", "0100000", jaws_menu_list, "서울시", 10000, 3000);
	Store* sincham_tteokbokki = new Store(4, "서울시", "신참떡볶이 상도역점", "0100000", sincham_menu_list, "서울시", 13000, 2000);

	Store* store_list[4] = { kyochon_chicken, bhc_chicken, jaws_tteokbokki, sincham_tteokbokki };
	int result = 0;
	while (true) {
		print_store_list(store_list, 4, cart);
		result = payment->show_cart_before_payment(cart, store_list);
		if (result == 0) break;
	}

	return 0;
}