#pragma once

#include "BaseMaterial.h"
#include <string>
#include <vector>

class GrapheneMaterial : public BaseMaterial {
public:
    GrapheneMaterial(bool doped = false);

    std::string name() const override;
    double bandGap() const override;
    double latticeConstant() const override;
    void simulateElectronTransport() override;

    void setDefectDensity(double density);   // in atoms/cm²
    double getDefectDensity() const;

private:
    bool isDoped;
    double defectDensity; // atoms/cm²
};
