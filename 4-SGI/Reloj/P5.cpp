/*
*Alumno: Victoria Beltrán Domínguez
*Título: Reloj3D
*
*/

#define PROYECTO "Reloj3D"
#include <iostream>
#include <sstream>
#include <GL\freeglut.h>
#include <Utilidades.h>
#include <ctime>

using namespace std;
string hora;
//FPS maximos
static int tasaFPS = 60;
//Variable temporal
static float alfa, alsecs, almin, alhora;
static float eyex = 0;
static float eyey = 0;
static float eyez = 4;
static float omegasegundos, omegahora, omegaminutos = 0;
GLuint rayaCorta, rayaLarga, rayas, petalo, corola, triangulo, manecilla;

void init() {

	glEnable(GL_DEPTH_TEST);

	/*Definimos las rayas largas del reloj*/
	rayaLarga = glGenLists(1);
	glNewList(rayaLarga, GL_COMPILE);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0.0, 0.3);
	glEnd();
	glEndList();

	/*Definimos las rayas cortas del reloj*/
	rayaCorta = glGenLists(1);
	glNewList(rayaCorta, GL_COMPILE);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0.0, 0.1);
	glEnd();
	glEndList();

	//Construye el petalo blanco
	petalo = glGenLists(1);
	glNewList(petalo, GL_COMPILE);
	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1, 1, 0.8);


	glScalef(0.15, 0.5, 0.15);
	glutSolidSphere(1, 20, 10);
	glPopMatrix();

	glPopAttrib();
	glEndList();

	//Construye la corola amarilla con 12 petalos
	corola = glGenLists(1);
	glNewList(corola, GL_COMPILE);
	glPushAttrib(GL_CURRENT_BIT);

	for (int i = 0; i < 12; i++) {
		glPushMatrix();
		glRotatef(i * 30, 0, 0, 1);
		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.7, 0.7, 0.7);

		glCallList(petalo);
	}
	glColor3f(1, 1, 0.4);
	glPushMatrix();
	glScalef(0.3, 0.3, 0.3);
	glutSolidSphere(1, 20, 10);
	glPopMatrix();
	glPopAttrib();
	glEndList();

	/*Definimos las posiciones de cada una de las rayas*/
	rayas = glGenLists(1);

	glNewList(rayas, GL_COMPILE);

	for (int i = 0; i < 12; i++) {
		if (i == 0 | i == 3 | i == 6 | i == 9) {

			glPushMatrix();
			glRotatef(i * 30, 0, 0, 1);
			glTranslatef(0, 0.6, 0.0);
			glCallList(rayaLarga);
			glPopMatrix();

		}
		else {

			glPushMatrix();
			glRotatef(i * 30, 0, 0, 1);
			glTranslatef(0, 0.7, 0.0);
			glCallList(rayaCorta);
			glPopMatrix();

		}

	}

	glEnd();
	glEndList();

	/*Triangulo*/
	triangulo = glGenLists(1);
	glNewList(triangulo, GL_COMPILE);
	glLineWidth(3);
	glBegin(GL_TRIANGLES);

	glColor3f(0.9, 0.8, 0.8);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(0, 1);

	glEnd();
	glEndList();

	/*Manecilla compuesta de triangulo y raya*/
	manecilla = glGenLists(1);
	glNewList(manecilla, GL_COMPILE);
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glTranslatef(0, 5, 0);
	glCallList(triangulo);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9, 0.8, 0.8);
	glScalef(0, 1.5, 0);
	glCallList(rayaLarga);
	glPopMatrix();


	glEnd();
	glEndList();

}


void display() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Situar la camara
	//punto donde me quiero situar, punto donde quiero mirar desde ahí, eje de rotación de la camara(?)
	
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);

	//Manecilla segundos
	glPushMatrix();
	glColor3f(1, 0, 0);
	glScalef(2.2, 2.2, 1);
	glRotatef(-alsecs, 0, 0, 1);
	glCallList(rayaLarga);
	glPopMatrix();

	//Manecilla minutos
	glPushMatrix();
	glTranslatef(0, 0, -0.0001);
	glRotatef(-almin, 0, 0, 1);
	glCallList(manecilla);
	glPopMatrix();

	//Manecilla hora
	glPushMatrix();
	glTranslatef(0, 0, -0.0002);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(-alhora, 0, 0, 1);
	glCallList(manecilla);
	glPopMatrix();


	//Flor en el centro
	glPushMatrix();
	glTranslatef(0, 0, -0.0003);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(-alfa, 0, 0, 1);
	glCallList(corola);
	glPopMatrix();

	//Probando raya
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 0, -0.0003);
	glCallList(rayas);
	glPopMatrix();

	/*Cilindro del arriba*/
	glPushMatrix();
	glTranslatef(0, 0, -0.0004);
	glColor3f(0.1, 0.1, 0.1);
	glutSolidCylinder(0.9, 0, 50, 50);
	glPopMatrix();

	/*Cilindro del fondo*/
	glPushMatrix();
	glTranslatef(0, 0, -0.0005);
	glColor3f(0.9, 0.8, 0.8);
	glutSolidCylinder(1, 0, 50, 50);
	glPopMatrix();


	//Intercambia el back buffer por el front buffer  haciendo así un flush
	glutSwapBuffers();

}
void reshape(GLint w, GLint h)
{
	float razonAspecto = float(w) / h;
	//Definir marco de dibujo
	glViewport(0, 0, w, h);

	//Construir camara propia
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float angulo = 1 / (sqrt(eyex*eyex + eyey * eyey + eyez * eyez));

	//Camara perspectiva
	gluPerspective(asin(angulo) * 360 / PI, razonAspecto, 100, 0);

}
void update()
{
	alfa += 1;
	time_t hora;
	time(&hora);
	struct tm horaActual;
	localtime_s(&horaActual, &hora);
	alsecs = (360.0 / 60.0)*horaActual.tm_sec;
	almin = (360.0 / 60.0)*horaActual.tm_min;
	alhora = (360.0 / 12.0)*horaActual.tm_hour;

	//Encola un evento de display: refresca la pantalla
	glutPostRedisplay();
}

void onTimer(int tiempo)
{
	//Muestra los frames / segundo en la barra de titulo
	int ahora, tiempotranscurrido;
	static int antes = glutGet(GLUT_ELAPSED_TIME);

	//Tiempo transcurrido
	ahora = glutGet(GLUT_ELAPSED_TIME);
	tiempotranscurrido = ahora - antes;
	glutTimerFunc(tiempo, onTimer, tiempo);
	update();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow(PROYECTO);
	init();
	//Registro de callbacks
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(1000 / tasaFPS, onTimer, 1000 / tasaFPS);
	cout << PROYECTO << "  en marcha" << endl;
	//Bucle de atención a eventos
	glutMainLoop();


}