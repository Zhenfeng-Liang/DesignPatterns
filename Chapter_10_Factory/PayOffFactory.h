
// Note: Singleton pattern to implement factory.
// Set constructors as private, only the class function (static function in this case) can call it. 

#ifndef PAYOFF_FACTORY_H
#define PAYOFF_FACTORY_H

#include "PayOff3.h"

#if defined(_MSC_VER)
#pragma warning( disable : 4786)
#endif

#include <map>
#include <string>

class PayOffFactory
{
public:
	
    // CreatePayOffFunction actually is the PayOff class Pointer
    // Note the typedef: this allows us to refer to pointers to functions which take
    // in a double and spit out a PayOff* as CreatePayOffFunction.
    // CreatePayOffFunction is a function pointer type.
    // Code: 
    //		CreatePayOffFunction f		// is equivalent to 
    //		PayOff* (*f)(double)
    // while the argument double should be strike in this case because we will use Create function
    // in class PayOffHelper
    typedef PayOff* (*CreatePayOffFunction)(double );
	
    static PayOffFactory& Instance();
	
    void RegisterPayOff(std::string, CreatePayOffFunction);
	
    PayOff* CreatePayOff(std::string PayOffId, double Strike);
	
    ~PayOffFactory(){};

private:

    std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
	
    PayOffFactory(){}
	
    PayOffFactory(const PayOffFactory&) {}
	
    PayOffFactory& operator = (const PayOffFactory&) { return *this; }

};

#endif
