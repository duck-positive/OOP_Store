# include "store.h"
using namespace std;

Store::Store() {
	this->store_id = 0;
	this-> store_address = "";
	this-> store_name = "";
	this-> store_phno = "";
	this-> user_address = "";
	this-> min_price = 0;
	this-> tip = 0;
}

Store::Store(int store_id, string store_address, string store_name, string store_phno, 
	Menu menu_list[], string user_address, int min_price, int tip)
{
	this->store_id = store_id;
	this->store_address = store_address;
	this->store_name = store_name;
	this->store_phno = store_phno;
	initialize_menu_list(menu_list);
	this->user_address = "";
	this->min_price = min_price;
	this->tip = tip;
}

void Store::initialize_menu_list(Menu menu_list[]) {
	for (int menu_list_index = 0; menu_list_index < 5; menu_list_index++) {
		this->menu_list[menu_list_index] = menu_list[menu_list_index];
	}
}

void Store::print_store_info() {
	system("cls");
	cout << endl << "���Ը� : " << this->store_name << endl;
	cout << "�ּ� �ֹ� �ݾ� : " << this->min_price << "��" << endl;
	cout << "��� �� : " << this->tip << "��" << endl;
	cout << "=================================" << endl;
	cout << "0. ���� ȭ������ ���ư���" << endl;

	for (int menu_list_index = 0; menu_list_index < 5; menu_list_index++) {
		if (this->menu_list[menu_list_index].get_menu_price() == 0) {
			break;
		}
		cout << menu_list_index + 1 << ". ";
		this->menu_list[menu_list_index].print_menu();
	}

}

bool Store::confirm_order(string store_address, string store_name, string store_phno, string user_address) {
	// ���� �ּҰ� ��ȯ�� ���
	return 0;
}

// ������ �Ϸ�Ǿ����� ������ ����
bool Store::confirm_deliver() {
	return 0;
}