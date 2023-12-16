#define _CRT_SECURE_NO_WARNINGS
#include <GL/glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <math.h>
#include <thread>
#include <cmath>
#include <stdlib.h>
#include "glaux.h"
#pragma comment(lib, "glaux.lib")

int maze[30][30] = {
{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
{1, 2, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
{1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
{1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
{1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
{1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1},
{1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
{1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// ���α׷� ���� �ð��� �����ϴ� ���� ����

#define FPS 60 // 1000/FPS�� Ÿ�̸� �ݹ��Ұ���
#define TO_RADIANS 3.14/180.0

GLuint g_textureID1 = -1; //�ؽ���1 : Data/wall
GLuint g_textureID2 = -1; //�ؽ���2 : Data/Lawn
GLuint g_textureID3 = -1; //�ؽ���3 : Data/Sky

const int width = 1400; //������ â �ʺ�,����
const int height = 600;


float pitch = 0.0, yaw = 0.0;
float camX = 1, camZ = 1; //ī�޶� �ʱ���ġ(������)
float cameraSpeed = 12.0;


bool Forward = false;
bool Backward = false;
bool Left = false;
bool Right = false;

float camSpeed = 30.0; //�̼�

float teapotRotation = 5.0; // Ƽ�� ȸ�� �ӵ�
float teapotVerticalMotion = 0.0;
float teopotRotateAngle = 1;
bool teapotMovingUp = true;

//Ƽ���� ��ġ ���� -> Ƽ�̰� �浹 : �̺�Ʈ ����
float teapotX = 0.0;
float teapotY = 0.0;
float teapotZ = 0.0;


void loadTexture(void) {
    AUX_RGBImageRec* pTextureImage1 = auxDIBImageLoad("C:/Users/kcw01/source/repos/Project11/Project11/Data/Wall.bmp");

    if (pTextureImage1 != NULL) {
        glGenTextures(1, &g_textureID1);
        glBindTexture(GL_TEXTURE_2D, g_textureID1);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage1->sizeX, pTextureImage1->sizeY, 0,
            GL_RGB, GL_UNSIGNED_BYTE, pTextureImage1->data);
    }

    AUX_RGBImageRec* pTextureImage2 = auxDIBImageLoad("C:/Users/kcw01/source/repos/Project11/Project11/Data/Lawn.bmp");
    if (pTextureImage2 != NULL) {
        glGenTextures(1, &g_textureID2);
        glBindTexture(GL_TEXTURE_2D, g_textureID2);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage2->sizeX, pTextureImage2->sizeY, 0,
            GL_RGB, GL_UNSIGNED_BYTE, pTextureImage2->data);
    }

    AUX_RGBImageRec* pTextureImage3 = auxDIBImageLoad("C:/Users/kcw01/source/repos/Project11/Project11/Data/Sky.bmp");
    if (pTextureImage3 != NULL) {
        glGenTextures(1, &g_textureID3);
        glBindTexture(GL_TEXTURE_2D, g_textureID3);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage3->sizeX, pTextureImage3->sizeY, 0,
            GL_RGB, GL_UNSIGNED_BYTE, pTextureImage3->data);
    }

    if (pTextureImage1) {
        if (pTextureImage1->data)
            free(pTextureImage1->data);

        free(pTextureImage1);
    }
    if (pTextureImage2) {
        if (pTextureImage2->data)
            free(pTextureImage2->data);

        free(pTextureImage2);
    }
    if (pTextureImage3) {
        if (pTextureImage3->data)
            free(pTextureImage3->data);

        free(pTextureImage3);
    }
}

void init() //���콺 Ŀ���� ������ â�� ����/2, �ʺ�/2 ������ ��ġ
{
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void camera() {
    if (Forward)
    {
        camX += cos((yaw + 90) * TO_RADIANS) / camSpeed;
        camZ -= sin((yaw + 90) * TO_RADIANS) / camSpeed;
    }
    if (Backward)
    {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) / camSpeed;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) / camSpeed;
    }
    if (Left)
    {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) / camSpeed *0.5;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) / camSpeed * 0.5;
    }
    if (Right)
    {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) / camSpeed * 0.5;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) / camSpeed * 0.5;
    }
    if (pitch >= 80)//��
        pitch = 80;
    if (pitch <= -20)//��
        pitch = -20;
    
    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);
    glTranslatef(-camX, 0.0, -camZ);
    
}

