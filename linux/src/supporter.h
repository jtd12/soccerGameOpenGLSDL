#ifndef DEF_SUPPORTER_H
#define DEF_SUPPORTER_H
#include<vector>
#include"vector"
#include"collisionplane.h"
#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include <SDL/SDL.h>

class supporter
{
	public:
	supporter(const char* c,unsigned int map );
	~supporter();
void update();
void show();
	std::string& getName();
	vector3d loc;

		private:
				unsigned int mesh;
	std::string name;
};
#endif
