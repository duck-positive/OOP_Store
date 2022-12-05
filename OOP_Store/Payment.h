#pragma once
#include "User.h"
#include "store.h"
#include "Cart.h"
using namespace std;
class Payment 
{
public:
	
	Payment();
	Payment(User* user, int payment_num, int card_number, int card_passwoed, int pay_number, int pay_password); 
	User get_user(User* user);
	int payment(Cart* cart, Store* store_list[]);

	~Payment();

	User* user;
	int payment_num;
	int total_price;
	int min_price;
	int card_number;
	int card_password;
	int pay_number;
	int pay_password;
};
