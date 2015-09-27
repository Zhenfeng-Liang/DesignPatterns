// This file was created to show a simple implementation of a Monte Carlo call option pricer
//
// Zhenfeng Liang 
//
// 1/9/2015, in Elmhurst

#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
public:

    // Switch to choose vanilla option
    enum OptionType {call, put};
    PayOff(double Strike_, OptionType TheOptionsType_);

    // Function object
    double operator()(double Spot) const;
	
private:
    double Strike;
    OptionType TheOptionsType;
};

#endif
