#ifndef CUSTOMER_H
#define CUSTOMER_H


#include <iostream>
#include "string.h"

class Customer {
		std::string tax_id;
		std::string last_name;
		std::string first_name;
		float checking_balance;
		int pin;


public:
	Customer(std::string tax_id, std::string last_name, std::string first_name, float checking_balance, int pin);

	~Customer();

		void setTaxId(std::string tId);

		void setLastName(std::string lastName);

		void setFirstName(std::string firstName);
		
		void setCheckingBalance(float checkingBalance);

		void setPin(int pin);

		std::string getTaxId();

		std::string getLastName();

		std::string getFirstName();
		
		float getCheckingBalance();

		int getPin();
};
#endif
