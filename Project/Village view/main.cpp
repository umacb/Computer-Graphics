#include<iostream>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<Windows.h>
#include<mmsystem.h>

using namespace std;


void DrawCircle(float cx,float cy,float r,int num_segments)
{
    glBegin(GL_POLYGON);
    for (int i=0; i<num_segments;i++ )
    {
        float theta = 2.0f * 3.1415926f * float(i)/float(num_segments);
        float x= r * cosf(theta);
        float y = r*sinf(theta);

        glVertex2f(x+cx, y+cy);
    }

    glEnd();

}

void daySky()
{
    glBegin(GL_QUADS);


    glColor3ub (248, 249, 222);
    glVertex2i(0,315);  //sky
    glColor3ub (132, 192, 255);
    glVertex2i(1200,315);
    glVertex2i(1200,0);
    glColor3ub (248, 249, 222);
    glVertex2i(0,0);

    glEnd();
}
void nightSky()
{
    glBegin(GL_QUADS);

    glColor3ub (132, 192, 255);
    glVertex2i(0,315);  //sky
    glVertex2i(1200,315);
    glVertex2i(1200,0);
    glVertex2i(0,0);

    glEnd();
}

void field()
{
    glBegin(GL_QUADS);

    glColor3ub (49, 140, 12);

    glVertex2i(0,700);  //field
    glVertex2i(1200,700);

    glColor3ub (192, 209, 127);

    glVertex2i(1200,315);
    glVertex2i(0,315);

    glEnd();
}

void river()
{
    glBegin(GL_POLYGON);

    glColor3ub (119, 207, 239);

    glVertex2i(0,700);  //river
    glVertex2i(850,700);
    glVertex2i(725,670);
    glVertex2i(783,650);
    glVertex2i(623,633);
    glVertex2i(675,610);
    glVertex2i(465,570);
    glVertex2i(605,535);
    glVertex2i(350,475);
    glVertex2i(463,455);
    glVertex2i(305,435);
    glVertex2i(500,365);
    glVertex2i(545,315);
    glColor3ub (248, 252, 199);
    glVertex2i(0,315);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3ub (0, 0, 0);

    glVertex2i(850,700); //river
    glVertex2i(725,670);
    glVertex2i(783,650);
    glVertex2i(623,633);
    glVertex2i(675,610);
    glVertex2i(465,570);
    glVertex2i(605,535);
    glVertex2i(400,488);
    glVertex2i(463,455);
    glVertex2i(379,445);
    glVertex2i(500,365);
    glVertex2i(545,315);
    glVertex2i(0,315);

    glEnd();

}

void nightRiver()
{
    glBegin(GL_POLYGON);

        //glColor3ub (56, 160, 229);
    glColor3ub (119, 207, 239);

    glVertex2i(0,700);  //river
    glVertex2i(850,700);
    glVertex2i(725,670);
    glVertex2i(783,650);
    glVertex2i(623,633);
    glVertex2i(675,610);
    glVertex2i(465,570);
    glVertex2i(605,535);
    glVertex2i(350,475);
    glVertex2i(463,455);
    glVertex2i(305,435);
    glVertex2i(500,365);
    glVertex2i(545,315);
    glColor3ub (255, 255, 255);
    glVertex2i(0,315);

    glEnd();
}

float positionSun=0;

float speedSun=1.0;

void sunUp()
{
    if (positionSun < -230)
    {
        positionSun= -230;

    }
    positionSun -= speedSun;

   glutPostRedisplay();
}

void sun() //sun
{

    glPushMatrix();
    glTranslated(0 , positionSun, 0);
    glColor3ub(255,185,35);
    DrawCircle(250,370,50,1000);
    glPopMatrix();

}

float positionMoon=0;
float speedMoon=1.0;

void moonDown()
{
    if (positionMoon > 190)
    {
        positionMoon= 190;

    }
    positionMoon += speedMoon;

   glutPostRedisplay();
}

void moon() //moon
{
    glPushMatrix();
    glTranslated(0 , positionMoon, 0);
    glColor3ub(255,255,255);
    DrawCircle(200,-50,50,1000);

    glColor3ub (132, 192, 255);
    DrawCircle(230,-70,50,1000);
    glPopMatrix();

}

float position1=0;
float position2=0;
float position3=0;
float position4=0;

float speed1=0.3;
float speed2=0.6;
float speed3=0.1;
float speed4=0.9;

void cloud1()
{
    if (position1 > 1200)
    {
        position1=-185;

    }
    position1 += speed1;

   glutPostRedisplay();

}

void cloud2()
{
    if (position2 > 950)
    {
        position2=-410;

    }
    position2 += speed2;

    glutPostRedisplay();
}

void cloud3()
{
    if (position3 > 750)
    {
        position3=-605;

    }
    position3 += speed3;

    glutPostRedisplay();
}

void cloud4()
{
    if (position4 > 200)
    {
        position4=-1185;

    }
    position4 += speed4;

    glutPostRedisplay();
}


