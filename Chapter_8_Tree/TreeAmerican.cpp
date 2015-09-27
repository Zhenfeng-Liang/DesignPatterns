


#include "TreeAmerican.h"
#include <minmax.h>

TreeAmerican::TreeAmerican(double FinalTime, const PayOffBridge& ThePayOff_) 
    : TreeProduct(FinalTime), ThePayOff(ThePayOff_)
{
}

TreeProduct* TreeAmerican::clone() const
{
    return new TreeAmerican(*this);
}

double TreeAmerican::FinalPayOff(double Spot) const
{
    return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double , double DiscountedFutureValue) const
{// Borland compiler doesnt like unused named variables
	
    return max(ThePayOff(Spot), DiscountedFutureValue);
}
