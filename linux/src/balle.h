#ifndef DEF_BALLE_H
#define DEF_BALLE_H
#include <GL/gl.h>
#include <GL/glu.h>
#include<vector>
#include"vector.h"
#include"collision.h"
#include"collisionsphere.h"
#include"collisionplane.h"
#include<cmath>
#include<iostream>
#define pi 3.14159265359 // on definit un nombre pi

class balle
{
	unsigned int mesh;
	std::string name;
	vector3d direction,rotation;
	collisionsphere cs;
	vector3d force;
    vector3d fixeBall;
	vector3d angle;
   	float maxSpeed;
		float acc;
		float dec;
		float speed,speed_ball_joueur,speed_ball_joueurAI,speed2_ball_joueurAI,speed_ball_goal;
		bool centrer,centreravant,centrercotedroit,centrercotegauche,centrerarriere,centrercotearrieredroit,centrercotearrieregauche;
	
	
	public:
		balle(const char * n,unsigned int map ,collisionsphere ccs,float normals);
		~balle();
		void update(std::vector<collisionplane>& collplane);
		void show();
		collisionsphere * getCollisionSphere();
		void setLocation(vector3d newLoc);
	
		
		void setFixe(vector3d f);
	
		vector3d getFixe();
		void setRotation(float y);
		vector3d getRot();

	float getSpeedBallJoueur();
	float getSpeedBallJoueurAI();
	float getSpeedBallJoueurAI2();
		float getSpeedBallgoal();
	void setSpeedBallJoueur(float s);
		void setSpeedBallgoal(float s);
	void setSpeedBallJoueurAI(float s);
	void setSpeedBallJoueurAI2(float s);
	void setSpeedBallAccJoueur(float s);
		void setSpeedBallAccgoal(float s);
	void setSpeedBallAccJoueurAI(float s);
	void setSpeedBallAccJoueurAI2(float s);
	void setSpeedBallDecJoueur(float s);
		void setSpeedBallDecgoal(float s);
	void setSpeedBallDecJoueurAI(float s);
	void setSpeedBallDecJoueurAI2(float s);
	vector3d getangle();
		void setangle(vector3d a);
	void setLocationincremente(vector3d newLoc);
		float maxSpeed_();
		float acce();
		float dece();
		vector3d getLocation();
		bool centrer_();
		bool centrerAvant_();
		bool centrerArriere_();
		bool centrerCoteArriereGauche_();
		bool centrerCoteArriereDroite_();
		bool centrerCoteGauche_();
		bool centrerCoteDroit_();
		void centrer_(bool c);
		void  centrerAvant_(bool c);
		void  centrerArriere_(bool c);
		void  centrerCoteArriereGauche_(bool c);
		void  centrerCoteArriereDroite_(bool c);
		void  centrerCoteGauche_(bool c);
		void  centrerCoteDroit_(bool c);

};
#endif




