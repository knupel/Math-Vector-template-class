#ifndef VEC2_H
# define VEC2_H
/**
* vec2 0.0.1
* 2020-2020
*/ 
#include "vec.cpp"
#include "rt_utils.cpp"

#include "rope.hpp"


/**
* TEMPLATE DECLARATION
*/
template <class T>
class vec2 : public vec<T> {
private:
	static int instance;
	static bool _warning;
	T _x;
	T _y;
public:
	vec2();
	vec2(T const &arg);
	vec2(T const &x, T const &y);
	vec2(vec2<T> const &src);
	~vec2();

	// set
	void x(T x);
	void y(T y);
  
  // get
	T x() const;	
	T y() const;
	vec2 copy() const;
	T * array() const;

	// common algorithm for all vec

	// Calcule the dot product of the vector
	T dot(vec2<T> const &v) const;
	T dot(T const &x, T const &y) const;

	// dir > return normal cartesian direction
	vec2 dir();
	vec2 dir(T const &a_x, T const &a_y);
	vec2 dir(vec2<T> const &origin);


	// square length can be usefull and faster when the real length is not necessary
	T magSq() const;
	T magSq(vec2<T> const &v) const;
	// Calculate the magnitude, distance or length of the vector or between two vectors.
	// mag and dist is a same methode
	double mag() const;
	double mag(vec2<T> const &v) const;
	// Calculate the magnitude, distance or length of the vector or between two vectors.
	// call mag to calculate the the dist
	double dist() const;
	double dist(vec2<T> const &v) const;

	// cacule the power of the vector for each component
	vec2 pow(T const &pow);
	vec2 pow(T const &pow_x, T const &pow_y);

	//normalize
	vec2 normalize();
	static vec2 normalize(vec2<T> target);

	// limit
	vec2 limit(T const &max);
	
	// operator
	// vec2 & operator=(vec2<T> const &rhs) const;
	vec2 & operator=(vec2<T> const &rhs);
	// vec2 & operator=(vec2<T> &rhs);

	vec2 operator+(vec2<T> const &rhs) const;
	vec2 operator+(T const &rhs) const;
	// vec2 add(vec2<T> const &rhs) const;
	// vec2 add(T const &rhs) const;
	vec2 & operator+=(vec2<T> const &rhs);
	vec2 & operator+=(T const &rhs);

	vec2 operator-(vec2<T> const &rhs) const;
	vec2 operator-(T const &rhs) const;
	// vec2 sub(vec2<T> const &rhs) const;
	// vec2 sub(T const &rhs) const;
	vec2 & operator-=(vec2<T> const &rhs);
	vec2 & operator-=(T const &rhs);

	vec2 operator*(vec2<T> const &rhs) const;
	vec2 operator*(T const &rhs) const;
	// vec2 mult(vec2<T> const &rhs) const;
	// vec2 mult(T const &rhs) const;
	vec2 & operator*=(vec2<T> const &rhs);
	vec2 & operator*=(T const &rhs);

	vec2 operator/(vec2<T> const &rhs) const;
	vec2 operator/(T const &rhs) const;
	// vec2 div(vec2<T> const &rhs) const;
	// vec2 div(T const &rhs) const;
	vec2 & operator/=(vec2<T> const &rhs);
	vec2 & operator/=(T const &rhs);

	// info
	static void warning(bool is);
	static int get_instance();
	
}; 


template <class T>
std::ostream & operator<<(std::ostream &out, vec2<T> const &rhs);





/**
* TEMPLATE DEFINITION
*/

// CONSTRUCTOR + DESTRUCTOR
template <class T>
vec2<T>::vec2() : _x(0), _y(0) {
	this->size = 2;
  set_list(this->v_list, &_x, &_y); 
	if(vec2<T>::_warning) {
		std::cout << "Default constructor vec2" << std::endl;
		vec2<T>::instance++;
	}	
	return;
}

template <class T>
vec2<T>::vec2(T const &arg) : _x(arg), _y(arg) {
	this->size = 2;
	set_list(this->v_list, &_x, &_y);
	if(vec2<T>::_warning) {
		std::cout << "Parametric constructor vec2" << std::endl;
		vec2<T>::instance++;
	}
	return;
}

template <class T>
vec2<T>::vec2(T const &x, T const &y) : _x(x), _y(y) {
	this->size = 2;
	set_list(this->v_list, &_x, &_y);
	if(vec2<T>::_warning) {
		std::cout << "Parametric constructor vec2" << std::endl;
		vec2<T>::instance++;
	}
	return;
}

template <class T>
vec2<T>::vec2(vec2<T> const &src) : _x(src.x()), _y(src.y()) {
	this->size = 2;
	set_list(this->v_list, &_x, &_y);
	if(vec2<T>::_warning) {
		std::cout << "Copy constructor vec2" << std::endl;
		vec2<T>::instance++;
	}
	return;
}
	
template <class T>
vec2<T>::~vec2() {
	if(vec2<T>::_warning) {
		std::cout << "Destructor vec2" << std::endl;
		vec2<T>::instance--;
	}
	return;
}


// COMMMON ALGORITHM FOR VEC
/**
* dot
*/
template <class T>
T vec2<T>::dot(vec2<T> const &v) const {
	return this->x()*v.x() + this->y()*v.y();
}

