#include "rope.hpp"
/**
* rope utils
* v 0.0.1
*/

/**
* Random function to compute few sort or random result.
* v 0.0.2
* http://www.cplusplus.com/reference/random/uniform_real_distribution/
*/
float random(float min, float max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_real_distribution<float> gen_rand_float(min,max);
	return gen_rand_float(generator); 
}

double random_double(double min, double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_real_distribution<double> gen_rand_double(min,max);
	return gen_rand_double(generator); 
}

bool random_bool() {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_int_distribution<int> gen_rand_int(0,1);
	return gen_rand_int(generator); 
}

char random_char(char min, char max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_int_distribution<int> gen_rand_int(min,max);
	return gen_rand_int(generator);
}

int random_int(int min, int max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_int_distribution<int> gen_rand_int(min,max);
	return gen_rand_int(generator); 
}

long random_long(long min, long max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::uniform_int_distribution<long> gen_rand_int(min,max);
	return gen_rand_int(generator); 
}

double random_normal(double min, double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::normal_distribution<double> gen_rand_double(min,max);
	return gen_rand_double(generator); 
}

int random_geom(double arg) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::geometric_distribution<int> gen_rand_int(std::abs(arg));
	return gen_rand_int(generator); 
}

double random_exp(double arg) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::exponential_distribution<double> gen_rand_double(std::abs(arg));
	return gen_rand_double(generator); 
}