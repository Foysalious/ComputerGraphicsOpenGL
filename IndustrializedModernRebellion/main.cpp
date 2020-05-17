#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

GLint i, j, k, trainST=0,bridgeST=0,roadST=0,roadMidST=0,mb1=0,mb2=0,mb3=0,grassST=0,treeBigST=0,tillaST=0;
GLfloat sun_spin=0, sun_x=0, sun_y=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat tr11=100,tr12=-200,tr22=0,trn=550;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;

void init(void)
{
	glClearColor(.40, .110, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

///*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
/// *** Sun_Model **///
void Sun_Model(){
    glPushMatrix();
    glTranslatef(800,150,0);
    circle(30);
    glPopMatrix();

}
void Moving_Sun_Model(){
    glPushMatrix();
    glRotatef(-sun_spin, 0,0,-.009);
    Sun_Model();
    glPopMatrix();

}
///*** Cloud_Model***///
void cloud_model_one(){

    glColor3f(1.25, 0.924, 0.930);

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right

    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();


    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();

    ///****Fill End****

}

void cloud_model_Two(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();



}

void cloud_model_Three(){
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(300,200,0);
    circle(15);
    glPopMatrix();

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340,220,0);
    circle(16);
    glPopMatrix();

    ///Top_Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380,200,0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190,0);
    circle(20);
    glPopMatrix();




    ///****Fill End****

}
///*** Hill_Model***///
void hill_big(){

    ///Hill
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(70, 70);
	glVertex2i(200, 225);
	glVertex2i(330, 70);

	glEnd();

	///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);

	glVertex2i(200, 225);
	glVertex2i(230, 190);
	glVertex2i(220, 180);
	glVertex2i(200, 190);
	glVertex2i(190, 180);
	glVertex2i(170, 190);

	glEnd();

}
void hill_small(){
    ///Hill_Small
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(250, 100);
	glVertex2i(310, 175);
	glVertex2i(370, 100);

	glEnd();

    ///Hill_Small_Snow
	glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(290, 150);
	glVertex2i(310, 175);
	glVertex2i(330, 150);
	glVertex2i(325, 140);
	glVertex2i(310, 150);
	glVertex2i(300, 140);


	glEnd();
}

///*** Tractor_Model ***///
void Tractor_Model()
{
    glBegin(GL_POLYGON); //engine
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(915,27);
    glVertex2i(915,40);
    glVertex2i(920,45);
    glVertex2i(940,45);
    glVertex2i(940,27);
    glEnd();
    glBegin(GL_POLYGON); // sit
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(945,27);
    glVertex2i(948,42);
    glVertex2i(975,50);
    glVertex2i(980,40);
    glVertex2i(980,27);
    glEnd();
    glBegin(GL_POLYGON); // break
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(930,27);
    glVertex2i(930,35);
    glVertex2i(950,35);
    glVertex2i(950,27);
    glEnd();
    glBegin(GL_POLYGON); // hood
    glColor3f(0.0, 0.0, 0.8);
    glVertex2i(948,44);
    glVertex2i(948,65);
    glVertex2i(940,65);
    glVertex2i(940,68);
    glVertex2i(970,68);
    glVertex2i(975,52);
    glEnd();

    glPushMatrix(); // back tire
    glColor3f(0.0,0.0,0.0);
    glTranslatef(960,30,0);
    circle(10);
    glPopMatrix();

    glPushMatrix(); // front tire
    glColor3f(0.0,0.0,0.0);
    glTranslatef(928,27,0);
    circle(7);
    glPopMatrix();
}

///*** Tractor_Model2 ***///
void Tractor_Model2()
{
    glBegin(GL_POLYGON); //engine
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(215,17);
    glVertex2i(215,30);
    glVertex2i(210,35);
    glVertex2i(190,35);
    glVertex2i(190,17);
    glEnd();
    glBegin(GL_POLYGON); // sit
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(185,17);
    glVertex2i(182,32);
    glVertex2i(155,40);
    glVertex2i(150,30);
    glVertex2i(150,17);
    glEnd();
    glBegin(GL_POLYGON); // break
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(200,17);
    glVertex2i(200,25);
    glVertex2i(180,25);
    glVertex2i(180,17);
    glEnd();
    glBegin(GL_POLYGON); // hood
    glColor3f(0.0, 0.0, 0.4);
    glVertex2i(182,34);
    glVertex2i(182,55);
    glVertex2i(190,55);
    glVertex2i(190,58);
    glVertex2i(150,58);
    glVertex2i(155,42);
    glEnd();

    glPushMatrix(); // back tire
    glColor3f(0.0,0.0,0.0);
    glTranslatef(165,20,0);
    circle(10);
    glPopMatrix();

    glPushMatrix(); // front tire
    glColor3f(0.0,0.0,0.0);
    glTranslatef(200,17,0);
    circle(7);
    glPopMatrix();
}
/// *** Grass_Model *** ///
void Grass_Model()
{
    for(int i=0; i<900; i=i+50)
    {
        glBegin(GL_POLYGON); // first Grass
        glColor3ub (3, 90, 30);
        glVertex2i(50+i,50);
        glVertex2i(53+i,58);
        glVertex2i(56+i,50);
        glEnd();

        glBegin(GL_POLYGON); // back Grass
        glColor3ub (3, 71, 23);
        glVertex2i(48+i,50);
        glVertex2i(46+i,56);
        glVertex2i(53+i,50);
        glVertex2i(53+i,50);
        glVertex2i(60+i,56);
        glVertex2i(58+i,50);
        glEnd();
    }
}
/// ***train model *** ///
void train_model()
{
glPushMatrix();

    glBegin(GL_POLYGON); //engine body
    glColor3ub (3, 71, 23);
	glVertex2i(480,122);
	glVertex2i(490,131);
	glVertex2i(600,131);
	glVertex2i(600,122);
    glEnd();
    glBegin(GL_POLYGON); // engine body
    glColor3ub (3, 71, 23);
	glVertex2i(560,122);
	glVertex2i(560,160);
	glVertex2i(600,160);
	glVertex2i(600,122);
    glEnd();
    glBegin(GL_POLYGON); // engine
    glColor3ub (71, 3, 23);
	glVertex2i(492,132);
	glVertex2i(515,150);
	glVertex2i(558,160);
	glVertex2i(558,132);
    glEnd();
    glColor3ub (21,67,96); // engine window
    glPointSize(4.0);
    glRectf(565,132,595,155);

    for(int i=0; i<401; i=i+100)
    {
        glBegin(GL_POLYGON); // car Body
        glColor3ub (3, 71, 23);
        glVertex2i(602+i,122);
        glVertex2i(602+i,160);
        glVertex2i(700+i,160);
        glVertex2i(700+i,122);
        glEnd();

        glBegin(GL_POLYGON); // car Door
        glColor3ub (21,67,96);
        glVertex2i(608+i,124);
        glVertex2i(608+i,155);
        glVertex2i(628+i,155);
        glVertex2i(628+i,124);
        glEnd();

        glColor3ub (21,67,96); // car1 window
        glPointSize(4.0);
        glRectf(631+i,132,651+i,155);

        glColor3ub (21,67,96); // car1 window
        glPointSize(4.0);
        glRectf(653+i,132,673+i,155);

        glColor3ub (21,67,96); // car1 window
        glPointSize(4.0);
        glRectf(675+i,132,695+i,155);
    }

glPopMatrix();
//glFlush();
}

/// *** train model *** ///
void bridge_model()
{
    int clrCnt =0;
	for(int i=0; i<1400; i=i+90)
    {
        glBegin(GL_POLYGON); // bridge slab
        glColor3ub (158, clrCnt, clrCnt+30);
        glVertex2i(0+i, 230);
        glVertex2i(0+i, 245);
        glVertex2i(90+i, 245);
        glVertex2i(90+i, 230);
        glEnd();
        clrCnt=clrCnt+10;

        glBegin(GL_POLYGON); // bridge pile base
        glColor3ub(28,90,188);
        glVertex2i(10+i, 120);
        glVertex2i(20+i, 145);
        glVertex2i(40+i, 145);
        glVertex2i(50+i, 120);
        glEnd();

        glBegin(GL_POLYGON); // bridge pile body
        glColor3ub(28,190,188);
        glVertex2i(22+i, 145);
        glVertex2i(25+i, 230);
        glVertex2i(35+i, 230);
        glVertex2i(38+i, 145);
        glEnd();

    }
}

///*** Tilla_Model ***///
void Tilla_One_Model(){
    ///Tilla
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);
	glVertex2i(0, 120);
	glVertex2i(10, 165);
	glVertex2i(20, 170);
	glVertex2i(40, 180);
	glVertex2i(50, 180);
	glVertex2i(50, 190);
	glVertex2i(60, 213);
	glVertex2i(65, 228);
	glVertex2i(70, 235);
	glVertex2i(80, 245);
	glVertex2i(90, 240);
	glVertex2i(110, 245);
	glVertex2i(120, 238);
	glVertex2i(140, 230);
	glVertex2i(150, 225);
	glVertex2i(170, 230);
	glVertex2i(180, 210);
	glVertex2i(190, 200);
	glVertex2i(210, 180);
	glVertex2i(230, 185);
	glVertex2i(250, 185);
	glVertex2i(260, 175);
	glVertex2i(270, 175);
	glVertex2i(280, 165);
	glVertex2i(300, 120);

	glEnd();

}

