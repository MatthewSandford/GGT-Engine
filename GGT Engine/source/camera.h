#pragma once

#include <SFML/Graphics.hpp>
#include "matrix.h"

class Camera
{
public:

	Camera(int16_t screenWidth, int16_t screenHeight) : FOV(60.0f), 
														nearValue(0.1f), 
														farValue(500.0f), 
														focus(false),
														position(0,0,-5)
														{ aspectRatio = screenWidth / float(screenHeight); };

	float FOV;
	float nearValue;
	float farValue;
	float aspectRatio;

	void Update();
	void HandleKeyPress();

	bool focus; 

private:

	Camera();
	Vector3f position;
	Vector3f rotation;

};