#ifndef VEC3_H
# define VEC3_H
/*
* vec3
* v 0.0.2
* 2020-2020
* Template Vec adapted from Rope Vector, Processing PVector, Openframework and GLSL.
*/
#include "vec2.hpp"

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
  vec3 & set(T const &arg);
  vec3 & set(T const &x, T const &y, T const &z);
  vec3 & x(T const &x);
  vec3 & y(T const &y);
	vec3 & z(T const &z);

	vec3 & min(T const &x);
	vec3 & max(T const &y);

	vec3 & red(T const &x);
	vec3 & gre(T const &y);
	vec3 & blu(T const &z);

	vec3 & hue(T const &x);
	vec3 & sat(T const &y);
	vec3 & bri(T const &z);

	//get
	T x() const;	
	T y() const;
	T z() const;

	T min() const;	
	T max() const;

	vec3 copy() const;
	T * array() const;

	T red() const;
	T gre() const;
	T blu() const;

	T hue() const;
	T sat() const;
	T bri() const;

	// get exotic
	// special
	vec3 rgb() const;
	vec3 hsb() const;

	vec2<T> xz() const;
	vec2<T> yz() const;
	vec2<T> zx() const;
	vec2<T> zy() const;
	vec2<T> zz() const;
 
	// x3
	vec3 xxx() const;
	vec3 xxy() const;
	vec3 xxz() const;
	vec3 xyx() const;
	vec3 xyy() const;
	vec3 xyz() const;
	vec3 xzx() const;
	vec3 xzy() const;

	// y3
	vec3 yxx() const;
	vec3 yxy() const;
	vec3 yxz() const;
	vec3 yyx() const;
	vec3 yyy() const;
	vec3 yyz() const;
	vec3 yzx() const;
	vec3 yzy() const;

	// z3
	vec3 zxx() const;
	vec3 zxy() const;
	vec3 zxz() const;
	vec3 zyx() const;
	vec3 zyy() const;
	vec3 zyz() const;
	vec3 zzx() const;
	vec3 zzy() const;
	vec3 zzz() const;


	// dot 
	// from vec2

	// cross
	vec3 cross(vec3<T> const &v)  const;

	// dir
	vec3 dir() const;
	vec3 dir(vec3<T> const &origin) const;

	// abs
	vec3 & abs();

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

	// calcule the power of the vector for each component
	vec3 & pow(T const &pow);
	vec3 & pow(T const &pow_x, T const &pow_y, T const &pow_z);

	// barycenter
	vec3 barycenter(vec3<T> const &other) const;

	//map
	vec3 & map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst);
	vec3 & map(vec3<T> const &start_src, vec3<T> const &stop_src, vec3<T> const &start_dst, vec3<T> const &stop_dst);




	//normalize
	vec3 & normalize();
	static vec3 normalize(vec3<T> &target);


	// limit
	vec3 & limit(T const &max);
	// constrain
	vec3 & constrain(T const &min, T const &max);
	vec3 & constrain(vec3<T> const &min, vec3<T> const &max);

	// compare 
	// from vec2

	// rand
	vec3 & rand();
	vec3 & rand(T const &max);
	vec3 & rand(T const &min, T const &max);
	vec3 & rand(vec3<T> const &min, vec3<T> const &max);
	vec3 & rand(T const &x_min, T const &y_min, T const &z_min,
						T const &x_max, T const &y_max, T const &z_max);

	vec3 & rand(std::default_random_engine &generator);
	vec3 & rand(T const &max, std::default_random_engine &generator);
	vec3 & rand(T const &min, T const &max, std::default_random_engine &generator);
	vec3 & rand(vec3<T> const &min, vec3<T> const &max, std::default_random_engine &generator);
	vec3 & rand(T const &x_min, T const &y_min, T const &z_min, 
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

	vec3 & operator+=(vec3<T> const &rhs);
	vec3 & operator+=(T const &rhs);
	vec3 & operator-=(vec3<T> const &rhs);
	vec3 & operator-=(T const &rhs);
	vec3 & operator*=(vec3<T> const &rhs);
	vec3 & operator*=(T const &rhs);
	vec3 & operator/=(vec3<T> const &rhs);
	vec3 & operator/=(T const &rhs);


	// info
	static void warning(bool is);
	static int get_instance();
};





#endif