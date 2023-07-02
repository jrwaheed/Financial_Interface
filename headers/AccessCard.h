#ifndef ACCESSCARD_H
#define ACCESSCARD_H


#include <iostream>
#include "string.h"

class AccessCard {
    std::string ac_tax_id;
    int ac_pin;


public:
	AccessCard(std::string ac_tax_id,  int ac_pin);

	std::string getTaxId();

	int getPin();
};
#endif
