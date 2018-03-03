#pragma once
#define _USE_MATH_DEFINES

#include "SFML/OpenGL.hpp"
#include "vector3f.h"

class Matrix4
{
public:

	Matrix4() { ToIdentity(); };

	void ToIdentity();
	void Translate(GLfloat x, GLfloat y, GLfloat z);
	void Rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	void Scale(GLfloat x, GLfloat y, GLfloat z);
	void Set(Matrix4 matrix);
	void Focus(Vector3f center);
	Matrix4 Multiply(Matrix4 & lhs, Matrix4 & rhs);

private:

	GLfloat matrix[4][4];

};
