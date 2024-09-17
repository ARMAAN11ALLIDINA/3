#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
int Window_ID;
int Window_Width = 600;
int Window_Height = 400;
float X_Rot   = 0.9f;
float Y_Rot   = 0.0f;
float X_Speed = 0.0f;
float Y_Speed = 0.05f;
float Z_Off   =-5.0f;
static void PrintString(void *font, char *str){
   int i,len=strlen(str);
   for(i=0;i < len; i++)
  	glutBitmapCharacter(font,*str++);
}
void RenderScene(void){
   char buf[80];
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0f, 0.0f, Z_Off);
   glRotatef(X_Rot,1.0f,0.0f,0.0f);
   glRotatef(Y_Rot,0.0f,1.0f,0.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glBegin(GL_QUADS);
   glNormal3f(0.0f, 0.0f, -1.0f);
   glColor4f(0.9, 0.2, 0.2, 1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(-1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(-1.0f, 1.0f, -1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(1.0f, 1.0f, -1.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(1.0f, -1.0f, -1.0f);
   glNormal3f(1.0f, 0.0f, 0.0f);
   glColor4f(0.2, 0.9, 0.2, 1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(1.0f, 1.0f, -1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(1.0f, -1.0f, 1.0f);
   glNormal3f(0.0f, 0.0f, 1.0f);
   glColor4f(0.9, 0.2, 0.2, 1.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(-1.0f, -1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(1.0f, -1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(-1.0f, 1.0f, 1.0f);
   glNormal3f(1.0f, 0.0f, 0.0f);
   glColor4f(0.2, 0.9, 0.2, 1.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(-1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(-1.0f, -1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(-1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(-1.0f, 1.0f, -1.0f);
   glNormal3f(0.0f, 0.0f, -1.0f);
   glColor4f(0.0, 0.0, 0.0, 1.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(-1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(1.0f, 1.0f, -1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(-1.0f, 1.0f, -1.0f);
   glNormal3f(0.0f, 0.0f, -1.0f);
   glColor4f(0.0, 0.0, 0.0, 1.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(-1.0f, -1.0f, 1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(-1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(1.0f, -1.0f, 1.0f);
   glEnd();
   glLoadIdentity();
   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   glOrtho(0, Window_Width, 0, Window_Height, -1.0, 1.0);
   glColor4f(0.6, 1.0, 0.6, 1.00);
   sprintf(buf, "%s","cube");
   glRasterPos2i(2, 2);
   PrintString(GLUT_BITMAP_HELVETICA_12, buf);
   glTranslatef(6.0f, Window_Height -14, 0.0f);
   glPopMatrix();
   glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
   glutSwapBuffers();
   X_Rot+=X_Speed;
   Y_Rot+=Y_Speed;
}
void MoveBackward(){
   Z_Off -= 0.05;
   glutPostRedisplay();
}
void MoveForward(){
   Z_Off += 0.05;
   glutPostRedisplay();
}
void CallBackMyControlMouse(int button, int state, int Width, int Height){
   if(state==GLUT_DOWN && button==GLUT_RIGHT_BUTTON){
  	glutIdleFunc(MoveForward);
   }
   else if(state==GLUT_DOWN && button==GLUT_LEFT_BUTTON){
  	glutIdleFunc(MoveBackward);
   }
}
void ResizeScene(int Width, int Height){
   if (Height == 0)
  	Height = 1;
   glViewport(0, 0, Width, Height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
   glMatrixMode(GL_MODELVIEW);
   Window_Width  = Width;
   Window_Height = Height;
}
void MyInit(int Width, int Height) {
   glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
   glClearDepth(1.0);
   glDepthFunc(GL_LESS);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);
   ResizeScene(Width,Height);
}
int main(int argc, char **argv){
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowSize(Window_Width, Window_Height);
   Window_ID = glutCreateWindow("cube");
   glutDisplayFunc(&RenderScene);
   glutIdleFunc(&RenderScene);
   glutReshapeFunc(&ResizeScene);
   glutMouseFunc(&CallBackMyControlMouse);
   MyInit(Window_Width, Window_Height);
   printf("\n%s\n", "cube");
   glutMainLoop();
   return 1;
}

