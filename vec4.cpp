#ifndef VEC4_H
# define VEC4_H

// #pragma once
/**
* vec3 0.0.1
* 2020-2020
*/
#include "vec3.cpp"

template <class T>
class vec4 : public vec3<T> {
private:
	static int instance;
	static bool _warning;
protected:
	T _w;
public:
	vec4();
	vec4(T const &arg);
	vec4(T const &x, T const &y, T const &z, T const &w);
	vec4(vec4<T> const &src);
	~vec4();

  // set
  vec4 set(T const &arg);
  vec4 set(T const &x, T const &y, T const &z, T const &w);
  vec4 x(T const &x);
  vec4 y(T const &y);
	vec4 z(T const &z);
	vec4 w(T const &w);

	vec4 min(T const &x);
	vec4 max(T const &y);

	vec4 red(T const &x);
	vec4 gre(T const &y);
	vec4 blu(T const &z);

	vec4 hue(T const &x);
	vec4 sat(T const &y);
	vec4 bri(T const &z);

	vec4 alp(T const &w);

	//get
	T x() const;	
	T y() const;
	T z() const;
	T w() const;

	T min() const;	
	T max() const;

	T red() const;
	T gre() const;
	T blu() const;

	T hue() const;
	T sat() const;
	T bri() const;

	T alp() const;


	// dot 
	// from vec2

	// cross
	// from vec3

	// dir
	vec4 dir();
	vec4 dir(vec4<T> const &origin);

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
	vec4 pow(T const &pow);
	vec4 pow(T const &pow_x, T const &pow_y, T const &pow_z, T const &pow_w);

	//map
	vec4 map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst);
	vec4 map(vec4<T> const &start_src, vec4<T> const &stop_src, vec4<T> const &start_dst, vec4<T> const &stop_dst);




	//normalize
	vec4 normalize();
	static vec4 normalize(vec4<T> &target);


	// limit
	vec4 limit(T const &max);
	// constrain
	vec4 constrain(T const &min, T const &max);
	vec4 constrain(vec4<T> const &min, vec4<T> const &max);

	// compare 
	// from vec2

	// rand
	vec4 rand();
	vec4 rand(T const &max);
	vec4 rand(T const &min, T const &max);
	vec4 rand(vec4<T> const &min, vec4<T> const &max);
	vec4 rand(T const &x_min, T const &y_min, T const &z_min, T const &w_min,
						T const &x_max, T const &y_max, T const &z_max, T const &w_max);

	vec4 rand(std::default_random_engine &generator);
	vec4 rand(T const &max, std::default_random_engine &generator);
	vec4 rand(T const &min, T const &max, std::default_random_engine &generator);
	vec4 rand(vec4<T> const &min, vec4<T> const &max, std::default_random_engine &generator);
	vec4 rand(T const &x_min, T const &y_min, T const &z_min, T const &w_min, 
						T const &x_max, T const &y_max, T const &z_max, T const &w_max,
						std::default_random_engine &generator);



	// wave
	vec4 wave(T const &value, T const &s);
	vec4 wave(T const &value, T const &sx, T const &sy, T const &sz, T const &sw);

	vec4 cos_wave(T const &value, T const &s);
	vec4 cos_wave(T const &value, T const &sx, T const &sy, T const &sz, T const &sw);

	vec4 sin_wave(T const &value, T const &s);
	vec4 sin_wave(T const &value, T const &sx, T const &sy, T const &sz, T const &sw);


	// op += *= /= -=
	// from vec2

	// other op
	vec4 operator+(vec4<T> const &rhs) const;
	vec4 operator+(T const &rhs) const;

	vec4 operator-(vec4<T> const &rhs) const;
	vec4 operator-(T const &rhs) const;

	vec4 operator*(vec4<T> const &rhs) const;
	vec4 operator*(T const &rhs) const;

	vec4 operator/(vec4<T> const &rhs) const;
	vec4 operator/(T const &rhs) const;


	// info
	static void warning(bool is);
	static int get_instance();
};

template <class T>
std::ostream & operator<<(std::ostream & out, vec4<T> const &rhs);










/**
* TEMPLATE DEFINITION
*/

// CONSTRUCTOR + DESTRUCTOR
template <class T>
vec4<T>::vec4() : vec3<T>(), _w(0) {
	this->size = 4;
	set_list(this->v_list, &this->_x, &this->_y, &this->_z, &_w);
	if(vec4<T>::_warning) {
		std::cout << "Default constructor vec4" << std::endl;
		vec4<T>::instance++;
	}	
	return;
}

