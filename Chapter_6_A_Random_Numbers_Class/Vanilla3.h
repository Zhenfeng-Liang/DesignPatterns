

#ifndef VANILLA_3_H
#define VANILLA_3_H
#include "PayOffBridge.h"

class VanillaOption
{
public:
	
    // We can pass in PayOff object indeed because PayOffBridge class define a constructor which take a PayOff object as 
    // a parameter. Implicit conversion.
    VanillaOption(const PayOffBridge& ThePayOff_,double Expiry);
    double OptionPayOff(double Spot) const;
    double GetExpiry() const;
private:
    double Expiry;

    // We can use the PayOffBridge class from now on.
    PayOffBridge ThePayOff;
};

#endif