void Tilla_Two_Model(){

	glColor3f(0.1, 1.293, 0.0);
    /// Left_Part
    glPushMatrix();
    glTranslatef(430,140,0);
    circle(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420,137,0);
    circle(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,130,0);
    circle(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,130,0);
    circle(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390,120,0);
    circle(50);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(445,130,0);
    circle(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455,125,0);
    circle(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,120,0);
    circle(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470,115,0);
    circle(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480,110,0);
    circle(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485,105,0);
    circle(40);
    glPopMatrix();



}
///*** House_Model ***///
void house(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 155);
	glVertex2i(285, 180);
	glVertex2i(380, 165);
	glVertex2i(380, 155);

	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 155);
	glVertex2i(285, 170);
	glVertex2i(380, 155);
	glVertex2i(380, 155);

	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 120);
	glVertex2i(290, 154);
	glVertex2i(375, 154);
	glVertex2i(375, 120);

	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 120);
	glVertex2i(350, 154);
	glVertex2i(375, 154);
	glVertex2i(375, 120);

	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 120);
	glVertex2i(330, 150);
	glVertex2i(350, 150);
	glVertex2i(350, 120);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 125);
	glVertex2i(295, 140);
	glVertex2i(310, 140);
	glVertex2i(310, 125);

	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 125);
	glVertex2i(312, 140);
	glVertex2i(327, 140);
	glVertex2i(327, 125);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 125);
	glVertex2i(355, 140);
	glVertex2i(370, 140);
	glVertex2i(370, 125);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 140);
	glVertex2i(257, 154);
	glVertex2i(290, 154);
	glVertex2i(290, 140);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 120);
	glVertex2i(255, 140);
	glVertex2i(290, 140);
	glVertex2i(290, 120);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 120);
	glVertex2i(260, 130);
	glVertex2i(285, 130);
	glVertex2i(285, 120);

	glEnd();


}

