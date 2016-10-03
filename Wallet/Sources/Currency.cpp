
#include <string>

#include "../Headers/Currency.h"
#include "../Headers/CurrencyType.h"

using namespace std;

Currency<CurrencyType>::Currency(string nameInput, int baseInput) : name(nameInput), base(baseInput) {
	//name = nameInput;
	//base = baseInput;
}