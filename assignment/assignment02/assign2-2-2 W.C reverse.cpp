#include <gl/glew.h>
#include <gl/freeglut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <vector>
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

    // Set background color
    glClearColor(0, 0, 0, 1.0);
    // Clear buffer
    glClear(GL_COLOR_BUFFER_BIT);
    // Set viewport
    glViewport(0, 0, 300, 300);
    // Load the identity matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 1번: 원점을 중심으로 0.2 크기의 흰색 사각형 그리기
    DrawBox(points, vec3(1, 1, 1));

    mat4 translateMatrix2 = translate(mat4(1), vec3(0, 0.4, 0));
    mat4 rotateMatrix = rotate(mat4(1), radians(30.0f), vec3(0, 0, 1));
    mat4 translateMatrix1 = translate(mat4(1), vec3(0.3, 0, 0));

    // 4번: 로컬 좌표계에서 (0, 0.4)로 이동 후 초록색 사각형 그리기
    vector<vec4> translatedPoints4;
    for (const auto& point : points)
    {
        vec4 translatedPoint = translateMatrix2 * point;
        translatedPoints4.push_back(translatedPoint);
    }
    DrawBox(translatedPoints4, vec3(0, 1, 0));

    // 3번: 로컬 좌표계에서 z축을 중심으로 -30도 회전 후 파란색 사각형 그리기
    vector<vec4> rotatedPoints3;
    for (const auto& point : translatedPoints4)
    {
        vec4 rotatedPoint = rotateMatrix * point;
        rotatedPoints3.push_back(rotatedPoint);
    }
    DrawBox(rotatedPoints3, vec3(0, 0, 1));

    // 2번: 로컬 좌표계에서 (-0.3, 0)으로 이동 후 빨간색 사각형 그리기
    vector<vec4> translatedPoints2;
    for (const auto& point : rotatedPoints3)
    {
        vec4 translatedPoint = translateMatrix1 * point;
        translatedPoints2.push_back(translatedPoint);
    }
    DrawBox(translatedPoints2, vec3(1, 0, 0));

    // Send it to the buffer
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
