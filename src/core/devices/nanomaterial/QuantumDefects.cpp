#include "QuantumDefects.h"
#include <sstream>

QuantumDefects::QuantumDefects() {}

void QuantumDefects::addDefect(const Defect& defect) {
    defects.push_back(defect);
}

void QuantumDefects::clearDefects() {
    defects.clear();
}

std::vector<Defect> QuantumDefects::getAllDefects() const {
    return defects;
}

unsigned int QuantumDefects::count(DefectType type) const {
    unsigned int total = 0;
    for (const auto& d : defects) {
        if (d.type == type) ++total;
    }
    return total;
}

std::string QuantumDefects::summary() const {
    std::map<DefectType, unsigned int> typeCounts;
    for (const auto& d : defects)
        typeCounts[d.type]++;

    std::ostringstream oss;
    oss << "Quantum Defect Summary:\n";
    for (const auto& pair : typeCounts) {
        std::string typeStr;
        switch (pair.first) {
            case DefectType::VACANCY:      typeStr = "Vacancy"; break;
            case DefectType::INTERSTITIAL: typeStr = "Interstitial"; break;
            case DefectType::SUBSTITUTION: typeStr = "Substitution"; break;
            case DefectType::TRAP:         typeStr = "Trap"; break;
            case DefectType::DISLOCATION:  typeStr = "Dislocation"; break;
        }
        oss << "  " << typeStr << ": " << pair.second << "\n";
    }

    return oss.str();
}
