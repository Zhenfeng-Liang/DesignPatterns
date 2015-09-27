
// Note: This class just encapsulate the PayOff Pointer. The main purpose of this class is to handle 
// memory management.

// Note: Bridge pattern "decouple an abstraction from its implementation so that the two can vary independently".
// In this case, it is indeed seperating the abstraction(PayOffBridge interface) and the actual implementation (PayOff itself)

// In this case, we define the the constructor, assignment operator and destuctor handling the memory management. 
// Once this file client call its default ones, it will actually call these ones which can handle the memory problem.
// Therefore, the client of this class would not need to declare their function to handle PayOffBridge pointer memory 
// problem. And because PayOffBridge is indeed the interface of PayOff, from now on, we can just use PayOffBridge rather
// than PayOff itself.

#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H
#include "PayOff3.h"

class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
private:
    PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const
{
    return ThePayOffPtr->operator ()(Spot);
}

#endif