template <class T>
T vec2<T>::dot(T const &x, T const &y) const {
	return this->x()*x + this->y()*y;
}

/**
* DIRECTION NORMAL
*/
template <class T>
vec2<T>	vec2<T>::dir() {
	return vec2<T>::dir(vec2<T>());
}

template <class T>
vec2<T>	vec2<T>::dir(T const &a_x, T const &a_y) {
	return vec2<T>::dir(vec2<T>(a_x, a_y));
}

template <class T>
vec2<T>	vec2<T>::dir(vec2<T> const &origin) {
	vec2 temp = *this;
	T dist = vec2<T>::dist(origin);
	temp -= origin;
	temp /= dist;
	return temp;
}





/**
* MAG / DIST
*/
template <class T>
T vec2<T>::magSq() const {
	T res = 0;
	for(size_t i = 0 ; i < this->v_list.size() ; i++) {
		res += (this->v_list.at(i)[0] * this->v_list.at(i)[0]);
	}
	return res;
}

template <class T>
T vec2<T>::magSq(vec2<T> const &v) const {
	T res = 0;
	for(size_t i = 0 ; i < this->v_list.size() ; i++) {
		res += ((v.v_list.at(i)[0] - this->v_list.at(i)[0]) * (v.v_list.at(i)[0] - this->v_list.at(i)[0]));
	}
	return res;
}

// mag
template <class T>
double vec2<T>::mag() const {
	return ::sqrt(vec2<T>::magSq());
}

template <class T>
double vec2<T>::mag(vec2<T> const &v) const {
	return ::sqrt(vec2<T>::magSq(v));
}

// dist
template <class T>
double vec2<T>::dist() const {
	return vec2<T>::mag();
}

template <class T>
double vec2<T>::dist(vec2<T> const &v) const {
	return vec2<T>::mag(v);
}


// pow
template <class T>
vec2<T>	vec2<T>::pow(T const &pow) {
	return vec2<T>::pow(pow, pow);
}

template <class T>
vec2<T>	vec2<T>::pow(T const &pow_x, T const &pow_y) {
	this->_x = ::pow(this->x(), pow_x);
	this->_y = ::pow(this->y(), pow_y);
	return *this;
}

//normalize
template <class T>
vec2<T>	vec2<T>::normalize(vec2<T> target) {
	return target.normalize();
}

template <class T>
vec2<T>	vec2<T>::normalize() {
	T m = vec2<T>::mag();
	if (m != 0 && m != 1) {
		*this /= m;
	}
	return *this;
}

template <class T>
vec2<T>	vec2<T>::limit(T const &max) {
	if (vec2<T>::magSq() > max*max) {
		vec2<T>::normalize();
		*this *= max;
	}
	return *this;
}

// OPERATOR
template <class T>
vec2<T> & vec2<T>::operator=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = rhs.ref().at(i)[0];
	}
	return *this;
}


// op add
template <class T>
vec2<T> vec2<T>::operator+(vec2<T> const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator+(T const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs;
	}
	return temp;
}

template <class T>
vec2<T> & vec2<T>::operator+=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] += rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator+=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] += rhs;
	}
	return *this;
}




// op sub
template <class T>
vec2<T> vec2<T>::operator-(vec2<T> const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator-(T const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs;
	}
	return temp;
}


template <class T>
vec2<T> & vec2<T>::operator-=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] -= rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator-=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] -= rhs;
	}
	return *this;
}



// op mult
template <class T>
vec2<T> vec2<T>::operator*(vec2<T> const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator*(T const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs;
	}
	return temp;
}

template <class T>
vec2<T> & vec2<T>::operator*=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] *= rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator*=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] *= rhs;
	}
	return *this;
}



// op div
template <class T>
vec2<T> vec2<T>::operator/(vec2<T> const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator/(T const &rhs) const {
	vec2 temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs;
	}
	return temp;
}

template <class T>
vec2<T> & vec2<T>::operator/=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] /= rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator/=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] /= rhs;
	}
	return *this;
}



// set
template <class T>
void vec2<T>::x(T x) {
	this->_x = x;
}

template <class T>
void vec2<T>::y(T y) {
	this->_y = y;
}



// get
template <class T>
T vec2<T>::x() const {
	return this->_x;
}

template <class T>
T vec2<T>::y() const {
	return this->_y;
}

template <class T>
vec2<T> vec2<T>::copy() const {
	return *this;
}

template <class T>
T * vec2<T>::array() const {
	static T arg[2];
	for(size_t i = 0 ; i < this->get_size() ; i++) {
		arg[i] = *this->v_list.at(i);
	}
	return arg;
}


// info
template <class T>
void vec2<T>::warning(bool is) {
	vec2<T>::_warning = is;
}


template <class T>
std::ostream & operator<<(std::ostream & out, vec2<T> const & rhs) {
	out << "[ " << rhs.x() << ", " << rhs.y() << " ]";
	return out;
}

template <class T>
int vec2<T>::get_instance() {
	return vec2<T>::instance;
}


// static instantiation
template <class T>
bool vec2<T>::_warning = false;

template <class T>
int vec2<T>::instance = 0;

#endif