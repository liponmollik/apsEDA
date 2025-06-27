#include "MoS2Material.h"
#include <iostream>
#include <cmath>

MoS2Material::MoS2Material(unsigned int layers)
    : layerCount(layers), strainPercent(0.0) {}

std::string MoS2Material::name() const {
    return "MoS₂ (" + std::to_string(layerCount) + "L)";
}

double MoS2Material::bandGap() const {
    // Monolayer: ~1.8 eV direct; multilayer: ~1.2 eV indirect
    double baseGap = (layerCount == 1) ? 1.8 : 1.2;

    // Apply bandgap reduction with strain (simple model)
    double adjustedGap = baseGap - (strainPercent * 0.05); // 0.05 eV per % strain
    return adjustedGap > 0 ? adjustedGap : 0.0;
}

double MoS2Material::latticeConstant() const {
    return 3.15; // Angstrom
}

void MoS2Material::simulateElectronTransport() {
    std::cout << "Simulating MoS₂ electron transport...\n";
    std::cout << "Name: " << name() << "\n";
    std::cout << "Bandgap: " << bandGap() << " eV\n";
    std::cout << "Strain: " << strainPercent << "%\n";
    // [Insert actual transport simulation here]
}

void MoS2Material::setStrainPercent(double strain) {
    strainPercent = strain;
}

double MoS2Material::getStrainPercent() const {
    return strainPercent;
}
