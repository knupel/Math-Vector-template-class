/*
* vec2
* v 0.0.1
* 2020-2020
* Template Vec adapted from Rope Vector, Processing PVector, Openframework and GLSL
*/
#include "vec2.hpp"



/**
* TEMPLATE DEFINITION
*/
template <class T>
std::ostream & operator<<(std::ostream &out, vec2<T> const &rhs);
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


// SET
template <class T>
vec2<T> & vec2<T>::set(T const &arg) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = arg;
	}
	return *this;
}

template <class T>
vec2<T> & vec2<T>::set(T const &x, T const &y) {
	this->_x = x;
	this->_y = y;
	return *this;
}

template <class T>
vec2<T> & vec2<T>::x(T const &x) {
	this->_x = x;
	return *this;
}

template <class T>
vec2<T> & vec2<T>::y(T const &y) {
	this->_y = y;
	return *this;
}


template <class T>
vec2<T> & vec2<T>::min(T const &x) {
	return this->x(x);
}

template <class T>
vec2<T> & vec2<T>::max(T const &y) {
	return this->y(y);
}



// GET
template <class T>
T vec2<T>::x() const {
	return this->_x;
}

template <class T>
T vec2<T>::y() const {
	return this->_y;
}

template <class T>
T vec2<T>::min() const {
	return this->_x;
}

template <class T>
T vec2<T>::max() const {
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


// COMMMON ALGORITHM FOR VEC
// 

// dot
template <class T>
T vec2<T>::dot(vec2<T> const &v) const {
	T res = 0;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		res += this->ref().at(i)[0] * v.ref().at(i)[0];
	}
	return res;
}

template <class T>
T vec2<T>::dot(T const &x, T const &y) const {
	return dot(vec2<T>(x,y));
}

/**
* DIRECTION NORMAL
*/
template <class T>
vec2<T>	vec2<T>::dir() const {
	return vec2<T>::dir(vec2<T>());
}

template <class T>
vec2<T>	vec2<T>::dir(vec2<T> const &origin) const {
	vec2 temp = *this;
	T dist = vec2<T>::dist(origin);
	temp -= origin;
	temp /= dist;
	return temp;
}

// abs
template <class T>
vec2<T>	& vec2<T>::abs() {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = std::abs(this->list().at(i));
	}
	return *this;
}

// rotate
template <class T>
vec2<T>	& vec2<T>::rotate(T angle) {
	if(std::is_arithmetic<T>::value) {
		T temp_x = this->_x * std::cos(angle) - this->_y * std::sin(angle);
		this->_y = this->_x * std::sin(angle) + this->_y * std::cos(angle);
		this->_x = temp_x;
	}
	return *this;
}

// rotate
template <class T>
vec2<T>	& vec2<T>::rotate(T angle, vec2<T> const &origin) {
	if(std::is_arithmetic<T>::value) {
		T temp_x = (this->_x - origin.x()) * std::cos(angle) - (this->_y - origin.y()) * std::sin(angle);
		this->_y = (this->_x - origin.x()) * std::sin(angle) + (this->_y - origin.y()) * std::cos(angle);
		this->_x = temp_x;
	}
	return *this;
}


// vec2 specialize
template <class T>
vec2<double> vec2<T>::tan() const {
	return std::tan(this->x(),this->y());
}

template <class T>
vec2<double> vec2<T>::tan(vec2<T> const &target) const {
	return std::tan(target.x(),target.y());
}


template <class T>
vec2<double> vec2<T>::tan(T const &x, T const &y) const {
	double tx = x;
	double ty = y;
	double mag = vec<T>::mag();
	tx /= mag;
	ty /= mag;
	return vec2<double>(-ty,tx);
}



template <class T>
double vec2<T>::angle() const{
	return std::atan2(this->y(),this->x());
}

template <class T>
double vec2<T>::angle(vec2<T> const &target) const{
	return std::atan2(this->y() - target.y(),this->x() - target.x());
}

template <class T>
double vec2<T>::heading() const {
	return angle();
}






// mag_sq
template <class T>
T vec2<T>::mag_sq() const {
	return vec<T>::mag_sq();
}

template <class T>
T vec2<T>::mag_sq(vec2<T> const &v) const {
	T res = 0;
	for(size_t i = 0 ; i < this->v_list.size() ; i++) {
		res += ((v.v_list.at(i)[0] - this->v_list.at(i)[0]) * (v.v_list.at(i)[0] - this->v_list.at(i)[0]));
	}
	return res;
}

// mag
template <class T>
double vec2<T>::mag() const {
	return vec<T>::mag();
}

