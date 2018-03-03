#include "renderer.h"

void Renderer::Init()
{
	modelManager.LoadModels("assets/model_files.json");
	textureManager.LoadTextures("assets/texture_files.json");
}

void Renderer::Render()
{
    for (Entity* entity : entityVector)
    {
		entity->Draw();
    }
}

void Renderer::AddEntity(Entity* entity)
{
    entityVector.push_back(entity);
}
