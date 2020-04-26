/*
* vec4
* v 0.0.2
* 2020-2020
* Template Vec adapted from Rope Vector, Processing PVector, Openframework and GLSL.
*/
#include "vec4.hpp"

/**
* TEMPLATE DEFINITION
*/
template <class T>
std::ostream & operator<<(std::ostream & out, vec4<T> const &rhs);
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
vec4<T> & vec4<T>::set(T const &arg) {
	this->_x = arg;
	this->_y = arg;
	this->_z = arg;
	this->_w = arg;
	return *this;
}


template <class T>
vec4<T> & vec4<T>::set(T const &x, T const &y, T const &z, T const &w) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
	this->_w = w;
	return *this;
}

// set xyzw
template <class T>
vec4<T> & vec4<T>::x(T const &x) {
	this->_x = x;
	return *this;
}
template <class T>
vec4<T> & vec4<T>::y(T const &y) {
	this->_y = y;
	return *this;
}

template <class T>
vec4<T> & vec4<T>::z(T const &z) {
	this->_z = z;
	return *this;
}

template <class T>
vec4<T> & vec4<T>::w(T const &w) {
	this->_w = w;
	return *this;
}

// set min max
template <class T>
vec4<T> & vec4<T>::min(T const &x) {
	this->_x = x;
	return *this;
}

template <class T>
vec4<T> & vec4<T>::max(T const &y) {
	this->_y = y;
	return *this;
}


template <class T>
vec4<T> vec4<T>::copy() const {
	return *this;
}

template <class T>
T * vec4<T>::array() const {
	static T arg[4];
	for(size_t i = 0 ; i < this->get_size() ; i++) {
		arg[i] = *this->v_list.at(i);
	}
	return arg;
}

// set rgb
template <class T>
vec4<T> & vec4<T>::red(T const &x) {
	this->_x = x;
	return *this;
}

template <class T>
vec4<T> & vec4<T>::gre(T const &y) {
	this->_y = y;
	return *this;
}

template <class T>
vec4<T> & vec4<T>::blu(T const &z) {
	return this->z(z);
}

// set hsb
template <class T>
vec4<T> & vec4<T>::hue(T const &x) {
	this->_x = x;
	return *this;

}
template <class T>
vec4<T> & vec4<T>::sat(T const &y) {
	this->_y = y;
	return *this;
}

template <class T>
vec4<T> & vec4<T>::bri(T const &z) {
	return this->z(z);
}

// alpha
template <class T>
vec4<T> & vec4<T>::alp(T const &w) {
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
vec4<T>	vec4<T>::dir() const {
	return vec4<T>::dir(vec4<T>());
}

template <class T>
vec4<T>	vec4<T>::dir(vec4<T> const &origin) const {
	vec4 temp = *this;
	T dist = vec4<T>::dist(origin);
	temp -= origin;
	temp /= dist;
	return temp;
}


// abs
template <class T>
vec4<T>	& vec4<T>::abs() {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = std::abs(this->list().at(i));
	}
	return *this;
}


// pow
template <class T>
vec4<T>	& vec4<T>::pow(T const &pow) {
	return vec4<T>::pow(pow, pow, pow, pow);
}

template <class T>
vec4<T>	& vec4<T>::pow(T const &pow_x, T const &pow_y, T const &pow_z, T const &pow_w) {
	this->_x = ::pow(this->x(), pow_x);
	this->_y = ::pow(this->y(), pow_y);
	this->_z = ::pow(this->z(), pow_z);
	this->_w = ::pow(this->w(), pow_w);
	return *this;
}


//map
template <class T>
vec4<T>	& vec4<T>::map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst) {
	vec2<T>::map(start_src, stop_src, start_dst, stop_dst);
	return *this;
}

template <class T>
vec4<T>	& vec4<T>::map(vec4<T> const &start_src, vec4<T> const &stop_src, vec4<T> const &start_dst, vec4<T> const &stop_dst) {
	vec2<T>::map(start_src, stop_src, start_dst, stop_dst);
	return *this;
}



// normalize
template <class T>
vec4<T>	& vec4<T>::normalize() {
	vec2<T>::normalize();
	return *this;
}

template <class T>
vec4<T>	vec4<T>::normalize(vec4<T> &target) {
	return target.normalize();
}



// limit
template <class T>
vec4<T>	& vec4<T>::limit(T const &max) {
	vec2<T>::limit(max);
	return *this;
}

