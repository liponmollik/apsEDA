#pragma once

#include <string>

class BaseMaterial {
public:
    virtual std::string name() const = 0;
    virtual double bandGap() const = 0;            // eV
    virtual double latticeConstant() const = 0;    // Angstrom
    virtual void simulateElectronTransport() = 0;

    virtual ~BaseMaterial() = default;
};
