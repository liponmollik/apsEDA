#ifndef LOGIC_SYNTHESIZER_H
#define LOGIC_SYNTHESIZER_H

#include <string>
#include <memory>
#include "Netlist.h"
#include "ConstraintManager.h"

class LogicSynthesizer
{
public:
    LogicSynthesizer();
    ~LogicSynthesizer();

    void loadRTL(const std::string& rtlFile);
    void setConstraints(std::shared_ptr<ConstraintManager> constraints);
    void runSynthesis();
    std::shared_ptr<Netlist> getSynthesizedNetlist() const;

private:
    std::string rtlSource;
    std::shared_ptr<ConstraintManager> constraintManager;
    std::shared_ptr<Netlist> netlist;

    void parseRTL();
    void optimizeLogic();
};

#endif // LOGIC_SYNTHESIZER_H
