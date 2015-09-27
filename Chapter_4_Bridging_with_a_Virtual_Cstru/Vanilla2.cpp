

#include "Vanilla2.h"

VanillaOption::VanillaOption(const PayOff& ThePayOff_, double Expiry_) : Expiry(Expiry_)
{
    // Call the virtual constructor so as to really creat another object. So the PayOff object in this 
    // VanillaOption object will not depend on the object outside.
    ThePayOffPtr = ThePayOff_.clone();
}

double VanillaOption::GetExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
    return (*ThePayOffPtr)(Spot);
}

VanillaOption::VanillaOption(const VanillaOption& original)
{
    Expiry = original.Expiry;

    // Call the virtual constructor so as to really creat another object. And two VanillaOption objects
    // will depend on 2 different PayOff objects.
    ThePayOffPtr = original.ThePayOffPtr->clone();
}

VanillaOption& VanillaOption::operator=(const VanillaOption& original)
{
    if (this != &original)
    {
        Expiry = original.Expiry;

        // Delete the original pointer first
        delete ThePayOffPtr;

        // Call the virtual constructor so as to really creat another object. And two VanillaOption objects
        // will depend on 2 different PayOff objects.
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }

    return *this;
}
VanillaOption::~VanillaOption()
{
    delete ThePayOffPtr;
}
