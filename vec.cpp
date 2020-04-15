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
public:
	vec ();
	std::vector<T*> v_list;
	virtual ~vec();
	unsigned short get_size() const;
	std::vector<T*> ref();
	std::vector<T> list();
	T min() const;
	T max() const;
};

template <class T>
vec<T>::vec() {
	//
}

template <class T>
vec<T>::~vec() {
	//
}

template <class T>
unsigned short vec<T>::get_size() const {
	return size;
}

template <class T>
std::vector<T> vec<T>::list() {
	std::vector<T> temp;
	for(size_t i = 0 ; i < v_list.size() ; i++) {
		temp.push_back(v_list.at(i)[0]);
	}
	return temp;
}

template <class T>
std::vector<T*> vec<T>::ref() {
	return v_list;
}

template <class T>
T vec<T>::min() const {
	std::vector<T> temp;
	for(size_t i = 0 ; i < v_list.size() ; i++) {
		temp.push_back(v_list.at(i)[0]);
	}
	return *std::min_element(temp.begin(), temp.end());
}

template <class T>
T vec<T>::max() const {
	std::vector<T> temp;
	for(size_t i = 0 ; i < v_list.size() ; i++) {
		temp.push_back(v_list.at(i)[0]);
	}
	return *std::max_element(temp.begin(), temp.end());
}

#endif