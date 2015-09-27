
// Note: Inheritance can help us add additional functionality through adding another inherited class
// by which we can avoid recompiliation of other files as the interface class (PayOff abstract class)
// doesn't change.

#ifndef DOUBLEDIGITAL_H
#define DOUBLEDIGITAL_H

#include "Payoff2.h"

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}

private:
    double LowerLevel;
    double UpperLevel;
};

#endif
