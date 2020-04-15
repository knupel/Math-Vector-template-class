#ifndef VEC3_H
# define VEC3_H

#include "vec.cpp"


/**
* TEMPLATE DECLARATION
*/
template <class T>
class vec3 : public vec<T> {
private:
	static int instance;
	static bool _warning;
	T _x;
	T _y;
	T _z;

public:
	vec3();
	vec3(T const &arg);
	vec3(T const &x, T const &y, T const &z);
	vec3(vec3<T> const &src);
	~vec3();

	vec3 & operator=(vec3<T> const &rhs);


	// static
	static int get_instance();
	static void warning(bool is);

	// set
	void x(T x);
	void y(T y);
	void z(T z);
  
  // get
	T x() const;	
	T y() const;
	T z() const;
	vec3 copy() const;
	T * array() const;
}; 

template <class T>
std::ostream & operator<<(std::ostream &out, vec3<T> const &rhs);





/**
* TEMPLATE DEFINITION
*/

// construtor / destructor
template <class T>
vec3<T>::vec3() : _x(0), _y(0), _z(0) {
	this->size = 3;
	set_list(this->v_list, &_x, &_y, &_z); 
	if(vec3<T>::_warning) {
		std::cout << "Default constructor vec3" << std::endl;
		vec3<T>::instance++;
	}	
	return;
}

template <class T>
vec3<T>::vec3(T const &arg) : _x(arg), _y(arg), _z(arg) {
	this->size = 3;
	set_list(this->v_list, &_x, &_y, &_z);
	if(vec3<T>::_warning) {
		std::cout << "Parametric constructor vec3" << std::endl;
		vec3<T>::instance++;
	}
	return;
}


template <class T>
vec3<T>::vec3(T const &x, T const &y, T const &z) : _x(x), _y(y), _z(z) {
	this->size = 3;
	set_list(this->v_list, &_x, &_y, &_z); 
	if(vec3<T>::_warning) {
		std::cout << "Parametric constructor vec3" << std::endl;
		vec3<T>::instance++;
	}
	return;
}

template <class T>
vec3<T>::vec3(vec3<T> const &src) : _x(src.x()), _y(src.y()), _z(src.z()) {
	this->size = 3;
	set_list(this->v_list, &_x, &_y, &_z); 
	if(vec3<T>::_warning) {
		std::cout << "Copy constructor  vec3" << std::endl;
		vec3<T>::instance++;
	}
	
	return;
}
	
template <class T>
vec3<T>::~vec3(){
	if(vec3<T>::_warning) {
		std::cout << "Destructor vec3" << std::endl;
		vec3<T>::instance--;
	}
	return;
}



// OPERATOR
template <class T>
vec3<T> & vec3<T>::operator=(vec3<T> const &rhs) {
	this->x = rhs.x();
	this->y = rhs.y();
	this->z = rhs.z();
	return *this;
}




// SET
template <class T>
void vec3<T>::x(T x) {
	this->_x = x;
}

template <class T>
void vec3<T>::y(T y) {
	this->_y = y;
}

template <class T>
void vec3<T>::z(T z) {
	this->_z = z;
}

// get
template <class T>
int vec3<T>::get_instance() {
	return vec3<T>::instance;
}

template <class T>
void vec3<T>::warning(bool is) {
	vec3<T>::_warning = is;
}

template <class T>
T vec3<T>::x() const {
	return this->_x;
}

template <class T>
T vec3<T>::y() const {
	return this->_y;
}

template <class T>
T vec3<T>::z() const {
	return this->_z;
}

// get copy
template <class T>
vec3<T> vec3<T>::copy() const {
	return *this;
}

template <class T>
T * vec3<T>::array() const {
	static T arg[3];
	for(size_t i = 0 ; i < this->size ; i++) {
		arg[i] = *this->v_list.at(i);
	}
	return arg;
}



// return info
template <class T>
std::ostream & operator<<(std::ostream & out, vec3<T> const & rhs) {
	out << "[ " << rhs.x() << ", " << rhs.y() << ", " << rhs.z() << " ]";
	return out;
}

template <class T>
int vec3<T>::instance = 0;

template <class T>
bool vec3<T>::_warning = false;

#endif