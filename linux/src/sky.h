#ifndef DEF_SKY
#define DEF_SKY
#include<vector>
#include"vector"
#include"collisionplane.h"
#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include <SDL/SDL.h>

class sky
{
		public:
	sky(const char* c,unsigned int map );
	~sky();
void update();
void show();
	std::string& getName();
	vector3d loc;

		private:
				unsigned int mesh;
	std::string name;
};
#endif
