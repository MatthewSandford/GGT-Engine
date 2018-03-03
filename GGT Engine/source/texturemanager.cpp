#include "texturemanager.h"

#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include "jsonhandler.h"

void TextureManager::LoadTextures(std::string inputFile)
{
    Json::Value root = JsonHandler::LoadJsonFromFile(inputFile);

    for (Json::Value& item : root["models"])
    {
        if (!LoadTexture(item["name"].asString(), item["path"].asString()))
        {
            std::cout << "Failed to load texture: " << item["path"].asString() << std::endl;
        }
        else
        {
            std::cout << "Loaded texture: " << item["path"].asString() << std::endl;
        }
    }
}

bool TextureManager::LoadTexture(std::string textureName, std::string inputFile)
{
    sf::Image texture;
    if (!texture.loadFromFile(inputFile))
    {
        return false;
    }

    glGenTextures(1, &textureMap[textureName]);
    glBindTexture(GL_TEXTURE_2D, textureMap[textureName]);
    sf::Vector2u textureSize = texture.getSize();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,textureSize.x, textureSize.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    return true;
}