void passive_motion(int x, int y)
{
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;

    yaw += (float)dev_x / cameraSpeed;
    pitch += (float)dev_y / cameraSpeed;
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        Forward = true;
        break;
    case 'A':
    case 'a':
        Left = true;
        break;
    case 'S':
    case 's':
        Backward = true;
        break;
    case 'D':
    case 'd':
        Right = true;
        break;

    case '[':
        camSpeed += 2.0;
        break;
    case ']':
        camSpeed -= 2.0;
        break;
    case '=':
        camSpeed = 40;
        break;
    case '<':
        cameraSpeed += 0.5;
        break;
    case '>':
        cameraSpeed -= 0.5;
        break;
    case '/':
        cameraSpeed = 15.0;
        break; 
    }
}
void keyboard_up(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        Forward = false;
        break;
    case 'A':
    case 'a':
        Left = false;
        break;
    case 'S':
    case 's':
        Backward = false;
        break;
    case 'D':
    case 'd':
        Right = false;
        break;

    }
}

void reshape(int w, int h) {
    
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 16.0/10.0, 0.1, 200);
    glMatrixMode(GL_MODELVIEW);
    
}

void draw_block() {
    glColor3f(1, 1, 1);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_textureID1);

    // Front Face
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, 0.5);
    glEnd();

    // Back Face
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
    glEnd();

    // Top Face
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
    glEnd();

    // Bottom Face
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 1.0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(0.0, 0.0); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    // Right Face
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0.0, 0.0); glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    // Left Face
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    glPopMatrix();
}

void drawTeapot(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y + teapotVerticalMotion, z);
    glRotatef(teopotRotateAngle, 0, 1, 0);
    glutSolidTeapot(0.25);  // teapot ũ��
    glPopMatrix();
}


void teapottimer(int) {
    // Ƽ���� ���Ʒ� ������ ������Ʈ
    if (teapotMovingUp) {
        teapotVerticalMotion += 0.005;
        if (teapotVerticalMotion >= 0.15) {
            teapotMovingUp = false;
        }
    }
    else {
        teapotVerticalMotion -= 0.005;
        if (teapotVerticalMotion <= -0.1) {
            teapotMovingUp = true;
        }
    }
    teopotRotateAngle += 1;
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, teapottimer, 0);
}

void drawsky() {
    // �ϴ� �׸���
    glPushMatrix();
    glColor3f(1, 1, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_textureID3);
    glBegin(GL_QUADS);
    //����
    glTexCoord2f(0.0, 0.0); glVertex3f(100,50,-100);// ���� ���
    glTexCoord2f(0.0, 1.0); glVertex3f(100,50,100);// ���� �ϴ�
    glTexCoord2f(1.0, 1.0); glVertex3f(-100,50,100);// ���� �ϴ�
    glTexCoord2f(1.0, 0.0); glVertex3f(-100,50,-100);// ���� ���
    //�����ʸ�
    glTexCoord2f(0.0, 0.0); glVertex3f(100,50,-100);// ���� ���
    glTexCoord2f(0.0, 1.0); glVertex3f(100,-0.5,-100);// ���� �ϴ�
    glTexCoord2f(1.0, 1.0); glVertex3f(-100,-0.5,-100);// ���� �ϴ�
    glTexCoord2f(1.0, 0.0); glVertex3f(-100,50,-100);// ���� ���
    //���ʸ�
    glTexCoord2f(0.0, 0.0); glVertex3f(100, 50, 100);// ���� ���
    glTexCoord2f(0.0, 1.0); glVertex3f(100, -0.5, 100);// ���� �ϴ�
    glTexCoord2f(1.0, 1.0); glVertex3f(-100, -0.5, 100);// ���� �ϴ�
    glTexCoord2f(1.0, 0.0); glVertex3f(-100, 50, 100);// ���� ���

    //���ʸ�
    glTexCoord2f(0.0, 0.0); glVertex3f(-100, 50, -100);// ���� ���
    glTexCoord2f(0.0, 1.0); glVertex3f(-100, 50, 100);// ���� �ϴ�
    glTexCoord2f(1.0, 1.0); glVertex3f(-100, -0.5, 100);// ���� �ϴ�
    glTexCoord2f(1.0, 0.0); glVertex3f(-100, -0.5, -100);// ���� ���

    //���ʸ�
    glTexCoord2f(0.0, 0.0); glVertex3f(100, 50, -100);// ���� ���
    glTexCoord2f(0.0, 1.0); glVertex3f(100, 50, 100);// ���� �ϴ�
    glTexCoord2f(1.0, 1.0); glVertex3f(100, -0.5, 100);// ���� �ϴ�
    glTexCoord2f(1.0, 0.0); glVertex3f(100, 0.5, -100);// ���� ���

    glEnd();

    glPopMatrix();
}

