#include<gl/glew.h>
#include<gl/freeglut.h>
#include<GL/GL.h>
#include<GL/GLU.h>
#include<GL/glut.h>
#include<vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

vector<vec4> points; 

void DrawBox(vector<vec4> points, vec3 color)
{
	

	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_LINES); 

	for (int i = 0; i < 3; i++)
	{
		glVertex3f(points[i][0], points[i][1], 0);
		glVertex3f(points[i + 1][0], points[i + 1][1], 0);
	}
	glVertex3f(points[3][0], points[3][1], 0);
	glVertex3f(points[0][0], points[0][1], 0);

	glEnd();
}

void ViewportTest()
{
	float size = 0.2;
	points.push_back(vec4(-size / 2, -size / 2, 0, 1));
	points.push_back(vec4(-size / 2, size / 2, 0, 1));
	points.push_back(vec4(size / 2, size / 2, 0, 1));
	points.push_back(vec4(size / 2, -size / 2, 0, 1));

	//set background color
	glClearColor(0, 0, 0, 1.0);
	//clear buffer
	glClear(GL_COLOR_BUFFER_BIT);
	//set viewport
	glViewport(0, 0, 300, 300);
	//draw square

	 //1번
	DrawBox(points, vec3(1, 1, 1));

	//2번 : x 0.3 평행이동
	mat4 translateMatrix = translate(mat4(1), vec3(0.3, 0, 0));
	vector<vec4> translatedPoints;
	for (const auto& point : points)
	{
		vec4 translatedPoint = translateMatrix * point;
		translatedPoints.push_back(translatedPoint);
	}
	DrawBox(translatedPoints, vec3(1, 0, 0));


	//3번 : 30도 회전
	mat4 rotateMatrix = rotate(mat4(1), radians(30.0f), vec3(0, 0, 1));
	vector<vec4> rotatedPoints;
	for (const auto& point : points)
	{
		vec4 rotatedPoint = rotateMatrix * point;
		rotatedPoints.push_back(rotatedPoint);
	}
	DrawBox(rotatedPoints, vec3(0, 0, 1));

	//4번 : y 0.4평행이동
	mat4 translateMatrix2 = translate(mat4(1), vec3(0, 0.4, 0));
	vector<vec4> translatedPoints2;
	for (const auto& point : points)
	{
		vec4 translatedPoint = translateMatrix2 * point;
		translatedPoints2.push_back(translatedPoint);
	}
	DrawBox(translatedPoints2, vec3(0, 1, 0));
	//send it to buffer
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("182947");
	glutDisplayFunc(ViewportTest);
	glutMainLoop();
	return 0;
}
