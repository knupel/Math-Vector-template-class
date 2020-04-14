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
	std::vector<T*> list();

	// common algorithm for all vec

	// Calcule the dot product of the vector
	T dot(vec2<T> const &v) const;
	T dot(T const &x, T const &y) const;

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


	// operator
	vec2 & operator=(vec2<T> const &rhs);

	vec2 operator+(vec2<T> const &rhs) const;
	vec2 operator+(T const &rhs) const;
	vec2 & operator+=(vec2<T> const &rhs);
	vec2 & operator+=(T const &rhs);

	vec2 operator-(vec2<T> const &rhs) const;
	vec2 operator-(T const &rhs) const;
	vec2 & operator-=(vec2<T> const &rhs);
	vec2 & operator-=(T const &rhs);

	vec2 operator*(vec2<T> const &rhs) const;
	vec2 operator*(T const &rhs) const;
	vec2 & operator*=(vec2<T> const &rhs);
	vec2 & operator*=(T const &rhs);

	vec2 operator/(vec2<T> const &rhs) const;
	vec2 operator/(T const &rhs) const;
	vec2 & operator/=(vec2<T> const &rhs);
	vec2 & operator/=(T const &rhs);

	// static
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
// dot
template <class T>
T vec2<T>::dot(vec2<T> const &v) const {
	return this->x()*v.x() + this->y()*v.y();
}

template <class T>
T vec2<T>::dot(T const &x, T const &y) const {
	return this->x()*x + this->y()*y;
}

// magSq
template <class T>
T vec2<T>::magSq() const {
	return (this->x()*this->x() + this->y()*this->y());
}

template <class T>
T vec2<T>::magSq(vec2<T> const &v) const {
	T temp_x = (v.x() - this->x()) * (v.x() - this->x());
	T temp_y = (v.y() - this->y()) * (v.y() - this->y());
	return (temp_x + temp_y);
}

// mag
template <class T>
double vec2<T>::mag() const {
	return ::sqrt(this->x()*this->x() + this->y()*this->y());
}

template <class T>
double vec2<T>::mag(vec2<T> const &v) const {
	T temp_x = (v.x() - this->x()) * (v.x() - this->x());
	T temp_y = (v.y() - this->y()) * (v.y() - this->y());
	return ::sqrt(temp_x + temp_y);
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

// OPERATOR
template <class T>
vec2<T> & vec2<T>::operator=(vec2<T> const &rhs) {
	this->x = rhs.x();
	this->y = rhs.y();
	return *this;
}


// op add
template <class T>
vec2<T> vec2<T>::operator+(vec2<T> const &rhs) const {
	return vec2(this->x() + rhs.x(), this->y() + rhs.y());
}

template <class T>
vec2<T> vec2<T>::operator+(T const &rhs) const {
	return vec2(this->x() + rhs, this->y() + rhs);
}

template <class T>
vec2<T> & vec2<T>::operator+=(vec2<T> const &rhs) {
	this->_x += rhs.x();
	this->_y += rhs.y();
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator+=(T const &rhs) {
	this->_x += rhs;
	this->_y += rhs;
	return *this;
}




// op sub
template <class T>
vec2<T> vec2<T>::operator-(vec2<T> const &rhs) const {
	return vec2(this->x() - rhs.x(), this->y() - rhs.y());
}

template <class T>
vec2<T> vec2<T>::operator-(T const &rhs) const {
	return vec2(this->x() - rhs, this->y() - rhs);
}


template <class T>
vec2<T> & vec2<T>::operator-=(vec2<T> const &rhs) {
	this->_x -= rhs.x();
	this->_y -= rhs.y();
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator-=(T const &rhs) {
	this->_x -= rhs;
	this->_y -= rhs;
	return *this;
}



// op mult
template <class T>
vec2<T> vec2<T>::operator*(vec2<T> const &rhs) const {
	return vec2(this->x() * rhs.x(), this->y() * rhs.y());
}

template <class T>
vec2<T> vec2<T>::operator*(T const &rhs) const {
	return vec2(this->x() * rhs, this->y() * rhs);
}

template <class T>
vec2<T> & vec2<T>::operator*=(vec2<T> const &rhs) {
	this->_x *= rhs.x();
	this->_y *= rhs.y();
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator*=(T const &rhs) {
	this->_x *= rhs;
	this->_y *= rhs;
	return *this;
}



// op div
template <class T>
vec2<T> vec2<T>::operator/(vec2<T> const &rhs) const {
	return vec2(this->x() / rhs.x(), this->y() / rhs.y());
}

template <class T>
vec2<T> vec2<T>::operator/(T const &rhs) const {
	return vec2(this->x() / rhs, this->y() / rhs);
}

template <class T>
vec2<T> & vec2<T>::operator/=(vec2<T> const &rhs) {
	this->_x /= rhs.x();
	this->_y /= rhs.y();
	return *this;
}

template <class T>
vec2<T> & vec2<T>::operator/=(T const &rhs) {
	this->_x /= rhs;
	this->_y /= rhs;
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
	// size_t const length = this->v_list.size();
	// T arg[length];
	// int temp = this->size;
	// static T *arg;
	if(this->arg == nullptr) {
	  printf("malloc");
		this->arg = (T*)malloc(this->size * sizeof(T));
	}
	size_t length = (sizeof(this->arg)/sizeof(*this->arg));
	for(size_t i = 0 ; i < length ; i++) {
		this->arg[i] = *this->v_list.at(i);
	}
	printf(" %p > ", &this->arg);
	return this->arg;
}

template <class T>
std::vector<T*> vec2<T>::list() {
	return this->v_list;
}



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