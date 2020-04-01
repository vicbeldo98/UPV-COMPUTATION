#include <iostream>
#include <GL/freeglut.h>
#include <Utilidades.h>
#include <sstream>
#define  PROYECTO "Videojuego"

using namespace std;
static int tasaFPS = 60;
static float poscamx = 0, poscamz = 0, poscamxanterior = poscamx;
static float mirax = 1, miraz = 0;
static float velocidad = 0, angulo_giro = 0;
static float auxx, auxz, alfa = 90;
static float mitadancho = 2, largo = 2, amplitud_curva = 3;
static int numquads = 40;
static float vt[2] = { 1,0 };
static float vn[2] = { 0,1 };
static float norma;
GLuint texturacarretera, texturafondo, texturacartel, texturaposte, texturacoche;
static float radiocilindro = 100;
static float poscartelx = 50, poscartelz = mitadancho;
static enum { ALAMBRICO, SOLIDO } modo;
static enum { DIA, NOCHE } tiempo;
static bool visibilidad, instr;
//Para el modo nocturno
static GLfloat Alg[] = { 0.0,0.0,0.0,1.0 };
static GLfloat Dlg[] = { 0.5,0.5,0.2,1.0 };
static GLfloat Slg[] = { 0.5,0.5,0.5,1.0 };
static float cutoff = 45, exponente = 5;
static float distfarolas = 20;
static int inicio_farola2 = distfarolas, inicio_farola3 = distfarolas * 2, inicio_farola4 = distfarolas * 3, inicio_farola5 = distfarolas * 4;
static GLfloat Dm[] = { 0.8,0.8,0.8,1.0 };
static GLfloat Sm[] = { 0.8,0.8,0.8,1.0 };
static GLfloat s = 3.0;
//Niebla
const GLfloat color[] = { 0.85,0.85,0.85,0.45 };
void init()
{
	//Lista de ordenes de dibujo
	cout << "SGI :: PRACTICA9 :: " << PROYECTO << "  :: INSTRUCCIONES DE USO:\n" << endl;
	cout << "->Flechas: Giro y aceleracion\n" << endl;
	cout << "->Teclas:" << endl;
	cout << "L:  Cambio DIA/NOCHE" << endl;
	cout << "N:  Cambio VISIBILIDAD ESCASA/BUENA" << endl;
	cout << "C:  Cambio INSTRUMENTACION ON/OFF" << endl;
	cout << "S:  Cambio ALAMBRICO/SOLIDO" << endl;
	cout << "ESC:  SALIR" << endl;
	modo = SOLIDO;
	tiempo = DIA;
	visibilidad = true;
	instr = false;
	//Normalizar
	glEnable(GL_NORMALIZE);

	//Activar la Visibilidad
	glEnable(GL_DEPTH_TEST);

	//Propiedades del motor de render
	glEnable(GL_BLEND);

	// Blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	//Texturas:
	//Carretera
	glGenTextures(1, &texturacarretera);
	glBindTexture(GL_TEXTURE_2D, texturacarretera);
	loadImageFile((char*)"carretera.jpg");

	//Fondo
	glGenTextures(1, &texturafondo);
	glBindTexture(GL_TEXTURE_2D, texturafondo);
	loadImageFile((char*)"desierto.jpg");

	//Cartel
	glGenTextures(1, &texturacartel);
	glBindTexture(GL_TEXTURE_2D, texturacartel);
	loadImageFile((char*)"cocacola.jpg");

	//Poste
	glGenTextures(1, &texturaposte);
	glBindTexture(GL_TEXTURE_2D, texturaposte);
	loadImageFile((char*)"madera.jpg");

	//Coche
	glGenTextures(1, &texturacoche);
	glBindTexture(GL_TEXTURE_2D, texturacoche);
	loadImageFile((char *)"coche.png");

	//Configurar luces
	//LIGHT0: Luz de luna
	GLfloat Al0[] = { 0.4,0.3,0.3,1.0 };
	GLfloat Dl0[] = { 0.05,0.05,0.1,1.0 };
	GLfloat Sl0[] = { 0.0,0.0,0.0,1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, Al0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Dl0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Sl0);
	GLfloat posicion[] = { 0.0, 10.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, posicion);

	//LIGHT1: FOCO
	GLfloat Al1[] = { 0.6,0.6,0.6,1.0 };
	GLfloat Dl1[] = { 0.7,0.7,0.7,1.0 };
	GLfloat Sl1[] = { 0.8,0.8,0.8,1.0 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, Al1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Dl1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Sl1);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 15.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 20.0);
	glLightfv(GL_LIGHT7, GL_AMBIENT, Al1);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, Dl1);
	glLightfv(GL_LIGHT7, GL_SPECULAR, Sl1);
	glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, 15.0);
	glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, 20.0);


	//LIGHT2: FAROLAS
	glLightfv(GL_LIGHT2, GL_AMBIENT, Alg);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Dlg);
	glLightfv(GL_LIGHT2, GL_SPECULAR, Slg);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, exponente);

	//LIGHT3: FAROLAS
	glLightfv(GL_LIGHT3, GL_AMBIENT, Alg);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, Dlg);
	glLightfv(GL_LIGHT3, GL_SPECULAR, Slg);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, exponente);

	//LIGHT4: FAROLAS
	glLightfv(GL_LIGHT4, GL_AMBIENT, Alg);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, Dlg);
	glLightfv(GL_LIGHT4, GL_SPECULAR, Slg);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, exponente);

	//LIGHT5: FAROLAS
	glLightfv(GL_LIGHT5, GL_AMBIENT, Alg);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, Dlg);
	glLightfv(GL_LIGHT5, GL_SPECULAR, Slg);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, exponente);

	float cutoff6 = 90;
	//LIGHT6: FAROLA AL CARTEL
	glLightfv(GL_LIGHT6, GL_AMBIENT, Alg);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, Dlg);
	glLightfv(GL_LIGHT6, GL_SPECULAR, Slg);
	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, cutoff6);
	glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, exponente);


}

