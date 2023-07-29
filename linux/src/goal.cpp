#include"goal.h"
goal::goal(std::vector<unsigned int>& anim,float sp,collisionsphere css)
{
	frames=anim;
		speed=sp;
		cs=css;
		speed2=0.0f;
			tirer=false;
			hastheball=false;
}
goal::~goal()
{
	
}
	bool goal::movement(vector3d playerLoc)
		{
			
			      vector3d newPos(cs.center);
			direction.change(playerLoc-cs.center);
			direction.normalize();

					newPos.y-=0.2f;
			  newPos+=direction*speed2;
		
			  setLocation(newPos);
			 	rotation.y=std::acos(direction.x)*(180/pi);
	 				if(direction.z<0)
	 				{
	 					rotation.y=-rotation.y;
					 }
					 
					 return 1;
					 	
					 
				
		}
	bool goal::update(std::vector<collisionplane>& collplane)
	{
		    vector3d newPos(cs.center);
			  
			       
			    	newPos.y-=0.2f;
			    
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
				 if(curFrame>36)
				 {
				 	curFrame=0;
				 }
				 return 1;
	}
		void goal::show()
		{
		glPushMatrix();
		glTranslatef(cs.center.x,cs.center.y,cs.center.z);

	 	glRotatef(-rotation.x*(180/pi),1,0,0);
	 	glRotatef(-rotation.y,0,1,0);
	 	glRotatef(-rotation.z*(180/pi),0,0,1);
	 
	 	glCallList(frames[curFrame]);
	 	glPopMatrix();
		}
			collisionsphere * goal::getCollisionSphere()
		{
				return &cs;
		}
		void goal::setLocationincremente(vector3d newLoc)
		{
			cs.center+=newLoc;
		}
		void goal::setLocation(vector3d newLoc)
		{
			cs.center=newLoc;
		}
		vector3d goal::getLocation()
		{
			return cs.center;
		}
			bool goal::getTirer()
		{
			return tirer;
		}
		void goal::setTirer(bool t)
		{
			tirer=t;
		}
			void goal::sethastheball(bool has)
		{
			hastheball=has;
		}
		bool goal::gethastheball()
		{
			return hastheball;
		}
			 float goal::getRotation()
		 {
		 	return rotation.y;
		 }
		 void goal::setRotation(float x)
		 {
		 	rotation.y=x;
		 }
		
		

