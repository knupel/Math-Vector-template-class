#ifndef VEC3_H
# define VEC3_H

// #pragma once
/**
* vec3 0.0.1
* 2020-2020
*/ 
// #include "vec.cpp"
#include "vec2.cpp"

// #include "r_t_utils.cpp"

template <class T>
class vec3 : public vec2<T> {
private:
	static int instance;
	static bool _warning;
protected:
	T _z;
public:
	vec3();
	vec3(T const &arg);
	vec3(T const &x, T const &y, T const &z);
	vec3(vec3<T> const &src);
	~vec3();

	T z() const;

	// info
	static void warning(bool is);
	static int get_instance();
};

template <class T>
std::ostream & operator<<(std::ostream & out, vec3<T> const &rhs);

/**
* TEMPLATE DEFINITION
*/
// get
template <class T>
T vec3<T>::z() const {
	return this->_z;
}

// CONSTRUCTOR + DESTRUCTOR
template <class T>
vec3<T>::vec3() : vec2<T>(), _z(0) {
	this->size = 3;
	set_list(this->v_list, &this->_x, &this->_y, &_z);
	if(vec3<T>::_warning) {
		std::cout << "Default constructor vec3" << std::endl;
		vec3<T>::instance++;
	}	
	return;
}

template <class T>
vec3<T>::vec3(T const &arg) : vec2<T>(arg), _z(arg) {
	this->size = 3;
	set_list(this->v_list, &this->_x, &this->_y, &_z); 
	if(vec3<T>::_warning) {
		std::cout << "Parametric constructor vec3" << std::endl;
		vec3<T>::instance++;
	}
	return;
}

template <class T>
vec3<T>::vec3(T const &x, T const &y, T const &z) : vec2<T>(x,y), _z(z) {
	this->size = 3;
	set_list(this->v_list, &this->_x, &this->_y, &_z);
	if(vec3<T>::_warning) {
		std::cout << "Parametric constructor vec3" << std::endl;
		vec3<T>::instance++;
	}
	return;
}

template <class T>
vec3<T>::vec3(vec3<T> const &src) : vec2<T>(src.x(),src.y()), _z(src.z()) {
	this->size = 3;
	set_list(this->v_list, &this->_x, &this->_y, &_z); 
	if(vec3<T>::_warning) {
		std::cout << "Copy constructor vec3" << std::endl;
		vec3<T>::instance++;
	}
	return;
}
	
template <class T>
vec3<T>::~vec3() {
	if(vec3<T>::_warning) {
		std::cout << "Destructor vec3" << std::endl;
		vec3<T>::instance--;
	}
	return;
}


// info
template <class T>
void vec3<T>::warning(bool is) {
	vec3<T>::_warning = is;
}

template <class T>
std::ostream & operator<<(std::ostream & out, vec3<T> const & rhs) {
	out << "[ " << rhs.x() << ", " << rhs.y() << ", " << rhs.z() << " ]";
	return out;
}

template <class T>
int vec3<T>::get_instance() {
	return vec3<T>::instance;
}

// static instantiation
template <class T>
bool vec3<T>::_warning = false;

template <class T>
int vec3<T>::instance = 0;
#endif