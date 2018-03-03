#pragma once

#include "model.h"
#include "SFML/OpenGL.hpp"

class Entity 
{
public:

	Entity() {};
    Model *model;
	GLuint textureId;

	void draw();

private:

};