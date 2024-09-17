#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
int Window_ID;
int Window_Width = 600;
int Window_Height = 400;
float X_Rot   = 0.45f;
float Y_Rot   = 0.0f;
float X_Speed = 0.0f;
float Y_Speed = 0.0125f;
float Z_Off =0.0f;
float xEye=0.0f;
float yEye=0.0f;
float zEye=5.0f;
void RenderScene(void){
   char buf[80];
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(xEye, yEye, zEye, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
   glTranslatef(0.0f, 0.0f, Z_Off);
   glRotatef(X_Rot,1.0f,0.0f,0.0f);
   glRotatef(Y_Rot,0.0f,1.0f,0.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glBegin(GL_QUADS);
   glColor3f(0.0f, 0.5f, 0.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(-1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(-1.0f, 1.0f, -1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(1.0f, 1.0f, -1.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(1.0f, -1.0f, -1.0f);
   glColor3f(0.5f, 0.0f, 0.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(1.0f, 1.0f, -1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(1.0f, -1.0f, 1.0f);
   glColor3f(0.0f, 1.0f, 0.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(-1.0f, -1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(1.0f, -1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(-1.0f, 1.0f, 1.0f);
   glColor3f(1.0f, 0.0f, 0.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(-1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(-1.0f, -1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(-1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(-1.0f, 1.0f, -1.0f);
   glColor3f(0.0f, 0.75f, 0.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(-1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(1.0f, 1.0f, 1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(1.0f, 1.0f, -1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(-1.0f, 1.0f, -1.0f);
   glTexCoord2f(0.005f, 0.005f); glVertex3f(-1.0f, -1.0f, 1.0f);
   glTexCoord2f(0.005f, 0.995f); glVertex3f(-1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.995f); glVertex3f(1.0f, -1.0f, -1.0f);
   glTexCoord2f(0.995f, 0.005f); glVertex3f(1.0f, -1.0f, 1.0f);
   glEnd();
   glTranslatef(3.0f,0.0f,0.0f);
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0, 1.0f);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glEnd();
   glTranslatef(-6.0f,0.0f,0.0f);
   GLUquadricObj *quad;
   quad=gluNewQuadric();
   glColor3f(0.0f,1.0f,0.0f);
   gluSphere(quad, 1, 32, 16);
   glTranslatef(3.0f, 2.0f, -1.0f);
   gluCylinder(quad, .5,.5,2,32,16);
   gluDeleteQuadric(quad);
   glutSwapBuffers();
   X_Rot+=X_Speed;
   Y_Rot+=Y_Speed;
}
void CallBackMyControlMouse(int button, int state, int Width, int Height){
   if(state==GLUT_DOWN && button==GLUT_RIGHT_BUTTON){
      xEye=5.0f;
      yEye=5.0f;
   }
   else if(state==GLUT_UP && button==GLUT_RIGHT_BUTTON){
      xEye=0.0f;
      yEye=0.0f;
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
   glutMainLoop();
   return 1;
}