template <class T>
double vec2<T>::mag(vec2<T> const &v) const {
	return ::sqrt(vec2<T>::mag_sq(v));
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
vec2<T>	& vec2<T>::pow(T const &pow) {
	return vec2<T>::pow(pow, pow);
}

template <class T>
vec2<T>	& vec2<T>::pow(T const &pow_x, T const &pow_y) {
	this->_x = ::pow(this->x(), pow_x);
	this->_y = ::pow(this->y(), pow_y);
	return *this;
}

template <class T>
vec2<T>	vec2<T>::barycenter(vec2<T> const &other) const {
	vec2<T> temp = *this;
	return (temp += other) / 2;
}


// map
template <class T>
vec2<T>	& vec2<T>::map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = ::map(	this->list().at(i),
																	start_src,stop_src, 
																	start_dst,stop_dst);
	}
	return *this;
}

template <class T>
vec2<T>	& vec2<T>::map(vec2<T> const &start_src, vec2<T> const &stop_src, vec2<T> const &start_dst, vec2<T> const &stop_dst) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = ::map(	this->list().at(i), 
																	start_src.ref().at(i)[0],stop_src.ref().at(i)[0], 
																	start_dst.ref().at(i)[0],stop_dst.ref().at(i)[0]);
	}
	return *this;
}






// normalize
template <class T>
vec2<T>	& vec2<T>::normalize() {
	T m = vec<T>::mag();
	if (m != 0 && m != 1) {
		*this /= m;
	}
	return *this;
}

template <class T>
vec2<T>	vec2<T>::normalize(vec2<T> &target) {
	return target.normalize();
}


// limit
template <class T>
vec2<T>	& vec2<T>::limit(T const &max) {
	if (vec<T>::mag_sq() > max*max) {
		vec2<T>::normalize();
		*this *= max;
	}
	return *this;
}


// constrain
template <class T>
vec2<T>	& vec2<T>::constrain(T const &min, T const &max) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->list().at(i) < min ) {
			this->ref().at(i)[0] = min;
		}
		if(this->list().at(i) > max ) {
			this->ref().at(i)[0] = max;
		}
	}
	return *this;
}

template <class T>
vec2<T>	& vec2<T>::constrain(vec2<T> const &min, vec2<T> const &max) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->list().at(i) < min.ref().at(i)[0]) {
			this->ref().at(i)[0] = min.ref().at(i)[0];
		}
		if(this->list().at(i) > max.ref().at(i)[0]) {
			this->ref().at(i)[0] = max.ref().at(i)[0];
		}
	}
	return *this;
}



// COMPARE
template <class T>
bool vec2<T>::compare(vec2<T> const &target, vec2<T> const &area) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if((	this->ref().at(i)[0] < target.ref().at(i)[0] - area.ref().at(i)[0] 
					|| this->ref().at(i)[0] > target.ref().at(i)[0] + area.ref().at(i)[0])) { 
			return false;
		}
	}
	return true;
}

template <class T>
bool vec2<T>::compare(vec2<T> const &target, T const &area) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if((	this->ref().at(i)[0] < target.ref().at(i)[0] - area 
					|| this->ref().at(i)[0] > target.ref().at(i)[0] + area)) {
			return false;
		}
	}
	return true;
}

template <class T>
bool vec2<T>::compare_angle(vec2<T> const &target, T const &area) {
	return abs(this->angle(target)) < area;
}





// random
template <class T>
vec2<T>	& vec2<T>::rand() {
	return rand(0,0, 1,1);
}

template <class T>
vec2<T>	& vec2<T>::rand(std::default_random_engine &generator) {
	return rand(0,0, 1,1, generator);
}

//
template <class T>
vec2<T>	& vec2<T>::rand(T const &max) {
	return rand(0,0, max,max);
}

template <class T>
vec2<T>	& vec2<T>::rand(T const &max, std::default_random_engine &generator) {
	return rand(0,0, max,max, generator);
}

//
template <class T>
vec2<T>	& vec2<T>::rand(T const &min, T const &max) {
	return rand(min,min, max,max);
}

template <class T>
vec2<T>	& vec2<T>::rand(T const &min, T const &max, std::default_random_engine &generator) {
	return rand(min,min, max,max, generator);
}

//
template <class T>
vec2<T>	& vec2<T>::rand(vec2<T> const &min, vec2<T> const &max) {
	return rand(min.x(),min.y(), max.x(),max.y());
}

template <class T>
vec2<T>	& vec2<T>::rand(vec2<T> const &min, vec2<T> const &max, std::default_random_engine &generator) {
	return rand(min.x(),min.y(), max.x(),max.y(), generator);
}

//
template <class T>
vec2<T>	& vec2<T>::rand(T const &x_min, T const &y_min, 
											T const &x_max, T const &y_max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return rand(x_min, y_min,
							x_max, y_max,
							generator);
}