void createCylinder() {
	float puntox_ant = radiocilindro * sin(rad(252)) + poscamx;
	float puntox;
	float puntoz_ant = radiocilindro * cos(rad(252)) + poscamz;
	float puntoz;
	float parte = 0;
	for (int i = 288; i <= 612; i += 36) {
		puntox = radiocilindro * sin(rad(i)) + poscamx;
		puntoz = radiocilindro * cos(rad(i)) + poscamz;
		float v1[3] = { puntox_ant,50,puntoz_ant };
		float v2[3] = { puntox,50,puntoz };
		float v3[3] = { puntox,-50,puntoz };
		float v4[3] = { puntox_ant,-50,puntoz_ant };
		//material cilindro
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Dm);
		glMaterialfv(GL_FRONT, GL_SPECULAR, Sm);
		glMaterialf(GL_FRONT, GL_SHININESS, s);
		//textura cilindro
		glBindTexture(GL_TEXTURE_2D, texturafondo);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		quadtex(v4, v3, v2, v1, parte, parte + 0.1, 0, 1, 25, 25);
		parte += 0.1;
		puntox_ant = puntox;
		puntoz_ant = puntoz;

	}
}

float dcurvas(float x) {
	return amplitud_curva * cos(x / 10.0) / 10.0;
}

float modvec(float x1, float x2) {
	return sqrt(x1*x1 + x2 * x2);
}

float curvas(float x) {
	return amplitud_curva * sin(x / 10.0);
}

void dibujar_cartel() {
	//Si ya lo hemos pasado redibujar
	if (poscartelx + 1 < poscamx) {
		poscartelx += 150;
	}
	float fx = curvas(poscartelx);
	vt[1] = dcurvas(poscartelx);
	vn[0] = -vt[1];
	norma = modvec(vn[0], vn[1]);
	vn[0] = vn[0] / norma;
	vn[1] = vn[1] / norma;
	float v1[3] = { poscartelx,5,fx + mitadancho };
	float v2[3] = { poscartelx,5,fx - mitadancho };
	float v3[3] = { poscartelx,3,fx - mitadancho };
	float v4[3] = { poscartelx,3,fx + mitadancho };
	//Material cartel
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Dm);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Sm);
	glMaterialf(GL_FRONT, GL_SHININESS, s);
	//Textura cartel
	glBindTexture(GL_TEXTURE_2D, texturacartel);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	quadtex(v3, v4, v1, v2, 0, 1, 0, 1, 25, 25);
	glPopMatrix();
	fx = curvas(poscartelx - 3.0);
	vt[1] = dcurvas(poscartelx - 3.0);
	vn[0] = -vt[1];
	norma = modvec(vn[0], vn[1]);
	vn[0] = vn[0] / norma;
	vn[1] = vn[1] / norma;
	//Iluminación del cartel
	GLfloat Pl6[] = { poscartelx - 3.0,4.0,fx,1.0 };
	GLfloat Dl6[] = { 1,0,0 };
	glLightfv(GL_LIGHT6, GL_POSITION, Pl6);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, Dl6);
	fx = curvas(poscartelx + 0.1);
	//Viga derecha
	float v12[3] = { poscartelx + 0.1,5,fx + mitadancho };
	float v22[3] = { poscartelx + 0.1,5,fx + mitadancho + 1 };
	float v32[3] = { poscartelx + 0.1,0,fx + mitadancho + 1 };
	float v42[3] = { poscartelx + 0.1,0,fx + mitadancho };
	//Material viga derecha
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Dm);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Sm);
	glMaterialf(GL_FRONT, GL_SHININESS, s);
	//Textura viga derecha
	glBindTexture(GL_TEXTURE_2D, texturaposte);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	quadtex(v42, v32, v22, v12, 0, 1, 0, 1);

	//Viga izquierda
	float v13[3] = { poscartelx + 0.1,5,fx - mitadancho };
	float v23[3] = { poscartelx + 0.1,5,fx - mitadancho - 1 };
	float v33[3] = { poscartelx + 0.1,0,fx - mitadancho - 1 };
	float v43[3] = { poscartelx + 0.1,0,fx - mitadancho };
	//Material viga izquierda
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Dm);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Sm);
	glMaterialf(GL_FRONT, GL_SHININESS, s);
	//Textura viga izquierda
	glBindTexture(GL_TEXTURE_2D, texturaposte);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	quadtex(v13, v23, v33, v43, 0, 1, 0, 1);

}