///*** House_Model2 ***///
void house2(){
     glColor3ub (255, 204, 153); //house body
    glBegin(GL_QUADS);
    glVertex2f(520, 120); //bottom
    glVertex2f(637, 120);
    glVertex2f(520, 160);//top
    glVertex2f(637, 160);
    glVertex2f(520, 160);//left
    glVertex2f(520, 120);
    glVertex2f(637, 160);//right
    glVertex2f(637, 120);
    glEnd();
    ///////////door
    glColor3ub (102, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2f(530, 120);//bottom
    glVertex2f(550, 120);
    glVertex2f(530, 160);//top
    glVertex2f(550, 160);
    glVertex2f(530, 160);//left
    glVertex2f(530, 120);
    glVertex2f(550, 160);//right
    glVertex2f(550, 120);
    glEnd();
    ////////window
    glColor3ub (153,102,51);
    glPointSize(4.0);
    glRectf(560,130,590,140);
//    glEnd();

    glColor3ub (153,102,51);
    glPointSize(4.0);
    glRectf(600,130,630,140);

     glColor3ub (151, 102, 153); //HUT head triangle
    glBegin(GL_POLYGON);
    glVertex2f(500, 150); //bottom
    glVertex2f(657, 150);
    glVertex2f(520, 180);//top
    glVertex2f(637, 180);
    glVertex2f(500, 150);//left
    glVertex2f(520, 180);
    glVertex2f(657, 150);//right
    glVertex2f(637, 180);
    glEnd();
}

///*** House Model 3 ***///
void house3()
{
    //backhead 1
    glBegin(GL_POLYGON);
    glColor3ub (15, 82, 163);
    glVertex2f(32,140);
    glVertex2f(65,190);
    glVertex2f(95,140);
    glEnd();
    //backhead 2
    glBegin(GL_POLYGON);
    glColor3ub (15, 82, 163);
    glVertex2f(135,140);
    glVertex2f(165,190);
    glVertex2f(198,140);
    glEnd();
    //back room
    glBegin(GL_POLYGON);
    glColor3ub (151, 102, 153);
    glVertex2f(40,120);
    glVertex2f(40,150);
    glVertex2f(190,150);
    glVertex2f(190,120);
    glEnd();
    //backhead Big
    glBegin(GL_POLYGON);
    glColor3ub (155, 122, 173);
    glVertex2f(70,145);
    glVertex2f(115,210);
    glVertex2f(160,145);
    glEnd();
    //front room
    glBegin(GL_POLYGON);
    glColor3ub (158, 182, 133);
    glVertex2f(90,120);
    glVertex2f(90,160);
    glVertex2f(140,160);
    glVertex2f(140,120);
    glEnd();
    ////////window
    glColor3ub (153,102,51);
    glPointSize(4.0);
    glRectf(55,125,75,145);
    ////////window
    glColor3ub (153,102,51);
    glPointSize(4.0);
    glRectf(155,125,175,145);
    //Door
    glBegin(GL_POLYGON);
    glColor3ub (153,102,51);
    glVertex2f(105,120);
    glVertex2f(105,145);
    glVertex2f(125,145);
    glVertex2f(125,120);
    glEnd();
}

///*** ModernHouse_Model ***///
void ModernHouse_Model1(){
    glBegin(GL_POLYGON); //left side skirt 3
    glColor3ub (21,67,96);
    glVertex2f(-5,110);
    glVertex2f(25,310);
    glVertex2f(25,130);
    glEnd();
    glBegin(GL_POLYGON); //left side skirt 2
    glColor3ub (21,97,96);
    glVertex2f(5,110);
    glVertex2f(35,310);
    glVertex2f(35,130);
    glEnd();
    glBegin(GL_POLYGON); //left side skirt
    glColor3ub (21,67,96);
    glVertex2f(15,110);
    glVertex2f(45,310);
    glVertex2f(45,130);
    glEnd();
    glBegin(GL_POLYGON); //front base
    glColor3ub (21,87,96);
    glVertex2f(0,100);
    glVertex2f(45,130);
    glVertex2f(205,130);
    glVertex2f(250,100);
    glEnd();
    glBegin(GL_POLYGON); //building back
    glColor3ub (21,107,96);
    glVertex2f(45,130);
    glVertex2f(45,310);
    glVertex2f(205,310);
    glVertex2f(205,130);
    glEnd();
    glBegin(GL_POLYGON); //building top
    glColor3ub (21,137,96);
    glVertex2f(45,310);
    glVertex2f(70,325);
    glVertex2f(225,325);
    glVertex2f(205,310);
    glEnd();
    glBegin(GL_POLYGON); //building right wall
    glColor3ub (21,157,96);
    glVertex2f(205,310);
    glVertex2f(225,325);
    glVertex2f(225,145);
    glVertex2f(205,130);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub (21,67,96); //right side skirt 3
    glVertex2f(255,110);
    glVertex2f(225,310);
    glVertex2f(225,130);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub (21,97,96); //right side skirt 2
    glVertex2f(245,110);
    glVertex2f(215,310);
    glVertex2f(215,130);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub (21,67,96); //right side skirt1
    glVertex2f(235,110);
    glVertex2f(205,310);
    glVertex2f(205,130);
    glEnd();

    for(int y=0; y<150; y=y+35)
    {
        for(int i=0; i<150; i=i+30)
        {
            glColor3ub (21,87,96); // Window Back
            glPointSize(4.0);
            glRectf(50+i,135+y,75+i,160+y);

            glColor3ub (21,127,96); // Window Front
            glPointSize(4.0);
            glRectf(52+i,137+y,73+i,158+y);
        }
    }
    glColor3ub (21,87,96); // door back
    glPointSize(4.0);
    glRectf(108,130,138,167);

    glColor3ub (21,107,96); // door Front
    glPointSize(4.0);
    glRectf(110,130,136,165);

}

void ModernHouse_Model2()
{
    glBegin(GL_POLYGON);    //Super Base
    glColor3ub (255, 204, 153);
    glVertex2i(240,90);
    glVertex2i(430,245);
    glVertex2i(390,245);
    glVertex2i(580,90);
    glEnd();

    glColor3f(1.0, .255, 1.0);
    glRectf(260,145,330,360);

    glBegin(GL_POLYGON);    //top left back building
    glColor3f( 1.0, .955, 1.0);
    glVertex2i(260,360);
    glVertex2i(275,375);
    glVertex2i(345,375);
    glVertex2i(330,360);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, .555, 1.0);
    glVertex2i(330,360);
    glVertex2i(345,375);
    glVertex2i(345,160);
    glVertex2i(330,145);
    glEnd();

    for(int y=0; y<180; y=y+26)
    {
        for(int i=0; i<40; i=i+17)
        {
            glColor3f( 1.0, .655, 1.0);
            glRectf(270+i,170+y,285+i,190+y);
        }
    }

    glColor3f(1.0, 1.0, .255);
    glRectf(500,145,570,430);

    glBegin(GL_POLYGON);    //top right back building
    glColor3f(1.0, 1.0, .955);
    glVertex2i(500,430);
    glVertex2i(485,445);
    glVertex2i(555,445);
    glVertex2i(570,430);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, .555);
    glVertex2i(500,430);
    glVertex2i(485,445);
    glVertex2i(485,160);
    glVertex2i(500,145);
    glEnd();

    for(int y=0; y<260; y=y+26)
    {
        for(int i=0; i<40; i=i+17)
        {
            glColor3f(1.0, 1.0, .655);
            glRectf(510+i,165+y,525+i,185+y);
        }
    }

    glColor3f(.555, .255, 1.0);
    glRectf(280,130,530,280);

    glBegin(GL_POLYGON);    ///top middle middle building
    glColor3f(.555, .555, 1.0);
    glVertex2i(280,280);
    glVertex2i(295,295);
    glVertex2i(540,295);
    glVertex2i(530,280);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.555, .755, 1.0);
    glVertex2i(530,280);
    glVertex2i(540,295);
    glVertex2i(540,145);
    glVertex2i(530,130);
    glEnd();

    for(int y=0; y<140; y=y+24)
    {
        for(int i=0; i<240; i=i+24)
        {
            glColor3f(.255, 1.0, 1.0);
            glRectf(285+i,135+y,305+i,155+y);
        }
    }

    glColor3f(0.255, 0.255, 3.255);
    glRectf(230,115,300,230);

    glBegin(GL_POLYGON);    //top left front building
    glColor3f(0.955, 0.955, 3.955);
    glVertex2i(230,230);
    glVertex2i(245,245);
    glVertex2i(315,245);
    glVertex2i(300,230);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.555, 0.555, 3.555);
    glVertex2i(300,230);
    glVertex2i(315,245);
    glVertex2i(315,130);
    glVertex2i(300,115);
    glEnd();

    for(int i=0; i<60; i=i+12)
    {
        glColor3f(.855, 1.0, 1.0);
        glRectf(235+i,120,245+i,150);

        glColor3f(.855, 1.0, 1.0);
        glRectf(235+i,155,245+i,185);

        glColor3f(.855, 1.0, 1.0);
        glRectf(235+i,190,245+i,220);
    }

    glColor3f(.255, 1.0, 1.0);
    glRectf(530,115,600,190);

    glBegin(GL_POLYGON);    //top right front building
    glColor3f(.955, 1.0, 1.0);
    glVertex2i(530,190);
    glVertex2i(515,205);
    glVertex2i(585,205);
    glVertex2i(600,190);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
    glVertex2i(530,190);
    glVertex2i(515,205);
    glVertex2i(515,130);
    glVertex2i(530,115);
    glEnd();

    for(int i=0; i<60; i=i+12)
    {
        glColor3f(.855, 1.0, 1.0);
        glRectf(535+i,120,545+i,150);

        glColor3f(.855, 1.0, 1.0);
        glRectf(535+i,155,545+i,185);
    }
}

