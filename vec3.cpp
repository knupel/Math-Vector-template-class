#ifndef VEC3_H
# define VEC3_H

// #pragma once
/**
* vec3 0.0.1
* 2020-2020
*/
#include "vec2.cpp"

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

  // set
  vec3 set(T const &arg);
  vec3 set(T const &x, T const &y, T const &z);
  vec3 x(T const &x);
  vec3 y(T const &y);
	vec3 z(T const &z);

	vec3 min(T const &x);
	vec3 max(T const &y);

	vec3 red(T const &x);
	vec3 gre(T const &y);
	vec3 blu(T const &z);

	vec3 hue(T const &x);
	vec3 sat(T const &y);
	vec3 bri(T const &z);

	//get
	T x() const;	
	T y() const;
	T z() const;

	T min() const;	
	T max() const;

	T red() const;
	T gre() const;
	T blu() const;

	T hue() const;
	T sat() const;
	T bri() const;


	// dot 
	// from vec2

	// cross
	vec3 cross(vec3<T> const &v);

	// dir
	vec3 dir();
	vec3 dir(vec3<T> const &origin);

	// tan
	// from vec2

	// angle
	// from vec2

	// heading
	// from vec2

	// mag_sq
	// from vec2

	// mag
	// from vec2

	// dist
	// from vec2

	// cacule the power of the vector for each component
	vec3 pow(T const &pow);
	vec3 pow(T const &pow_x, T const &pow_y, T const &pow_z);

	//map
	vec3 map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst);
	vec3 map(vec3<T> const &start_src, vec3<T> const &stop_src, vec3<T> const &start_dst, vec3<T> const &stop_dst);




	//normalize
	vec3 normalize();
	static vec3 normalize(vec3<T> &target);


	// limit
	vec3 limit(T const &max);
	// constrain
	vec3 constrain(T const &min, T const &max);
	vec3 constrain(vec3<T> const &min, vec3<T> const &max);

	// compare 
	// from vec2

	// rand
	vec3 rand();
	vec3 rand(T const &max);
	vec3 rand(T const &min, T const &max);
	vec3 rand(vec3<T> const &min, vec3<T> const &max);
	vec3 rand(T const &x_min, T const &y_min, T const &z_min,
						T const &x_max, T const &y_max, T const &z_max);

	vec3 rand(std::default_random_engine &generator);
	vec3 rand(T const &max, std::default_random_engine &generator);
	vec3 rand(T const &min, T const &max, std::default_random_engine &generator);
	vec3 rand(vec3<T> const &min, vec3<T> const &max, std::default_random_engine &generator);
	vec3 rand(T const &x_min, T const &y_min, T const &z_min, 
						T const &x_max, T const &y_max, T const &z_max,
						std::default_random_engine &generator);



	// wave
	vec3 wave(T const &value, T const &s);
	vec3 wave(T const &value, T const &sx, T const &sy, T const &sz);

	vec3 cos_wave(T const &value, T const &s);
	vec3 cos_wave(T const &value, T const &sx, T const &sy, T const &sz);

	vec3 sin_wave(T const &value, T const &s);
	vec3 sin_wave(T const &value, T const &sx, T const &sy, T const &sz);


	// op += *= /= -=
	// from vec2

	// other op
	vec3 operator+(vec3<T> const &rhs) const;
	vec3 operator+(T const &rhs) const;

	vec3 operator-(vec3<T> const &rhs) const;
	vec3 operator-(T const &rhs) const;

	vec3 operator*(vec3<T> const &rhs) const;
	vec3 operator*(T const &rhs) const;

	vec3 operator/(vec3<T> const &rhs) const;
	vec3 operator/(T const &rhs) const;


	// info
	static void warning(bool is);
	static int get_instance();
};

template <class T>
std::ostream & operator<<(std::ostream & out, vec3<T> const &rhs);










/**
* TEMPLATE DEFINITION
*/

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


// SET
template <class T>
vec3<T> vec3<T>::set(T const &arg) {
	this->_x = arg;
	this->_y = arg;
	this->_z = arg;
	return *this;
}

template <class T>
vec3<T> vec3<T>::set(T const &x, T const &y, T const &z) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
	return *this;
}

// set xyz
template <class T>
vec3<T> vec3<T>::x(T const &x) {
	this->_x = x;
	return *this;
}
template <class T>
vec3<T> vec3<T>::y(T const &y) {
	this->_y = y;
	return *this;
}

template <class T>
vec3<T> vec3<T>::z(T const &z) {
	this->_z = z;
	return *this;
}

// set min max
template <class T>
vec3<T> vec3<T>::min(T const &x) {
	this->_x = x;
	return *this;
}

