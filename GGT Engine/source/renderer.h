#pragma once

#include "entity.h"
#include "modelmanager.h"
#include "texturemanager.h"
#include <vector>

class Renderer
{
public:

	ModelManger modelManager;
	TextureManager textureManager;

	Renderer() { Init(); }
	void Init();
    void Render();
    void AddEntity(Entity* entity);



private:

    std::vector<Entity*> entityVector;

};