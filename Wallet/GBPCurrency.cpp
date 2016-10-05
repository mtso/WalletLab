
#include "GBPCurrency.h"

GBPCurrency::GBPCurrency(int initMain, int initSub)
	: Currency(GBP, 100, "pounds", "pence", initMain, initSub)
{
}
GBPCurrency::~GBPCurrency()
{

}