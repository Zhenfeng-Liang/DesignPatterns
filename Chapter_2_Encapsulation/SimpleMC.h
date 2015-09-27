// This file was created to show a simple implementation of a Monte Carlo call option pricer
//
// Zhenfeng Liang 
//
// 1/9/2015, in Elmhurst

#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include "PayOff1.h"

double SimpleMonteCarlo2(const PayOff& thePayOff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);

#endif
