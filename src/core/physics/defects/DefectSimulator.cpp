#include "DefectSimulator.h"
#include <cmath>

DefectSimulator::DefectSimulator(double volumeX_nm, double volumeY_nm, double volumeZ_nm)
    : volX(volumeX_nm), volY(volumeY_nm), volZ(volumeZ_nm), density_cm3(1e15),
      distUniform(0.0, 1.0) {
    engine.seed(42);
}

void DefectSimulator::setDefectDensity(double density) {
    density_cm3 = density;
}

void DefectSimulator::enableDefectType(DefectType type, double probability) {
    probabilities[type] = probability;
    updateTypeSelector();
}

void DefectSimulator::updateTypeSelector() {
    std::vector<double> probs;
    for (int i = 0; i <= static_cast<int>(DefectType::DISLOCATION); ++i) {
        probs.push_back(probabilities.count(static_cast<DefectType>(i)) ?
                        probabilities[static_cast<DefectType>(i)] : 0.0);
    }
    typeSelector = std::discrete_distribution<int>(probs.begin(), probs.end());
}

DefectType DefectSimulator::randomDefectType() {
    return static_cast<DefectType>(typeSelector(engine));
}

double DefectSimulator::randomPosition(double max) {
    return distUniform(engine) * max;
}

double DefectSimulator::randomEnergyLevel(DefectType type) {
    switch (type) {
        case DefectType::TRAP: return -0.3 + distUniform(engine) * 0.6;
        case DefectType::VACANCY: return 0.0 + distUniform(engine) * 0.1;
        case DefectType::INTERSTITIAL: return 0.0;
        default: return 0.0;
    }
}

QuantumDefects DefectSimulator::generate(unsigned int seed) {
    engine.seed(seed);
    QuantumDefects defectList;

    double volume_cm3 = (volX * volY * volZ) * 1e-21; // nm³ → cm³
    unsigned int defectCount = static_cast<unsigned int>(density_cm3 * volume_cm3);

    for (unsigned int i = 0; i < defectCount; ++i) {
        DefectType dtype = randomDefectType();

        Defect d {
            dtype,
            "X", // Unknown or general atom
            randomPosition(volX),
            randomPosition(volY),
            randomPosition(volZ),
            randomEnergyLevel(dtype)
        };
        defectList.addDefect(d);
    }

    return defectList;
}
