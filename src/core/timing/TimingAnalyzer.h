#ifndef TIMING_ANALYZER_H
#define TIMING_ANALYZER_H

#include <string>
#include <vector>
#include "TimingPath.h"
#include "Netlist.h"

class TimingAnalyzer
{
public:
    TimingAnalyzer();
    ~TimingAnalyzer();

    void loadNetlist(std::shared_ptr<Netlist> netlist);
    void setClockFrequency(double frequencyMHz);
    void runAnalysis();

    std::vector<TimingPath> getCriticalPaths(int topN = 10) const;
    bool hasTimingViolations() const;

private:
    std::shared_ptr<Netlist> netlist;
    double clockFrequencyMHz;
    std::vector<TimingPath> criticalPaths;

    void calculateSlack();
};

#endif // TIMING_ANALYZER_H
