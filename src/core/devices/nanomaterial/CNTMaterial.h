#pragma once

#include "BaseMaterial.h"
#include <string>
#include <utility> // for std::pair

class CNTMaterial : public BaseMaterial {
public:
    CNTMaterial(unsigned int n, unsigned int m, double length_nm = 100.0);

    std::string name() const override;
    double bandGap() const override;
    double latticeConstant() const override;
    void simulateElectronTransport() override;

    bool isMetallic() const;
    std::pair<unsigned int, unsigned int> chirality() const;
    double getLength() const;

private:
    unsigned int n_;     // Chirality index n
    unsigned int m_;     // Chirality index m
    double length_nm;    // Nanotube length in nanometers

    bool metallic;
    double calculateBandGap() const;
};
