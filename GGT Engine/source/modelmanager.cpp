#include "modelmanager.h"
#include "jsonhandler.h"

void ModelManger::LoadModels(std::string inputFile)
{
    Json::Value root = JsonHandler::LoadJsonFromFile(inputFile);

    for (Json::Value& item : root["models"])
    {
        AddModel(item["name"].asString(), item["path"].asString());
    }
}

void ModelManger::AddModel(std::string modelName, std::string fileName)
{
    Model* model = new Model(fileName);
    modelMap.insert(std::pair<std::string, Model*>(modelName, model));
}
