#pragma once

#include "QuantumDefects.h"
#include <random>

class DefectSimulator {
public:
    DefectSimulator(double volumeX_nm, double volumeY_nm, double volumeZ_nm);

    void setDefectDensity(double density_per_cm3);
    void enableDefectType(DefectType type, double probability);
    QuantumDefects generate(unsigned int seed = 42);

private:
    double volX, volY, volZ;         // Volume dimensions in nm
    double density_cm3;              // Defects/cm³
    std::map<DefectType, double> probabilities;

    std::default_random_engine engine;
    std::uniform_real_distribution<double> distUniform;
    std::discrete_distribution<int> typeSelector;

    void updateTypeSelector();
    DefectType randomDefectType();
    double randomPosition(double max);
    double randomEnergyLevel(DefectType type);
};
