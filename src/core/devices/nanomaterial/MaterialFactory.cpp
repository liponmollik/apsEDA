#include "MaterialFactory.h"
#include "GrapheneMaterial.h"
#include "MoS2Material.h"
#include "CNTMaterial.h"
#include <iostream>

std::shared_ptr<BaseMaterial> MaterialFactory::create(const std::string& type, const std::map<std::string, double>& params) {
    if (type == "graphene") {
        bool doped = params.count("doped") ? static_cast<bool>(params.at("doped")) : false;
        auto mat = std::make_shared<GrapheneMaterial>(doped);
        if (params.count("defect_density"))
            mat->setDefectDensity(params.at("defect_density"));
        return mat;
    }

    if (type == "mos2") {
        unsigned int layers = params.count("layers") ? static_cast<unsigned int>(params.at("layers")) : 1;
        auto mat = std::make_shared<MoS2Material>(layers);
        if (params.count("strain"))
            mat->setStrainPercent(params.at("strain"));
        return mat;
    }

    if (type == "cnt") {
        unsigned int n = static_cast<unsigned int>(params.at("n"));
        unsigned int m = static_cast<unsigned int>(params.at("m"));
        double len = params.count("length") ? params.at("length") : 100.0;
        return std::make_shared<CNTMaterial>(n, m, len);
    }

    std::cerr << "[MaterialFactory] Unknown material type: " << type << "\n";
    return nullptr;
}
