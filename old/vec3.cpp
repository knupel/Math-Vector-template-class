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


		// square length can be usefull and faster when the real length is not necessary
	T magSq() const;
	T magSq(vec3<T> const &v) const;
	// Calculate the magnitude, distance or length of the vector or between two vectors.
	// mag and dist is a same methode
	double mag() const;
	double mag(vec3<T> const &v) const;
	// Calculate the magnitude, distance or length of the vector or between two vectors.
	// call mag to calculate the the dist
	double dist() const;
	double dist(vec3<T> const &v) const;

	// mist
	/**
	* CROSS PRODUCT
	* Calculates and returns a vector composed of the cross product between
  * two vectors.
  */
  /*
  vec3 cross(vec3<T> const &v) const;
  // vec<T> target to store the result
  vec3 cross(vec3<T> const &v, vec3<T> const &target) const;
  static vec3 cross(vec3<T> const &v1, vec3<T> const &v2, vec3<T> const &target) const;
  */
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
	this->_x = rhs.x();
	this->_y = rhs.y();
	this->_z = rhs.z();
	return *this;
}

/*
// cross
vec3<T>	vec3<T>::cross(vec3<T> const &v) const {
	return vec3<T>::cross(v, nullptr):

}
  // vec<T> target to store the result
vec3<T>	vec3<T>::cross(vec3<T> const &v, vec3<T> &target) const {
	T cross_x = this->y() * v.z() - v.y() * this->z();
  T cross_y = this->z() * v.x() - v.z() * this->x();
  T cross_z = this->x() * v.y() - v.x() * this->y();

  if (target == nullptr) {
		target = vec3<T>(cross_x, cross_y, cross_z);
	} else {
		target->set(cross_x, cross_y, cross_z);
	}
	return target;
}


//  static vec3 cross(vec3<T> const &v1, vec3<T> const &v2, vec3<T> &target);
*/



/**
* MAG / DIST
*/
template <class T>
T vec3<T>::magSq() const {
	T res = 0;
	for(size_t i = 0 ; i < this->v_list.size() ; i++) {
		res += (this->v_list.at(i)[0] * this->v_list.at(i)[0]);
	}
	return res;
}

template <class T>
T vec3<T>::magSq(vec3<T> const &v) const {
	T res = 0;
	for(size_t i = 0 ; i < this->v_list.size() ; i++) {
		res += ((v.v_list.at(i)[0] - this->v_list.at(i)[0]) * (v.v_list.at(i)[0] - this->v_list.at(i)[0]));
	}
	return res;
}

// mag
template <class T>
double vec3<T>::mag() const {
	return ::sqrt(vec3<T>::magSq());
}

template <class T>
double vec3<T>::mag(vec3<T> const &v) const {
	return ::sqrt(vec3<T>::magSq(v));
}

// dist
template <class T>
double vec3<T>::dist() const {
	return vec3<T>::mag();
}

template <class T>
double vec3<T>::dist(vec3<T> const &v) const {
	return vec3<T>::mag(v);
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