#ifndef DEF_RANDOM_H
#define DEF_RANDOM_H
#include<iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <cmath>

class Random
{
	public:
		Random();
		float random(float a,float b);
		
		private:
			float r,diff,random_;
};
#endif
