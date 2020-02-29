
#include <random>
#include <iostream>

#ifndef __RNG_H__
#define __RNG_H__

class Rng 
{

private:

	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution;

public:

	Rng();
	double probability();
};

#endif // !__RNG_H__
