#include"player.h"

playerCam::playerCam(const char * n,collisionsphere ccs,float sprints,float normals,float looks)
{
	name=n;
	cs=ccs;
	sprintspeed=sprints;
	normalspeed=normals;
	force.change(0,-0.05,0);
	setPosition(ccs.center);
	cam.setSpeed(normalspeed,looks);
	isground=iscollision=issprint=false;
	energy=20;
}
playerCam::~playerCam()
{

}
void playerCam::update(std::vector<collisionplane>& collplane)
{
	
	//	if(direction.y>=force.y)
			//direction+=force;
			vector3d newPos(cam.getLocation());
	 		newPos+=direction;
	 			
	 		for(int i=0;i<collplane.size();i++)
				collision::sphereplane(newPos,collplane[i].normal,collplane[i].p[0],collplane[i].p[1],collplane[i].p[2],collplane[i].p[3],cs.r);
	 				if(cam.getLocation().y<newPos.y)
	 				{
					 isground=true;
				}
				else
				{
					false;
				}
	 		setPosition(newPos);
	 			
}
void playerCam::setSprint()
{
	if(energy>2.0)
	{
		issprint=true;
		cam.setSpeed(sprintspeed,cam.getMousevel());
	}
	else
	{
		issprint=false;
	}
}
void playerCam::stopSprint()
{
	issprint=false;
		cam.setSpeed(normalspeed,cam.getMousevel());
}
void playerCam::setJump()
{
	if(isground)
	{
		direction.y=1.0f;
		isground=false;
	}
}

void playerCam::setPosition(vector3d pos)
{
	cs.center=pos;
	cam.setLocation(pos);
}

		vector3d playerCam::getLocation()
{
	return loc;
}
	 	void playerCam::setLocation(vector3d newLoc)
	 	{
	 		cs.center=newLoc;
		 }
	collisionsphere playerCam::getCollissionSphere()
	 	{
	 		return cs;
		 }