template <class T>
vec2<T>	& vec2<T>::rand(T const &x_min, T const &y_min, 
											T const &x_max, T const &y_max,
											std::default_random_engine &generator) {
	switch(vec<T>::get_type()) {
		case 'c':
			this->_x = random_char(x_min, x_max);
			this->_y = random_char(y_min, y_max);
			break;
		case 'b':
			this->_x = random_bool();
			this->_y = random_bool();
			break;
		case 's':
			this->_x = random_int(x_min, x_max);
			this->_y = random_int(y_min, y_max);
			break;
		case 'i':
			this->_x = random_int(x_min, x_max);
			this->_y = random_int(y_min, y_max);
			break;
		case 'l':
			this->_x = random_long(x_min, x_max);
			this->_y = random_long(y_min, y_max);
			break;
		case 'f':
			this->_x = random(x_min, x_max);
			this->_y = random(y_min, y_max);
			break;
		case 'd':
			this->_x = random_double(x_min, x_max);
			this->_y = random_double(y_min, y_max);
			break;
		case 'h':
			this->_x = random_long_double(x_min, x_max);
			this->_y = random_long_double(y_min, y_max);
			break;
		default:
			if(vec2<T>::_warning) {
				std::cout << "vec2<T>::rand(); wait <T arg> like bool, char, int, float, double" << std::endl;
			}
			abort();
	}
	return *this;
}




// wave
template <class T>
vec2<T>	vec2<T>::wave(T const &value, T const &s) {
	return cos_wave(value,s,s);
}

template <class T>
vec2<T>	vec2<T>::wave(T const &value, T const &sx, T const &sy) {
	return cos_wave(value,sx,sy);
}

template <class T>
vec2<T>	vec2<T>::cos_wave(T const &value, T const &s) {
	return cos_wave(value,s,s);
}

template <class T>
vec2<T>	vec2<T>::cos_wave(T const &value, T const &sx, T const &sy) {
	T tx = cos(value * sx) + this->x();
	T ty = cos(value * sy) + this->y();
	return vec2<T>(tx,ty);
}

template <class T>
vec2<T>	vec2<T>::sin_wave(T const &value, T const &s) {
	return sin_wave(value,s,s);
}

template <class T>
vec2<T>	vec2<T>::sin_wave(T const &value, T const &sx, T const &sy) {
	T tx = std::sin(value * sx) + this->x();
	T ty = std::sin(value * sy) + this->y();
	return vec2<T>(tx,ty);
}







// OPERATOR
// op =
template <class T>
vec2<T> & vec2<T>::operator=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		this->ref().at(i)[0] = rhs.ref().at(i)[0];
	}
	return *this;
}


// op +
template <class T>
vec2<T> vec2<T>::operator+(vec2<T> const &rhs) const {
	vec2<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator+(T const &rhs) const {
	vec2<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] + rhs;
	}
	return temp;
}



// op -
template <class T>
vec2<T> vec2<T>::operator-(vec2<T> const &rhs) const {
	vec2<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator-(T const &rhs) const {
	vec2<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] - rhs;
	}
	return temp;
}





// op *
template <class T>
vec2<T> vec2<T>::operator*(vec2<T> const &rhs) const {
	vec2<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator*(T const &rhs) const {
	vec2<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] * rhs;
	}
	return temp;
}






// op /
template <class T>
vec2<T> vec2<T>::operator/(vec2<T> const &rhs) const {
	vec2<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs.ref().at(i)[0];
	}
	return temp;
}

template <class T>
vec2<T> vec2<T>::operator/(T const &rhs) const {
	vec2<T> temp;
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		temp.ref().at(i)[0] = this->ref().at(i)[0] / rhs;
	}
	return temp;
}

// op +=
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

// op -=
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

// op *=
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

// op /=
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

// op ==
template <class T>
bool vec2<T>::operator==(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->ref().at(i)[0] != rhs.ref().at(i)[0])
			return false;
	}
	return true;
}


template <class T>
bool vec2<T>::operator==(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->ref().at(i)[0] != rhs)
			return false;
	}
	return true;
}

// op !=
template <class T>
bool vec2<T>::operator!=(vec2<T> const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->ref().at(i)[0] != rhs.ref().at(i)[0]) {
			return true;
		}
	}
	return false;
}


template <class T>
bool vec2<T>::operator!=(T const &rhs) {
	for(unsigned short i = 0 ; i < this->get_size() ; i++) {
		if(this->ref().at(i)[0] != rhs) {
			return true;
		}
	}
	return false;
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

// get exotic > return copy vector of the arguments asked.
template <class T>
vec2<T> vec2<T>::xx() const {
	return vec2<T>(this->x(),this->x());
}


template <class T>
vec2<T> vec2<T>::xy() const {
	return vec2<T>(this->x(),this->y());
}

template <class T>
vec2<T> vec2<T>::yx() const {
	return vec2<T>(this->y(),this->x());
}

template <class T>
vec2<T> vec2<T>::yy() const {
	return vec2<T>(this->y(),this->y());
}