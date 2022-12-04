#pragma once
#include "User.h"
using namespace std;
class Payment 
{
public:
	User user_id;
	int payment_num;
	int total_price;
	int min_price;
	int card_number;
	int card_password;
	int pay_number;
	int pay_password;

	Payment(User user_id, int payment_num, 
		int total_price, int min_price,int card_number,int card_passwoed
	,int pay_number,int pay_password) : user_id(user_id),payment_num(payment_num)
		,total_price(total_price),min_price(min_price),card_number(card_number),
		card_password(card_password),pay_number(pay_number),pay_password(pay_password)
	{}
	int get_cart_price(int get_total_price,int min_price);
	User get_user(User* user);
	string payment();

	~Payment();
};
