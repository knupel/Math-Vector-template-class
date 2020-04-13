#ifndef VEC_H
# define VEC_H
// Template Vec adapted from Rope Vector and Processing PVector

#include <iostream>
#include <cmath>
#include <vector>

template <class T>
class vec {
private:
	static int instance;
protected:
	unsigned short size = 0;
public:
	vec ();
	std::vector<T*> v_list;
	virtual ~vec();
	unsigned short get_size() const;

	// static
	static int get_instance();
};

template <class T>
vec<T>::vec() {
	vec<T>::instance++;
}

template <class T>
vec<T>::~vec() {
	vec<T>::instance--;
}

template <class T>
unsigned short vec<T>::get_size() const {
	return size;
}


template <class T>
int vec<T>::get_instance() {
	return vec<T>::instance;
}

template <class T>
int vec<T>::instance = 0;

#endif