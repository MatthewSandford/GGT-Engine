#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>

class Face
{
public:

	std::vector<sf::Vector3f> vertexPositions;
	std::vector<sf::Vector3f> vertexNormals;
	std::vector<sf::Vector2f> vertexTexcoords;

};

class FaceData
{
public:

    std::vector<int> vertexPositionsIndex;
    std::vector<int> vertexNormalsIndex;
    std::vector<int> vertexTexcoordsIndex;
};

class Model
{
public:

    Model(std::string fileName);
    void LoadModel(std::string fileName);

    std::vector<Face*> faces;
};