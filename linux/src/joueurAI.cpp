	#include"joueurAI.h"
	
	playerAI::playerAI(std::vector<unsigned int>& anim,float sp,collisionsphere css)
	{
		frames=anim;
		speed=sp;
		cs=css;
		control=false;
		control2=false;
		control3=false;
		control4=false;
		hastheball=false;
		rotation.y=180;
		hastheball=false;
		attaquer_=false;
	
		speed2=rand.random(0.15,0.2);
		iswalk=false;
		isattack=isdead=false;
		walk=20;
		attack=2;
		die=3;
		next=false;
		avancerAI=false;
			tir=false;
			tir2=false;
			tir3=false;
			tir4=false;
			tir5=false;
		
		
	}
		playerAI::~playerAI()
		{
			
		}
		bool playerAI::movement(vector3d playerLoc)
		{
			
			      vector3d newPos(cs.center);
			direction.change(playerLoc-cs.center);
			direction.normalize();

					newPos.y-=0.01f;
						if(newPos.y<0.0f)
			    	{
			    		newPos.y=5.0f;
					}
			  newPos+=direction*speed2;
		
			  setLocation(newPos);
			 	rotation.y=std::acos(direction.x)*(180/pi);
	 				if(direction.z<0)
	 				{
	 					rotation.y=-rotation.y;
					 }
					 return 1;
					 	
					 
				
		}
bool playerAI::update(std::vector<collisionplane>& collplane)
{
	        newPos=vector3d(cs.center);
			       
			    	newPos.y-=0.01f;
			    	if(newPos.y<0.0f)
			    	{
			    		newPos.y=5.0f;
					}
			for(int i=0;i<collplane.size();i++)
				collision::sphereplane(newPos,collplane[i].normal,collplane[i].p[0],collplane[i].p[1],collplane[i].p[2],collplane[i].p[3],cs.r);
	 				setLocation(newPos);
	 					/*if(!control && !control2 && !control3 && !control4 && hastheball==false)
	 					{
						 
	 				rotation.y=std::acos(-direction.x);
	 				if(direction.z>0)
	 				{
	 					rotation.y=-rotation.y*(180/pi);
					 }
				}
				*/
			

				 curFrame++;
				 	 if(direction.x!=0)
				{
						
					isdead=false;
					iswalk=isattack=true;
				
				
				}
				else
				{
						isdead=true;
					iswalk=isattack=false;
	
					
						
				}
					if(iswalk && curFrame>=walk)
	{
		curFrame=1;
	}
	else if( isattack && curFrame>=walk+attack)
	{
		curFrame=walk;
	}
	else if( isdead && curFrame>=walk+attack+die)
	{
		curFrame=walk+attack+die-1;
	}
	return 1;
}

	void playerAI::show()
		{
				
		glPushMatrix();
		glTranslatef(cs.center.x,cs.center.y,cs.center.z);

	 	glRotatef(-rotation.x*(180/pi),1,0,0);
	 	glRotatef(-rotation.y,0,1,0);
	 	glRotatef(-rotation.z*(180/pi),0,0,1);
	 
	 	glCallList(frames[curFrame]);
	 	glPopMatrix();
		}

	collisionsphere * playerAI::getCollisionSphere()
		{
				return &cs;
		}
		void playerAI::setLocation(vector3d newLoc)
		{
			cs.center=newLoc;
		}
	
		 
		vector3d playerAI::getLocation()
		{
			return cs.center;
					  }		 	
					   void playerAI::setattaquer(bool x)
		 {
		 	attaquer_=x;
		 }
		 	 void playerAI::setdefendre(bool x)
		 {
		 defendre=x;
		 }
		 bool playerAI::getattaquer()
		 {
		 	return attaquer_;
		 }
		 	 bool playerAI::getdefendre()
		 {
		 	return defendre;
		 }
		 void playerAI::sethastheball(bool has)
		{
			hastheball=has;
		}
		bool playerAI::gethastheball()
		{
			return hastheball;
		}
		 float playerAI::getRotation()
		 {
		 	return rotation.y;
		 }
		  bool playerAI::getNext()
		 {
		 	return next;
		 }
		 void playerAI::setNext(bool n)
		 {
		 	next=n;
		 }
		 	void playerAI::setLocationincremente(vector3d newLoc)
		{
			cs.center+=newLoc;
		}
		
		 	bool playerAI::getTirer()
		{
			return tir;
		}
		void playerAI::setTirer(bool t)
		{
			tir=t;
		}
		
		 	bool playerAI::getTirer2()
		{
			return tir2;
		}
		void playerAI::setTirer2(bool t)
		{
			tir2=t;
		}
		
		 	bool playerAI::getTirer3()
		{
			return tir3;
		}
		void playerAI::setTirer3(bool t)
		{
			tir3=t;
		}
			 	bool playerAI::getTirer4()
		{
			return tir4;
		}
		void playerAI::setTirer4(bool t)
		{
			tir4=t;
		}
		
				 	bool playerAI::getTirer5()
		{
			return tir5;
		}
		void playerAI::setTirer5(bool t)
		{
			tir5=t;
		}
		 
		 
		
		


