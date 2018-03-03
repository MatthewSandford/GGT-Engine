#pragma once

#include "model.h"
#include "SFML/OpenGL.hpp"

class Entity 
{
public:

	Entity(): position(0,0,0) {};
    Model *model;
	GLuint textureId;

	Vector3f position;

	void Draw();

private:

};