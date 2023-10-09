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
vec4 center(0.0f, 0.0f, 0.0f, 1.0f);

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
    float size = 0.1; // 반 간격을 0.1로 줄임
    points.push_back(vec4(center[0] - size, center[1] - size, 0, 1));
    points.push_back(vec4(center[0] - size, center[1] + size, 0, 1));
    points.push_back(vec4(center[0] + size, center[1] + size, 0, 1));
    points.push_back(vec4(center[0] + size, center[1] - size, 0, 1));

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

    // 2번: 로컬 좌표계에서 (0.3, 0)으로 이동 후 빨간색 사각형 그리기
    glTranslatef(0.3, 0, 0);
    DrawBox(points, vec3(1, 0, 0));

    // 3번: 로컬 좌표계에서 z축을 중심으로 30도 회전 후 파란색 사각형 그리기
    glRotatef(30.0f, 0, 0, 1);
    DrawBox(points, vec3(0, 0, 1));

    // 4번: 로컬 좌표계에서 (0, 0.4)로 이동 후 초록색 사각형 그리기
    glTranslatef(0, 0.4, 0);
    DrawBox(points, vec3(0, 1, 0));

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
