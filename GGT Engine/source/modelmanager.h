#pragma once

#include "model.h"
#include <unordered_map>

class ModelManger
{
public:

    void LoadModels(std::string inputFile);
    void AddModel(std::string modelName, std::string fileName);
    std::unordered_map<std::string, Model*> modelMap;

};