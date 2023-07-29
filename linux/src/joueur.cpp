#include"joueur.h"

	player::player(std::vector<unsigned int>& anim,float sp,collisionsphere css)
	{
		frames=anim;
		speed=sp;
		cs=css;
		control=false;
		control2=false;
		control3=false;
		control4=false;
		hastheball=false;
		rotation.y=0;
		space=false;
		attaquer_=false;
		speed2=rand.random(0.1,0.2);
		iswalk=false;
		isattack=isdead=false;
		isshoot=false;
		walk=20;
		attack=2;
		die=3;
		shoot=11;
		defendre_=false;
		next=false;
		tirer=false;
		setkeyshoot_=false;
		tir=false;
		
	}
		player::~player()
		{
			
		}
		void player::setkeyshoot(bool s)
		{
			setkeyshoot_=s;
		}
	void player::avancer()
		{
			if(control)
			{
	
				rotation.y=0;
				cs.center.x+=speed;
			
			
			
	 			
		}
	
			
		}
			void player::reculer()
		{
			if(control2)
			{
				
				rotation.y=180;
				cs.center.x-=speed;
	
				
			
	 			
		}
		
		}
		void player::avantdroite()
		{
			if(control && control3)
			{
				rotation.y=45;
			
				cs.center.x+=speed;
					
			}
		}
			void player::avantgauche()
		{
			if(control && control4)
			{
				rotation.y=-45;
				cs.center.x+=speed;
				cs.center.z-=speed;	
				
						
			
			}
		
		}
			void player::arrieredroite()
		{
			if(control2 && control3)
			{
				rotation.y=135;
				cs.center.z+=speed;
				cs.center.x-=speed;		
					 
			
			
			}
		}
			void player::arrieregauche()
		{
			if(control2 && control4)
			{
				rotation.y=-135;
				cs.center.z-=speed;
				cs.center.x-=speed;	
					
			
			}
		
		}
				void player::droite()
		{
			if(control3)
			{
				
				rotation.y=90;
				cs.center.z+=speed;

	 			
		}
			
		
			
		}
				void player::gauche()
		{
			if(control4 )
			{
				
				rotation.y=-90;
				cs.center.z-=speed;
					
				
			
	 			
	 			
		}
	
			
		}
		bool player::movement(vector3d playerLoc)
		{
		
		
				
			
			      vector3d newPos(cs.center);
			      	newPos.y-=0.01f;
			      		if(newPos.y<0.0f)
			    	{
			    		newPos.y=5.0f;
					}
			direction.change(playerLoc-cs.center);
			direction.normalize();
		

			  newPos+=direction*speed2;
			  setLocation(newPos);
			 	rotation.y=std::acos(direction.x)*(180/pi);
	 				if(direction.z<0)
	 				{
	 					rotation.y=-rotation.y;
					 }
				
				
				
				
				return 1;
				
				
			
							
			
		}
		bool player::update(std::vector<collisionplane>& collplane)
		{
		
	/*
			direction.change(playerLoc-cs.center);
			direction.normalize();
			
		    
		
			/*if(!control && !control2 && !control3 && !control4 && hastheball==false)
			    newPos+=direction*speed;
			    */
			         vector3d newPos(cs.center);
			  
			       
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
				 
				 
					 
					 if(control )
				{
						isshoot=false;
					isdead=false;
					iswalk=isattack=true;
				
				
				}
						 if(control2)
				{
					isdead=false;
					iswalk=isattack=true;
				
				
				}
						 if(control3)
				{
					isdead=false;
					iswalk=isattack=true;
			
				
				}
						 if(control4)
				{
					isdead=false;
					iswalk=isattack=true;
			
				
				}
			else	if(!control && !control2 && !control3 && !control4 )
				{
						isdead=true;
					iswalk=isattack=false;
	
					
						
				}
				else if(setkeyshoot_ )
				{
				isshoot=true;
					isdead=false;
					iswalk=isattack=false;
				}
				else if(setkeyshoot_==false)
				{
						isshoot=false;
						iswalk=isattack=true;
						
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
	else if(isshoot && curFrame>=walk+attack+die+shoot)
		 	 {
		 	 	curFrame=walk+attack+die+shoot-11;
				  }	

	

	
					
					 return 0;
	 			
	 		
		}
		void player::show()
		{
		glPushMatrix();
		glTranslatef(cs.center.x,cs.center.y,cs.center.z);

	 	glRotatef(-rotation.x*(180/pi),1,0,0);
	 	glRotatef(-rotation.y,0,1,0);
	 	glRotatef(-rotation.z*(180/pi),0,0,1);
	 
	 	glCallList(frames[curFrame]);
	 	glPopMatrix();
		}
		bool player::setAttack(collisionsphere player)
		{
			if(collision::spheresphere(player.center,player.r,cs.center,cs.r))
			{

			}
			return 1;
		}
		collisionsphere * player::getCollisionSphere()
		{
				return &cs;
		}
		void player::setLocationincremente(vector3d newLoc)
		{
			cs.center+=newLoc;
		}
		void player::setLocation(vector3d newLoc)
		{
			cs.center=newLoc;
		}
		vector3d player::getLocation()
		{
			return cs.center;
		}
		void player::sethastheball(bool has)
		{
			hastheball=has;
		}
		bool player::gethastheball()
		{
			return hastheball;
		}
	   void player::getcontrol(bool c)
	   {
	   	control=c;
	   }
	   void player::getcontrol2(bool c)
	   {
	   	control2=c;
	   }
	   void player::getcontrol3(bool c)
	   {
	   	control3=c;
	   }
	   void player::getcontrol4(bool c)
	   {
	   	control4=c;
	   }
		bool player::setcontrol()
		 {
		 	return control;
		 }
		 	bool player::setcontrol2()
		 {
		 	return control2;
		 }
		 	bool player::setcontrol3()
		 {
		 	return control3;
		 }
		 	bool player::setcontrol4()
		 {
		 	return control4;
		 }
	
		 float player::getRotation()
		 {
		 	return rotation.y;
		 }
		 void player::setRotation(float x)
		 {
		 	rotation.y=x;
		 }
		
		
		
		 void player::setespace(bool x)
		 {
		 	space=x;
		 }
		 bool player::getespace()
		 {
		 	return space;
		 }
	
		 void player::setattaquer(bool x)
		 {
		 	attaquer_=x;
		 }
		 	 void player::setdefendre(bool x)
		 {
		 	defendre_=x;
		 }
		 bool player::getattaquer()
		 {
		 	return attaquer_;
		 }
		 	 bool player::getdefendre()
		 {
		 	return defendre_;
		 }
		 
		 bool player::getNext()
		 {
		 	return next;
		 }
		 void player::setNext(bool n)
		 {
		 	next=n;
		 }
		 void player::shooter(bool s)
		 {
		 	tirer=s;
		 }
		 bool player::shooter_()
		 {
		 	return tirer;
		 }
		bool player::getTirer()
		{
			return tir;
		}
		void player::setTirer(bool t)
		{
			tir=t;
		}
		

	


