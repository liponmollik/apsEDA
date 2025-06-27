#pragma once

#include "BaseMaterial.h"
#include <string>

class MoS2Material : public BaseMaterial {
public:
    MoS2Material(unsigned int layers = 1);  // 1L, 2L, etc.

    std::string name() const override;
    double bandGap() const override;
    double latticeConstant() const override;
    void simulateElectronTransport() override;

    void setStrainPercent(double strain);
    double getStrainPercent() const;

private:
    unsigned int layerCount;    // Number of atomic layers
    double strainPercent;       // Strain applied (0–10%)
};
