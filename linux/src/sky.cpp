#include"sky.h"
sky::sky(const char* c,unsigned int map )
{
	mesh=map;
	name=c;
	loc.x=0;
	loc.y=0;
	loc.z=0;
	
	
}
sky::~sky()
{
}
void sky:: update()
{
}
void sky::show()
{

	glCallList(mesh);
}
