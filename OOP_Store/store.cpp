# include "store.h"
using namespace std;

store::store() {
	this->	store_id = 0;
	this-> store_address = "";
	this-> store_name = "";
	this-> store_phno = "";
	this-> menu_name = "";
	this-> menu_price = 0;
	this-> user_address = "";
	this-> min_price = 0;
	this-> tip = 0;
}

store::store(int store_id, string store_address, string store_name, string store_phno, 
	string menu_name, int menu_price, string user_address, int min_price, int tip)
{
	this->store_id = store_id;
	this->store_address = store_address;
	this->store_name = store_name;
	this->store_phno = store_phno;
	this->menu_name = menu_name;
	this->menu_price = menu_price;
	this->user_address = user_address;
	this->min_price = min_price;
	this->tip = tip;
}

void add_menu(const Menu& m) {
	menu_list.addMenu(m);
}

void store::delete_menu(const Menu& m) {
	menu_list.deleteMenu(m);
}
bool store::confirm_order(string store_address, string store_name, string store_phno, string user_address) {
	// 유저 주소가 반환될 경우
	
}

// 배차가 완료되었음을 고객에게 전달
bool store::confirm_deliver() {
	
}