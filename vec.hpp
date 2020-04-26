#ifndef VEC_H
# define VEC_H
/*
* vec
* v 0.0.1
* 2020-2020
* Template Vec adapted from Rope Vector, Processing PVector, Openframework and GLSL
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <random>

#include "rope.hpp"

#include "r_t_utils.cpp"

template <class T>
class vec {
protected:
	unsigned short size = 0;
	char type = 0;
public:
	vec ();
	std::vector<T*> v_list;
	virtual ~vec();
	unsigned short get_size() const;
	char get_type() const;

	std::vector<T*> ref() const;
	std::vector<T> list();
	T sum() const;
	T average() const;
	T min() const;
	T max() const;


	T mag_sq() const;
	double mag() const;

};

#endif