void drawCloud() // Megh
{

    glPushMatrix();
    glTranslated(position1,0, 0);

    glColor3f(0.8,0.8,0.8); //1st megh
    DrawCircle(30,185,25,1000);
    DrawCircle(50,160,20,1000);
    DrawCircle(75,140,20,1000);
    DrawCircle(107,125,30,1000);
    DrawCircle(140,155,30,1000);
    DrawCircle(75,180,35,1000);
    DrawCircle(120,175,35,1000);
    DrawCircle(165,190,20,1000);

    glPopMatrix();

    glPushMatrix();
    glTranslated(position2,0, 0);

    glColor3f(0.8,0.8,0.8); //2nd megh
    DrawCircle(265,70,20,1000);
    DrawCircle(285,50,20,1000);
    DrawCircle(310,30,25,1000);
    DrawCircle(338,35,20,1000);
    DrawCircle(360,45,17,1000);
    DrawCircle(380,55,18,1000);
    DrawCircle(390,75,20,1000);
    DrawCircle(305,65,30,1000);
    DrawCircle(350,65,30,1000);

    glPopMatrix();

    glPushMatrix();
    glTranslated(position3,0, 0);

    glColor3f(0.8,0.8,0.8); //3rd megh
    DrawCircle(485,142,25,1000);
    DrawCircle(500,120,20,1000);
    DrawCircle(530,105,25,1000);
    DrawCircle(560,115,20,1000);
    DrawCircle(580,140,25,1000);
    DrawCircle(515,150,25,1000);
    DrawCircle(550,150,25,1000);
    DrawCircle(540,135,25,1000);

    glPopMatrix();

    glPushMatrix();
    glTranslated(position4,0, 0);

    glColor3f(0.8,0.8,0.8); //4th megh
    DrawCircle(1030,85,25,1000);
    DrawCircle(1050,58,20,1000);
    DrawCircle(1075,35,25,1000);
    DrawCircle(1105,45,20,1000);
    DrawCircle(1135,60,25,1000);
    DrawCircle(1075,85,35,1000);
    DrawCircle(1125,90,35,1000);
    DrawCircle(1160,80,25,1000);

    glPopMatrix();


}

