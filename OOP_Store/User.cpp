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
void User::setuser_id(string e) {
	this->user_id = e;
}
void User::setname(string n) {
	this->name = n;
}

void User::setpassword(string p) {
	this->password = p;
}

void User::setphone_number(string ph) {
	this->phone_number = ph;
}

void User::setaddress(string add) {
	this->address = add;
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
string User::getuser_id()const {
	return this->user_id;
}

string User::getname()const {
	return this->name;
}

string User::getpassword()const {
	return this->password;
}

string User::getphone_number()const {
	return this->phone_number;
}


string User::getaddress()const {
	return this->address;
}
User::~User() {
	
}