void drawground() {
    // �ٴ� �׸���
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_textureID2);
    glBegin(GL_QUADS);
    for (int i = -10; i < 10; i++) {
        for (int j = -10; j < 10; j++) {
            glTexCoord2f(0.0, 0.0); glVertex3f(i * 30, -0.5, j * 30);                 // ���� ���
            glTexCoord2f(0.0, 1.0); glVertex3f(i * 30, -0.5, (j + 1) * 30);          // ���� �ϴ�
            glTexCoord2f(1.0, 1.0); glVertex3f((i + 1) * 30, -0.5, (j + 1) * 30);    // ���� �ϴ�
            glTexCoord2f(1.0, 0.0); glVertex3f((i + 1) * 30, -0.5, j * 30);          // ���� ���
        }
    }
    glEnd();
    glPopMatrix();
}

void drawMaze() { //�̷� �׸��� + �ؽ���

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (maze[i][j] == 1) { //��
                glPushMatrix();
                glTranslatef(-i, 0.0, j);
                draw_block();
                glPopMatrix();

            }
            else if (maze[i][j] == 2) { //������
                glColor3d(1, 0, 0);
                glPushMatrix();
                teapotX = -i; //Ƽ�� ��ġ ����
                teapotY = 0.0;
                teapotZ = j;
                drawTeapot(teapotX, teapotY, teapotZ);
                glPopMatrix();
            }
            else { //�����
                
            }
            glPopMatrix();
        }
    }
    drawsky();
    drawground();
}

// �浹 ���� �Լ�
bool checkCollision(double pointX, double pointY, double pointZ, double teapotX, double teapotY, double teapotZ, double collisionDistance) {
    // y ��ǥ�� �����ϰ� x�� z ��ǥ���� ���
    double distanceSquared = (pointX - teapotX) * (pointX - teapotX) + (pointZ - teapotZ) * (pointZ - teapotZ);

    // �浹 ���θ� �Ǵ�
    return distanceSquared <= (collisionDistance * collisionDistance);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glViewport(width / 2 - 100, 0, 800, height); //������ ����Ʈ
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  // �𵨺� ��� �ʱ�ȭ
    camera();
    drawMaze();

    glViewport(0, 0, height, height);//���� ����Ʈ
    glLoadIdentity();  // �𵨺� ��� �ʱ�ȭ
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(
        -15, 25, 15,
        -15, 0, 15,
        1, 0, 0
    );

    drawMaze();
    // ���� ����Ʈ�� �� �׸���
    glPointSize(8.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(camX, 0.0f, camZ); // ���ϴ� ��ǥ�� �� ���
    glEnd();

    if (checkCollision(teapotX, teapotY, teapotZ, camX, 0.0f, camZ, 0.3)) {
        std::this_thread::sleep_for(std::chrono::seconds(3)); //3�� ���
        exit(0);
    }
    glutSwapBuffers();
}



void timer(int)
{

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);  // â ũ��
    glutCreateWindow("182947 ��â��");

    glEnable(GL_DEPTH_TEST);



    init();
    loadTexture();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, teapottimer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();
    
    

    return 0;
}