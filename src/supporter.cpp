#include"supporter.h"
supporter::supporter(const char* c,unsigned int map )
{
	mesh=map;
	name=c;
	loc.x=0;
	loc.y=0;
	loc.z=0;
	
	
}
supporter::~supporter()
{
}
void supporter:: update()
{
}
void supporter::show()
{

	glCallList(mesh);
}
