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
	this->user_address = user_address;
	this->min_price = min_price;
	this->tip = tip;
}

void Store::initialize_menu_list(Menu menu_list[]) {
	for (int i = 0; i < 5; i++) {
		this->menu_list[i] = menu_list[i];
	}
}

void Store::print_menu() {
	cout << this->store_name << endl;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ". " << this->menu_list[i].menu_name << "  ||  " << this->menu_list[i].menu_price << endl;
	}

	int input = 0;
	
	cout << "�߰��� �޴� ��ȣ�� �������ּ���(���� ���� ȭ�� 0) : ";
}

bool Store::confirm_order(string store_address, string store_name, string store_phno, string user_address) {
	// ���� �ּҰ� ��ȯ�� ���
	return 0;
}

// ������ �Ϸ�Ǿ����� ������ ����
bool Store::confirm_deliver() {
	return 0;
}