// constrain
template <class T>
vec4<T>	& vec4<T>::constrain(T const &min, T const &max) {
	vec2<T>::constrain(min,max);
	return *this;
}

template <class T>
vec4<T>	& vec4<T>::constrain(vec4<T> const &min, vec4<T> const &max) {
	vec2<T>::constrain(min,max);
	return *this;
}



// random
template <class T>
vec4<T>	& vec4<T>::rand() {
	return rand(0,0,0,0, 1,1,1,1);
}

template <class T>
vec4<T>	& vec4<T>::rand(std::default_random_engine &generator) {
	return rand(0,0,0,0, 1,1,1,1, generator);
}

//
template <class T>
vec4<T>	& vec4<T>::rand(T const &max) {
	return rand(0,0,0,0, max,max,max,max);
}

template <class T>
vec4<T>	& vec4<T>::rand(T const &max, std::default_random_engine &generator) {
	return rand(0,0,0,0, max,max,max,max, generator);
}

//
template <class T>
vec4<T>	& vec4<T>::rand(T const &min, T const &max) {
	return rand(min,min,min,min, max,max,max,max);
}

template <class T>
vec4<T>	& vec4<T>::rand(T const &min, T const &max, std::default_random_engine &generator) {
	return rand(min,min,min,min, max,max,max,max, generator);
}

//
template <class T>
vec4<T>	& vec4<T>::rand(vec4<T> const &min, vec4<T> const &max) {
	return rand(min.x(), min.y(), min.z(), min.w(),
							max.x(), max.y(), max.z(), max.w());
}

template <class T>
vec4<T>	& vec4<T>::rand(vec4<T> const &min, vec4<T> const &max, std::default_random_engine &generator) {
	return rand(min.x(), min.y(), min.z(), min.w(),
							max.x(), max.y(), max.z(), max.w(),
							generator);
}

//
template <class T>
vec4<T>	& vec4<T>::rand(T const &x_min, T const &y_min, T const &z_min, T const &w_min,
											T const &x_max, T const &y_max, T const &z_max, T const &w_max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return rand(x_min, y_min, z_min, w_min,
							x_max, y_max, z_max, w_max,
							generator);
}


template <class T>
vec4<T>	& vec4<T>::rand(T const &x_min, T const &y_min, T const &z_min, T const &w_min,
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
		case 'h':
			this->_x = random_long_double(x_min, x_max);
			this->_y = random_long_double(y_min, y_max);
			this->_z = random_long_double(z_min, z_max);
			this->_w = random_long_double(w_min, w_max);
			break;
		default:
			std::cout << "vec4<T>::rand(); wait <T arg> like bool, char, int, float, double" << std::endl;
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



// op +=
template <class T>
vec4<T> & vec4<T>::operator+=(vec4<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] += rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec4<T> & vec4<T>::operator+=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] += rhs;
	}
	return *this;
}

// op -=
template <class T>
vec4<T> & vec4<T>::operator-=(vec4<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] -= rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec4<T> & vec4<T>::operator-=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] -= rhs;
	}
	return *this;
}

// op *=
template <class T>
vec4<T> & vec4<T>::operator*=(vec4<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] *= rhs.ref().at(i)[0];
	}
	return *this;
}

template <class T>
vec4<T> & vec4<T>::operator*=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] *= rhs;
	}
	return *this;
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