void drawTree()
{
    glBegin(GL_QUADS);

    glColor3ub(100,30,22);

    glVertex2i(787,368);//middle big tree START
    glVertex2i(811,368);
    glVertex2i(811,258);
    glVertex2i(787,258);
    glVertex2i(787,258);
    glVertex2i(811,258);
    glVertex2i(838,105);
    glVertex2i(830,102);
    glVertex2i(825,182);
    glVertex2i(887,119);
    glVertex2i(883,114);
    glVertex2i(823,162);
    glVertex2i(820,157);
    glVertex2i(823,143);
    glVertex2i(802,115);
    glVertex2i(796,115);
    glVertex2i(804,226);
    glVertex2i(809,216);
    glVertex2i(771,164);
    glVertex2i(767,166);
    glVertex2i(794,204);
    glVertex2i(795,194);
    glVertex2i(752,171);
    glVertex2i(750,173);//Middle big tree END





    glVertex2i(917,383);//Right big tree
    glVertex2i(935,378);
    glVertex2i(938,271);
    glVertex2i(916,270);
    glVertex2i(916,270);
    glVertex2i(938,271);
    glVertex2i(923,215);
    glVertex2i(908,238);
    glVertex2i(908,238);
    glVertex2i(915,231);
    glVertex2i(883,174);
    glVertex2i(880,182);
    glVertex2i(915,228);
    glVertex2i(922,230);
    glVertex2i(985,155);
    glVertex2i(983,150);
    glVertex2i(932,209);
    glVertex2i(936,208);
    glVertex2i(936,163);
    glVertex2i(928,164);
    glVertex2i(930,331);
    glVertex2i(1016,230);
    glVertex2i(1014,224);
    glVertex2i(929,305);




    glBegin(GL_QUADS); //LEFT  RIVER TREE

    glColor3ub(153,81,10);
    glVertex2i(327,316);
    glVertex2i(337,316);
    glVertex2i(322,251);
    glVertex2i(312,251);
    glVertex2i(312,251);
    glVertex2i(322,251);
    glVertex2i(323,212);
    glVertex2i(314,212);

    glVertex2i(351,316);// Right river tree
    glVertex2i(359,315);
    glVertex2i(370,204);
    glVertex2i(362,203);
    glVertex2i(362,203);
    glVertex2i(370,204);
    glVertex2i(379,175);
    glVertex2i(373,174);

    glVertex2i(375,317);//third tree
    glVertex2i(385,316);
    glVertex2i(413,271);
    glVertex2i(403,268);
    glVertex2i(413,271);
    glVertex2i(403,268);
    glVertex2i(450,238);
    glVertex2i(443,231);

    glEnd();

    glBegin(GL_POLYGON);


    glColor3ub (49, 140, 12);


    glVertex2i(314,213); //river left tree leaf
    glVertex2i(319,213);
    glVertex2i(338,184);
    glVertex2i(334,178);
    glVertex2i(345,169);
    glVertex2i(337,168);
    glVertex2i(345,155);
    glVertex2i(340,154);
    glVertex2i(355,127);
    glVertex2i(329,154);

    glVertex2i(313,212);
    glVertex2i(319,212);
    glVertex2i(316,194);
    glVertex2i(262,134);
    glVertex2i(279,157);
    glVertex2i(277,162);
    glVertex2i(283,168);
    glVertex2i(282,173);
    glVertex2i(285,176);
    glVertex2i(284,182);
    glVertex2i(288,185);
    glVertex2i(288,192);

    glVertex2i(313,214);
    glVertex2i(317,214);
    glVertex2i(317,204);
    glVertex2i(262,204);
    glVertex2i(233,216);
    glVertex2i(252,212);
    glVertex2i(256,217);
    glVertex2i(263,213);
    glVertex2i(268,218);
    glVertex2i(276,217);
    glVertex2i(278,220);
    glVertex2i(283,217);
    glVertex2i(285,222);

    glVertex2i(314,214);
    glVertex2i(313,209);
    glVertex2i(285,243);
    glVertex2i(288,247);
    glVertex2i(280,270);
    glVertex2i(291,255);
    glVertex2i(292,269);
    glVertex2i(300,244);
    glVertex2i(304,244);
    glVertex2i(304,237);
    glVertex2i(308,234);

    glVertex2i(316,212);
    glVertex2i(320,239);
    glVertex2i(326,239);
    glVertex2i(326,247);
    glVertex2i(333,249);
    glVertex2i(341,266);
    glVertex2i(342,243);
    glVertex2i(321,213);

    glVertex2i(317,212);
    glVertex2i(339,215);
    glVertex2i(340,222);
    glVertex2i(346,214);
    glVertex2i(355,220);
    glVertex2i(355,214);
    glVertex2i(368,218);
    glVertex2i(368,213);
    glVertex2i(385,216);
    glVertex2i(359,203);
    glVertex2i(315,202);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (49, 140, 12);

    glVertex2i(376,175);//right river tree leaf
    glVertex2i(395,179);
    glVertex2i(397,186);
    glVertex2i(403,179);
    glVertex2i(409,180);
    glVertex2i(411,186);
    glVertex2i(416,181);
    glVertex2i(437,190);
    glVertex2i(411,167);
    glVertex2i(378,167);

    glVertex2i(394,160);
    glVertex2i(390,158);
    glVertex2i(400,147);
    glVertex2i(392,146);
    glVertex2i(400,131);
    glVertex2i(394,130);
    glVertex2i(413,104);
    glVertex2i(389,127);
    glVertex2i(379,149);
    glVertex2i(375,173);


    glVertex2i(374,163);
    glVertex2i(365,148);
    glVertex2i(345,135);
    glVertex2i(320,137);
    glVertex2i(344,142);
    glVertex2i(350,152);
    glVertex2i(353,151);
    glVertex2i(345,160);
    glVertex2i(361,159);
    glVertex2i(360,167);


    glVertex2i(357,173);
    glVertex2i(347,175);
    glVertex2i(324,189);
    glVertex2i(340,186);
    glVertex2i(340,193);
    glVertex2i(352,192);
    glVertex2i(346,206);
    glVertex2i(370,183);


    glVertex2i(376,178);
    glVertex2i(372,202);
    glVertex2i(377,203);
    glVertex2i(378,211);
    glVertex2i(384,211);
    glVertex2i(384,217);
    glVertex2i(389,219);
    glVertex2i(413,240);
    glVertex2i(403,206);
    glVertex2i(379,175);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (49, 140, 12);

    glVertex2i(443,239);//river third tree leaf
    glVertex2i(441,233);
    glVertex2i(418,228);
    glVertex2i(395,229);
    glVertex2i(371,244);
    glVertex2i(385,242);
    glVertex2i(391,253);
    glVertex2i(397,242);
    glVertex2i(403,250);
    glVertex2i(411,240);
    glVertex2i(415,246);
    glVertex2i(439,239);



    glVertex2i(444,237);
    glVertex2i(455,223);
    glVertex2i(461,179);
    glVertex2i(451,160);
    glVertex2i(454,177);
    glVertex2i(442,176);
    glVertex2i(446,188);
    glVertex2i(434,189);
    glVertex2i(441,201);
    glVertex2i(429,202);
    glVertex2i(442,237);

    glVertex2i(441,240);
    glVertex2i(479,245);
    glVertex2i(485,231);
    glVertex2i(499,243);
    glVertex2i(501,229);
    glVertex2i(513,238);
    glVertex2i(513,226);
    glVertex2i(531,225);
    glVertex2i(522,215);
    glVertex2i(486,212);
    glVertex2i(464,224);
    glVertex2i(439,240);


    glVertex2i(441,241);
    glVertex2i(446,242);
    glVertex2i(434,264);
    glVertex2i(446,262);
    glVertex2i(439,276);
    glVertex2i(453,273);
    glVertex2i(446,290);
    glVertex2i(460,279);
    glVertex2i(469,296);
    glVertex2i(469,276);
    glVertex2i(464,250);
    glVertex2i(445,237);





    glEnd();



    glColor3ub(49,140,12);
    DrawCircle(770,200,25,1000);
    DrawCircle(735,180,30,1000);
    DrawCircle(745,135,30,1000);
    DrawCircle(785,155,30,1000);

    DrawCircle(735,225,25,1000);
    DrawCircle(695,204,30,1000);
    DrawCircle(692,150,30,1000);
    DrawCircle(660,180,30,1000);


    DrawCircle(790,90,35,1000);// dark khoyeri tree 1
    DrawCircle(830,75,40,1000);
    DrawCircle(890,100,30,1000);
    DrawCircle(875,80,36,1000);

    DrawCircle(790,50,30,1000);// dark khoyeri tree 1
    DrawCircle(840,35,30,1000);
    DrawCircle(755,68,30,1000);
    DrawCircle(875,80,36,1000);
    DrawCircle(885,37,25,1000);
    DrawCircle(920,60,30,1000);




    DrawCircle(875,235,35,1000); // dark khoyeri tree 2
    DrawCircle(860,195,30,1000);
    DrawCircle(900,175,35,1000);
    DrawCircle(945,150,35,1000);
    DrawCircle(985,165,40,1000);
    DrawCircle(975,225,40,1000);
    DrawCircle(1045,190,40,1000);
    DrawCircle(1025,235,40,1000);
    DrawCircle(975,120,30,1000);
    DrawCircle(1030,140,35,1000);
    DrawCircle(1075,240,35,1000);
}

