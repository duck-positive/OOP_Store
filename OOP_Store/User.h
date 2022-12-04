#pragma once
#include<iostream>
#include<string>

using namespace std;
class User
{
protected:
	string user_id;
	string name;
	string password;
	string phone_number;
	string address;

public:
	User();
	User(string e, string n, string p, string ph, string add,int store_id);
	///setter///
	void setuser_id(string e);
	void setname(string n);
	void setpassword(string p);
	void setphone_number(string ph);
	void setaddress(string add);
	void category_search(int store_id);

	///Getter///
	string getuser_id()const;
	string getname()const;
	string getpassword()const;
	string getphone_number()const;
	string getaddress()const;
	
	~User();
};

