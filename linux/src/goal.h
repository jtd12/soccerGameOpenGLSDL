#ifndef DEF_GOAL_H
#define DEF_GOAL_H
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

class goal
{
	
	public:
	goal(std::vector<unsigned int>& anim,float sp,collisionsphere css);
	~goal();
bool update(std::vector<collisionplane>& collplane);
	void show();	
		bool setAttack(collisionsphere player);
		collisionsphere * getCollisionSphere();
			void setLocationincremente(vector3d newLoc);
				void setLocation(vector3d newLoc);
		vector3d getLocation();
		bool movement(vector3d playerLoc);
			void sethastheball(bool has);
		bool gethastheball();
			void setTirer(bool t);
		bool getTirer();
			float getRotation();
		void setRotation(float x);
		private:
				std::vector<unsigned int > frames;
					unsigned int curFrame;
	float speed,speed2;
	vector3d direction,rotation;
	collisionsphere cs;
		vector3d newPos;
			bool hastheball;
				bool tirer;
};
#endif

