#include <iostream>
#include "../headers/Customer.h"




Customer::Customer(std::string tax_id, std::string last_name, std::string first_name, float checking_balance, int pin) :
	tax_id(tax_id),
	last_name(last_name),
	first_name(first_name),
	checking_balance(checking_balance),
	pin(pin)
{}

Customer::~Customer(){};

		void Customer::setTaxId(std::string tId){
			tax_id = tId;
		};

		void Customer::setLastName(std::string lastName){
			last_name = lastName;
		};

		void Customer::setFirstName(std::string firstName){
			first_name = firstName;
		};
		
		void Customer::setCheckingBalance(float checkingBalance){
			checking_balance = checkingBalance;
		};

		void Customer::setPin(int newPin){
			pin = newPin;
		};

		std::string Customer::getTaxId(){
			return tax_id;
		};

		std::string Customer::getLastName(){
			return last_name;
		};

		std::string Customer::getFirstName(){
			return first_name;
		};
		
		float Customer::getCheckingBalance(){
			return checking_balance;
		};

		int Customer::getPin(){
			return pin;
		}