///*** Field_Model ***///
void field(){
    ///Field
	glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
    //glColor3ub(122,132,123);
	glVertex2i(0, 70);
	glVertex2i(0, 120);
	glVertex2i(1000, 120);
	glVertex2i(1000, 70);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);
	//glColor3ub(122,132,123);
	glVertex2i(0, 0);
	glVertex2i(0, 70);
	glVertex2i(1000, 70);
	glVertex2i(1000, 0);

	glEnd();


}
void Road()
{
    int roadClr =0;
    for(int i=0; i<1000; i=i+50)
    {
        glBegin(GL_POLYGON); // ROad Skirt up
        if(i==0 || i%100==0)
        {
            glColor3ub(382,115,123);
        }
        else
        {
            glColor3ub(0,0,0);
        }
        glVertex2i(0+i,65);
        glVertex2i(0+i,70);
        glVertex2i(50+i,70);
        glVertex2i(50+i,65);
        glEnd();

        glBegin(GL_POLYGON); // Road Mid
        glColor3ub(158,182,roadClr);
        glVertex2i(0+i,5);
        glVertex2i(0+i,65);
        glVertex2i(50+i,65);
        glVertex2i(50+i,5);
        glEnd();
        roadClr=roadClr+10;

        glBegin(GL_POLYGON); // ROad Skirt down
        if(i==0 || i%100==0)
        {
            glColor3ub(382,115,123);
        }
        else
        {
            glColor3ub(0,0,0);
        }
        glVertex2i(0+i,0);
        glVertex2i(0+i,5);
        glVertex2i(50+i,5);
        glVertex2i(50+i,0);
        glEnd();
    }
}