void dibujarCarretera() {
	//Dibujar carretera
	for (int i = poscamx - 1; i <= poscamx + numquads * largo; i += largo) {
		glPushMatrix();
		float fx = curvas(i);
		vt[1] = dcurvas(i);
		vn[0] = -vt[1];
		norma = modvec(vn[0], vn[1]);
		vn[0] = vn[0] / norma;
		vn[1] = vn[1] / norma;
		float v0[3] = { (float)i + vn[0] * mitadancho,0,fx + vn[1] * mitadancho };
		float v3[3] = { (float)i - vn[0] * mitadancho,0,fx - vn[1] * mitadancho };
		fx = curvas(i + largo);
		vt[1] = dcurvas(i + largo);
		vn[0] = -vt[1];
		norma = modvec(vn[0], vn[1]);
		vn[0] = vn[0] / norma;
		vn[1] = vn[1] / norma;
		float v1[3] = { (float)i + largo + vn[0] * mitadancho,0,fx + vn[1] * mitadancho };
		float v2[3] = { (float)i + largo - vn[0] * mitadancho,0,fx - vn[1] * mitadancho };
		//Material de la carretera
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Dm);
		glMaterialfv(GL_FRONT, GL_SPECULAR, Sm);
		glMaterialf(GL_FRONT, GL_SHININESS, s);
		//Aplicamos textura
		glBindTexture(GL_TEXTURE_2D, texturacarretera);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		quadtex(v1, v2, v3, v0, 0, 1, 0, 1, 25, 25);

		glPopMatrix();
	}
	poscamxanterior = poscamx;
}

