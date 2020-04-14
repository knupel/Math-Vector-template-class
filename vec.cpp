#ifndef VEC_H
# define VEC_H
/*
* vec2 0.0.1
* Template Vec adapted from Rope Vector and Processing PVector
*/

#include <iostream>
#include <cmath>
#include <vector>

template <class T>
class vec {
protected:
	unsigned short size = 0;
	static T *arg;
public:
	vec ();
	std::vector<T*> v_list;
	virtual ~vec();
	unsigned short get_size() const;
};

template <class T>
vec<T>::vec() {
	//
}

template <class T>
vec<T>::~vec() {
	if(arg != nullptr)
		free(arg);
	//
}

template <class T>
unsigned short vec<T>::get_size() const {
	return size;
}

template <class T>
T  *vec<T>::arg = nullptr;


#endif