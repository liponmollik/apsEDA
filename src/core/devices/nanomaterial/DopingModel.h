#pragma once

#include <string>

enum class DopingType {
    NONE,
    N_TYPE,
    P_TYPE
};

class DopingModel {
public:
    DopingModel();

    void setDopingType(DopingType type);
    void setConcentration(double cm3); // in atoms/cm³
    void setDopantElement(const std::string& elementSymbol);

    DopingType getDopingType() const;
    double getConcentration() const;
    std::string getDopantElement() const;

    std::string description() const;

private:
    DopingType dopingType;
    double concentration; // atoms/cm³
    std::string dopantElement;
};
