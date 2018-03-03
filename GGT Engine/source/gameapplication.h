#pragma once
#include "renderer.h"
#include "application.h"

class GameApplication : public Application
{
public:

	void Init();

private:

	Renderer renderer;
};