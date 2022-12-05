#include "Payment.h"
#include <iostream>
#include <string>

using namespace std;

Payment::Payment() {
	this->user = new User();
	this->payment_num = 0;
	this->total_price = 0;
	this->min_price = 0;
	this->card_number = 0;
	this->card_password = 0;
	this->pay_number = 0;
	this->pay_password = 0;
}

Payment::Payment(User* user, int payment_num, int card_number, int card_password, int pay_number, int pay_password)
{
	this->user = user;
	this->payment_num = payment_num;
	this->total_price = 0;
	this->min_price = 0;
	this->card_number = card_number;
	this->card_password = card_password;
	this->pay_number = pay_number;
	this->pay_password = pay_password;
}

int Payment::payment(Cart* cart, Store* store_list[]) {
	int input_card_number;
	int input_card_password;
	int input_pay_number;
	int input_pay_password;
	int select_action = 0;
	while (true) {
		cart->sum_price();
		int cart_total_price = cart->total_price;

		if (cart_total_price == 0) {
			while (true) {
				system("cls");
				cout << "장바구니가 비어있습니다" << endl;
				cout << "1. 더 고르기" << endl;
				cin >> select_action;
				if (select_action == 1) {
					return 1;
				}
				else {// 예외처리 추가 필요
					cout << "입력이 잘못되었습니다." << endl;
				}
			}
		}
		else {
			int store_id_in_cart = cart->get_menu_store_id();
			for (int search_matching_store_index = 0; search_matching_store_index < 10; search_matching_store_index++) {
				if (store_list[search_matching_store_index]->store_id == store_id_in_cart) {
					store_list[search_matching_store_index]->min_price = this->min_price;
					this->total_price = store_list[search_matching_store_index]->tip;
					break;
				}
			}
		}
		this->total_price += cart->total_price;

		cart->show_cart();
		cout << "총 주문 금액 : " << this->total_price << endl;



		int select_item = 0;
		cout << "1. 더 고르기" << endl;
		cout << "2. 장바구니에 담은 메뉴 삭제" << endl;
		cout << "3. 결제하기" << endl;
		cin >> select_action;
		if (select_action == 1) {
			return 1;
		}
		else if (select_action == 2) {
			cart->show_cart();
			cout << "삭제할 메뉴의 번호를 입력해주세요(취소 0) : ";
			cin >> select_item;
			cart->delete_select_menu(select_item);
		}
		else break;
	}
A:

	if (this->min_price > this->total_price)
	{
		std::cout << "주문 최소 금액을 넘지 못해 배달이 불가합니다." << endl;
		return 1;
	}
	std::cout << "\t\t\t\t ****************결제 방법을 선택해 주세요.****************" << endl;
	std::cout << "\t\t\t\t 사회적 거리두기 강화를 위해 대면 결제는 제공되지 않습니다." << endl;
	std::cout << "\t\t\t\t**********************************************************" << endl;
	std::cout << "\t\t\t\t             Press 1 For Credit Card:    " << endl;
	std::cout << "\t\t\t\t             Press 2 For On-Line Payment:" << endl;
	std::cin >> select_action;
	system("cls");
	switch (select_action)
	{
	case 1:
	B:
		std::cout << "\t\t\t\t*****************************************" << endl;
		std::cout << "\t\t\t\t   Credit Cart 결제를 선택하셨습니다. " << endl;
		std::cout << "\t\t\t\t*****************************************" << endl;
		std::cout << "\t\t\t\t 카드 번호를 입력하세요:";
		std::cin >> input_card_number;
		if (this->card_number != input_card_number)
		{
			std::cout << "번호가 일치하지 않습니다.";
			goto B;
		}
		std::cout << "\t\t\t\t 카드 비밀번호를 입력하세요 :";
		std::cin >> input_card_password;
		if (this->card_password != input_card_password)
		{
			std::cout << "번호가 일치하지 않습니다.";
			goto B;
		}

		std::cout << "\t\t\t\t************************************************" << endl;
		std::cout << "\t\t\t\t 결제가 완료되었습니다. 가게에서 확인 중입니다.  " << endl;
		std::cout << "\t\t\t\t************************************************" << endl;
		break;
	

	case 2:
	C:
		std::cout << "\t\t\t\t*****************************************" << endl;
		std::cout << "\t\t\t\t   On-Line Payment 결제를 선택하셨습니다. " << endl;
		std::cout << "\t\t\t\t*****************************************" << endl;
		std::cout << "\t\t\t\t Pay 회사를 선택해 주세요.:";
		std::cout << "\t\t\t\t press 1 카카오 페이";
		std::cout << "\t\t\t\t press 2 네이버 페이";
		std::cout << "\t\t\t\t press 3 배민 페이";
		std::cin >> input_pay_number;
		if (this->pay_number != input_pay_number)
		{
			std::cout << "번호가 일치하지 않습니다.";
			goto C;
		}

		std::cout << "\t\t\t\t Pay 비밀번호를 입력하세요 :";
		std::cin >> input_pay_password;
		if (this->pay_password != input_pay_password)
		{
			std::cout << "번호가 일치하지 않습니다.";
			goto C;
		}
		
		std::cout << "\t\t\t\t************************************************" << endl;
		std::cout << "\t\t\t\t 결제가 완료되었습니다. 가게에서 확인 중입니다.  " << endl;
		std::cout << "\t\t\t\t************************************************" << endl;
		break;

	default:
		goto A;
		std::cout << "유효하지 않은 입력값입니다." << endl;

	}
	return 0;


}

Payment::~Payment() {}