template <class T>
vec4<T>::vec4(T const &arg) : vec3<T>(arg), _w(arg) {
	this->size = 4;
	set_list(this->v_list, &this->_x, &this->_y, &this->_z, &_w); 
	if(vec4<T>::_warning) {
		std::cout << "Parametric constructor vec4" << std::endl;
		vec4<T>::instance++;
	}
	return;
}

template <class T>
vec4<T>::vec4(T const &x, T const &y, T const &z, T const &w) : vec3<T>(x,y,z), _w(w) {
	this->size = 4;
	set_list(this->v_list, &this->_x, &this->_y, &this->_z, &_w);
	if(vec4<T>::_warning) {
		std::cout << "Parametric constructor vec4" << std::endl;
		vec4<T>::instance++;
	}
	return;
}

template <class T>
vec4<T>::vec4(vec4<T> const &src) : vec3<T>(src.x(),src.y(),src.z()), _w(src.w()) {
	this->size = 4;
	set_list(this->v_list, &this->_x, &this->_y, &this->_z, &_w); 
	if(vec4<T>::_warning) {
		std::cout << "Copy constructor vec4" << std::endl;
		vec4<T>::instance++;
	}
	return;
}
	
template <class T>
vec4<T>::~vec4() {
	if(vec4<T>::_warning) {
		std::cout << "Destructor vec4" << std::endl;
		vec4<T>::instance--;
	}
	return;
}


// SET
template <class T>
vec4<T> vec4<T>::set(T const &arg) {
	this->_x = arg;
	this->_y = arg;
	this->_z = arg;
	this->_w = arg;
	return *this;
}


template <class T>
vec4<T> vec4<T>::set(T const &x, T const &y, T const &z, T const &w) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
	this->_w = w;
	return *this;
}

// set xyzw
template <class T>
vec4<T> vec4<T>::x(T const &x) {
	this->_x = x;
	return *this;
}
template <class T>
vec4<T> vec4<T>::y(T const &y) {
	this->_y = y;
	return *this;
}

template <class T>
vec4<T> vec4<T>::z(T const &z) {
	this->_z = z;
	return *this;
}

template <class T>
vec4<T> vec4<T>::w(T const &w) {
	this->_w = w;
	return *this;
}

// set min max
template <class T>
vec4<T> vec4<T>::min(T const &x) {
	this->_x = x;
	return *this;
}

template <class T>
vec4<T> vec4<T>::max(T const &y) {
	this->_y = y;
	return *this;
}


// set rgb
template <class T>
vec4<T> vec4<T>::red(T const &x) {
	this->_x = x;
	return *this;
}

template <class T>
vec4<T> vec4<T>::gre(T const &y) {
	this->_y = y;
	return *this;
}

template <class T>
vec4<T> vec4<T>::blu(T const &z) {
	return this->z(z);
}

// set hsb
template <class T>
vec4<T> vec4<T>::hue(T const &x) {
	this->_x = x;
	return *this;

}
template <class T>
vec4<T> vec4<T>::sat(T const &y) {
	this->_y = y;
	return *this;
}

template <class T>
vec4<T> vec4<T>::bri(T const &z) {
	return this->z(z);
}

// alpha
template <class T>
vec4<T> vec4<T>::alp(T const &w) {
	return this->w(w);
}




// GET
//get xyz
template <class T>
T vec4<T>::x() const {
	return this->_x;
}

template <class T>
T vec4<T>::y() const {
	return this->_y;
}

template <class T>
T vec4<T>::z() const {
	return this->_z;
}

template <class T>
T vec4<T>::w() const {
	return this->_w;
}

// get min max
template <class T>
T vec4<T>::min() const {
	return this->_x;
}

template <class T>
T vec4<T>::max() const {
	return this->_y;
}

// get rgb
template <class T>
T vec4<T>::red() const {
	return this->_x;
}

template <class T>
T vec4<T>::gre() const {
	return this->_zy;
}

template <class T>
T vec4<T>::blu() const {
	return this->_z;
}

// get hsb
template <class T>
T vec4<T>::hue() const {
	return this->_x;
}

template <class T>
T vec4<T>::sat() const {
	return this->_y;
}

template <class T>
T vec4<T>::bri() const {
	return this->_z;
}


// get alpha
template <class T>
T vec4<T>::alp() const {
	return this->_w;
}






