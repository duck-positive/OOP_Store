#pragma once
#include "User.h"
using namespace std;
class Payment 
{
public:
	
	Payment();
	Payment(User user, int payment_num, int total_price, int min_price, int card_number, int card_passwoed, int pay_number, int pay_password);
	int get_cart_price(int get_total_price,int min_price);
	User get_user(User* user);
	string payment();

	~Payment();

	User user;
	int payment_num;
	int total_price;
	int min_price;
	int card_number;
	int card_password;
	int pay_number;
	int pay_password;
};