void cargarNoche()
{
	//Activar la iluminación
	glEnable(GL_LIGHTING);
	//Borrar pantalla
	//Borra Buffer de Profundidad
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner en el titulo la velocidad actual
	stringstream titulo;
	titulo << "SPEED = " << velocidad / 10.0 << "m/s";
	glutSetWindowTitle(titulo.str().c_str());

	//Si hay coche ponle dos focos uno en cada lado
	if (instr) {
		GLfloat Pl1[] = { 0.8,0.7,0.0,1.0 };
		GLfloat Dl1[] = { 0.0,-0.3,-0.8 };
		glLightfv(GL_LIGHT1, GL_POSITION, Pl1);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Dl1);
		glEnable(GL_LIGHT1);

		GLfloat Pl7[] = { -0.8,0.7,0.0,1.0 };
		GLfloat Dl7[] = { 0.0,-0.3,-0.8 };
		glLightfv(GL_LIGHT7, GL_POSITION, Pl7);
		glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, Dl1);
		glEnable(GL_LIGHT7);
	}
	//Si no hay coche, un sólo foco
	else {
		GLfloat Pl1[] = { 0.0,0.7,0.0,1.0 };
		GLfloat Dl1[] = { 0.0,-0.3,-0.8 };
		glLightfv(GL_LIGHT1, GL_POSITION, Pl1);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Dl1);
		glEnable(GL_LIGHT1);
	}

	//Situar la Cámara
	gluLookAt(poscamx, 1, poscamz, poscamx + (mirax * 5), 1, poscamz + (miraz * 5), 0, 1, 0);
	//Dibujar farolas
	GLfloat Dl[] = { 0.0,-1.0,0.0 };
	float fx = curvas(inicio_farola2);
	vt[1] = dcurvas(inicio_farola2);
	vn[0] = -vt[1];
	norma = modvec(vn[0], vn[1]);
	vn[0] = vn[0] / norma;
	vn[1] = vn[1] / norma;
	GLfloat Pl2[] = { inicio_farola2 ,4.0,fx + vn[1] * mitadancho - mitadancho,1.0 };
	fx = curvas(inicio_farola3);
	vt[1] = dcurvas(inicio_farola3);
	vn[0] = -vt[1];
	norma = modvec(vn[0], vn[1]);
	vn[0] = vn[0] / norma;
	vn[1] = vn[1] / norma;
	GLfloat Pl3[] = { inicio_farola3 ,4.0,fx + vn[1] * mitadancho - mitadancho,1.0 };
	fx = curvas(inicio_farola4);
	vt[1] = dcurvas(inicio_farola4);
	vn[0] = -vt[1];
	norma = modvec(vn[0], vn[1]);
	vn[0] = vn[0] / norma;
	vn[1] = vn[1] / norma;
	GLfloat Pl4[] = { inicio_farola4 ,4.0,fx + vn[1] * mitadancho - mitadancho,1.0 };
	fx = curvas(inicio_farola5);
	vt[1] = dcurvas(inicio_farola5);
	vn[0] = -vt[1];
	norma = modvec(vn[0], vn[1]);
	vn[0] = vn[0] / norma;
	vn[1] = vn[1] / norma;
	GLfloat Pl5[] = { inicio_farola5,4.0,fx + vn[1] * mitadancho - mitadancho,1.0 };
	if (poscamx > inicio_farola2 + 5) {
		inicio_farola2 += distfarolas * 4;
	}
	glPushMatrix();
	glLightfv(GL_LIGHT2, GL_POSITION, Pl2);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, Dl);

	if (poscamx > inicio_farola3 + 5) {
		inicio_farola3 += distfarolas * 4;
	}
	glLightfv(GL_LIGHT3, GL_POSITION, Pl3);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, Dl);

	if (poscamx > inicio_farola4 + 5) {
		inicio_farola4 += distfarolas * 4;
	}
	glLightfv(GL_LIGHT4, GL_POSITION, Pl4);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, Dl);

	if (poscamx > inicio_farola5 + 5) {
		inicio_farola5 += distfarolas * 4;
	}
	glLightfv(GL_LIGHT5, GL_POSITION, Pl5);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, Dl);
	glPopMatrix();

	if (poscamx + largo >= poscamxanterior) {
		dibujarCarretera();
	}

	//Crear vistas
	createCylinder();
	//Crear cartel
	dibujar_cartel();

}

void rotateVector(float x1, float y1, float *x2, float *y2, float angle) {
	float a = rad(angle);
	*x2 = cos(a)*x1 - sin(a)*y1;
	*y2 = sin(a)*x1 + cos(a)*y1;
}

void cargarDia()
{
	//Activar la iluminación
	glDisable(GL_LIGHTING);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//Borrar pantalla
	//Borra Buffer de Profundidad
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner en el titulo la velocidad actual
	stringstream titulo;
	titulo << "SPEED = " << velocidad / 10.0 << "m/s";
	glutSetWindowTitle(titulo.str().c_str());

	//Situar la Cámara
	gluLookAt(poscamx, 1, poscamz, poscamx + (mirax * 5), 1, poscamz + (miraz * 5), 0, 1, 0);

	//Dibujar carretera si es necesario
	if (poscamx + largo >= poscamxanterior) {
		dibujarCarretera();
	}
	//Crear vistas
	createCylinder();
	//Crear cartel
	dibujar_cartel();

}

