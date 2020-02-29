
#include "rng.h"

Rng::Rng(): distribution(std::uniform_real_distribution<double>(0.0, 1.0))
{
	generator.seed(std::random_device()());
}

double Rng::probability()
{
	return distribution(generator);
}