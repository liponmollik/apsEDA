#pragma once

#include <string>
#include <vector>
#include <map>

enum class DefectType {
    VACANCY,
    INTERSTITIAL,
    SUBSTITUTION,
    TRAP,
    DISLOCATION
};

struct Defect {
    DefectType type;
    std::string atomSymbol;
    double positionX;  // in nm
    double positionY;  // in nm
    double positionZ;  // in nm
    double energyLevel; // eV below or above band edge
};

class QuantumDefects {
public:
    QuantumDefects();

    void addDefect(const Defect& defect);
    void clearDefects();

    std::vector<Defect> getAllDefects() const;
    unsigned int count(DefectType type) const;
    std::string summary() const;

private:
    std::vector<Defect> defects;
};
