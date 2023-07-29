#ifndef DEF_JOUEUR_H
#define DEF_JOUEUR_H
#include <GL/gl.h>
#include <GL/glu.h>
#include<vector>
#include"vector.h"
#include"collision.h"
#include"collisionsphere.h"
#include"collisionplane.h"
#include<cmath>
#include<iostream>
#include"random.h"
#include <C:/library/SDL-1.2.15/include/SDL/SDL.h>
#define pi 3.14159265359 // on definit un nombre pi

class player
{
	std::vector<unsigned int > frames;
	unsigned int walk,attack,die,shoot;
	unsigned int curFrame;
	float speed,speed2;
	vector3d direction,rotation;
	collisionsphere cs;
		vector3d newPos;
bool control,control2,control3,control4,setkeyshoot_;
		bool hastheball;
	bool attaquer_,defendre_;
	bool space;
	bool iswalk,isattack,isdead,isshoot;
	bool next;
	bool tirer;
	Random rand;
	bool tir;
	bool passe;
	bool touchV;
	
	public:
		
		player(std::vector<unsigned int>& anim,float sp,collisionsphere css);
			~player();
		bool update(std::vector<collisionplane>& collplane);
		void show();
		void setLocationincremente(vector3d newLoc);
		bool setAttack(collisionsphere player);
		collisionsphere * getCollisionSphere();
		void setLocation(vector3d newLoc);
		vector3d getLocation();
		void avancer();
		void reculer();
		void droite();
		void gauche();
		void avantdroite();
		void avantgauche();
		void arrieredroite();
		void arrieregauche();
		bool movement(vector3d playerLoc);
		void sethastheball(bool has);
		bool gethastheball();
		void getcontrol(bool c);
		void getcontrol2(bool c);
		void getcontrol3(bool c);
		void getcontrol4(bool c);
		bool setcontrol();
		bool setcontrol2();
		bool setcontrol3();
		bool setcontrol4();
		float getRotation();
		void setRotation(float x);
		bool getespace();
		void setespace(bool x);
		void setattaquer(bool x);
		void setdefendre(bool x);
		bool getattaquer();
		bool getdefendre();
		void setNext(bool n);
		bool getNext();
		bool shooter_();
		void shooter(bool s);
		void setkeyshoot(bool s);
		void setTirer(bool t);
		bool getTirer();
		bool getPasser();
		void setPasser(bool t);
		void setTouchV(bool x);
		bool getTouchV();
	
		
};
#endif