template <class T>
vec3<T> vec3<T>::max(T const &y) {
	this->_y = y;
	return *this;
}


// set rgb
template <class T>
vec3<T> vec3<T>::red(T const &x) {
	this->_x = x;
	return *this;
}

template <class T>
vec3<T> vec3<T>::gre(T const &y) {
	this->_y = y;
	return *this;
}

template <class T>
vec3<T> vec3<T>::blu(T const &z) {
	return this->z(z);
}

// set hsb
template <class T>
vec3<T> vec3<T>::hue(T const &x) {
	this->_x = x;
	return *this;

}
template <class T>
vec3<T> vec3<T>::sat(T const &y) {
	this->_y = y;
	return *this;
}

template <class T>
vec3<T> vec3<T>::bri(T const &z) {
	return this->z(z);
}




// GET
//get xyz
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

// get min max
template <class T>
T vec3<T>::min() const {
	return this->_x;
}

template <class T>
T vec3<T>::max() const {
	return this->_y;
}

// get rgb
template <class T>
T vec3<T>::red() const {
	return this->_x;
}

template <class T>
T vec3<T>::gre() const {
	return this->_zy;
}

template <class T>
T vec3<T>::blu() const {
	return this->_z;
}

// get hsb
template <class T>
T vec3<T>::hue() const {
	return this->_x;
}

template <class T>
T vec3<T>::sat() const {
	return this->_y;
}

template <class T>
T vec3<T>::bri() const {
	return this->_z;
}







// COMMMON ALGORITHM FOR VEC
// 
// dir
template <class T>
vec3<T>	vec3<T>::dir() {
	return vec3<T>::dir(vec3<T>());
}

template <class T>
vec3<T>	vec3<T>::dir(vec3<T> const &origin) {
	vec3 temp = *this;
	T dist = vec3<T>::dist(origin);
	temp -= origin;
	temp /= dist;
	return temp;
}

// cross
template <class T>
vec3<T>	vec3<T>::cross(vec3<T> const &v) {
	T cross_x = this->y() * v.z() - v.y() * this->z();
	T cross_y = this->z() * v.x() - v.z() * this->x();
	T cross_z = this->x() * v.y() - v.x() * this->y();
	return vec3<T>(cross_x, cross_y, cross_z);
}



// pow
template <class T>
vec3<T>	vec3<T>::pow(T const &pow) {
	return vec3<T>::pow(pow, pow, pow);
}

template <class T>
vec3<T>	vec3<T>::pow(T const &pow_x, T const &pow_y, T const &pow_z) {
	this->_x = ::pow(this->x(), pow_x);
	this->_y = ::pow(this->y(), pow_y);
	this->_z = ::pow(this->z(), pow_z);
	return *this;
}


//map
template <class T>
vec3<T>	vec3<T>::map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst) {
	vec2<T>::map(start_src, stop_src, start_dst, stop_dst);
	return *this;
}

template <class T>
vec3<T>	vec3<T>::map(vec3<T> const &start_src, vec3<T> const &stop_src, vec3<T> const &start_dst, vec3<T> const &stop_dst) {
	vec2<T>::map(start_src, stop_src, start_dst, stop_dst);
	return *this;
}



// normalize
template <class T>
vec3<T>	vec3<T>::normalize() {
	vec2<T>::normalize();
	return *this;
}

template <class T>
vec3<T>	vec3<T>::normalize(vec3<T> &target) {
	return target.normalize();
}



// limit
template <class T>
vec3<T>	vec3<T>::limit(T const &max) {
	vec2<T>::limit(max);
	return *this;
}

// constrain
template <class T>
vec3<T>	vec3<T>::constrain(T const &min, T const &max) {
	vec2<T>::constrain(min,max);
	return *this;
}

template <class T>
vec3<T>	vec3<T>::constrain(vec3<T> const &min, vec3<T> const &max) {
	vec2<T>::constrain(min,max);
	return *this;
}



// random
template <class T>
vec3<T>	vec3<T>::rand() {
	return rand(0,0,0, 1,1,1);
}

template <class T>
vec3<T>	vec3<T>::rand(std::default_random_engine &generator) {
	return rand(0,0,0, 1,1,1, generator);
}

//
template <class T>
vec3<T>	vec3<T>::rand(T const &max) {
	return rand(0,0,0, max,max,max);
}

template <class T>
vec3<T>	vec3<T>::rand(T const &max, std::default_random_engine &generator) {
	return rand(0,0,0, max,max,max, generator);
}

//
template <class T>
vec3<T>	vec3<T>::rand(T const &min, T const &max) {
	return rand(min,min,min, max,max,max);
}

