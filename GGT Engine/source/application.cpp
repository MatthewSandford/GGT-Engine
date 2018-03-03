#include <json/json.h>
#include "application.h"
#include <iostream>
#include <gl/GL.h>
#include <gl/GLU.h>﻿

Application::Application(Json::Value& config) : window({ config["window_size"]["width"].asUInt(), config["window_size"]["height"].asUInt() }, config["window_name"].asCString()),
												closing(false)
{
	window.setFramerateLimit(config["max_frame_rate"].asUInt());
}

void Application::Start()
{
	Init();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				closing = true;
			}
		}

		Update();
		Display();

		if (closing)
		{
			window.close();
		}
	}
}

void Application::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		Entity* entity = new Entity();
		entity->model = renderer.modelManager.modelMap["CUBE"];
		renderer.AddEntity(entity);
	}
}

void Application::Init()
{
	glClearColor(0.3f, 0.3f, 0.3f, 0.f);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 300.0f);
}

void Application::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	sf::Vector2u wsize = window.getSize();
	glViewport(0, 0, wsize.x, wsize.y);
	gluPerspective(60, (float)wsize.x / (float)wsize.y, 0.1f, 512.f);

	glPushMatrix();
	glTranslatef(0.f, 0.f, -5.f);

	renderer.Render();

	window.display();
}
