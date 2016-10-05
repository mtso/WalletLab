
#include <iostream>
#include <string>

#include "USDCurrency.h"

USDCurrency::USDCurrency(int initMain, int initSub) 
	: Currency(USD, 100, "dollars", "cents", initMain, initSub) 
{

}

USDCurrency::~USDCurrency() {
	std::cout << "Calling USD destructor\n";
}
