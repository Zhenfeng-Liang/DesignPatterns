


#ifndef VANILLA_1_H
#define VANILLA_1_H
#include "PayOff2.h"

class VanillaOption
{
public:
    VanillaOption(PayOff& ThePayOff_, double Expiry_);
    double GetExpiry() const;
    double OptionPayOff(double Spot) const;
private:
    double Expiry;

    // We declare PayOff as reference here which is such a bad practice in that VanillaOption depends on the 
    // object outside (The payoff object passed in to construct VanillaOption). We will use virtual construction to
    // avoid this problem.
    PayOff& ThePayOff;
};

#endif