// COMMMON ALGORITHM FOR VEC
// 
// dir
template <class T>
vec4<T>	vec4<T>::dir() {
	return vec4<T>::dir(vec4<T>());
}

template <class T>
vec4<T>	vec4<T>::dir(vec4<T> const &origin) {
	vec4 temp = *this;
	T dist = vec4<T>::dist(origin);
	temp -= origin;
	temp /= dist;
	return temp;
}


// pow
template <class T>
vec4<T>	vec4<T>::pow(T const &pow) {
	return vec4<T>::pow(pow, pow, pow, pow);
}

template <class T>
vec4<T>	vec4<T>::pow(T const &pow_x, T const &pow_y, T const &pow_z, T const &pow_w) {
	this->_x = ::pow(this->x(), pow_x);
	this->_y = ::pow(this->y(), pow_y);
	this->_z = ::pow(this->z(), pow_z);
	this->_w = ::pow(this->w(), pow_w);
	return *this;
}


//map
template <class T>
vec4<T>	vec4<T>::map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst) {
	vec2<T>::map(start_src, stop_src, start_dst, stop_dst);
	return *this;
}

template <class T>
vec4<T>	vec4<T>::map(vec4<T> const &start_src, vec4<T> const &stop_src, vec4<T> const &start_dst, vec4<T> const &stop_dst) {
	vec2<T>::map(start_src, stop_src, start_dst, stop_dst);
	return *this;
}



// normalize
template <class T>
vec4<T>	vec4<T>::normalize() {
	vec2<T>::normalize();
	return *this;
}

template <class T>
vec4<T>	vec4<T>::normalize(vec4<T> &target) {
	return target.normalize();
}



// limit
template <class T>
vec4<T>	vec4<T>::limit(T const &max) {
	vec2<T>::limit(max);
	return *this;
}

// constrain
template <class T>
vec4<T>	vec4<T>::constrain(T const &min, T const &max) {
	vec2<T>::constrain(min,max);
	return *this;
}

template <class T>
vec4<T>	vec4<T>::constrain(vec4<T> const &min, vec4<T> const &max) {
	vec2<T>::constrain(min,max);
	return *this;
}



// random
template <class T>
vec4<T>	vec4<T>::rand() {
	return rand(0,0,0,0, 1,1,1,1);
}

template <class T>
vec4<T>	vec4<T>::rand(std::default_random_engine &generator) {
	return rand(0,0,0,0, 1,1,1,1, generator);
}

//
template <class T>
vec4<T>	vec4<T>::rand(T const &max) {
	return rand(0,0,0,0, max,max,max,max);
}

template <class T>
vec4<T>	vec4<T>::rand(T const &max, std::default_random_engine &generator) {
	return rand(0,0,0,0, max,max,max,max, generator);
}

//
template <class T>
vec4<T>	vec4<T>::rand(T const &min, T const &max) {
	return rand(min,min,min,min, max,max,max,max);
}

template <class T>
vec4<T>	vec4<T>::rand(T const &min, T const &max, std::default_random_engine &generator) {
	return rand(min,min,min,min, max,max,max,max, generator);
}

//
template <class T>
vec4<T>	vec4<T>::rand(vec4<T> const &min, vec4<T> const &max) {
	return rand(min.x(), min.y(), min.z(), min.w(),
							max.x(), max.y(), max.z(), max.w());
}

template <class T>
vec4<T>	vec4<T>::rand(vec4<T> const &min, vec4<T> const &max, std::default_random_engine &generator) {
	return rand(min.x(), min.y(), min.z(), min.w(),
							max.x(), max.y(), max.z(), max.w(),
							generator);
}

//
template <class T>
vec4<T>	vec4<T>::rand(T const &x_min, T const &y_min, T const &z_min, T const &w_min,
											T const &x_max, T const &y_max, T const &z_max, T const &w_max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return rand(x_min, y_min, z_min, w_min,
							x_max, y_max, z_max, w_max,
							generator);
}


