#pragma once

#include <memory>
#include <string>
#include <map>
#include <vector>

#include "BaseMaterial.h"

class MaterialFactory {
public:
    static std::shared_ptr<BaseMaterial> create(const std::string& type, const std::map<std::string, double>& params);
};