void house()
{

    glBegin(GL_QUADS);

        glColor3ub(145, 128, 108);
        glVertex2i(510, 400); //h2 south
        glVertex2i(608, 414);
        glVertex2i(608, 365);
        glVertex2i(510, 353);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(510, 400); //h2 south
        glVertex2i(608, 414);
        glVertex2i(608, 365);
        glVertex2i(510, 353);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub(0, 0, 0);
        glVertex2i(505, 410); //h2 south base
        glVertex2i(608, 424);
        glVertex2i(608, 414);
        glVertex2i(505, 400);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub(114, 82, 12);
        glVertex2i(540, 404); //h2 door
        glVertex2i(565, 408);
        glVertex2i(568, 365);
        glVertex2i(542, 363);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(540, 404); //h2 door
        glVertex2i(565, 408);
        glVertex2i(568, 365);
        glVertex2i(542, 363);

    glEnd();

    glBegin(GL_LINES);

        glColor3ub(0, 0, 0);
        glVertex2i(552, 405); //h2 door
        glVertex2i(553, 365);

    glEnd();



    glBegin(GL_POLYGON);

        glColor3ub(130, 114, 97);

        glVertex2i(608, 414);//h2 east
        glVertex2i(672, 408);
        glVertex2i(677, 350);
        glVertex2i(660, 327);
        glVertex2i(608, 368);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);

        glVertex2i(608, 414);//h2 east
        glVertex2i(672, 408);
        glVertex2i(677, 350);
        glVertex2i(660, 327);
        glVertex2i(608, 368);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3ub(0, 0, 0);

        glVertex2i(608, 424);//h2 east base
        glVertex2i(672, 418);
        glVertex2i(672, 408);
        glVertex2i(608, 414);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub(92, 66, 9);
        glVertex2i(626, 402); //h2 window
        glVertex2i(651, 400);
        glVertex2i(651, 379);
        glVertex2i(626, 381);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);

        glVertex2i(626, 402); //h2 window
        glVertex2i(651, 400);
        glVertex2i(651, 379);
        glVertex2i(626, 381);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3ub(178, 130, 3);

        glVertex2i(496, 368);//h2 roof front
        glVertex2i(600, 377);
        glVertex2i(660, 327);
        glVertex2i(610, 276);
        glVertex2i(561, 291);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);

        glVertex2i(496, 368);//h2 roof front
        glVertex2i(600, 377);
        glVertex2i(660, 327);
        glVertex2i(610, 276);
        glVertex2i(561, 291);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3ub(178, 130, 3);

        glVertex2i(680, 355);//h2 roof main
        glVertex2i(788, 288);
        glVertex2i(756, 264);
        glVertex2i(597, 270);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);

        glVertex2i(680, 355);//h2 roof main
        glVertex2i(788, 288);
        glVertex2i(756, 264);
        glVertex2i(597, 270);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3ub(178, 130, 3);

        glVertex2i(561, 291);//h2 roof tri
        glVertex2i(610, 276);
        glVertex2i(597, 270);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);

        glVertex2i(561, 291);//h2 roof tri
        glVertex2i(605, 277);
        glVertex2i(597, 270);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3ub(130, 114, 97);

        glVertex2i(672, 408);//h2 east 2
        glVertex2i(706, 409);
        glVertex2i(707, 363);
        glVertex2i(676, 362);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);

        glVertex2i(672, 408);//h2 east 2
        glVertex2i(706, 409);
        glVertex2i(707, 363);
        glVertex2i(676, 362);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3ub(0, 0, 0);

        glVertex2i(672, 418);//h2 east 2 base
        glVertex2i(706, 419);
        glVertex2i(707, 409);
        glVertex2i(672, 408);

    glEnd();


    glBegin(GL_QUADS);
        glColor3ub(229, 219, 107);//house 1

        glVertex2i(705, 430);//h1 south
        glVertex2i(814, 444);
        glVertex2i(817, 375);
        glVertex2i(705, 364);

    glEnd();

    glBegin(GL_LINE_STRIP);

        glColor3ub(0, 0, 0);
        glVertex2i(705, 364);
        glVertex2i(705, 430);//h1 south
        glVertex2i(814, 444);
        glVertex2i(817, 375);

    glEnd();

    glBegin(GL_LINES);

        glVertex2i(705, 430); //h1 base
        glVertex2i(705, 450);

        glVertex2i(814, 444);
        glVertex2i(814, 464);

        glVertex2i(944, 430);
        glVertex2i(944, 450);

        glVertex2i(884, 437);
        glVertex2i(884, 457);

        glVertex2i(765, 438);//h1 ladder
        glVertex2i(743, 468);

        glVertex2i(735, 434);
        glVertex2i(715, 460);

        glVertex2i(748, 460);
        glVertex2i(722, 450);

        glVertex2i(756, 450);
        glVertex2i(728, 440);


    glEnd();


    glBegin(GL_QUADS);

        glColor3ub(204, 195, 100);
        glVertex2i(814, 444);//h1 east
        glVertex2i(944, 430);
        glVertex2i(944, 360);
        glVertex2i(817, 375);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(814, 444);//h1 east
        glVertex2i(944, 430);
        glVertex2i(944, 360);
        glVertex2i(817, 375);

    glEnd();

    glBegin(GL_QUADS);

         glColor3ub(92, 66, 9);
        glVertex2i(854, 423); //h1 window east
        glVertex2i(898, 421);
        glVertex2i(900, 407);
        glVertex2i(855, 406);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(854, 423); //h1 window east
        glVertex2i(898, 421);
        glVertex2i(900, 407);
        glVertex2i(855, 406);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub(16, 59, 89);

        glVertex2i(886, 415);//h1 east shade
        glVertex2i(990, 405);
        glVertex2i(944, 360);
        glVertex2i(817, 375);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(886, 415);//h1 east shade
        glVertex2i(990, 405);
        glVertex2i(944, 360);
        glVertex2i(817, 375);

    glEnd();


    glBegin(GL_QUADS);

        glColor3ub(26, 92, 138);
        glVertex2i(672, 360);//h1 main shade
        glVertex2i(812, 383);
        glVertex2i(913, 284);
        glVertex2i(785, 277);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(672, 360);//h1 main shade
        glVertex2i(812, 383);
        glVertex2i(913, 284);
        glVertex2i(785, 277);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub(16, 59, 89);
        glVertex2i(944, 360); //h1 shade tri side
        glVertex2i(955, 362);
        glVertex2i(913, 284);
        glVertex2i(905, 292);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(944, 360); //h1 shade tri side
        glVertex2i(955, 362);
        glVertex2i(913, 284);
        glVertex2i(905, 292);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub(114, 82, 12);
        glVertex2i(735, 434);//h1 door
        glVertex2i(762, 437);
        glVertex2i(762, 393);
        glVertex2i(735, 391);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(735, 434);//h1 door
        glVertex2i(762, 437);
        glVertex2i(762, 393);
        glVertex2i(735, 391);

    glEnd();

    glBegin(GL_LINES);

        glColor3ub(0, 0, 0);
        glVertex2i(748, 434);//h1 door
        glVertex2i(748, 391);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub(114, 82, 12);
        glVertex2i(773, 420); //h1 window right
        glVertex2i(795, 421);
        glVertex2i(796, 402);
        glVertex2i(774, 401);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(773, 420); //h1 window right
        glVertex2i(795, 421);
        glVertex2i(796, 402);
        glVertex2i(774, 401);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub(114, 82, 12);
        glVertex2i(711, 413); //h1 window left
        glVertex2i(728, 414);
        glVertex2i(729, 397);
        glVertex2i(712, 396);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(711, 413); //h1 window left
        glVertex2i(728, 414);
        glVertex2i(729, 397);
        glVertex2i(712, 396);

    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3ub(16, 59, 89);

        glVertex2i(817, 375);//h1 shade tri
        glVertex2i(944, 360);
        glVertex2i(905, 292);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub(0, 0, 0);
        glVertex2i(817, 375);//h1 shade tri
        glVertex2i(944, 360);
        glVertex2i(905, 292);

    glEnd();

}

