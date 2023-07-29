#ifndef DEF_GAME_H
#define DEF_GAME_H
#include <stdlib.h>
#include<time.h>
#include <SDL/SDL.h>
#include<SDL/SDL_ttf.h>
 #ifndef GL_UNSIGNED_SHORT_5_6_5
 #define GL_UNSIGNED_SHORT_5_6_5 0x8363
 #endif
 #ifndef GL_CLAMP_TO_EDGE
 #define GL_CLAMP_TO_EDGE 0x812F
 #endif
#include<GL/gl.h>
#include<GL/glu.h>
#include"objloader.h"
#include"vector.h"
#include"collisionplane.h"
#include"collisionsphere.h"
#include"level.h"
#include"player.h"
#include"joueur.h"
#include"joueurAI.h"
#include"balle.h"
#include"random.h"
#include"supporter.h"
#include"sky.h"
#include"goal.h"
#include <iostream>
#include <sstream>
//#include"camera.h"

class game
{
void lighting();
void separatePlayer();
void separatePlayerAI();
void cameras_setup();
void camSetLocation(vector3d loc);
vector3d camGetLocation();
void suivre();
void suivreAI();
bool limitBall();
void limitJoueur();
void limitJoueur2();
void attaquer();
void defendre();
void movement();
void movementAI();
void attaquerAI();
void collision();
void defendreAI();
void movementBall();
void suivreBall();
void updateGame();
vector3d direction;
void passerBall();
void passerBallAI();
void AIcontroller();
void hud();
void drawHud();
void drawHudJoueur();
void hudJoueur();
void hudJoueur2();
void tirerGoal();
void RenderText(std::string message, SDL_Color color, int x, int y,float x2,float y2, int size);
bool collisionGoal();
objloader obj;
balle *ball;
std::vector<goal*> goal_;
std::vector<supporter*> support;
float speed;
std::vector<level*> levels;
std::vector<player*> joueur;
std::vector<playerAI*> joueurAI;
vector3d camLoc;
int screenWidth;
int screenHeight;
int mode;
bool start;
int startgame;
Random rand;
sky *soleil;
playerCam *playerCam_;	
 float rand_;
SDL_Surface* screen;
	std::vector<unsigned int> texture;
		std::vector<std::string> loadedTextures;
	std::vector<int> loadedTexturesNum;
	std::vector<collisionplane> mapcp;
     std::vector<unsigned int> anim;
     std::vector<unsigned int> anim2;
        std::vector<unsigned int> anim3;
             std::vector<unsigned int> anim4;
      	std::vector<vector3d> mapsp;
		int tmpx,tmpy;
	int menu;
	int hudTex;
	int hudTex1;
	int hudTex2;
camera *cam;
	float star;
	int partie;
		int francePoint;
      	int allemagnePoint;
	void enable2D(int width, int height);
	std::string int2str(int x);
	std::string float2str(float x);
	std::string vector2str(vector3d x);
	public:
		
	game();
	~game();
	void loadScene1();
	void loadScene2();	
	void startG();
	void update();
	void show();
		
	
		
};
#endif
