/**
* Rope C++
* v 0.0.2
* Rope C++ library adaptation in the same way of Rope from Processing
* https://github.com/StanLepunK/Rope
*/
#ifndef ROPE_H
# define ROPE_H

#include <iostream>
#include <cmath>
#include <random>

// radnom declaration
float random(float min, float max);
double random_double(double min, double max);
bool random_bool();
int random_int(int min, int max);
long random_long(long min, long max);
char random_char(char min, char max);
double random_normal(double min, double max);
int random_geom(double arg);
double random_exp(double arg);

#endif