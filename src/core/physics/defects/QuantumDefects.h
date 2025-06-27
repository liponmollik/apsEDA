#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

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
    double positionX;
    double positionY;
    double positionZ;
    double energyLevel;
};

class QuantumDefects {
public:
    QuantumDefects();

    void addDefect(const Defect& defect);
    void clearDefects();

    std::vector<Defect> getAllDefects() const;
    unsigned int count(DefectType type) const;
    std::string summary() const;

    //New function
    nlohmann::json exportToJson() const;

private:
    std::vector<Defect> defects;
    std::string defectTypeToString(DefectType type) const;
};
