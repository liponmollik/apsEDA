#include "GrapheneMaterial.h"

int main() {
    GrapheneMaterial graphene(true); // doped
    graphene.setDefectDensity(1e10); // 10^10 atoms/cm²

    graphene.simulateElectronTransport();

    return 0;
}