void boat1()
{
    glBegin(GL_POLYGON);

        glColor3ub (20, 20, 21);

        glVertex2i(320,560);  //fixed boat
        glVertex2i(470,555);
        glVertex2i(535,515);
        glVertex2i(485,530);
        glVertex2i(310,535);
        glVertex2i(235,525);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub (0,0,0);

        glVertex2i(263,467); //boitha
        glVertex2i(263,570);
        glVertex2i(267,570);
        glVertex2i(267,467);

    glEnd();

}


float positionBoat=0;

float speedBoat=0.3;

void Boating()
{
    if (positionBoat > 500)
    {
        positionBoat= -300;

    }
    positionBoat += speedBoat;

   glutPostRedisplay();
}


void boat2()
{
    glPushMatrix();
    glTranslated(positionBoat , 0, 0);

    glBegin(GL_POLYGON);

        glColor3ub (0, 0, 0);

        glVertex2i(176,365);  //boat 2
        glVertex2i(255,365);
        glVertex2i(300,332);
        glVertex2i(270,350);
        glVertex2i(185,350);
        glVertex2i(122,335);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3ub (153, 110, 30);

        glVertex2i(175,350); //boat 2 body
        glVertex2i(250,350);
        glVertex2i(250,320);
        glVertex2i(175,320);

    glEnd();

    glBegin(GL_LINES);

        glColor3ub (0,0,0);

        glVertex2i(134,366); //boat 2 boitha
        glVertex2i(175,340);

    glEnd();

    glPopMatrix();
}

