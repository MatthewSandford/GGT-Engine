#pragma once

#include <json/json.h>
#include <fstream>
#include <string>

class JsonHandler
{
public:

	static Json::Value LoadJsonFromFile(std::string fileName);

private:

};
