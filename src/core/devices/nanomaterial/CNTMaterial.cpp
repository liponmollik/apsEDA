#include "CNTMaterial.h"
#include <cmath>
#include <iostream>
#include <sstream>

CNTMaterial::CNTMaterial(unsigned int n, unsigned int m, double length)
    : n_(n), m_(m), length_nm(length) {
    // Metallic if (n - m) mod 3 == 0 (approximation)
    metallic = ((n_ - m_) % 3 == 0);
}

std::string CNTMaterial::name() const {
    std::ostringstream oss;
    oss << "CNT (" << n_ << ", " << m_ << ")";
    return oss.str();
}

double CNTMaterial::calculateBandGap() const {
    if (metallic) return 0.0;

    // Approximate bandgap formula for semiconducting CNTs
    // Eg = 2γ0 * a / d; γ0 ≈ 2.9 eV, a ≈ 0.142 nm (C-C bond length)
    const double a = 0.142; // nm
    const double gamma0 = 2.9; // eV

    double d = (a / M_PI) * std::sqrt(3.0 * (n_ * n_ + m_ * m_ + n_ * m_));
    return 2.0 * gamma0 * a / d; // Simplified
}

double CNTMaterial::bandGap() const {
    return calculateBandGap();
}

double CNTMaterial::latticeConstant() const {
    // Return lattice periodicity (approx)
    return 0.246; // nm (graphene lattice constant)
}

void CNTMaterial::simulateElectronTransport() {
    std::cout << "Simulating transport in: " << name() << "\n";
    std::cout << "Type: " << (metallic ? "Metallic" : "Semiconducting") << "\n";
    std::cout << "Bandgap: " << bandGap() << " eV\n";
    std::cout << "Length: " << length_nm << " nm\n";
    // [Insert transport physics here...]
}

bool CNTMaterial::isMetallic() const {
    return metallic;
}

std::pair<unsigned int, unsigned int> CNTMaterial::chirality() const {
    return {n_, m_};
}

double CNTMaterial::getLength() const {
    return length_nm;
}
