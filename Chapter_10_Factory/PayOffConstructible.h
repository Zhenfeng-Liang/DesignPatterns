


#ifndef PAYOFF_CONSTRUCTIBLE_H
#define PAYOFF_CONSTRUCTIBLE_H

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

#include <iostream>
#include "PayOff3.h"
#include "PayOffFactory.h"
#include <string>

template <class T>
class PayOffHelper
{
public:
    PayOffHelper(std::string);
    static PayOff* Create(double);
};

template <class T>
PayOff* PayOffHelper<T>::Create(double Strike)
{
    return new T(Strike);
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
    PayOffFactory& thePayOffFactory = PayOffFactory::Instance();

    // Passing the function name Create which is actually 
    // a function pointer which is the type as CreatePayOffFunction.
    thePayOffFactory.RegisterPayOff(id,PayOffHelper<T>::Create); 
}

#endif
