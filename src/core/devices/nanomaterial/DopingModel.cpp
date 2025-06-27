#include "DopingModel.h"
#include <sstream>

DopingModel::DopingModel()
    : dopingType(DopingType::NONE), concentration(0.0), dopantElement("None") {}

void DopingModel::setDopingType(DopingType type) {
    dopingType = type;
}

void DopingModel::setConcentration(double cm3) {
    concentration = cm3;
}

void DopingModel::setDopantElement(const std::string& elementSymbol) {
    dopantElement = elementSymbol;
}

DopingType DopingModel::getDopingType() const {
    return dopingType;
}

double DopingModel::getConcentration() const {
    return concentration;
}

std::string DopingModel::getDopantElement() const {
    return dopantElement;
}

std::string DopingModel::description() const {
    std::ostringstream oss;
    oss << "Doping Type: ";
    switch (dopingType) {
        case DopingType::N_TYPE: oss << "N-Type"; break;
        case DopingType::P_TYPE: oss << "P-Type"; break;
        case DopingType::NONE:   oss << "None";   break;
    }
    oss << ", Dopant: " << dopantElement
        << ", Concentration: " << concentration << " atoms/cm³";
    return oss.str();
}
