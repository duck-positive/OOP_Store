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
	
	int show_cart_before_payment(Cart* cart, Store* store_list[]);

	User* user;
	int payment_num;
	int total_price;
	int min_price;
	int card_number;
	int card_password;
	int pay_number;
	int pay_password;
};
