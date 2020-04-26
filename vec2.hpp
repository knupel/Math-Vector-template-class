#ifndef VEC2_H
# define VEC2_H
/*
* vec2
* v 0.0.2
* 2020-2020
* Template Vec adapted from Rope Vector, Processing PVector, Openframework and GLSL
*/
#include "vec.hpp"


template <class T>
class vec2 : public vec<T> {
private:
	static int instance;
	static bool _warning;
protected:
	T _x;
	T _y;
public:
	vec2();
	vec2(T const &arg);
	vec2(T const &x, T const &y);
	vec2(vec2<T> const &src);
	~vec2();

	// set
	vec2 & set(T const &arg);
	vec2 & set(T const &x, T const &y);
	vec2 & x(T const &x);
	vec2 & y(T const &y);

	vec2 & min(T const &x);
	vec2 & max(T const &y);
  
  // get
	T x() const;	
	T y() const;
	T min() const;	
	T max() const;
	
	vec2 copy() const;
	T * array() const;
	// get exotic
	vec2 xx() const;
	vec2 xy() const;
	vec2 yx() const;
	vec2 yy() const;


	// Calcule the dot product of the vector
	T dot(vec2<T> const &v) const;
	T dot(T const &x, T const &y) const;

	// dir > return normal cartesian direction
	vec2 dir() const;
	vec2 dir(vec2<T> const &origin) const;

	// abs
	vec2 & abs();

	// rotate
	vec2 & rotate(T angle);
	vec2 & rotate(T angle, vec2<T> const &origin);

	// square length can be usefull and faster when the real length is not necessary
	T mag_sq() const;
	T mag_sq(vec2<T> const &v) const;
	// Calculate the magnitude, distance or length of the vector or between two vectors.
	// mag and dist is a same methode
	double mag() const;
	double mag(vec2<T> const &v) const;
	// Calculate the magnitude, distance or length of the vector or between two vectors.
	// call mag to calculate the the dist
	double dist() const;
	double dist(vec2<T> const &v) const;

	// caccule the power of the vector for each component
	vec2 & pow(T const &pow);
	vec2 & pow(T const &pow_x, T const &pow_y);

	// barycenter
	vec2 barycenter(vec2<T> const &other) const;


	//map
	vec2 & map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst);
	vec2 & map(vec2<T> const &start_src, vec2<T> const &stop_src, vec2<T> const &start_dst, vec2<T> const &stop_dst);



	//normalize
	vec2 & normalize();
	static vec2 normalize(vec2<T> &target);

	// limit
	vec2 & limit(T const &max);

	// constrain
	vec2 & constrain(T const &min, T const &max);
	vec2 & constrain(vec2<T> const &min, vec2<T> const &max);
	
	// compare
  bool compare(vec2<T> const &target, vec2<T> const &area);
  bool compare(vec2<T> const &target, T const &area);
  bool compare_angle(vec2<T> const &target, T const &area);



  // random
  vec2 & rand();
	vec2 & rand(T const &max);
	vec2 & rand(T const &min, T const &max);
	vec2 & rand(vec2<T> const &min, vec2<T> const &max);
	vec2 & rand(T const &x_min, T const &y_min, 
							T const &x_max, T const &y_max);

	vec2 & rand(std::default_random_engine &generator);
	vec2 & rand(T const &max, std::default_random_engine &generator);
	vec2 & rand(T const &min, T const &max, std::default_random_engine &generator);
	vec2 & rand(vec2<T> const &min, vec2<T> const &max, std::default_random_engine &generator);
	vec2 & rand(T const &x_min, T const &y_min, 
							T const &x_max, T const &y_max, 
							std::default_random_engine &generator);






	// wave
	vec2 wave(T const &value, T const &s);
	vec2 wave(T const &value, T const &sx, T const &sy);

	vec2 cos_wave(T const &value, T const &s);
	vec2 cos_wave(T const &value, T const &sx, T const &sy);

	vec2 sin_wave(T const &value, T const &s);
	vec2 sin_wave(T const &value, T const &sx, T const &sy);





	// vec2 specialize trigonometry
	vec2<double> tan() const;
	vec2<double> tan(vec2<T> const &target) const;
	vec2<double> tan(T const &a_x, T const &a_y) const;

	double angle() const;
	double angle(vec2<T> const &target) const;
	double heading() const;

	// op
	bool operator==(vec2<T> const &rhs);
	bool operator==(T const &rhs);

	bool operator!=(vec2<T> const &rhs);
	bool operator!=(T const &rhs);

	vec2 & operator=(vec2<T> const &rhs);

	vec2 operator+(vec2<T> const &rhs) const;
	vec2 operator+(T const &rhs) const;
	vec2 operator-(vec2<T> const &rhs) const;
	vec2 operator-(T const &rhs) const;
	vec2 operator*(vec2<T> const &rhs) const;
	vec2 operator*(T const &rhs) const;
	vec2 operator/(vec2<T> const &rhs) const;
	vec2 operator/(T const &rhs) const;

	vec2 & operator+=(vec2<T> const &rhs);
	vec2 & operator+=(T const &rhs);
	vec2 & operator-=(vec2<T> const &rhs);
	vec2 & operator-=(T const &rhs);
	vec2 & operator*=(vec2<T> const &rhs);
	vec2 & operator*=(T const &rhs);
	vec2 & operator/=(vec2<T> const &rhs);
	vec2 & operator/=(T const &rhs);




	// info
	static void warning(bool is);
	static int get_instance();
}; 

#endif


