#include "GrapheneMaterial.h"
#include <iostream>

GrapheneMaterial::GrapheneMaterial(bool doped)
    : isDoped(doped), defectDensity(0.0) {}

std::string GrapheneMaterial::name() const {
    return isDoped ? "Doped Graphene" : "Graphene";
}

double GrapheneMaterial::bandGap() const {
    // Intrinsic graphene is gapless (~0 eV); bandgap opens slightly with doping
    return isDoped ? 0.1 : 0.0;
}

double GrapheneMaterial::latticeConstant() const {
    return 2.46; // Angstrom (approx. C-C bond length in graphene)
}

void GrapheneMaterial::simulateElectronTransport() {
    std::cout << "Simulating electron transport in " << name() << "...\n";
    std::cout << "Bandgap: " << bandGap() << " eV\n";
    std::cout << "Defect Density: " << defectDensity << " atoms/cm²\n";
    // [Simulation placeholder]
}

void GrapheneMaterial::setDefectDensity(double density) {
    defectDensity = density;
}

double GrapheneMaterial::getDefectDensity() const {
    return defectDensity;
}