template <class T>
vec3<T>	vec3<T>::rand(T const &min, T const &max, std::default_random_engine &generator) {
	return rand(min,min,min, max,max,max, generator);
}

//
template <class T>
vec3<T>	vec3<T>::rand(vec3<T> const &min, vec3<T> const &max) {
	return rand(min.x(), min.y(), min.z(), 
							max.x(), max.y(), max.z());
}

template <class T>
vec3<T>	vec3<T>::rand(vec3<T> const &min, vec3<T> const &max, std::default_random_engine &generator) {
	return rand(min.x(), min.y(), min.z(),
							max.x(), max.y(), max.z(),
							generator);
}

//
template <class T>
vec3<T>	vec3<T>::rand(T const &x_min, T const &y_min, T const &z_min,
											T const &x_max, T const &y_max, T const &z_max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return rand(x_min, y_min, z_min,
							x_max, y_max, z_max,
							generator);
}


template <class T>
vec3<T>	vec3<T>::rand(T const &x_min, T const &y_min, T const &z_min, 
											T const &x_max, T const &y_max, T const &z_max,
											std::default_random_engine &generator) {
	switch(vec<T>::get_type()) {
		case 'c':
			this->_x = random_char(x_min, x_max);
			this->_y = random_char(y_min, y_max);
			this->_z = random_char(z_min, z_max);
			break;
		case 'b':
			this->_x = random_bool();
			this->_y = random_bool();
			this->_z = random_bool();
			break;
		case 's':
			this->_x = random_int(x_min, x_max);
			this->_y = random_int(y_min, y_max);
			this->_z = random_int(z_min, z_max);
			break;
		case 'i':
			this->_x = random_int(x_min, x_max);
			this->_y = random_int(y_min, y_max);
			this->_z = random_int(z_min, z_max);
			break;
		case 'l':
			this->_x = random_long(x_min, x_max);
			this->_y = random_long(y_min, y_max);
			this->_z = random_long(z_min, z_max);
			break;
		case 'f':
			this->_x = random(x_min, x_max);
			this->_y = random(y_min, y_max);
			this->_z = random(z_min, z_max);
			break;
		case 'd':
			this->_x = random_double(x_min, x_max);
			this->_y = random_double(y_min, y_max);
			this->_z = random_double(z_min, z_max);
			break;
		default:
			if(vec3<T>::_warning) {
				std::cout << "vec3<T>::rand(); wait <T arg> like bool, char, int, float, double" << std::endl;
			}
			abort();
	}
	return *this;
}







// wave
template <class T>
vec3<T>	vec3<T>::wave(T const &value, T const &s) {
	return cos_wave(value,s,s,s);
}

template <class T>
vec3<T>	vec3<T>::wave(T const &value, T const &sx, T const &sy, T const &sz) {
	return cos_wave(value,sx,sy,sz);
}

template <class T>
vec3<T>	vec3<T>::cos_wave(T const &value, T const &s) {
	return cos_wave(value,s,s,s);
}

template <class T>
vec3<T>	vec3<T>::cos_wave(T const &value, T const &sx, T const &sy, T const &sz) {
	T tx = cos(value * sx) + this->x();
	T ty = cos(value * sy) + this->y();
	T tz = cos(value * sz) + this->z();
	return vec3<T>(tx,ty,tz);
}

template <class T>
vec3<T>	vec3<T>::sin_wave(T const &value, T const &s) {
	return sin_wave(value,s,s,s);
}

template <class T>
vec3<T>	vec3<T>::sin_wave(T const &value, T const &sx, T const &sy, T const &sz) {
	T tx = sin(value * sx) + this->x();
	T ty = sin(value * sy) + this->y();
	T tz = sin(value * sz) + this->z();
	return vec3<T>(tx,ty,tz);
}



// OPERATOR + - * /
// op +
template <class T>
vec3<T> vec3<T>::operator+(vec3<T> const &rhs) const {
	vec3<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec3<T> vec3<T>::operator+(T const &rhs) const {
	vec3<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs;
	}
	return temp;
}


// op -
template <class T>
vec3<T> vec3<T>::operator-(vec3<T> const &rhs) const {
	vec3<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec3<T> vec3<T>::operator-(T const &rhs) const {
	vec3<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs;
	}
	return temp;
}


// op *
template <class T>
vec3<T> vec3<T>::operator*(vec3<T> const &rhs) const {
	vec3<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec3<T> vec3<T>::operator*(T const &rhs) const {
	vec3<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs;
	}
	return temp;
}


// op *
template <class T>
vec3<T> vec3<T>::operator/(vec3<T> const &rhs) const {
	vec3<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec3<T> vec3<T>::operator/(T const &rhs) const {
	vec3<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs;
	}
	return temp;
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