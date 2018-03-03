#include "matrix.h"
#include "math.h"
#include "matrix.h"

void Matrix4::ToIdentity()
{
	matrix[0][0] = 1.0;	matrix[1][0] = 0.0;	matrix[2][0] = 0.0;	matrix[3][0] = 0.0;
	matrix[0][1] = 0.0;	matrix[1][1] = 1.0;	matrix[2][1] = 0.0;	matrix[3][1] = 0.0;
	matrix[0][2] = 0.0;	matrix[1][2] = 0.0;	matrix[2][2] = 1.0;	matrix[3][2] = 0.0;
	matrix[0][3] = 0.0;	matrix[1][3] = 0.0;	matrix[2][3] = 0.0;	matrix[3][3] = 1.0;
}

void Matrix4::Translate(GLfloat x, GLfloat y, GLfloat z)
{
	matrix[0][0] = x;
	matrix[1][1] = y;
	matrix[2][2] = z;
}

void Matrix4::Rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat length = sqrt(x*x + y * y + z * z);
	x /= length;
	y /= length;
	z /= length;

	GLfloat rads = angle * (2.f * M_PI) / 360.f;

	GLfloat c = cos(rads);
	GLfloat s = sin(rads);

	Matrix4 rotateMatrix;
	rotateMatrix.matrix[0][0] = x * x*(1 - c) + c;		rotateMatrix.matrix[1][0] = x * y*(1 - c) - z * s;		rotateMatrix.matrix[2][0] = x * z*(1 - c) + y * s;		rotateMatrix.matrix[3][0] = 0;
	rotateMatrix.matrix[0][1] = y * x*(1 - c) + z * s;	rotateMatrix.matrix[1][1] = y * y*(1 - c) + c;			rotateMatrix.matrix[2][1] = y * z*(1 - c) - x * s;		rotateMatrix.matrix[3][1] = 0;
	rotateMatrix.matrix[0][2] = x * z*(1 - c) - y * s;	rotateMatrix.matrix[1][2] = y * z*(1 - c) + x * s;		rotateMatrix.matrix[2][2] = z * z*(1 - c) + c;			rotateMatrix.matrix[3][2] = 0;
	rotateMatrix.matrix[0][3] = 0;						rotateMatrix.matrix[1][3] = 0;							rotateMatrix.matrix[2][3] = 0;							rotateMatrix.matrix[3][3] = 1;
 	
	Set(Multiply(*this, rotateMatrix));
}

void Matrix4::Scale(GLfloat x, GLfloat y, GLfloat z)
{
	matrix[0][0] *= x;
	matrix[1][1] *= y;
	matrix[2][2] *= z;
}

Matrix4 Matrix4::Multiply(Matrix4 & lhs, Matrix4 & rhs)
{
	Matrix4 out;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			out.matrix[col][row] =
				lhs.matrix[0][row] * rhs.matrix[col][0] +
				lhs.matrix[1][row] * rhs.matrix[col][1] +
				lhs.matrix[2][row] * rhs.matrix[col][2] +
				lhs.matrix[3][row] * rhs.matrix[col][3];
		}
	}
	return out;
}

void Matrix4::Set(Matrix4 inMatrix)
{
	matrix[0][0] = inMatrix.matrix[0][0];	matrix[1][0] = inMatrix.matrix[1][0];	matrix[2][0] = inMatrix.matrix[2][0];	matrix[3][0] = inMatrix.matrix[3][0];
	matrix[0][1] = inMatrix.matrix[0][1];	matrix[1][1] = inMatrix.matrix[1][1];	matrix[2][1] = inMatrix.matrix[2][1];	matrix[3][1] = inMatrix.matrix[3][1];
	matrix[0][2] = inMatrix.matrix[0][2];	matrix[1][2] = inMatrix.matrix[1][2];   matrix[2][2] = inMatrix.matrix[2][2];	matrix[3][2] = inMatrix.matrix[3][2];
	matrix[0][3] = inMatrix.matrix[0][3];	matrix[1][3] = inMatrix.matrix[1][3];	matrix[2][3] = inMatrix.matrix[2][3];	matrix[3][3] = inMatrix.matrix[3][3];
}

void Matrix4::Focus(Vector3f center)
{
	Vector3f eye(matrix[0][0], matrix[1][1], matrix[2][2]);
	Vector3f f = Vector3f::Normalise(center - eye);
	Vector3f u = Vector3f::Normalise(Vector3f(0, 1, 0));
	Vector3f s = Vector3f::Normalise(Vector3f::Cross(f, u));
	u = Vector3f::Cross(s, f);

	//Row 0
	matrix[0][0] = s.x;
	matrix[1][0] = s.y;
	matrix[2][0] = s.z;
	matrix[3][0] = -Vector3f::Dot(s, eye);

	//Row 1	
	matrix[0][1] = u.x;
	matrix[1][1] = u.y;
	matrix[2][1] = u.z;
	matrix[3][1] = -Vector3f::Dot(u, eye);

	//Row 2
	matrix[0][2] = -f.x;
	matrix[1][2] = -f.y;
	matrix[2][2] = -f.z;
	matrix[3][2] = Vector3f::Dot(f, eye);

	//Row 3
	matrix[0][3] = 0.0;
	matrix[1][3] = 0.0;
	matrix[2][3] = 0.0;
	matrix[3][3] = 1.0;
}