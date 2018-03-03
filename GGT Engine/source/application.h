#pragma once

#include "camera.h"
#include "renderer.h"

class Application
{
public:

	Application(Json::Value& config);

	void Start();
	void Init();
	void Update();
	void Display();

	bool closing;

private:

	Camera camera; 
	sf::RenderWindow window;
    Renderer renderer;
};