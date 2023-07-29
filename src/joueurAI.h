#ifndef DEF_JOUEURAI_H
#define DEF_JOUEURAI_H
#include <GL/gl.h>
#include <GL/glu.h>
#include<vector>
#include"vector.h"
#include"collision.h"
#include"collisionsphere.h"
#include"collisionplane.h"
#include"joueur.h"
#include<cmath>
#include<iostream>
#include"random.h"
#include <C:/library/SDL-1.2.15/include/SDL/SDL.h>
#define pi 3.14159265359 // on definit un nombre pi
class playerAI
{
		public:
		
			 playerAI(std::vector<unsigned int>& anim,float sp,collisionsphere css);
			~playerAI();
				collisionsphere * getCollisionSphere();
		void setLocation(vector3d newLoc);
			bool update(std::vector<collisionplane>& collplane);
			void show();
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
		vector3d getLocation();
		void setNext(bool n);
		bool getNext();
		
		bool getespace();
		bool getlctrl();
		void setlctrl(bool x);
		void setespace(bool x);
		void setattaquer(bool x);
		bool getattaquer();
		bool getdefendre();
		void setdefendre(bool);
		void setLocationincremente(vector3d newLoc);
	void setTirer(bool t);
		bool getTirer();
			void setTirer2(bool t);
		bool getTirer2();
			void setTirer3(bool t);
		bool getTirer3();
		void setTirer4(bool t);
		bool getTirer4();
		void setTirer5(bool t);
		bool getTirer5();
			private:
				
	std::vector<unsigned int > frames;
	unsigned int walk,attack,die;
	unsigned int curFrame;
	float speed,speed2;
	vector3d direction,rotation;
	collisionsphere cs;
		vector3d newPos;
bool control,control2,control3,control4;
		bool hastheball;
	bool attaquer_,defendre;
	bool iswalk,isattack,isdead;
	bool next;
	bool centrer,centreravant,centrercotedroit,centrercotegauche,centrerarriere,centrercotearrieredroit,centrercotearrieregauche;
	bool avancerAI;
		Random rand;
		bool tir,tir2,tir3,tir4,tir5;
	

		
	
};
#endif