void boat3()
{
    glBegin(GL_POLYGON);

        glColor3ub (20, 20, 21);

        glVertex2i(320,609);  //fixed boat2
        glVertex2i(420,625);
        glVertex2i(425,655);
        glEnd();

    glBegin(GL_POLYGON);

        glColor3ub (20, 20, 21);

        glVertex2i(420,625);
        glVertex2i(425,655);
        glVertex2i(575,645);
        glVertex2i(575,615);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3ub (20, 20, 21);

        glVertex2i(575,645);
        glVertex2i(575,615);
        glVertex2i(660,590);

    glEnd();

    glBegin(GL_QUADS);

        glColor3ub (0,0,0);

        glVertex2i(350,580); //boitha2
        glVertex2i(350,670);
        glVertex2i(354,670);
        glVertex2i(354,580);

    glEnd();

}

void bushBack()
{

 glBegin(GL_QUADS);

        glColor3ub(100,30,22);

        glVertex2i(0,315);
        glVertex2i(1100,315);
        glVertex2i(1100,310);
        glVertex2i(0,310);

    glEnd();

    glColor3ub(48, 119, 18);
    int a = 1100, b = 1090, c = 1075, d = 1060, e = 1047;
    for(int i=0; i<30; i++)
    {
        DrawCircle(a,308,19,1000);
        glColor3ub(48, 119, 18);
        DrawCircle(b,295,14,1000);
        DrawCircle(c,297,14,1000);
        DrawCircle(d,308,14,1000);
        DrawCircle(e,311,14,1000);
        a-=53;
        b-=53;
        c-=53;
        d-=53;
        e-=53;
    }
    glColor3ub(48, 119, 18);
    DrawCircle(1130,300,20,1000);
    DrawCircle(1155,300,20,1000);
    DrawCircle(1180,300,25,1000);
    glEnd();

}

void bushTop()
{

    glBegin(GL_POLYGON);

        glColor3ub (48, 119, 18);

        glVertex2i(1080,441);// bush
        glVertex2i(1080,455);
        glVertex2i(1190,455);
        glVertex2i(1190,441);

    glEnd();

    glColor3ub(48, 119, 18);
    DrawCircle(1085,435,20,1000);
    glColor3ub(48, 119, 18);
    DrawCircle(1115,420,25,1000);
    DrawCircle(1145,425,25,1000);
    DrawCircle(1175,430,20,1000);
    DrawCircle(1190,445,10,1000);



glBegin(GL_QUADS); //Fence

    glColor3ub (0, 0, 0);

    glVertex2i(700,642);
    glVertex2i(713,563);
    glVertex2i(720,563);
    glVertex2i(708,644);

glEnd();

glBegin(GL_QUADS);

    glColor3ub (0, 0, 0);

    glVertex2i(750,648);
    glVertex2i(756,575);
    glVertex2i(761,576);
    glVertex2i(757,647);

glEnd();

glBegin(GL_QUADS);

    glColor3ub (0, 0, 0);

    glVertex2i(794,651);
    glVertex2i(795,602);
    glVertex2i(801,596);
    glVertex2i(798,652);

glEnd();

glBegin(GL_QUADS);

    glColor3ub (0, 0, 0);

    glVertex2i(704,575);
    glVertex2i(783,596);
    glVertex2i(785,602);
    glVertex2i(700,578);

glEnd();

glBegin(GL_QUADS);

    glColor3ub (0, 0, 0);

    glVertex2i(681,603);
    glVertex2i(792,622);
    glVertex2i(792,628);
    glVertex2i(687,608);

glEnd(); // Fence End


}


