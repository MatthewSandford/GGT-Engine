#include "camera.h"

#include "SFML/OpenGL.hpp"
#include <gl/GL.h>
#include <gl/GLU.h>﻿

void Camera::Update()
{
	HandleKeyPress();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FOV, aspectRatio, nearValue, farValue);

	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);
}

void Camera::HandleKeyPress()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		position.x += 0.001;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		position.x -= 0.001;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.y += 0.001;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
	{
		position.y -= 0.001;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotation.x += 0.1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotation.x -= 0.1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		rotation.z += 0.1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		rotation.z -= 0.1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		focus = true;
	}
	else
	{
		focus = false;
	}
}