template <class T>
vec4<T>	vec4<T>::rand(T const &x_min, T const &y_min, T const &z_min, T const &w_min,
											T const &x_max, T const &y_max, T const &z_max, T const &w_max,
											std::default_random_engine &generator) {
	switch(vec<T>::get_type()) {
		case 'c':
			this->_x = random_char(x_min, x_max);
			this->_y = random_char(y_min, y_max);
			this->_z = random_char(z_min, z_max);
			this->_w = random_char(w_min, w_max);
			break;
		case 'b':
			this->_x = random_bool();
			this->_y = random_bool();
			this->_z = random_bool();
			this->_w = random_bool();
			break;
		case 's':
			this->_x = random_int(x_min, x_max);
			this->_y = random_int(y_min, y_max);
			this->_z = random_int(z_min, z_max);
			this->_w = random_int(w_min, w_max);
			break;
		case 'i':
			this->_x = random_int(x_min, x_max);
			this->_y = random_int(y_min, y_max);
			this->_z = random_int(z_min, z_max);
			this->_w = random_int(w_min, w_max);
			break;
		case 'l':
			this->_x = random_long(x_min, x_max);
			this->_y = random_long(y_min, y_max);
			this->_z = random_long(z_min, z_max);
			this->_w = random_long(w_min, w_max);
			break;
		case 'f':
			this->_x = random(x_min, x_max);
			this->_y = random(y_min, y_max);
			this->_z = random(z_min, z_max);
			this->_w = random(w_min, w_max);
			break;
		case 'd':
			this->_x = random_double(x_min, x_max);
			this->_y = random_double(y_min, y_max);
			this->_z = random_double(z_min, z_max);
			this->_w = random_double(w_min, w_max);
			break;
		default:
			if(vec4<T>::_warning) {
				std::cout << "vec4<T>::rand(); wait <T arg> like bool, char, int, float, double" << std::endl;
			}
			abort();
	}
	return *this;
}







// wave
template <class T>
vec4<T>	vec4<T>::wave(T const &value, T const &s) {
	return cos_wave(value,s,s,s,s);
}

template <class T>
vec4<T>	vec4<T>::wave(T const &value, T const &sx, T const &sy, T const &sz, T const &sw) {
	return cos_wave(value,sx,sy,sz,sw);
}

template <class T>
vec4<T>	vec4<T>::cos_wave(T const &value, T const &s) {
	return cos_wave(value,s,s,s,s);
}

template <class T>
vec4<T>	vec4<T>::cos_wave(T const &value, T const &sx, T const &sy, T const &sz, T const &sw) {
	T tx = cos(value * sx) + this->x();
	T ty = cos(value * sy) + this->y();
	T tz = cos(value * sz) + this->z();
	T tw = cos(value * sw) + this->w();
	return vec4<T>(tx,ty,tz,tw);
}

template <class T>
vec4<T>	vec4<T>::sin_wave(T const &value, T const &s) {
	return sin_wave(value,s,s,s,s);
}

template <class T>
vec4<T>	vec4<T>::sin_wave(T const &value, T const &sx, T const &sy, T const &sz, T const &sw) {
	T tx = sin(value * sx) + this->x();
	T ty = sin(value * sy) + this->y();
	T tz = sin(value * sz) + this->z();
	T tw = sin(value * sw) + this->w();
	return vec4<T>(tx,ty,tz,tw);
}



// OPERATOR + - * /
// op +
template <class T>
vec4<T> vec4<T>::operator+(vec4<T> const &rhs) const {
	vec4<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec4<T> vec4<T>::operator+(T const &rhs) const {
	vec4<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs;
	}
	return temp;
}


// op -
template <class T>
vec4<T> vec4<T>::operator-(vec4<T> const &rhs) const {
	vec4<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec4<T> vec4<T>::operator-(T const &rhs) const {
	vec4<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs;
	}
	return temp;
}


// op *
template <class T>
vec4<T> vec4<T>::operator*(vec4<T> const &rhs) const {
	vec4<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec4<T> vec4<T>::operator*(T const &rhs) const {
	vec4<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs;
	}
	return temp;
}


// op *
template <class T>
vec4<T> vec4<T>::operator/(vec4<T> const &rhs) const {
	vec4<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec4<T> vec4<T>::operator/(T const &rhs) const {
	vec4<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs;
	}
	return temp;
}








// info
template <class T>
void vec4<T>::warning(bool is) {
	vec4<T>::_warning = is;
}

template <class T>
std::ostream & operator<<(std::ostream & out, vec4<T> const & rhs) {
	out << "[ " << rhs.x() << ", " << rhs.y() << ", " << rhs.z() << ", " << rhs.w() << " ]";
	return out;
}

template <class T>
int vec4<T>::get_instance() {
	return vec4<T>::instance;
}

// static instantiation
template <class T>
bool vec4<T>::_warning = false;

template <class T>
int vec4<T>::instance = 0;
#endif