#pragma once
#include<iostream>
#include<string>

using namespace std;
class User
{
protected:
	
	string name;
	string password;
	string phone_number;
	

public:
	User();
	User(string user_id, string name, string password, string phone_number, string address);
	///setter///
	void set_user_id(string user_id);
	void set_name(string n);
	void set_password(string p);
	void set_phone_number(string ph);
	void set_address(string add);
	void category_search(int store_id);

	///Getter///
	string get_user_id()const;
	string get_name()const;
	string get_password()const;
	string get_phone_number()const;
	string get_address()const;


	string user_id;
	string address;
};