void RoadMidSkirt()
{
    for(int i=0; i<1000; i=i+20)
    {
        glBegin(GL_POLYGON); // ROad Skirt up
        if(i==0 || i%100==0)
        {
            glColor3ub(158,182,133);
        }
        else
        {
            glColor3ub(0,0,0);
        }
        glVertex2i(0+i,30);
        glVertex2i(0+i,35);
        glVertex2i(20+i,35);
        glVertex2i(20+i,30);
        glEnd();
    }
}
///*** Tree_Model ***///
void Tree_Model_One(){


    glPushMatrix();
    glTranslatef(110,112,0);
    circle(25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,90,0);
    circle(10);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(109, 70);
	glVertex2f(109, 90);
	glVertex2f(111, 90);
	glVertex2f(111, 70);

    glEnd();

}
void Tree_Model_Two(){

    glPushMatrix();
    glTranslatef(130,90,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,86,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,86,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,85,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(129, 70);
	glVertex2f(129, 84);
	glVertex2f(131, 84);
	glVertex2f(131, 70);

    glEnd();
}

void Tree_Model_Three(){


    glBegin(GL_POLYGON);
	glVertex2f(125, 90);
	glVertex2f(133, 105);
	glVertex2f(141, 90);
	glEnd();

    glBegin(GL_POLYGON);
	glVertex2f(125, 83);
	glVertex2f(133, 115);
	glVertex2f(141, 83);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(132, 70);
	glVertex2f(132, 84);
	glVertex2f(134, 84);
	glVertex2f(134, 70);
    glEnd();
}

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model(){

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 120);
    glVertex2i(380, 320);
    glVertex2i(384, 320);
    glVertex2i(390, 120);
    glEnd();
}

