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
				cout << "��ٱ��ϰ� ����ֽ��ϴ�" << endl;
				cout << "1. �� ����" << endl;
				cin >> select_action;
				if (select_action == 1) {
					return 1;
				}
				else {// ����ó�� �߰� �ʿ�
					cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
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
		cout << "�� �ֹ� �ݾ� : " << this->total_price << endl;



		int select_item = 0;
		cout << "1. �� ����" << endl;
		cout << "2. ��ٱ��Ͽ� ���� �޴� ����" << endl;
		cout << "3. �����ϱ�" << endl;
		cin >> select_action;
		if (select_action == 1) {
			return 1;
		}
		else if (select_action == 2) {
			cart->show_cart();
			cout << "������ �޴��� ��ȣ�� �Է����ּ���(��� 0) : ";
			cin >> select_item;
			cart->delete_select_menu(select_item);
		}
		else break;
	}
A:

	if (this->min_price > this->total_price)
	{
		std::cout << "�ֹ� �ּ� �ݾ��� ���� ���� ����� �Ұ��մϴ�." << endl;
		return 1;
	}
	std::cout << "\t\t\t\t ****************���� ����� ������ �ּ���.****************" << endl;
	std::cout << "\t\t\t\t ��ȸ�� �Ÿ��α� ��ȭ�� ���� ��� ������ �������� �ʽ��ϴ�." << endl;
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
		std::cout << "\t\t\t\t   Credit Cart ������ �����ϼ̽��ϴ�. " << endl;
		std::cout << "\t\t\t\t*****************************************" << endl;
		std::cout << "\t\t\t\t ī�� ��ȣ�� �Է��ϼ���:";
		std::cin >> input_card_number;
		if (this->card_number != input_card_number)
		{
			std::cout << "��ȣ�� ��ġ���� �ʽ��ϴ�.";
			goto B;
		}
		std::cout << "\t\t\t\t ī�� ��й�ȣ�� �Է��ϼ��� :";
		std::cin >> input_card_password;
		if (this->card_password != input_card_password)
		{
			std::cout << "��ȣ�� ��ġ���� �ʽ��ϴ�.";
			goto B;
		}

		std::cout << "\t\t\t\t************************************************" << endl;
		std::cout << "\t\t\t\t ������ �Ϸ�Ǿ����ϴ�. ���Կ��� Ȯ�� ���Դϴ�.  " << endl;
		std::cout << "\t\t\t\t************************************************" << endl;
		break;
	

	case 2:
	C:
		std::cout << "\t\t\t\t*****************************************" << endl;
		std::cout << "\t\t\t\t   On-Line Payment ������ �����ϼ̽��ϴ�. " << endl;
		std::cout << "\t\t\t\t*****************************************" << endl;
		std::cout << "\t\t\t\t Pay ȸ�縦 ������ �ּ���.:";
		std::cout << "\t\t\t\t press 1 īī�� ����";
		std::cout << "\t\t\t\t press 2 ���̹� ����";
		std::cout << "\t\t\t\t press 3 ��� ����";
		std::cin >> input_pay_number;
		if (this->pay_number != input_pay_number)
		{
			std::cout << "��ȣ�� ��ġ���� �ʽ��ϴ�.";
			goto C;
		}

		std::cout << "\t\t\t\t Pay ��й�ȣ�� �Է��ϼ��� :";
		std::cin >> input_pay_password;
		if (this->pay_password != input_pay_password)
		{
			std::cout << "��ȣ�� ��ġ���� �ʽ��ϴ�.";
			goto C;
		}
		
		std::cout << "\t\t\t\t************************************************" << endl;
		std::cout << "\t\t\t\t ������ �Ϸ�Ǿ����ϴ�. ���Կ��� Ȯ�� ���Դϴ�.  " << endl;
		std::cout << "\t\t\t\t************************************************" << endl;
		break;

	default:
		goto A;
		std::cout << "��ȿ���� ���� �Է°��Դϴ�." << endl;

	}
	return 0;


}

Payment::~Payment() {}