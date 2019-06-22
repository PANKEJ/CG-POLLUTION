#include<GL/glut.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"all.h"
#define f4 GLUT_BITMAP_TIMES_ROMAN_24
#define f5 GLUT_BITMAP_HELVETICA_12
double color1[][3]={{0.137255,0.656863,0.137255}/*0forestgreen*/,{0.498039,1.0,0.0}/*1medspringgreen*/,{0.65,.50,.039}/*2medwood*/,
					{.52,.37,.26}/*3darkwood*/,{0.88,0.70,0.40}/*4lightwood*/,{0.396078,0.9869,0.9}/*5water*/,{.20,.20,.20}/*6gray20*/,
					{.45,.45,.45}/*7gray45*/,{0.36,0.25,0.20}/*8darkbrown*/,{1.0,1.0,1.0}/*9white*/,{0.50,0.98740,0.40}/*10lightgreen*/,
					{0.309804,0.309804,0.184314}/*11DARKOLIVEGREEN*/,{.10,.10,.10}/*12gray10*/,{0.0,0.698039,1.0}/*13skyblue*/,
					{.8,.8,.8}/*14gray80*/,{0.184314,0.309804,0.309804}/*15darkslategrey*/,{0.81,0.71,0.23}/*16oldgold*/,
					{0.55,0.09,0.09}/*17scarlet*/,{0.0,0.0,0.0}/*18black*/,{0.957, 0.643, 0.376}/*19SandyBrown(skin)*/,
					{0.863, 0.078, 0.235}/*20CRIMSONRED*/,{0.729, 0.333, 0.827}/*21medorchid*/,{0.545, 0.000, 0.545}/*22darkmagenta*/,
					{1.000, 0.647, 0.000}/*23orange*/,{1.000, 0.549, 0.000}/*24darkorange*/,{0.529, 0.808, 0.980}/*25litskyblue*/,
					{0.118, 0.565, 1.000}/*26dodgerblue*/,{ 0.220, 0.220, 0.220 }/*27gray22*/,{.6,.6,.6}/*28gray60*/,/*29gray*/{0.752941,0.752941,0.752941},
					/*30gold*/{1.000, 0.843, 0.000},/*31orange*/{1.000, 0.647, 0.000},/*32wood*/{0.52,0.37,0.26},/*33orangered*/{1.000, 0.271, 0.000},
					/*34Turquoise*/{0.251, 0.878, 0.816},/*35cadetblue*/{0.373, 0.620, 0.627},/*36darkgoldenrod*/{0.722, 0.525, 0.043},
					/*37meddeepblue*/{0.000, 0.000, 0.804},/*38darkgreen*/{0.000, 0.392, 0.000}};

int flag=0;
int b1=0,b2=0,b3=0,b4=0,b5=0;
float pos1,pos2=250,pos3,pos4,p1,fi=500.0;
float cx1=0,cy1=30;
float c1=0.0,c2=200.0,c3=300,c4=480,c5=600,c6=480,k1=0.0,k2=100.0,k3=350.0;
int i,j=0,col=1,np=0,ap=0,wp=0,sp=0,hb=0;
double ry=400;
double r1=0,r2=0,r3=0,r4=0,r5=0,sv=0.5;
int win0,win1,win2,win3,win4,accept=0;
double scv=5,r=10;

/*<<<<<<<<<---------------------AIR POLLUTION---------------------->>>>>>>>*/
void slow()
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2f(-10,-10);
	glVertex2f(-50,-10);
	glVertex2f(-50,-50);
	glVertex2f(-10,-50);
	glEnd();
}
void drawrain()
{
	glColor3dv(color1[5]);
	glBegin(GL_POLYGON);
	glVertex2f(10,15);
	glVertex2f(6,3);
	glVertex2f(7,2);
	glVertex2f(8,1);
	glVertex2f(10,0);
	glVertex2f(12,1);
	glVertex2f(13,2);
	glVertex2f(14,3);
	glEnd();
}
void rainmotion()
{	
	for(i=0;i<=1200;i+=75)
	{
		glPushMatrix();
		glTranslated(i,ry,0);	
		drawrain();
		glPopMatrix();
	}
	ry-=25;
	
	for(int j=0;j<=5000;j++)
	{
		glPushMatrix();
		glTranslated(j,0,0);
		glPopMatrix();
	}
	if(ry<0)
	{
		ry=1400;
		col=15;
	}
}

void drawCircle(int l,int m,int col1,float r)
{
    int i, x, y;
    double radius = r;
    glColor3dv(color1[col1]);
    double twoPi = 2.0 * 3.142;
    x =l, y =m;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f((x + (radius * cos(i * twoPi / 20))), (y + (radius * sin(i * twoPi / 20))));
    }
    glEnd();
}