///*** Windmill_Blades_Model ***///

void Windmill_Blade(){
///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///*** Windmill_Final_Model ***///
void Windmill(){



        ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,330,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,330,0);
    Windmill_Blade();
    glPopMatrix();




}


///Model_End
///=======================================================================================================///


///=================///
///***   Object  ***///
///=================///

///*** Sun ***///
void Sun(){
    glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}
///*** Cloud_One_Model_One ***///
void cloud_one(){
    glPushMatrix();
    glTranslatef(cx,20,0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Two_Model_one ***///

void cloud_two(){
    glPushMatrix();
    glTranslatef(bx+100,150,0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Three_Model_Two ***///

void cloud_three(){
    glPushMatrix();
    glTranslatef(ax-80,80,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Four_Model_Two ***///

void cloud_four(){
    glPushMatrix();
    glTranslatef(dx+300,125,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Five_Model_Three ***///
void cloud_five(){

    glPushMatrix();
    glTranslatef(ax+-300,170,0);
    cloud_model_Three();
    glPopMatrix();
}
///*** Cloud_Six_Model_Three ***///
void cloud_six(){

    glPushMatrix();
    glTranslatef(cx+-500,20,0);
    cloud_model_Three();
    glPopMatrix();
}

///*** House_One ***///
void house_one(){
    glPushMatrix();
    glTranslatef(-200,0,0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_two(){
    glPushMatrix();
    glTranslatef(450,0,0);
    house();
    glPopMatrix();
}
///*** House_Four ***///
void house_four(){
    glPushMatrix();
    glTranslatef(220,0,0);
    house3();
    glPopMatrix();
}
///*** House_Three ***///
void house_three(){
    glPushMatrix();
    glTranslatef(50, 0,0);
    house2();
    glPopMatrix();
}
///*** House_five ***///
void house_five(){
    glPushMatrix();
    glTranslatef(850, 0,0);
    house3();
    glPopMatrix();
}

///*** ModernHouse_one ***///
void ModernHouse_one(){
    glPushMatrix();
    glTranslatef(0, 0,0);
    ModernHouse_Model1();
    glPopMatrix();
}
void ModernHouse_two(){
    glPushMatrix();
    glTranslatef(830, 0,0);
    ModernHouse_Model1();
    glPopMatrix();
}

void ModernHouse_three(){
    glPushMatrix();
    glTranslatef(0, 0,0);
    ModernHouse_Model2();
    glPopMatrix();
}
///*** Bridge ***///
void bridge(){
    glPushMatrix();
    glTranslatef(0,-50,0);
    bridge_model();
    glPopMatrix();
}
///*** Hill_big_One ***///
void Hill_Big_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two(){
    glPushMatrix();
    glTranslatef(550,-20,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_Small_One ***///
void Hill_Small_One(){
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_small();
    glPopMatrix();

}
/// *** Tilla_One_Model_One ***///

void Tilla_One(){

    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_One_Model();
    glPopMatrix();

}
/// *** Tilla_Two_Model_Two ***///
void Tilla_Two(){

    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Three_Model_Two ***///
void Tilla_Three(){

    glPushMatrix();
    glTranslatef(100,35,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Four_Model_One ***///
void Tilla_Four(){

    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(850,0,0);
    Tilla_One_Model();
    glPopMatrix();


}
///*** Tree_1 ***///
void Tree_One(){
    glColor3ub(3,90,30);
    glPushMatrix();
    glTranslatef(120,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two(){
    glColor3ub(3,90,30);
    glPushMatrix();
    glTranslatef(320,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three(){
    glColor3ub(40,180,99);
    glPushMatrix();
    glTranslatef(580,0,0);
    Tree_Model_One();
    glPopMatrix();
}
///*** Tree_4 ***///
void Tree_Four(){
    glColor3ub(40,180,99);
    glPushMatrix();
    glTranslatef(750,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_5 ***///
void Tree_Five(){
    glColor3ub(40,180,90);
    glPushMatrix();
    glTranslatef(-10,30,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_6 ***///
void Tree_Six(){
    glColor3ub(3,71,23);
    glPushMatrix();
    glTranslatef(30,30,0);
    Tree_Model_Two();
    glPopMatrix();
}
///*** Tree_7 ***///
void Tree_Seven(){
    glColor3ub(3,71,23);
    glPushMatrix();
    glTranslatef(600,15,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***///
void Tree_Eight(){
    glColor3ub(40,180,99);
    glPushMatrix();
    glTranslatef(630,30,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_9 ***///
void Tree_Nine(){
    glColor3ub(3,90,30);
    glPushMatrix();
    glTranslatef(680,20,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_10 ***///
void Tree_Ten(){
    glColor3ub(40,180,90);
    glPushMatrix();
    glTranslatef(180,20,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_11 ***///
void Tree_Eleven(){
    glColor3ub(3,71,23);
    glPushMatrix();
    glTranslatef(220,20,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_12 ***///
void Tree_Twelve(){
    glColor3ub(3,90,30);
    glPushMatrix();
    glTranslatef(428,20,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_13 ***///
void Tree_Thirteen(){
    glColor3ub(3,71,23);
    glPushMatrix();
    glTranslatef(160,0,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_14 ***///
void Tree_fourteen(){
    glColor3ub(40,180,90);
    glPushMatrix();
    glTranslatef(240,0,0);
    Tree_Model_Three();
    glPopMatrix();
}

/// *** Tractor One ***///
void Tractor_One()
{
    glPushMatrix();
    glTranslatef(tr11,0,0);
    Tractor_Model();
    glPopMatrix();
}

/// *** Tractor Two ***///
void Tractor_Two()
{
    glPushMatrix();
    glTranslatef(tr12,0,0);
    Tractor_Model2();
    glPopMatrix();
}

/// *** Tractor Three ***///
void Tractor_Three()
{
    glPushMatrix();
    glTranslatef(tr22,20,0);
    Tractor_Model();
    glPopMatrix();
}

/// *** Grass ***///
void Grass_One()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    Grass_Model();
    glPopMatrix();
}
void Grass_Two()
{
    glPushMatrix();
    glTranslatef(25,-25,0);
    Grass_Model();
    glPopMatrix();
}

/// *** Train ***///
void train()
{
    glPushMatrix();
    glTranslatef(trn,75,0);
    train_model();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(-50,0,0);
    Windmill();
    glPopMatrix();

}

void Windmill_Two(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,0,0);
    Windmill();
    glPopMatrix();

}
void Windmill_Three(){
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(58,0,0);
    Windmill();
    glPopMatrix();

}
void keyboard(unsigned char key, int x, int y){

	 if (key == 't')
		if(trainST == 0)
            trainST = 1;
        else
            trainST = 0;
	else if (key == 'b')
        if(bridgeST == 0)
            bridgeST = 1;
        else
            bridgeST = 0;
	else if (key == '1')
        if(mb1 == 0)
            mb1=1;
        else
            mb1=0;
	else if (key == '2')
        if(mb2 == 0)
            mb2=1;
        else
            mb2=0;
    else if (key == '3')
        if(mb3 == 0)
            mb3=1;
        else
            mb3=0;
    else if (key == 'g')
        if(grassST == 0)
            grassST=1;
        else
            grassST=0;
    else if (key == 'w')
        if(treeBigST == 0)
            treeBigST=1;
        else
            treeBigST=0;
    else if (key == 'l')
        if(tillaST == 0)
            tillaST=1;
        else
            tillaST=0;

    else if (key == 'r')
        if(roadST == 0)
            roadST=1;
        else
            roadST=0;
    else if (key == 'e')
        if(roadMidST == 0)
            roadMidST=1;
        else
            roadMidST=0;

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

    ///*** Object_Layer ***///
    Sun();
    Windmill_Three();
    if(tillaST==1)
        Tilla_Four();
    cloud_three();
    cloud_four();
    Windmill_One();
    Windmill_Two();
    if(tillaST==1)
        Tilla_Three();
        Tilla_One();
        Tilla_Two();
    if(bridgeST==1)
        bridge();
    house_one();
    cloud_one();
    house_two();
    house_four();
    house_three();

    cloud_two();
    cloud_five();
    cloud_six();
    house_five();
    field();
    if(roadST==1)
        Road();
    if(roadMidST==1)
        RoadMidSkirt();
    if(mb1==1)
        ModernHouse_three();
    if(mb2==1)
        ModernHouse_two();
    if(mb3==1)
        ModernHouse_one();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();
    if(bridgeST==1)
        bridge();
    if(trainST==1)
        train();
    if(treeBigST==1)
        {Tree_One();
        Tree_Two();
        Tree_Three();
        Tree_Four();}
    Tree_Thirteen();
    Tree_fourteen();
    if(grassST==1)
        Grass_One();
    Tractor_Three();
    if(grassST==1)
        Grass_Two();
    Tractor_One();
    Tractor_Two();

	glFlush();
}
///========================///
///*** Speed & Movement ***///
///========================///
///*** Sun_Move ***///
void sun_move(){

    sun_spin = sun_spin + 0.0008;
    if(sun_spin>20){
            sun_spin = 0;
    }
}
void move_right(){

    sun_move();

    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;
    tr11 = tr11 - .10;
    tr12 = tr12 + .10;
    tr22 = tr22 - .15;



    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;

    }
    if(cx>1000){
            cx= -400;

    }
    if(dx>1000){
            dx= -500;

    }

    if(tr11<-1000){
            tr11= 100;

    }

    if(tr12>1000){
            tr12= -200;

    }
    if(tr22<-1000){
            tr22= 200;
    }

        if(trainST==1)
    {
        trn = trn - .20;
        if(trn<-1100)
        {
            trn=500;
        }
    }
    glutPostRedisplay();
}

void mouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 50);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("Industrialized Modern Rebellion");

	glutKeyboardFunc(keyboard);
	init();
	glutDisplayFunc(display);

    glutMouseFunc(mouse);

    glutFullScreen();
	glutMainLoop();
}
