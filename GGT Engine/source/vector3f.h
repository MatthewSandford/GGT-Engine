#pragma once

#include "SFML/OpenGL.hpp"

class Vector3f 
{
public:

	Vector3f() : x(0), y(0), z(0) {};
	Vector3f(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {}

	Vector3f	operator-(Vector3f rhs);
	Vector3f	operator+(Vector3f rhs);
	Vector3f	operator/(GLfloat rhs);
	Vector3f	operator*(GLfloat rhs);
	GLfloat		Length();

	static Vector3f		Normalise(Vector3f v);
	static Vector3f		Cross(Vector3f v1, Vector3f v2);
	static GLfloat		Dot(Vector3f v1, Vector3f v2);

	GLfloat x, y, z;

private:


};