// GET EXOTIC
// special
template <class T>
vec4<T> vec4<T>::rgba() const {
	return vec4<T>(this->x(),this->y(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::hsba() const {
	return vec4<T>(this->x(),this->y(),this->z(),this->w());
}


// XYZW
template <class T>
vec2<T> vec4<T>::ww() const {
	return vec2<T>(this->w(),this->w());
}
template <class T>
vec2<T> vec4<T>::wx() const {
	return vec2<T>(this->w(),this->x());
}
template <class T>
vec2<T> vec4<T>::wy() const {
	return vec2<T>(this->w(),this->y());
}
template <class T>
vec2<T> vec4<T>::wz() const {
	return vec2<T>(this->w(),this->z());
}
template <class T>
vec2<T> vec4<T>::xw() const {
	return vec2<T>(this->x(),this->w());
}
template <class T>
vec2<T> vec4<T>::yw()const {
	return vec2<T>(this->y(),this->w());
}
template <class T>
vec2<T> vec4<T>::zw()const {
	return vec2<T>(this->z(),this->w());
}


// w3
template <class T>
vec3<T> vec4<T>::www()const {
	return vec3<T>(this->w(),this->w(),this->w());
}
template <class T>
vec3<T> vec4<T>::wwx() const {
	return vec3<T>(this->w(),this->w(),this->x());
}
template <class T>
vec3<T> vec4<T>::wwy() const {
	return vec3<T>(this->w(),this->w(),this->y());
}
template <class T>
vec3<T> vec4<T>::wwz() const {
	return vec3<T>(this->w(),this->w(),this->z());
}
template <class T>
vec3<T> vec4<T>::wxw() const {
	return vec3<T>(this->w(),this->x(),this->w());
}
template <class T>
vec3<T> vec4<T>::wxx() const {
	return vec3<T>(this->w(),this->x(),this->x());
}
template <class T>
vec3<T> vec4<T>::wxy() const {
	return vec3<T>(this->w(),this->x(),this->y());
}
template <class T>
vec3<T> vec4<T>::wxz() const {
	return vec3<T>(this->w(),this->x(),this->z());
}
template <class T>
vec3<T> vec4<T>::wyw() const {
	return vec3<T>(this->w(),this->y(),this->w());
}
template <class T>
vec3<T> vec4<T>::wyx() const {
	return vec3<T>(this->w(),this->y(),this->x());
}
template <class T>
vec3<T> vec4<T>::wyy() const {
	return vec3<T>(this->w(),this->y(),this->y());
}
template <class T>
vec3<T> vec4<T>::wyz() const {
	return vec3<T>(this->w(),this->y(),this->z());
}
template <class T>
vec3<T> vec4<T>::wzw() const {
	return vec3<T>(this->w(),this->z(),this->w());
}
template <class T>
vec3<T> vec4<T>::wzx() const {
	return vec3<T>(this->w(),this->z(),this->x());
}
template <class T>
vec3<T> vec4<T>::wzy() const {
	return vec3<T>(this->w(),this->z(),this->y());
}
template <class T>
vec3<T> vec4<T>::wzz() const {
	return vec3<T>(this->w(),this->z(),this->z());
}

// x3
template <class T>
vec3<T> vec4<T>::xww() const {
	return vec3<T>(this->x(),this->w(),this->w());
}
template <class T>
vec3<T> vec4<T>::xwx() const {
	return vec3<T>(this->x(),this->w(),this->x());
}
template <class T>
vec3<T> vec4<T>::xwy() const {
	return vec3<T>(this->x(),this->w(),this->y());
}
template <class T>
vec3<T> vec4<T>::xwz() const {
	return vec3<T>(this->x(),this->w(),this->z());
}
template <class T>
vec3<T> vec4<T>::xxw() const {
	return vec3<T>(this->x(),this->x(),this->w());
}
template <class T>
vec3<T> vec4<T>::xyw() const {
	return vec3<T>(this->x(),this->y(),this->w());
}
template <class T>
vec3<T> vec4<T>::xzw() const {
	return vec3<T>(this->x(),this->z(),this->w());
}

// y3
template <class T>
vec3<T> vec4<T>::yww() const {
	return vec3<T>(this->y(),this->w(),this->w());
}
template <class T>
vec3<T> vec4<T>::ywx() const {
	return vec3<T>(this->y(),this->w(),this->x());
}
template <class T>
vec3<T> vec4<T>::ywy() const {
	return vec3<T>(this->y(),this->w(),this->y());
}
template <class T>
vec3<T> vec4<T>::ywz() const {
	return vec3<T>(this->y(),this->w(),this->z());
}
template <class T>
vec3<T> vec4<T>::yxw() const {
	return vec3<T>(this->y(),this->x(),this->w());
}
template <class T>
vec3<T> vec4<T>::yyw() const {
	return vec3<T>(this->y(),this->y(),this->w());
}
template <class T>
vec3<T> vec4<T>::yzw() const {
	return vec3<T>(this->y(),this->z(),this->w());
}

// z3
template <class T>
vec3<T> vec4<T>::zww() const {
	return vec3<T>(this->z(),this->w(),this->w());
}
template <class T>
vec3<T> vec4<T>::zwx() const {
	return vec3<T>(this->z(),this->w(),this->x());
}
template <class T>
vec3<T> vec4<T>::zwy() const {
	return vec3<T>(this->z(),this->w(),this->y());
}
template <class T>
vec3<T> vec4<T>::zwz() const {
	return vec3<T>(this->z(),this->w(),this->z());
}
template <class T>
vec3<T> vec4<T>::zxw() const {
	return vec3<T>(this->z(),this->x(),this->w());
}
template <class T>
vec3<T> vec4<T>::zyw() const {
	return vec3<T>(this->z(),this->wy(),this->w());
}
template <class T>
vec3<T> vec4<T>::zzw() const {
	return vec3<T>(this->z(),this->z(),this->w());
}



// W4
// w3
template <class T>
vec4<T> vec4<T>::wwww() const {
	return vec4<T>(this->w(),this->w(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::wwwx() const {
	return vec4<T>(this->w(),this->w(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::wwwy() const {
	return vec4<T>(this->w(),this->w(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::wwwz() const {
	return vec4<T>(this->w(),this->w(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::wwxw() const {
	return vec4<T>(this->w(),this->w(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::wwxx() const {
	return vec4<T>(this->w(),this->w(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::wwxy() const {
	return vec4<T>(this->w(),this->w(),this->x(),this->y());	
}
template <class T>
vec4<T> vec4<T>::wwxz() const {
	return vec4<T>(this->w(),this->w(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::wwyw() const {
	return vec4<T>(this->w(),this->w(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::wwyx() const {
	return vec4<T>(this->w(),this->w(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::wwyy() const {
	return vec4<T>(this->w(),this->w(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::wwyz() const {
	return vec4<T>(this->w(),this->w(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::wwzw() const {
	return vec4<T>(this->w(),this->w(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::wwzx() const {
	return vec4<T>(this->w(),this->w(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::wwzy() const {
	return vec4<T>(this->w(),this->w(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::wwzz() const {
	return vec4<T>(this->w(),this->w(),this->z(),this->z());
}

// x3
template <class T>
vec4<T> vec4<T>::wxww() const {
	return vec4<T>(this->w(),this->x(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::wxwx() const {
	return vec4<T>(this->w(),this->x(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::wxwy() const {
	return vec4<T>(this->w(),this->x(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::wxwz() const {
	return vec4<T>(this->w(),this->x(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::wxxw() const {
	return vec4<T>(this->w(),this->x(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::wxxx() const {
	return vec4<T>(this->w(),this->x(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::wxxy() const {
	return vec4<T>(this->w(),this->x(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::wxxz() const {
	return vec4<T>(this->w(),this->x(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::wxyw() const {
	return vec4<T>(this->w(),this->x(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::wxyx() const {
	return vec4<T>(this->w(),this->x(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::wxyy() const {
	return vec4<T>(this->w(),this->x(),this->y(),this->y());	
}
template <class T>
vec4<T> vec4<T>::wxyz() const {
	return vec4<T>(this->w(),this->x(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::wxzw() const {
	return vec4<T>(this->w(),this->x(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::wxzx() const {
	return vec4<T>(this->w(),this->x(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::wxzy() const {
	return vec4<T>(this->w(),this->x(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::wxzz() const {
	return vec4<T>(this->w(),this->x(),this->z(),this->z());
}

// y3
template <class T>
vec4<T> vec4<T>::wyww() const {
	return vec4<T>(this->w(),this->y(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::wywx() const {
	return vec4<T>(this->w(),this->y(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::wywy() const {
	return vec4<T>(this->w(),this->y(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::wywz() const {
	return vec4<T>(this->w(),this->y(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::wyxw() const {
	return vec4<T>(this->w(),this->y(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::wyxx() const {
	return vec4<T>(this->w(),this->y(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::wyxy() const {
	return vec4<T>(this->w(),this->y(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::wyxz() const {
	return vec4<T>(this->w(),this->y(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::wyyw() const {
	return vec4<T>(this->w(),this->y(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::wyyx() const {
	return vec4<T>(this->w(),this->y(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::wyyy() const {
	return vec4<T>(this->w(),this->y(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::wyyz() const {
	return vec4<T>(this->w(),this->y(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::wyzw() const {
	return vec4<T>(this->w(),this->y(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::wyzx() const {
	return vec4<T>(this->w(),this->y(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::wyzy() const {
	return vec4<T>(this->w(),this->y(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::wyzz() const {
	return vec4<T>(this->w(),this->y(),this->z(),this->z());
}

// z3
template <class T>
vec4<T> vec4<T>::wzww() const {
	return vec4<T>(this->w(),this->z(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::wzwx() const {
	return vec4<T>(this->w(),this->z(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::wzwy() const {
	return vec4<T>(this->w(),this->z(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::wzwz() const {
	return vec4<T>(this->w(),this->z(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::wzxw() const {
	return vec4<T>(this->w(),this->z(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::wzxx() const {
	return vec4<T>(this->w(),this->z(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::wzxy() const {
	return vec4<T>(this->w(),this->z(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::wzxz() const {
	return vec4<T>(this->w(),this->z(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::wzyw() const {
	return vec4<T>(this->w(),this->z(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::wzyx() const {
	return vec4<T>(this->w(),this->z(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::wzyy() const {
	return vec4<T>(this->w(),this->z(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::wzyz() const {
	return vec4<T>(this->w(),this->z(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::wzzw() const {
	return vec4<T>(this->w(),this->z(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::wzzx() const {
	return vec4<T>(this->w(),this->z(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::wzzy() const {
	return vec4<T>(this->w(),this->z(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::wzzz() const {
	return vec4<T>(this->w(),this->z(),this->z(),this->z());
}


// X4
// w3
template <class T>
vec4<T> vec4<T>::xwww() const {
	return vec4<T>(this->x(),this->w(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::xwwx() const {
	return vec4<T>(this->x(),this->w(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::xwwy() const {
	return vec4<T>(this->x(),this->w(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::xwwz() const {
	return vec4<T>(this->x(),this->w(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::xwxw() const {
	return vec4<T>(this->x(),this->w(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::xwxx() const {
	return vec4<T>(this->x(),this->w(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::xwxy() const {
	return vec4<T>(this->x(),this->w(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::xwxz() const {
	return vec4<T>(this->x(),this->w(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::xwyw() const {
	return vec4<T>(this->x(),this->w(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::xwyx() const {
	return vec4<T>(this->x(),this->w(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::xwyy() const {
	return vec4<T>(this->x(),this->w(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::xwyz() const {
	return vec4<T>(this->x(),this->w(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::xwzw() const {
	return vec4<T>(this->x(),this->w(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::xwzx() const {
	return vec4<T>(this->x(),this->w(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::xwzy() const {
	return vec4<T>(this->x(),this->w(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::xwzz() const {
	return vec4<T>(this->x(),this->w(),this->z(),this->z());
}

// x3
template <class T>
vec4<T> vec4<T>::xxww() const {
	return vec4<T>(this->x(),this->x(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::xxwx() const {
	return vec4<T>(this->x(),this->x(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::xxwy() const {
	return vec4<T>(this->x(),this->x(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::xxwz() const {
	return vec4<T>(this->x(),this->x(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::xxxw() const {
	return vec4<T>(this->x(),this->x(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::xxxx() const {
	return vec4<T>(this->x(),this->x(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::xxxy() const {
	return vec4<T>(this->x(),this->x(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::xxxz() const {
	return vec4<T>(this->x(),this->x(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::xxyw() const {
	return vec4<T>(this->x(),this->x(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::xxyx() const {
	return vec4<T>(this->x(),this->x(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::xxyy() const {
	return vec4<T>(this->x(),this->x(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::xxyz() const {
	return vec4<T>(this->x(),this->x(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::xxzw() const {
	return vec4<T>(this->x(),this->x(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::xxzx() const {
	return vec4<T>(this->x(),this->x(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::xxzy() const {
	return vec4<T>(this->x(),this->x(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::xxzz() const {
	return vec4<T>(this->x(),this->x(),this->z(),this->z());
}

// y3
template <class T>
vec4<T> vec4<T>::xyww() const {
	return vec4<T>(this->x(),this->y(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::xywx() const {
	return vec4<T>(this->x(),this->y(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::xywy() const {
	return vec4<T>(this->x(),this->y(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::xywz() const {
	return vec4<T>(this->x(),this->y(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::xyxw() const {
	return vec4<T>(this->x(),this->y(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::xyxx() const {
	return vec4<T>(this->x(),this->y(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::xyxy() const {
	return vec4<T>(this->x(),this->y(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::xyxz() const {
	return vec4<T>(this->x(),this->y(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::xyyw() const {
	return vec4<T>(this->x(),this->y(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::xyyx() const {
	return vec4<T>(this->x(),this->y(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::xyyy() const {
	return vec4<T>(this->x(),this->y(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::xyyz() const {
	return vec4<T>(this->x(),this->y(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::xyzw() const {
	return vec4<T>(this->x(),this->y(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::xyzx() const {
	return vec4<T>(this->x(),this->y(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::xyzy() const {
	return vec4<T>(this->x(),this->y(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::xyzz() const {
	return vec4<T>(this->x(),this->y(),this->z(),this->z());
}

// z3
template <class T>
vec4<T> vec4<T>::xzww() const {
	return vec4<T>(this->x(),this->z(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::xzwx() const {
	return vec4<T>(this->x(),this->z(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::xzwy() const {
	return vec4<T>(this->x(),this->z(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::xzwz() const {
	return vec4<T>(this->x(),this->z(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::xzxw() const {
	return vec4<T>(this->x(),this->z(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::xzxx() const {
	return vec4<T>(this->x(),this->z(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::xzxy() const {
	return vec4<T>(this->x(),this->z(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::xzxz() const {
	return vec4<T>(this->x(),this->z(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::xzyw() const {
	return vec4<T>(this->x(),this->z(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::xzyx() const {
	return vec4<T>(this->x(),this->z(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::xzyy() const {
	return vec4<T>(this->x(),this->z(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::xzyz() const {
	return vec4<T>(this->x(),this->z(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::xzzw() const {
	return vec4<T>(this->x(),this->z(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::xzzx() const {
	return vec4<T>(this->x(),this->z(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::xzzy() const {
	return vec4<T>(this->x(),this->z(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::xzzz() const {
	return vec4<T>(this->x(),this->z(),this->z(),this->z());
}


// Y4
// w3
template <class T>
vec4<T> vec4<T>::ywww() const {
	return vec4<T>(this->y(),this->w(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::ywwx() const {
	return vec4<T>(this->y(),this->w(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::ywwy() const {
	return vec4<T>(this->y(),this->w(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::ywwz() const {
	return vec4<T>(this->y(),this->w(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::ywxw() const {
	return vec4<T>(this->y(),this->w(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::ywxx() const {
	return vec4<T>(this->y(),this->w(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::ywxy() const {
	return vec4<T>(this->y(),this->w(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::ywxz() const {
	return vec4<T>(this->y(),this->w(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::ywyw() const {
	return vec4<T>(this->y(),this->w(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::ywyx() const {
	return vec4<T>(this->y(),this->w(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::ywyy() const {
	return vec4<T>(this->y(),this->w(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::ywyz() const {
	return vec4<T>(this->y(),this->w(),this->y(),this->z());	
}
template <class T>
vec4<T> vec4<T>::ywzw() const {
	return vec4<T>(this->y(),this->w(),this->z(),this->w());	
}
template <class T>
vec4<T> vec4<T>::ywzx() const {
	return vec4<T>(this->y(),this->w(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::ywzy() const {
	return vec4<T>(this->y(),this->w(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::ywzz() const {
	return vec4<T>(this->y(),this->w(),this->z(),this->z());
}

// x3
template <class T>
vec4<T> vec4<T>::yxww() const {
	return vec4<T>(this->y(),this->x(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::yxwx() const {
	return vec4<T>(this->y(),this->x(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::yxwy() const {
	return vec4<T>(this->y(),this->x(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::yxwz() const {
	return vec4<T>(this->y(),this->x(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::yxxw() const {
	return vec4<T>(this->y(),this->x(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::yxxx() const {
	return vec4<T>(this->y(),this->x(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::yxxy() const {
	return vec4<T>(this->y(),this->x(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::yxxz() const {
	return vec4<T>(this->y(),this->x(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::yxyw() const {
	return vec4<T>(this->y(),this->x(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::yxyx() const {
	return vec4<T>(this->y(),this->x(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::yxyy() const {
	return vec4<T>(this->y(),this->x(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::yxyz() const {
	return vec4<T>(this->y(),this->x(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::yxzw() const {
	return vec4<T>(this->y(),this->x(),this->z(),this->w());	
}
template <class T>
vec4<T> vec4<T>::yxzx() const {
	return vec4<T>(this->y(),this->x(),this->z(),this->x());	
}
template <class T>
vec4<T> vec4<T>::yxzy() const {
	return vec4<T>(this->y(),this->x(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::yxzz() const {
	return vec4<T>(this->y(),this->x(),this->z(),this->z());
}

// y3
template <class T>
vec4<T> vec4<T>::yyww() const {
	return vec4<T>(this->y(),this->y(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::yywx() const {
	return vec4<T>(this->y(),this->y(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::yywy() const {
	return vec4<T>(this->y(),this->y(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::yywz() const {
	return vec4<T>(this->y(),this->y(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::yyxw() const {
	return vec4<T>(this->y(),this->y(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::yyxx() const {
	return vec4<T>(this->y(),this->y(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::yyxy() const {
	return vec4<T>(this->y(),this->y(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::yyxz() const {
	return vec4<T>(this->y(),this->y(),this->x(),this->z());	
}
template <class T>
vec4<T> vec4<T>::yyyw() const {
	return vec4<T>(this->y(),this->y(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::yyyx() const {
	return vec4<T>(this->y(),this->y(),this->y(),this->x());	
}
template <class T>
vec4<T> vec4<T>::yyyy() const {
	return vec4<T>(this->y(),this->y(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::yyyz() const {
	return vec4<T>(this->y(),this->y(),this->y(),this->z());	
}
template <class T>
vec4<T> vec4<T>::yyzw() const {
	return vec4<T>(this->y(),this->y(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::yyzx() const {
	return vec4<T>(this->y(),this->y(),this->y(),this->x());	
}
template <class T>
vec4<T> vec4<T>::yyzy() const {
	return vec4<T>(this->y(),this->y(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::yyzz() const {
	return vec4<T>(this->y(),this->y(),this->y(),this->z());
}

// z3
template <class T>
vec4<T> vec4<T>::yzww() const {
	return vec4<T>(this->y(),this->z(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::yzwx() const {
	return vec4<T>(this->y(),this->z(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::yzwy() const {
	return vec4<T>(this->y(),this->z(),this->w(),this->y());	
}
template <class T>
vec4<T> vec4<T>::yzwz() const {
	return vec4<T>(this->y(),this->z(),this->w(),this->z());	
}
template <class T>
vec4<T> vec4<T>::yzxw() const {
	return vec4<T>(this->y(),this->z(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::yzxx() const {
	return vec4<T>(this->y(),this->z(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::yzxy() const {
	return vec4<T>(this->y(),this->z(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::yzxz() const {
	return vec4<T>(this->y(),this->z(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::yzyw() const {
	return vec4<T>(this->y(),this->z(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::yzyx() const {
	return vec4<T>(this->y(),this->z(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::yzyy() const {
	return vec4<T>(this->y(),this->z(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::yzyz() const {
	return vec4<T>(this->y(),this->z(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::yzzw() const {
	return vec4<T>(this->y(),this->z(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::yzzx() const {
	return vec4<T>(this->y(),this->z(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::yzzy() const {
	return vec4<T>(this->y(),this->z(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::yzzz() const {
	return vec4<T>(this->y(),this->z(),this->z(),this->z());
}



// Z4
// w3
template <class T>
vec4<T> vec4<T>::zwww() const {
	return vec4<T>(this->z(),this->w(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::zwwx() const {
	return vec4<T>(this->z(),this->w(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::zwwy() const {
	return vec4<T>(this->z(),this->w(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::zwwz() const {
	return vec4<T>(this->z(),this->w(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::zwxw() const {
	return vec4<T>(this->z(),this->w(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::zwxx() const {
	return vec4<T>(this->z(),this->w(),this->x(),this->x());	
}
template <class T>
vec4<T> vec4<T>::zwxy() const {
	return vec4<T>(this->z(),this->w(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::zwxz() const {
	return vec4<T>(this->z(),this->w(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::zwyw() const {
	return vec4<T>(this->z(),this->w(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::zwyx() const {
	return vec4<T>(this->z(),this->w(),this->y(),this->x());	
}
template <class T>
vec4<T> vec4<T>::zwyy() const {
	return vec4<T>(this->z(),this->w(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::zwyz() const {
	return vec4<T>(this->z(),this->w(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::zwzw() const {
	return vec4<T>(this->z(),this->w(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::zwzx() const {
	return vec4<T>(this->z(),this->w(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::zwzy() const {
	return vec4<T>(this->z(),this->w(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::zwzz() const {
	return vec4<T>(this->z(),this->w(),this->z(),this->z());
}

// x3
template <class T>
vec4<T> vec4<T>::zxww() const {
	return vec4<T>(this->z(),this->x(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::zxwx() const {
	return vec4<T>(this->z(),this->x(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::zxwy() const {
	return vec4<T>(this->z(),this->x(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::zxwz() const {
	return vec4<T>(this->z(),this->x(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::zxxw() const {
	return vec4<T>(this->z(),this->x(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::zxxx() const {
	return vec4<T>(this->z(),this->x(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::zxxy() const {
	return vec4<T>(this->z(),this->x(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::zxxz() const {
	return vec4<T>(this->z(),this->x(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::zxyw() const {
	return vec4<T>(this->z(),this->x(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::zxyx() const {
	return vec4<T>(this->z(),this->x(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::zxyy() const {
	return vec4<T>(this->z(),this->x(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::zxyz() const {
	return vec4<T>(this->z(),this->x(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::zxzw() const {
	return vec4<T>(this->z(),this->x(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::zxzx() const {
	return vec4<T>(this->z(),this->x(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::zxzy() const {
	return vec4<T>(this->z(),this->x(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::zxzz() const {
	return vec4<T>(this->z(),this->x(),this->z(),this->z());
}

// y3
template <class T>
vec4<T> vec4<T>::zyww() const {
	return vec4<T>(this->z(),this->y(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::zywx() const {
	return vec4<T>(this->z(),this->y(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::zywy() const {
	return vec4<T>(this->z(),this->y(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::zywz() const {
	return vec4<T>(this->z(),this->y(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::zyxw() const {
	return vec4<T>(this->z(),this->y(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::zyxx() const {
	return vec4<T>(this->z(),this->y(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::zyxy() const {
	return vec4<T>(this->z(),this->y(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::zyxz() const {
	return vec4<T>(this->z(),this->y(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::zyyw() const {
	return vec4<T>(this->z(),this->y(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::zyyx() const {
	return vec4<T>(this->z(),this->y(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::zyyy() const {
	return vec4<T>(this->z(),this->y(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::zyyz() const {
	return vec4<T>(this->z(),this->y(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::zyzw() const {
	return vec4<T>(this->z(),this->y(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::zyzx() const {
	return vec4<T>(this->z(),this->y(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::zyzy() const {
	return vec4<T>(this->z(),this->y(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::zyzz() const {
	return vec4<T>(this->z(),this->y(),this->z(),this->z());
}

// z3
template <class T>
vec4<T> vec4<T>::zzww() const {
	return vec4<T>(this->z(),this->z(),this->w(),this->w());
}
template <class T>
vec4<T> vec4<T>::zzwx() const {
	return vec4<T>(this->z(),this->z(),this->w(),this->x());
}
template <class T>
vec4<T> vec4<T>::zzwy() const {
	return vec4<T>(this->z(),this->z(),this->w(),this->y());
}
template <class T>
vec4<T> vec4<T>::zzwz() const {
	return vec4<T>(this->z(),this->z(),this->w(),this->z());
}
template <class T>
vec4<T> vec4<T>::zzxw() const {
	return vec4<T>(this->z(),this->z(),this->x(),this->w());
}
template <class T>
vec4<T> vec4<T>::zzxx() const {
	return vec4<T>(this->z(),this->z(),this->x(),this->x());
}
template <class T>
vec4<T> vec4<T>::zzxy() const {
	return vec4<T>(this->z(),this->z(),this->x(),this->y());
}
template <class T>
vec4<T> vec4<T>::zzxz() const {
	return vec4<T>(this->z(),this->z(),this->x(),this->z());
}
template <class T>
vec4<T> vec4<T>::zzyw() const {
	return vec4<T>(this->z(),this->z(),this->y(),this->w());
}
template <class T>
vec4<T> vec4<T>::zzyx() const {
	return vec4<T>(this->z(),this->z(),this->y(),this->x());
}
template <class T>
vec4<T> vec4<T>::zzyy() const {
	return vec4<T>(this->z(),this->z(),this->y(),this->y());
}
template <class T>
vec4<T> vec4<T>::zzyz() const {
	return vec4<T>(this->z(),this->z(),this->y(),this->z());
}
template <class T>
vec4<T> vec4<T>::zzzw() const {
	return vec4<T>(this->z(),this->z(),this->z(),this->w());
}
template <class T>
vec4<T> vec4<T>::zzzx() const {
	return vec4<T>(this->z(),this->z(),this->z(),this->x());
}
template <class T>
vec4<T> vec4<T>::zzzy() const {
	return vec4<T>(this->z(),this->z(),this->z(),this->y());
}
template <class T>
vec4<T> vec4<T>::zzzz()const {
	return vec4<T>(this->z(),this->z(),this->z(),this->z());
}








