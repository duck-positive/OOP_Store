#include "User.h"
User::User()
{
	this->user_id = "";
	this->name = "";
	this->password = "";
	this->phone_number = "";
	this->address = "";
}
User::User(string user_id, string name, string password, string phone_number, string address)
{
	this->user_id = user_id;
	this->name = name;
	this->password = password;
	this->phone_number = phone_number;
	this->address = address;
}
//setter///
void User::set_user_id(string user_id) {
	this->user_id = user_id;
}
void User::set_name(string name) {
	this->name = name;
}

void User::set_password(string password) {
	this->password = password;
}

void User::set_phone_number(string phone_number) {
	this->phone_number = phone_number;
}

void User::set_address(string address) {
	this->address = address;
}

//void category_search(int store_id) {
//	system("cls");
//	cout << "\t\t\t\t------------------------------" << endl;
//	cout << "\t\t\t\t|      category_list          |" << endl;
//	cout << "\t\t\t\t|   1번은 한식 2번은 중식     |" << endl;
//	cout << "\t\t\t\t------------------------------" << endl;
//
//	if(store_id==1){
//		for (int i = 0; i < 10; i++)
//		{
//			store_id[i].display();
//		}
//	}
//		
//	else if(store_id == 2) {
//
//		for (int i = 10; i < 20; i++)
//		{
//			store_id[i].display();
//		}
//
//	}
//}


//Getter//
string User::get_user_id()const {
	return this->user_id;
}

string User::get_name()const {
	return this->name;
}

string User::get_password()const {
	return this->password;
}

string User::get_phone_number()const {
	return this->phone_number;
}


string User::get_address()const {
	return this->address;
}