void thelagari()
{

    glLineWidth(5.0);
    glColor3ub(50,50,50);
    DrawCircle(870,635,25,1000);//yellow

    glColor3ub (49, 140, 12);
    DrawCircle(870,635,20,1000);//white

    glColor3ub(0,0,0);
    DrawCircle(870,635,5,1000);// bhitorer chaka black


    glBegin(GL_LINES);

        glColor3ub (0,0,0); // bhitorer line
        glVertex2i(870,635);
        glVertex2i(852,625);

        glVertex2i(870,635);
        glVertex2i(870,615);

        glVertex2i(870,635);
        glVertex2i(890,635);

        glVertex2i(870,635);
        glVertex2i(880,655);

        glVertex2i(870,635);
        glVertex2i(855,650);


    glEnd();


    glBegin(GL_POLYGON);

        glColor3ub (153, 110, 30);

        glVertex2i(820,590); //thelgari body
        glVertex2i(990,668);
        glVertex2i(1010,645);
        glVertex2i(860,580);

    glEnd();

    glBegin(GL_LINE_LOOP);

        glColor3ub (50, 50, 50);

        glVertex2i(820,590); //thelgari body
        glVertex2i(990,668);
        glVertex2i(1010,645);
        glVertex2i(860,580);

    glEnd();

    glBegin(GL_LINES);

        glColor3ub (0,0,0); // thelagarir lathi
        glVertex2i(832,587);
        glVertex2i(820,580);

        glVertex2i(850,582);
        glVertex2i(835,575);

        glVertex2i(810,580);
        glVertex2i(840,570);

    glEnd();

}

void khor()
{

    glColor3ub(255,185,35);
    DrawCircle(1035,385,30,1000);//yellow

glBegin(GL_POLYGON);

        glColor3ub (255,185,35);

        glVertex2i(1005,385); //khorer body
        glVertex2i(970,455);
        glVertex2i(1100,455);
        glVertex2i(1065,385);

    glEnd();

glBegin(GL_POLYGON);

        glColor3ub (153,81,10);

        glVertex2i(1030,335); //khorer matha
        glVertex2i(1030,355);
        glVertex2i(1038,355);
        glVertex2i(1038,335);

    glEnd();

}


void hanger()
{

glBegin(GL_LINES);

        glColor3ub (153, 97, 24);

        glVertex2i(1035,495); // hanger left
        glVertex2i(1035,595);

    glEnd();

glBegin(GL_LINES);

        glVertex2i(1036,509); // hanger mid
        glVertex2i(1175,509);

    glEnd();

glBegin(GL_LINES);

        glVertex2i(1175,495);// hanger right
        glVertex2i(1175,595);

    glEnd();


    glBegin(GL_POLYGON);

        glColor3ub (244,80,26);

        glVertex2i(1050,505);// lungi
        glVertex2i(1050,545);
        glVertex2i(1100,545);
        glVertex2i(1100,505);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3ub (26,142,244);

        glVertex2i(1110,505);// lungi 2
        glVertex2i(1110,545);
        glVertex2i(1160,545);
        glVertex2i(1160,505);

    glEnd();

}


void hangerEmpty()
{

glBegin(GL_LINES);

        glColor3ub (153, 97, 24);

        glVertex2i(1035,495); // hanger left
        glVertex2i(1035,595);

    glEnd();

glBegin(GL_LINES);

        glVertex2i(1036,509); // hanger mid
        glVertex2i(1175,509);

    glEnd();

glBegin(GL_LINES);

        glVertex2i(1175,495);// hanger right
        glVertex2i(1175,595);

    glEnd();

}



float positionCrow1=0;
float positionCrow2=0;
float positionCrow3=0;
float speedCrow1=5.0;
float speedCrow2=5.0;
float speedCrow3=5.0;

void crowFly1()
{
    if (positionCrow1 < -260)
    {
        positionCrow1= 1100;

    }
    positionCrow1 -= speedCrow1;

   glutPostRedisplay();
}

void crowFly2()
{
    if (positionCrow2 < -260)
    {
        positionCrow2= 1100;

    }
    positionCrow2 -= speedCrow2;

   glutPostRedisplay();
}


void crowFly3()
{
    if (positionCrow3 < -260)
    {
        positionCrow3= 1100;

    }
    positionCrow3 -= speedCrow3;

   glutPostRedisplay();
}


