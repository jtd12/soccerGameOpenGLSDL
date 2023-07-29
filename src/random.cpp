#include"random.h"

Random::Random()
{
	r=0;
	diff=0;
	random_=0;

}
float Random::random(float a, float b) {
    random_ = ((float) rand()) / (float) RAND_MAX;
    diff = b - a;
     r = random_ * diff;
    return a + r;
}
