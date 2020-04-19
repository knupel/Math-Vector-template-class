/**
* Rope C++
* v 0.0.2
* Rope C++ library adaptation in the same way of Rope from Processing
* https://github.com/StanLepunK/Rope
*/
#ifndef ROPE_H
# define ROPE_H

#pragma once

#include <iostream>
#include <cmath>
#include <random>

// radnom declaration
float random(float min, float max);
float random(float min, float max, std::default_random_engine &generator);

double random_double(double min, double max);
double random_double(double min, double max, std::default_random_engine &generator);

bool random_bool();
bool random_bool(std::default_random_engine &generator);

int random_int(int min, int max);
int random_int(int min, int max, std::default_random_engine &generator);

long random_long(long min, long max);
long random_long(long min, long max, std::default_random_engine &generator);

char random_char(char min, char max);
char random_char(char min, char max, std::default_random_engine &generator);

double random_normal(double min, double max);
double random_normal(double min, double max, std::default_random_engine &generator);

int random_geom(double arg);
int random_geom(double arg, std::default_random_engine &generator);

double random_exp(double arg);
double random_exp(double arg, std::default_random_engine &generator);

#endif