void drawsmoke()
{
	glPushMatrix();
	glTranslated(178,300,0);
	glBegin(GL_POLYGON);
	glColor3dv(color1[12]);
	glVertex2f(60,10);
	glVertex2f(70,0);
	glVertex2f(100,0);
	glVertex2f(120,20);
	glVertex2f(120,40);
	glColor3dv(color1[14]);
	glVertex2f(100,60);
	glVertex2f(70,60);
	glVertex2f(60,50);
	glVertex2f(50,60);
	glVertex2f(20,60);
	glColor3dv(color1[12]);
	glVertex2f(0,40);
	glVertex2f(0,20);
	glVertex2f(20,0);
	glVertex2f(50,0);
    glEnd();
	glPopMatrix();
}

void carsmoke()
{
	
	glPushMatrix();
	glTranslated(500+r4,75,0);
	glScaled(0.03*sv,0.03*sv,0);
	drawsmoke();
	sv+=0.005;
	r4+=0.13;
	glPopMatrix();
	if(r4>200)
	{
		r4=0;
		sv=0;
	}
}

void drawcars(int x,int y,int col,float r)
{
	glColor3f(0.9,0.1,0.0);//red
	glBegin(GL_POLYGON);
	glVertex2f(60,10);
	glVertex2f(60,20);
	glVertex2f(80,20);
	glVertex2f(90,30);
	glVertex2f(110,30);
	glVertex2f(120,20);
	glVertex2f(140,20);
	glVertex2f(140,10);
	glEnd();
	drawCircle(x,y,col,r);
	drawCircle(x+40,y,col,r);
}
void cars()
{	glPushMatrix();
	glTranslated(400,75,0);
	drawcars(80,7,6,6.5);
	glPopMatrix();
}

void carmotion()
{  	
	glPushMatrix();
	glTranslated(k1,0,0);
	cars();
	carsmoke();
	k1-=0.023;
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(k2,0,0);
	cars();carsmoke();
	k2-=0.053;

	glPopMatrix();
	glPushMatrix();
	glTranslated(k3,0,0);
	cars();carsmoke();
	k3-=0.13;
	glPopMatrix();
}


void strips(float dist)
{	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(20.0+dist,70.0);
	glVertex2f(20.0+dist,75.0);
	glVertex2f(60.0+dist,75.0);
	glVertex2f(60.0+dist,70.0);
	glEnd();
}
void land_road(int col1,int col2)
{	float d=0.0;
	for(int i=0;i<7;i++)
	{	strips(d);
		d+=70.0;
	}
	//greenland
	glPointSize(2.0);
	glPushMatrix();
	glColor3dv(color1[col1]);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,45);
	glVertex2f(500,45);
	glVertex2f(500,0);
	glEnd();
	//road
	glBegin(GL_POLYGON);
	glColor3dv(color1[col2]);
	glVertex2f(0,0);
	glVertex2f(0,100);
	glVertex2f(380,100);
	//glVertex2f(410,95);
	//glVertex2f(460,92);
	glVertex2f(500,100);
	glVertex2f(500,0);
	glEnd();
	glPopMatrix();
}