void display() {
	if (tiempo == DIA) {
		glDisable(GL_LIGHTING);
		cargarDia();
	}
	else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);
		glEnable(GL_LIGHT3);
		glEnable(GL_LIGHT4);
		glEnable(GL_LIGHT5);
		glEnable(GL_LIGHT6);
		glEnable(GL_LIGHT7);
		cargarNoche();
	}
	if (visibilidad) {
		glDisable(GL_FOG);
	}
	else {
		glEnable(GL_FOG);
		glFogfv(GL_FOG_COLOR, color);
		glFogf(GL_FOG_DENSITY, 0.15);
	}
	if (modo == SOLIDO) {
		glEnable(GL_TEXTURE_2D);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else {
		glDisable(GL_TEXTURE_2D);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	if (modo == SOLIDO) { glColor3f(1.0, 1.0, 1.0); }
	else { glColor3f(0.0, 0.0, 0.0); }

	if (instr == TRUE) {
		//Cargar coche:: Objetos traslucidos que van pegados a la camara
		glPushMatrix();		// Apilar la modelview
		glLoadIdentity();	// Camara en posicion de defecto
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();		// Apilar la projection
		glLoadIdentity();	// Vista por defecto
		glOrtho(-1, 1, -1, 1, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
		//Dibujar donut
		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glScalef(0.1, 0.1, 0.1);
		glTranslatef(5.7, -1.7, 0.0);
		glRotatef(alfa, 0, 1, 0);
		alfa = alfa + 0.3;
		if (alfa == 360) { alfa = 0; }
		if (tiempo == DIA) { glColor4f(1.0, 1.0, 1.0, 0.5); }
		else {
			static GLfloat Dn[] = { 0.5,0.5,0.5,0.5 };
			static GLfloat Sn[] = { 0.5,0.5,0.5,0.5 };
			static GLfloat n = 3.0;
			glMaterialfv(GL_FRONT, GL_DIFFUSE, Dn);
			glMaterialfv(GL_FRONT, GL_SPECULAR, Sn);
			glMaterialf(GL_FRONT, GL_SHININESS, n);
		}
		glutSolidTorus(0.2, 0.5, 50, 50);
		glPopAttrib();
		glPopMatrix();

		//Dibujarcoche
		glBindTexture(GL_TEXTURE_2D, texturacoche);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		float v0[3] = { -1.2,-1.5,0 };
		float v1[3] = { 1.2,-1.5,0 };
		float v2[3] = { 1.2,1.6,0 };
		float v3[3] = { -1.2,1.6,0 };
		quadtex(v0, v1, v2, v3);
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
	}
	glutSwapBuffers();

}

void reshape(GLint w, GLint h) {

	float razonAspecto = float(w) / h;

	//Definir el marco de dibujo
	glViewport(0, 0, w, h);

	//Construir Cámara Propia
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Cámara Perspectiva
	gluPerspective(45, razonAspecto, 1, radiocilindro);
}

void onSpecialKey(int tecla, int x, int y) {
	//Callback de atencion al pulsado de letras y numeros
	switch (tecla) {
	case GLUT_KEY_UP:
		velocidad += 1;
		break;

	case GLUT_KEY_DOWN:
		if (velocidad > 0) { velocidad -= 1; }
		break;
	case GLUT_KEY_RIGHT:
		if (angulo_giro < 90) {
			rotateVector(mirax, miraz, &auxx, &auxz, 0.5);
			mirax = auxx;
			miraz = auxz;
			angulo_giro += 0.7;
		}
		break;
	case GLUT_KEY_LEFT:
		if (angulo_giro > -90) {
			rotateVector(mirax, miraz, &auxx, &auxz, -0.5);
			mirax = auxx;
			miraz = auxz;
			angulo_giro -= 0.7;
		}
		break;
	}

	//Redibujo
	glutPostRedisplay();
}

void onKey(unsigned char tecla, int x, int y) {
	//Callback de atencion al pulsado de letras y numeros
	tecla = toupper(tecla);
	switch (tecla) {
	case 'L': if (tiempo == DIA) tiempo = NOCHE;
			  else tiempo = DIA;
		;
		break;
	case 'N': if (visibilidad) visibilidad = false;
			  else visibilidad = true;
		break;
	case 'C': if (instr) instr = false;
			  else instr = true;
		break;
	case 'S': if (modo == ALAMBRICO) modo = SOLIDO;
			  else modo = ALAMBRICO;
		break;

	case 27: exit(0);
	}

	//Redibujo
	glutPostRedisplay();
}

void onTimer(int tiempo)
{
	int ahora;
	static int antes = glutGet(GLUT_ELAPSED_TIME);
	float tiempotranscurrido;
	//Tiempo transcurrido
	ahora = glutGet(GLUT_ELAPSED_TIME);
	tiempotranscurrido = ahora - antes;
	poscamx += mirax * (velocidad / 10.0)*(tiempotranscurrido / 1000.0);
	poscamz += miraz * (velocidad / 10.0)*(tiempotranscurrido / 1000.0);
	antes = ahora;
	//Vuelve a arrancar el cronómetro
	glutTimerFunc(tiempo, onTimer, tiempo);
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	//Inicializaciones
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow(PROYECTO);
	init();

	//Registro callbacks
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(onSpecialKey);
	glutKeyboardFunc(onKey);
	glutTimerFunc(1000 / tasaFPS, onTimer, 1000 / tasaFPS);
	//bucle de atencion a eventos
	glutMainLoop();
}