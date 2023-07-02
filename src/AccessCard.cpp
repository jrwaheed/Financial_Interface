#include <iostream>
#include "../headers/AccessCard.h"




AccessCard::AccessCard(std::string ac_tax_id,  int ac_pin) :
	ac_tax_id(ac_tax_id),
	ac_pin(ac_pin)
    {}

    std::string AccessCard::getTaxId(){
        return ac_tax_id;
    };


    int AccessCard::getPin(){
        return ac_pin;
    }