void factory(int col1,int col2)
{ //building
	glPointSize(2.0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3dv(color1[col1]);
	glVertex2f(158.0,100.0);
	glVertex2f(165.0,170.0);
	glVertex2f(250.0,170.0);
	glVertex2f(255.0,125.0);
	glVertex2f(265.0,150.0);
	glVertex2f(265.0,125.0);
	glVertex2f(275.0,150.0);
	glVertex2f(275.0,125.0);
	glVertex2f(285.0,150.0);
	glVertex2f(285.0,100.0);
	glEnd();
	//Chimney1
	glShadeModel(GL_SMOOTH);
	glColor3dv(color1[col2]);
	glBegin(GL_POLYGON);
	glVertex2f(178.0,150.0);
	glVertex2f(180.0,300.0);
	glVertex2f(188.0,300.0);
	glVertex2f(190.0,150.0);
	glEnd();
	//Chimney2
	glBegin(GL_POLYGON);
	glVertex2f(196.0,150.0);
	glVertex2f(198.0,280.0);
	glVertex2f(206.0,280.0);
	glVertex2f(208.0,150.0);
	glEnd();
	//Chimney3
	glBegin(GL_POLYGON);
	glVertex2f(212.0,150.0);
	glVertex2f(214.0,260.0);
	glVertex2f(222.0,260.0);
	glVertex2f(224.0,150.0);
	glEnd();
	glPopMatrix();
}
void backdrop(int col)
{
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(0,0);
		glVertex2f(1200,0);
		glColor3dv(color1[col]);//0.0,0.698039,1.0
		glVertex2f(1200,700);
		glVertex2f(0,700);
		glEnd();

}
void house(int col1,int col2,int col3=3,int col4=3,int col5=4)
{	//windows
	 glColor3dv(color1[col1]);
	 glBegin(GL_POLYGON);
	 glVertex2f(320.0,100.0);
	 glVertex2f(320.0,110.0);
	 glVertex2f(330.0,110.0);
	 glVertex2f(330.0,100.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(309.0,110.0);
	 glVertex2f(309.0,115.0);
	 glVertex2f(315.0,115.0);
	 glVertex2f(315.0,110.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(335.0,110.0);
	 glVertex2f(335.0,115.0);
	 glVertex2f(342.0,115.0);
	 glVertex2f(342.0,110.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(370.0,100.0);
	 glVertex2f(370.0,110.0);
	 glVertex2f(380.0,110.0);
	 glVertex2f(380.0,100.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(359.0,110.0);
	 glVertex2f(359.0,115.0);
	 glVertex2f(365.0,115.0);
	 glVertex2f(365.0,110.0);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(385.0,110.0);
	 glVertex2f(385.0,115.0);
	 glVertex2f(392.0,115.0);
	 glVertex2f(392.0,110.0);
	 glEnd();

	 //left house
	 glColor3dv(color1[col2]);
	 glBegin(GL_POLYGON);
	 glVertex2f(305.0,100.0);
	 glVertex2f(305.0,130.0);
	 glColor3dv(color1[col3]);
	 glVertex2f(345.0,130.0);
	 glVertex2f(345.0,100.0);
	 glEnd();
	 glColor3dv(color1[col4]);
	 glBegin(GL_POLYGON);
	 glVertex2f(300.0,130.0);
	 glColor3dv(color1[col5]);
	 glVertex2f(325.0,157.95);
	 glVertex2f(350.0,130.0);
	 glEnd();
	//righthouse
	 glColor3dv(color1[col2]);
	 glBegin(GL_POLYGON);
	 glVertex2f(355.0,100.0);
	 glVertex2f(355.0,130.0);
	 glColor3dv(color1[col3]);
	 glVertex2f(395.0,130.0);
	 glVertex2f(395.0,97.0);
	 glEnd();
	 glColor3dv(color1[col4]);
	 glBegin(GL_POLYGON);
	 glVertex2f(350.0,130.0);
	 glVertex2f(375.0,157.95); 
	 glColor3dv(color1[col5]);
	 glVertex2f(400.0,130.0);
	 glEnd();
	
}

void tree(float dist,int col2)
{
	glColor3dv(color1[col2]);
	glBegin(GL_POLYGON);
	glVertex2f(430.0+dist,80.0);
	glVertex2f(435.0+dist,100.0);
	glVertex2f(440.0+dist,150.0);
	glVertex2f(440.0+dist,150.0);
	glVertex2f(450.0+dist,110.0);
	glVertex2f(455.0+dist,75.0);
	glEnd();

}
void blackclouds2(int col1)
{
	drawCircle(10,450,col1,58);
	drawCircle(116,450,col1,58);
	drawCircle(220,450,col1,58);
	drawCircle(330,450,col1,58);
	drawCircle(430,450,col1,58);
	drawCircle(530,450,col1,58);
}
void blackclouds1()
{
	drawCircle(-38,392,27,58);
	drawCircle(60,392,27,58);
	drawCircle(160,392,27,58);
	drawCircle(215,352,27,40);
	drawCircle(210,300,27,10);
	drawCircle(220,280,27,8);
	drawCircle(270,392,27,58);
	drawCircle(380,392,27,58);
	drawCircle(480,392,27,58);

}

void drawcloud(int col1)
{
	drawCircle(100,110,col1,30);
	drawCircle(150,130,col1,40);
	drawCircle(130,90,col1,20);
	drawCircle(190,110,col1,31);
	drawCircle(168,90,col1,25);
}

void clouds(int high,int col1)
{
	glPushMatrix();
	glTranslated(400,high,0);
	drawcloud(col1);
	glPopMatrix();
}
void cloudmotion(int col1)
{  	glPushMatrix();
	glTranslated(c1,0,0);
	clouds(290,col1);
	c1-=0.08;
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(c2,0,0);
	clouds(250,col1);
	c2-=0.08;

	glPopMatrix();
	glPushMatrix();
	glTranslated(c3,0,0);
	clouds(300,col1);
	c3-=0.08;
	glPopMatrix();

	glPushMatrix();
	glTranslated(c4,0,0);
	clouds(270,col1);
	c4-=0.08;
	glPopMatrix();
}
void smokemotion()
{
	glPushMatrix();
	glTranslated(178,300,0);
	glScaled(-0.03*sv,0.06*sv,0);
	drawsmoke();
	sv+=0.009;
	r1+=0.0;
	glPopMatrix();
	if(r1>200)
	{
		r1=0;
		sv=0;
	}

	glPushMatrix();
	glTranslated(205,270,0);
	glScaled(-0.02*sv,0.04*sv,0);
	drawsmoke();
	sv+=0.009;
	r2+=0.00;
	glPopMatrix();
	if(r2>200)
	{
		r2=0;
		sv=0;
	}

	glPushMatrix();
	glTranslated(219,250,0);
	glScaled(-0.015*sv,0.05*sv,0);
	drawsmoke();
	sv+=0.009;
	r3+=0.0;
	glPopMatrix();
	if(r3>200)
	{
		r3=0;
		sv=0;
	}
}


void firstpage_A(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(160,200,f4,17,"AIR POLLUTION");
	backdrop(17);
	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display1);
	}
    glutPostRedisplay();
	glFlush();

}
void lastpage_A()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(40,360,f4,17,"EFFECTS OF AIR POLLUTION");
	PrintText(40,320,f5,18,"1.It weakens the lungs to function well, leading to asthma attacks");
	PrintText(40,290,f5,18,"2.It causes irritation of eyes, nose, mouth and throat");
	PrintText(40,260,f5,18,"3.It causes respiratory symptoms such as coughing and wheezing");
	PrintText(40,230,f5,18,"4.It increases the chances of respiratory diseases such as bronchitis");
	PrintText(40,200,f5,18,"5.It is the main reason of headaches and dizziness");
	PrintText(40,170,f5,18,"6.It causes disruption of endocrine, reproductive and immune systems");
	PrintText(40,140,f5,18,"7.It creates cardiovascular problems");
	PrintText(40,110,f5,18,"8.It may cause cancer due to presence of carcinogenic contents in it");
	backdrop(17);
	if(ap)
	{
		ap=0;
		flag=0;
		window2();
	}
	glutPostRedisplay();
	glFlush();
}
void display4()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	land_road(11,12);
	house(12,3,17,15,16);
	tree(0.0,8);
	tree(45.0,3);
	cloudmotion(28);
	blackclouds2(7);
	backdrop(6);
	glPopMatrix();

	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(lastpage_A);
	}
    glutPostRedisplay();
	glFlush();
}

