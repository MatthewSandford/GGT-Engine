#include "entity.h"

void Entity::Draw()
{
	glTranslatef(position.x, position.y, position.z);
	glBegin(GL_TRIANGLES);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureId);

	for (Face* face : model->faces)
	{
		for (uint16_t i = 0; i < face->vertexPositions.size(); ++i)
		{
			Vector3f& normal = face->vertexNormals[i];
			Vector3f& position = face->vertexPositions[i];

			glNormal3f(normal.x, normal.z, normal.y);
			glVertex3f(position.x, position.z, position.y);
		}
	}

	glEnd();
}
