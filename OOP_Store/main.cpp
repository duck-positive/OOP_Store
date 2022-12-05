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
		cout << "���� ��� ���" << endl;
		for (int i = 0; i < list_size; i++) {
			if (store_list[i]->store_name != "") {
				cout << i + 1 << ". " << store_list[i]->store_name << endl;
			}
			else break;
		}
		int input = 0;
		cout << "��ٱ��Ϸ� ���� : 0" << endl;
		cin >> input;
		//��ٱ��Ϸ� ����
		if (input == 0) {
			system("cls");
			break;
		}
		//�޴� ��� �����ϱ� ���� �� �ݺ�
		while (true) {
			store_list[input - 1]->print_menu();
			int select = 0;
			int option_select = 0;
			cin >> select;
			//���� ������� ���ư���
			if (select == 0) {
				break;
			}
			else {
				if (input != 0) {
					store_list[input-1]->menu_list[select-1].print_info();
					cin >> option_select;
				}
			}
			store_list[input]->menu_list[select-1].option_check[option_select-1] = true;
			store_list[input]->menu_list[select-1].add_cart(cart);

			cout << "success  �޴��� ��� �����Ͻðڽ��ϱ�?(���� ���� ȭ�� 0 else 1)" << endl;
			cin >> select;
			if (select == 0) break;
		}
	}
}


int main() {
	User* user = new User("user_id", "user_name", "1234", "01012345678", "�����");
	Payment* payment = new Payment(user, 10, 1234, 2345, 12, 34);
	
	Cart* cart = new Cart();
	std::string option[10] = { "ġ� 3�� �߰�", "������ �߰�", "������ �߰�", "", "" , "" , "" , "" , "" , "" };
	std::string option2[10] = { "ġ� 3�� �߰�", "������ �߰�", "������", "dd", "dd", "dd", "dd", "dd", "dd", "dd" };
	std::string option3[10] = { "ġ� 3�� �߰�", "������ �߰�", "������", "dd", "dd", "dd", "dd", "dd", "dd", "dd" };
	std::string option4[10] = { "ġ� 3�� �߰�", "������ �߰�", "������", "dd", "dd", "dd", "dd", "dd", "dd", "dd" };
	bool option_cnt[10] = { false, };
	int option_price[10] = { 3500, 9000, 5500, 0, 0, 0, 0, 0, 0, 0};
	Menu kyochon_menu_list[5] = {
		Menu(1, "����޺�", "light", 20000, 3, option, option_cnt, option_price), 
		Menu(1, "�����޺�", "light", 20000, 3, option, option_cnt, option_price), 
		Menu(1, "��Ͽ�������", "light", 16000, 3, option, option_cnt, option_price), 
		Menu(1, "�����������", "light", 17000, 3, option, option_cnt, option_price) };
	Store* store = new Store(1, "�����", "����ġŲ ���ͳ���", "0100000", kyochon_menu_list, "user_address", 16000, 4000);

	Store* store2 = new Store(1, "�����", "����ġŲ2", "0100000", kyochon_menu_list, "�����", 1000, 3000);
	Store* store3 = new Store(1, "�����", "����ġŲ3", "0100000", kyochon_menu_list, "�����", 1000, 3000);
	Store* store4 = new Store(1, "�����", "����ġŲ4", "0100000", kyochon_menu_list, "�����", 1000, 3000);
	Store* store5 = new Store(1, "�����", "����ġŲ5", "0100000", kyochon_menu_list, "�����", 1000, 3000);
	Store* store6 = new Store(1, "�����", "����ġŲ6", "0100000", kyochon_menu_list, "�����", 1000, 3000);
	Store* store7 = new Store(1, "�����", "����ġŲ7", "0100000", kyochon_menu_list, "�����", 1000, 3000);
	Store* store8 = new Store(1, "�����", "����ġŲ8", "0100000", kyochon_menu_list, "�����", 1000, 3000);
	Store* store9 = new Store(1, "�����", "����ġŲ9", "0100000", kyochon_menu_list, "�����", 1000, 3000);
	Store* store10 = new Store(1, "�����", "����ġŲ10", "0100000", kyochon_menu_list, "�����", 1000, 3000);

	Store* store_list[10] = { store, store2, store3, store4, store5, store6, store7, store8, store9, store10};
	while (true) {
		print_store_list(store_list, 10, cart);
		int result = payment->payment(cart);
		if (result == 0) break;
	}

	return 0;
}