void display3()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	blackclouds2(7);
	rainmotion();
	cloudmotion(28);
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	smokemotion();
	blackclouds1();
	land_road(10,12);
	house(9,3,4);
	drawCircle(440,150,10,30);
	tree(0.0,8);
	drawCircle(480,150,11,30);
	tree(45.0,3);
	backdrop(6);
	glPopMatrix();

	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display4);
	}
    glutPostRedisplay();
	glFlush();
}
void display2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	smokemotion();
	cloudmotion(14);
	blackclouds2(7);
	land_road(0,12);
	house(9,3,4);
	drawCircle(440,150,0,30);
	tree(0.0,8);
	drawCircle(480,150,1,30);
	tree(45.0,3);

	backdrop(13);
	if(ap)
	{
		
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display3);
	}
    glutPostRedisplay();
	glFlush();
}
void display1(void)
{	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	land_road(1,12);
	house(9,3,4);
	drawCircle(440,150,0,30);
	tree(0.0,8);
	drawCircle(480,150,1,30);
	tree(45.0,3);
	cloudmotion(9);
	backdrop(13);//background gradient
	if(ap)
	{
		
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display2);
	}
    glutPostRedisplay();
	glFlush();
}
void APmouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		ap=1;
	}
}
void APkeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			ap=1;
		}
}
void airpollutioninit()
{	
	glutDisplayFunc(firstpage_A);
	glutMouseFunc(APmouse);
	glutKeyboardFunc(APkeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}


void FinalPage()
{	
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	backdrop(13);
	PrintText(220,250,f4,17,"THANK YOU..!");
	glutPostRedisplay();
	glFlush();
}

void reshape1(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,450);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void MainWindowinit()
{	
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutReshapeFunc(reshape1);
	glutDisplayFunc(firstpage_M);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,1.0);
	glutMainLoop();
}


void Introduction(GLint sizex,GLint sizey,GLint posx,GLint posy)
{
	glutInitWindowSize(sizex,sizey);//420,900
	glutInitWindowPosition(posx,posy);//474,0
	win0=glutCreateWindow("INTRODUCTION");
	MainWindowinit();
}

void window1()
{	
	glutInitWindowSize(450,350);
	glutInitWindowPosition(0,0);
	win1=glutCreateWindow("Air Pollution");
	glutReshapeFunc(reshape1);
	airpollutioninit();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	Introduction(1366,768,0,0);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}