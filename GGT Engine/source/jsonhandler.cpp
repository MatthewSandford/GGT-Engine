#include "jsonhandler.h"

Json::Value JsonHandler::LoadJsonFromFile(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	Json::Value root;
	file >> root;
	return root;
}
