#include "QuantumDefects.h"
#include <sstream>
#include <map>
using json = nlohmann::json;

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
    std::map<DefectType, unsigned int> defectCount;
    for (const auto& d : defects) {
        defectCount[d.type]++;
    }

    std::ostringstream oss;
    oss << "Quantum Defects Summary:\n";
    for (const auto& entry : defectCount) {
        oss << "  " << defectTypeToString(entry.first) << ": " << entry.second << "\n";
    }

    return oss.str();
}

std::string QuantumDefects::defectTypeToString(DefectType type) const {
    switch (type) {
        case DefectType::VACANCY: return "Vacancy";
        case DefectType::INTERSTITIAL: return "Interstitial";
        case DefectType::SUBSTITUTION: return "Substitution";
        case DefectType::TRAP: return "Trap";
        case DefectType::DISLOCATION: return "Dislocation";
        default: return "Unknown";
    }
}

json QuantumDefects::exportToJson() const {
    json j;
    for (const auto& d : defects) {
        j["defects"].push_back({
            {"type", defectTypeToString(d.type)},
            {"atom", d.atomSymbol},
            {"position", {
                {"x", d.positionX},
                {"y", d.positionY},
                {"z", d.positionZ}
            }},
            {"energyLevel_eV", d.energyLevel}
        });
    }
    return j;
}
