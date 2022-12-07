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
		cout << "���� ���" << endl;
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
		cout << "0. ��ٱ��� ����" << endl;
		cout << "=================================" << endl;
		cout << "������ �ൿ�� ��ȣ�� �Է����ּ��� : ";
		cin >> input;
		//��ٱ��Ϸ� ����
		if (input == 0) {
			system("cls");
			break;
		}
		
		//�޴� ��� �����ϱ� ���� �� �ݺ�
		while (true) {
			store_list[input - 1]->print_store_info();
			cout << "������ �ൿ�� ��ȣ�� �Է����ּ��� : ";
			cin >> select;
			//���� ������� ���ư���
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
				cout << "�޴� ���� ���� : ";
				cin >> menu_count;
				cout << endl;
				if (menu_count == 0) {
					cout << "������ �ּ� 1�� �̻��̾�� �մϴ�" << endl;
				}
				else {
					store_list[input - 1]->menu_list[select - 1].set_menu_count(menu_count);
					store_list[input - 1]->menu_list[select - 1].add_cart(cart);
					store_list[input - 1]->menu_list[select - 1].option_check[option_select - 1] = false;
					break;
				}
			}

			cout << "�޴��� ��� �����Ͻðڽ��ϱ�?(���� ���� ȭ��: 0, �޴� ���� ȭ��: 1)" << endl;
			cin >> select;
			if (select == 0) break;
		}
	}
}


int main() {
	User* user = new User("user_id", "user_name", "1234", "01012345678", "�����");
	Payment* payment = new Payment(user, 10, 1234, 2345, 12, 34);
	
	Cart* cart = new Cart(user->user_id);
	std::string kyochon_option[5] = { "ġ� 3�� �߰�", "������ �߰�", "������ �߰�", "", "" };
	int kyochon_option_price[5] = { 3500, 9000, 5500, 0, 0 };
	std::string bhc_option[5] = { "������ ������", "�Ѹ� ġ�", "�Ѹ��Ҷ�", "", ""  };
	int bhc_option_price[5] = { 3500, 9000, 5500, 0, 0 };
	std::string jaws_option[5] = { "Ƣ�� �߰�", "���̴� �߰�", "�ݶ� �߰�", "", "" };
	int jaws_option_price[5] = { 3500, 1500, 1500, 0, 0 };

	Menu kyochon_menu_list[5] = {
		Menu(1, "����޺�", "������ ���� ������ �ٸ��� ��� �� �ִ� �޴�", 20000, 3, kyochon_option, kyochon_option_price), 
		Menu(1, "�����޺�", "������ ���� ������ �ٸ��� ��� �� �ִ� �޴�", 20000, 3, kyochon_option, kyochon_option_price),
		Menu(1, "��Ͽ�������", "������ ���� �Ѹ��� ġŲ", 16000, 3, kyochon_option, kyochon_option_price),
		Menu(1, "�����������", "������ ���� �Ѹ��� ġŲ", 17000, 3, kyochon_option, kyochon_option_price) };

	Menu bhc_menu_list[5] = {
		Menu(2, "�Ѹ�Ŭ", "���� ���� ��, �Ѹ�Ŭ", 18000, 3, bhc_option, bhc_option_price),
		Menu(2, "����ŷ", "����¬���� ���� ġŲ", 18000, 3, bhc_option, bhc_option_price),
		Menu(2, "����ŷ", "ȭ�������� ���� ġŲ", 19000, 3, bhc_option, bhc_option_price),
		Menu(2, "Ŀ����", "Ŀ�� �Ŀ���� ���� ������� ���� ġŲ", 18000, 3, bhc_option, bhc_option_price) };

	Menu jaws_menu_list[5] = {
		Menu(3, "�ҽ� ������", "�ҽ� ������", 3500, 3, jaws_option, jaws_option_price),
		Menu(3, "ġ�� ������", "ġ� ���� ������", 5000, 3, jaws_option, jaws_option_price),
		Menu(3, "�ҽ� ������", "�ҽ� ����", 4000, 3, jaws_option, jaws_option_price),
		Menu(3, "�λ� �", "�", 3500, 3, jaws_option, jaws_option_price) };

	Menu sincham_menu_list[5] = {
		Menu(3, "������", "������", 4000, 3, jaws_option, jaws_option_price),
		Menu(3, "����", "����", 5500, 3, jaws_option, jaws_option_price),
		Menu(3, "������", "������", 3500, 3, jaws_option, jaws_option_price),
		Menu(3, "��� Ƣ��", "��� Ƣ��", 4000, 3, jaws_option, jaws_option_price) };

	Store* kyochon_chicken = new Store(1, "�����", "����ġŲ ���ͳ���", "0100000", kyochon_menu_list, "user_address", 16000, 4000);
	Store* bhc_chicken = new Store(2, "�����", "BHC ����", "0100000", bhc_menu_list, "�����", 16000, 3000);
	Store* jaws_tteokbokki = new Store(3, "�����", "�ҽ������� �߾Ӵ���", "0100000", jaws_menu_list, "�����", 10000, 3000);
	Store* sincham_tteokbokki = new Store(4, "�����", "���������� �󵵿���", "0100000", sincham_menu_list, "�����", 13000, 2000);

	Store* store_list[4] = { kyochon_chicken, bhc_chicken, jaws_tteokbokki, sincham_tteokbokki };
	int result = 0;
	while (true) {
		print_store_list(store_list, 4, cart);
		result = payment->show_cart_before_payment(cart, store_list);
		if (result == 0) break;
	}

	return 0;
}