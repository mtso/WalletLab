
#include "../Headers/GBPCurrency.h";

GBPCurrency::GBPCurrency(int mainInput, int subInput)
: Currency(GBP, 100, "pounds", "pence")
{
	value = { mainInput, subInput };
}
GBPCurrency::~GBPCurrency()
{

}