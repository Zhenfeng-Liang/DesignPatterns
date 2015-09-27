
// Note : Decoration pattern. 
// Inheritance from StatisticsMC make sure the ConvergenceTable has the same interface with MCStatistics
// Composition of the StatisticsMC's Wrapper enables this class to have any StatisticsMC derived class's function as desired.

// Can decorate a class as many times as you want.

#ifndef CONVERGENCE_TABLE_H
#define CONVERGENCE_TABLE_H

#include "MCStatistics.h"
#include "wrapper.h"

class ConvergenceTable : public StatisticsMC
{
public:
	
    // Accept implicit conversion
    ConvergenceTable(const Wrapper<StatisticsMC>& Inner_);
    virtual StatisticsMC* clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;

private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double> > ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
};

#endif
