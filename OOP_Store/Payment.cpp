#include "Payment.h"
#include <iostream>
#include <string>

using namespace std;

Payment::Payment() {
	this->user = User();
	this->payment_num = 0;
	this->total_price = 0;
	this->min_price = 0;
	this->card_number = 0;
	this->card_password = 0;
	this->pay_number = 0;
	this->pay_password = 0;
}

Payment::Payment(User user, int payment_num,
	int total_price, int min_price, int card_number, int card_passwoed
	, int pay_number, int pay_password)
{
	this->user = user;
	this->payment_num = payment_num;
	this->total_price = total_price;
	this->min_price = min_price;
	this->card_number = card_number;
	this->card_password = card_password;
	this->pay_number = pay_number;
	this->pay_password = pay_password;
}



int Payment::get_cart_price(int get_total_price,int min_price)
{
	this->total_price = get_total_price;
	this->min_price = min_price;

	return get_total_price;
}

string Payment::payment() {
	int input_card_number;
	int input_card_password;
	int input_pay_number;
	int input_pay_password;
	int option = 0;
	
A:

	if (this->min_price > this->total_price)
	{
		std::cout << "주문 최소 금액을 넘지 못해 배달이 불가합니다." << endl;
		return "0";
	}
	std::cout << "\t\t\t\t ****************결제 방법을 선택해 주세요.****************" << endl;
	std::cout << "\t\t\t\t 사회적 거리두기 강화를 위해 대면 결제는 제공되지 않습니다." << endl;
	std::cout << "\t\t\t\t**********************************************************" << endl;
	std::cout << "\t\t\t\t             Press 1 For Credit Card:    " << endl;
	std::cout << "\t\t\t\t             Press 2 For On-Line Payment:" << endl;
	std::cin >> option;
	system("cls");
	switch (option)
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
	return this->user.address;


}

Payment::~Payment() {}