void crow()
{


    glPushMatrix();
    glTranslated(positionCrow1 , 0, 0);
    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    glVertex2i(164,156);// 1st crow
    glVertex2i(180,153);
    glVertex2i(183,152);
    glVertex2i(179,148);
    glVertex2i(174,149);
    glVertex2i(174,147);
    glVertex2i(172,146);
    glVertex2i(170,143);
    glVertex2i(165,147);
    glVertex2i(161,147);
    glVertex2i(160,150);
    glVertex2i(158,153);
    glVertex2i(162,154);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(positionCrow2 , 0, 0);
    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    glVertex2i(224,146);// 2nd crow
    glVertex2i(239,142);
    glVertex2i(243,139);
    glVertex2i(239,137);
    glVertex2i(234,138);
    glVertex2i(234,136);
    glVertex2i(231,136);
    glVertex2i(229,133);
    glVertex2i(224,138);
    glVertex2i(221,137);
    glVertex2i(220,140);
    glVertex2i(218,144);
    glVertex2i(222,144);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(positionCrow3 , 0, 0);
    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    glVertex2i(176,120);// 3rd crow
    glVertex2i(194,118);
    glVertex2i(200,116);
    glVertex2i(194,112);
    glVertex2i(188,113);
    glVertex2i(189,110);
    glVertex2i(186,110);
    glVertex2i(185,106);
    glVertex2i(177,111);
    glVertex2i(174,110);
    glVertex2i(172,113);
    glVertex2i(169,116);
    glVertex2i(174,118);

    glEnd();
    glPopMatrix();
}




void night()
{

    glBegin(GL_QUADS);

        glColor4f(0.0, 0.0, 0.0, 0.7);

        glVertex2i(0,700);  //Dark
        glVertex2i(1200,700);
        glVertex2i(1200,0);
        glVertex2i(0,0);

    glEnd();

}


float positionRain=0;

float speedRain=5.0;

void rainDown()
{
    if (positionRain > 700)
    {
        positionRain = 0;

    }
    positionRain += speedRain;

   glutPostRedisplay();
}

void rain()
{
    glLineWidth(1.0);

    glBegin(GL_QUADS);

        glColor4f(0.466, 0.639, 0.729, 0.4);

        glVertex2i(0,700);  //rain
        glVertex2i(1200,700);
        glVertex2i(1200,0);
        glVertex2i(0,0);

    glEnd();

    glPushMatrix();
    glTranslated(0 , positionRain, 0);

    glBegin(GL_LINES);

    glColor3ub (255, 255, 255);

    int X = 7, Y = -700;
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<60; j++)
        {

            glVertex2i(X, Y);
            glVertex2i(X+3, Y+10);

            X=X+40;
        }
        X=7;
        Y=Y+30;
    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslated(0 , positionRain, 0);

    glBegin(GL_LINES);

    glColor3ub (255, 255, 255);

    X = 27, Y = -683;
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<60; j++)
        {

            glVertex2i(X, Y);
            glVertex2i(X+3, Y+10);

            X=X+40;
        }
        X=27;
        Y=Y+30;
    }
    glEnd();

    glPopMatrix();

}



void dayDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (0, 0, 0);
    glPointSize(5.0);
    glLineWidth(1.5);

    glEnable(GL_LIGHT0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    daySky();
    sun();
    sunUp();
    bushBack();
    field();
    river();
    drawCloud();
    cloud1();
    cloud2();
    cloud3();
    cloud4();
    drawTree();
    boat1();
    boat2();
    boat3();
    Boating();
    house();
    bushTop();
    thelagari();
    khor();
    hanger();
    crow();
    crowFly1();
    crowFly2();
    crowFly3();

    glFlush ();
}

void nightDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (0, 0, 0);
    glPointSize(5.0);
    glLineWidth(1.5);

    glEnable(GL_LIGHT0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    nightSky();
    moon();
    moonDown();
    bushBack();
    field();
    nightRiver();

    drawCloud();
    cloud1();
    cloud2();
    cloud3();
    cloud4();
    drawTree();
    boat1();
    boat2();
    boat3();
    Boating();
    house();
    bushTop();
    thelagari();
    khor();
    hangerEmpty();
    night();



    glFlush ();
}
void rainDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (0, 0, 0);
    glPointSize(5.0);
    glLineWidth(1.5);

    glEnable(GL_LIGHT0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    daySky();
    bushBack();
    field();
    river();
    drawCloud();
    cloud1();
    cloud2();
    cloud3();
    cloud4();
    drawTree();
    boat1();
    boat2();
    boat3();
    Boating();
    house();
    bushTop();
    thelagari();
    khor();
    hangerEmpty();
    rain();
    rainDown();

    glFlush ();
}

void myInit (void)
{
    glClearColor(0.2, 0.6, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 700.0, 0.0);
}

void myKey(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'd':

            glutDisplayFunc(dayDisplay);
            positionMoon = 0;
            break;

        case 'n':

            glutDisplayFunc(nightDisplay);
            positionSun = 0;
            break;

        case 'r':

            glutDisplayFunc(rainDisplay);
            break;

        case 't':
            exit(0);
            break;

        default:
            break;
    }
}

int main(int argc, char** argv)
{

    cout << endl << "******** Village View ********" << endl << endl;

    cout << "Press N : For Night mode " << endl << endl;
    cout << "Press R : For Rainy mode " << endl << endl;
    cout << "Press D : For Day mode " << endl << endl;
    cout << "Press T : To terminate the window " << endl << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 700);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Project");
    glutDisplayFunc(dayDisplay);
    glutKeyboardFunc(myKey);
    myInit ();
    glutMainLoop();
    return 0;
}
