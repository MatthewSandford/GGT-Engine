#pragma once

#include "SFML/OpenGL.hpp"
#include "jsonhandler.h"

#include <unordered_map>

class TextureManager
{
public:

    void LoadTextures(std::string inputFile);
    bool LoadTexture(std::string textureName, std::string inputFile);

    std::unordered_map<std::string, GLuint> textureMap;

};