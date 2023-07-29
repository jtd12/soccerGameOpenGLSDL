#include"balle.h"

balle::balle(const char * n,unsigned int map ,collisionsphere ccs,float normals)
{
	name=n;
	cs=ccs;
	mesh=map;
	fixeBall=vector3d(0,0,0);
	speed=normals;
	angle=vector3d(0,0,0);
	maxSpeed=2.0f;
	acc=0.9f;
	dec=0.005f;
	speed_ball_joueur=0.0f;
	speed_ball_joueurAI=0.0f;
	speed2_ball_joueurAI=0.0f;
	speed_ball_goal=0.0f;

	
			centrercotegauche=false;
			centrercotedroit=false;
			centreravant=false;
			centrer=false;
			centrercotearrieredroit=false;
			centrercotearrieregauche=false;
			centrerarriere=false;
		
			
		
}
balle::~balle()
{
	
}
void balle::update(std::vector<collisionplane>& collplane)
{
	if(direction.y>=force.y)
			direction+=force;
		vector3d newPos(cs.center);
			newPos.y-=0.01f;
	
			    newPos+=direction*speed;
			for(int i=0;i<collplane.size();i++)
				collision::sphereplane(newPos,collplane[i].normal,collplane[i].p[0],collplane[i].p[1],collplane[i].p[2],collplane[i].p[3],cs.r);
	 				setLocation(newPos);
}
void balle::show()
{
		glPushMatrix();
		glTranslatef(cs.center.x+fixeBall.x,cs.center.y,cs.center.z+fixeBall.z);

	 	glRotatef(-rotation.x*(180/pi),1,0,0);
	 	glRotatef(-rotation.y,0,1,0);
	 	glRotatef(-rotation.z*(180/pi),0,0,1);
	 
	 	glCallList(mesh);
	 	glPopMatrix();
}
	collisionsphere * balle::getCollisionSphere()
		{
				return &cs;
		}
		void balle::setLocation(vector3d newLoc)
		{
			cs.center=newLoc;
		}
	
		void balle::setFixe(vector3d f)
		{
			fixeBall=f;
		
		}
	
	
		vector3d balle::getFixe()
		{
		
			return fixeBall;
			}
		
			void balle::setRotation(float y)
			{
				rotation.z+=y;
			}
		void balle::setLocationincremente(vector3d newLoc)
		{
			cs.center+=newLoc;
		}
		
			vector3d balle::getLocation()
			{
				return cs.center;
			}
		
			float balle::getSpeedBallJoueur()
			{
				return speed_ball_joueur;
			}
				float balle::getSpeedBallgoal()
			{
				return speed_ball_goal;
			}
			
			
				float balle::getSpeedBallJoueurAI()
			{
				return speed_ball_joueurAI;
			}
			
			
				float balle::getSpeedBallJoueurAI2()
			{
				return speed2_ball_joueurAI;
			}
			
			
			void balle::setSpeedBallJoueur(float s)
			{
				speed_ball_joueur=s;
			}
				void balle::setSpeedBallgoal(float s)
			{
				speed_ball_goal=s;
			}
			
			
				void balle::setSpeedBallJoueurAI(float s)
			{
				speed_ball_joueurAI=s;
			}
			
				void balle::setSpeedBallJoueurAI2(float s)
			{
				speed2_ball_joueurAI=s;
			}
			
			
			
			void balle::setSpeedBallAccJoueur(float s)
			{
				speed_ball_joueur+=s;
			}
						
			void balle::setSpeedBallAccgoal(float s)
			{
				speed_ball_goal+=s;
			}
			
			
				void balle::setSpeedBallAccJoueurAI(float s)
			{
				speed_ball_joueurAI+=s;
			}
			
					void balle::setSpeedBallAccJoueurAI2(float s)
			{
				speed2_ball_joueurAI+=s;
			}
			
			
				void balle::setSpeedBallDecJoueur(float s)
			{
				speed_ball_joueur-=s;
			}
				void balle::setSpeedBallDecgoal(float s)
			{
				speed_ball_goal-=s;
			}
			
			
				void balle::setSpeedBallDecJoueurAI(float s)
			{
				speed_ball_joueurAI-=s;
			}
			
					void balle::setSpeedBallDecJoueurAI2(float s)
			{
				speed2_ball_joueurAI-=s;
			}
			
			
		
		vector3d balle::getRot()
		{
			return rotation;
		}
		
			 void balle::setangle(vector3d a)
		 {
		 	angle=a;
		 }
		 vector3d balle::getangle()
		 {
		 	return angle;
		 }
		
		 float balle::dece()
		 {
		 	return dec;
		 }
		 
		 float balle::acce()
		 {
		 	return acc;
		 }
		
		 float balle::maxSpeed_()
		 {
		 	return maxSpeed;
		 }
	
		
	
		 	bool balle::centrer_()
		 	{
		 		return centrer;
			 }
		bool balle::centrerAvant_()
		{
			return centreravant;
		}
		bool balle::centrerArriere_()
		{
			return centrerarriere;
		}
		bool balle::centrerCoteArriereGauche_()
		{
		
		return centrercotearrieregauche;
	}
	
		bool balle::centrerCoteArriereDroite_()
		{
		return centrercotearrieredroit;
		}
		bool balle::centrerCoteGauche_()
		{
		return centrercotegauche;
		}
		bool balle::centrerCoteDroit_()
		{
			return centrercotedroit;
		}
		
			void balle::centrer_(bool c)
		 	{
		 	 centrer=c;
			 }
	void balle::centrerAvant_(bool c)
		{
		 centreravant=c;
		}
		void balle::centrerArriere_(bool c)
		{
		centrerarriere=c;
		}
			void balle::centrerCoteArriereGauche_(bool c)
		{
		
		 centrercotearrieregauche=c;
	}
	
			void balle::centrerCoteArriereDroite_(bool c)
		{
		 centrercotearrieredroit=c;
		}
		void balle::centrerCoteGauche_(bool c)
		{
		centrercotegauche=c;
		}
		void balle::centrerCoteDroit_(bool c)
		{
		 centrercotedroit=c;
		}



