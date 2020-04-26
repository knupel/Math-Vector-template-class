#ifndef VEC4_H
# define VEC4_H
/*
* vec4
* v 0.0.2
* 2020-2020
* Template Vec adapted from Rope Vector, Processing PVector, Openframework and GLSL.
*/
#include "vec3.hpp"

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
  vec4 & set(T const &arg);
  vec4 & set(T const &x, T const &y, T const &z, T const &w);
  vec4 & x(T const &x);
  vec4 & y(T const &y);
	vec4 & z(T const &z);
	vec4 & w(T const &w);

	vec4 & min(T const &x);
	vec4 & max(T const &y);

	vec4 & red(T const &x);
	vec4 & gre(T const &y);
	vec4 & blu(T const &z);

	vec4 & hue(T const &x);
	vec4 & sat(T const &y);
	vec4 & bri(T const &z);

	vec4 & alp(T const &w);

	//get
	T x() const;	
	T y() const;
	T z() const;
	T w() const;

	T min() const;	
	T max() const;

	vec4 copy() const;
	T * array() const;

	T red() const;
	T gre() const;
	T blu() const;

	T hue() const;
	T sat() const;
	T bri() const;

	T alp() const;

	// get exotic
	// special
	vec4 rgba() const;
	vec4 hsba() const;

	// XYZW
	vec2<T> ww() const;
	vec2<T> wx() const;
	vec2<T> wy() const;
	vec2<T> wz() const;
	vec2<T> xw() const;
	vec2<T> yw() const;
	vec2<T> zw() const;

	// w3
	vec3<T> www() const;
	vec3<T> wwx() const;
	vec3<T> wwy() const;
	vec3<T> wwz() const;
	vec3<T> wxw() const;
	vec3<T> wxx() const;
	vec3<T> wxy() const;
	vec3<T> wxz() const;
	vec3<T> wyw() const;
	vec3<T> wyx() const;
	vec3<T> wyy() const;
	vec3<T> wyz() const;
	vec3<T> wzw() const;
	vec3<T> wzx() const;
	vec3<T> wzy() const;
	vec3<T> wzz() const;

	// x3
	vec3<T> xww() const;
	vec3<T> xwx() const;
	vec3<T> xwy() const;
	vec3<T> xwz() const;
	vec3<T> xxw() const;
	vec3<T> xyw() const;
	vec3<T> xzw() const;

	// y3
	vec3<T> yww() const;
	vec3<T> ywx() const;
	vec3<T> ywy() const;
	vec3<T> ywz() const;
	vec3<T> yxw() const;
	vec3<T> yyw() const;
	vec3<T> yzw() const;

	// z3
	vec3<T> zww() const;
	vec3<T> zwx() const;
	vec3<T> zwy() const;
	vec3<T> zwz() const;
	vec3<T> zxw() const;
	vec3<T> zyw() const;
	vec3<T> zzw() const;

	//// W4
	// w3
	vec4 wwww() const;
	vec4 wwwx() const;
	vec4 wwwy() const;
	vec4 wwwz() const;
	vec4 wwxw() const;
	vec4 wwxx() const;
	vec4 wwxy() const;
	vec4 wwxz() const;
	vec4 wwyw() const;
	vec4 wwyx() const;
	vec4 wwyy() const;
	vec4 wwyz() const;
	vec4 wwzw() const;
	vec4 wwzx() const;
	vec4 wwzy() const;
	vec4 wwzz() const;

	// x3
	vec4 wxww() const;
	vec4 wxwx() const;
	vec4 wxwy() const;
	vec4 wxwz() const;
	vec4 wxxw() const;
	vec4 wxxx() const;
	vec4 wxxy() const;
	vec4 wxxz() const;
	vec4 wxyw() const;
	vec4 wxyx() const;
	vec4 wxyy() const;
	vec4 wxyz() const;
	vec4 wxzw() const;
	vec4 wxzx() const;
	vec4 wxzy() const;
	vec4 wxzz() const;

	// y3
	vec4 wyww() const;
	vec4 wywx() const;
	vec4 wywy() const;
	vec4 wywz() const;
	vec4 wyxw() const;
	vec4 wyxx() const;
	vec4 wyxy() const;
	vec4 wyxz() const;
	vec4 wyyw() const;
	vec4 wyyx() const;
	vec4 wyyy() const;
	vec4 wyyz() const;
	vec4 wyzw() const;
	vec4 wyzx() const;
	vec4 wyzy() const;
	vec4 wyzz() const;

	// z3
	vec4 wzww() const;
	vec4 wzwx() const;
	vec4 wzwy() const;
	vec4 wzwz() const;
	vec4 wzxw() const;
	vec4 wzxx() const;
	vec4 wzxy() const;
	vec4 wzxz() const;
	vec4 wzyw() const;
	vec4 wzyx() const;
	vec4 wzyy() const;
	vec4 wzyz() const;
	vec4 wzzw() const;
	vec4 wzzx() const;
	vec4 wzzy() const;
	vec4 wzzz() const;


	//// X4
	// w3
	vec4 xwww() const;
	vec4 xwwx() const;
	vec4 xwwy() const;
	vec4 xwwz() const;
	vec4 xwxw() const;
	vec4 xwxx() const;
	vec4 xwxy() const;
	vec4 xwxz() const;
	vec4 xwyw() const;
	vec4 xwyx() const;
	vec4 xwyy() const;
	vec4 xwyz() const;
	vec4 xwzw() const;
	vec4 xwzx() const;
	vec4 xwzy() const;
	vec4 xwzz() const;

	// x3
	vec4 xxww() const;
	vec4 xxwx() const;
	vec4 xxwy() const;
	vec4 xxwz() const;
	vec4 xxxw() const;
	vec4 xxxx() const;
	vec4 xxxy() const;
	vec4 xxxz() const;
	vec4 xxyw() const;
	vec4 xxyx() const;
	vec4 xxyy() const;
	vec4 xxyz() const;
	vec4 xxzw() const;
	vec4 xxzx() const;
	vec4 xxzy() const;
	vec4 xxzz() const;

	// y3
	vec4 xyww() const;
	vec4 xywx() const;
	vec4 xywy() const;
	vec4 xywz() const;
	vec4 xyxw() const;
	vec4 xyxx() const;
	vec4 xyxy() const;
	vec4 xyxz() const;
	vec4 xyyw() const;
	vec4 xyyx() const;
	vec4 xyyy() const;
	vec4 xyyz() const;
	vec4 xyzw() const;
	vec4 xyzx() const;
	vec4 xyzy() const;
	vec4 xyzz() const;

	// z3
	vec4 xzww() const;
	vec4 xzwx() const;
	vec4 xzwy() const;
	vec4 xzwz() const;
	vec4 xzxw() const;
	vec4 xzxx() const;
	vec4 xzxy() const;
	vec4 xzxz() const;
	vec4 xzyw() const;
	vec4 xzyx() const;
	vec4 xzyy() const;
	vec4 xzyz() const;
	vec4 xzzw() const;
	vec4 xzzx() const;
	vec4 xzzy() const;
	vec4 xzzz() const;

	//// Y4
	// w3
	vec4 ywww() const;
	vec4 ywwx() const;
	vec4 ywwy() const;
	vec4 ywwz() const;
	vec4 ywxw() const;
	vec4 ywxx() const;
	vec4 ywxy() const;
	vec4 ywxz() const;
	vec4 ywyw() const;
	vec4 ywyx() const;
	vec4 ywyy() const;
	vec4 ywyz() const;
	vec4 ywzw() const;
	vec4 ywzx() const;
	vec4 ywzy() const;
	vec4 ywzz() const;

	// x3
	vec4 yxww() const;
	vec4 yxwx() const;
	vec4 yxwy() const;
	vec4 yxwz() const;
	vec4 yxxw() const;
	vec4 yxxx() const;
	vec4 yxxy() const;
	vec4 yxxz() const;
	vec4 yxyw() const;
	vec4 yxyx() const;
	vec4 yxyy() const;
	vec4 yxyz() const;
	vec4 yxzw() const;
	vec4 yxzx() const;
	vec4 yxzy() const;
	vec4 yxzz() const;

	// y3
	vec4 yyww() const;
	vec4 yywx() const;
	vec4 yywy() const;
	vec4 yywz() const;
	vec4 yyxw() const;
	vec4 yyxx() const;
	vec4 yyxy() const;
	vec4 yyxz() const;
	vec4 yyyw() const;
	vec4 yyyx() const;
	vec4 yyyy() const;
	vec4 yyyz() const;
	vec4 yyzw() const;
	vec4 yyzx() const;
	vec4 yyzy() const;
	vec4 yyzz() const;

	// z3
	vec4 yzww() const;
	vec4 yzwx() const;
	vec4 yzwy() const;
	vec4 yzwz() const;
	vec4 yzxw() const;
	vec4 yzxx() const;
	vec4 yzxy() const;
	vec4 yzxz() const;
	vec4 yzyw() const;
	vec4 yzyx() const;
	vec4 yzyy() const;
	vec4 yzyz() const;
	vec4 yzzw() const;
	vec4 yzzx() const;
	vec4 yzzy() const;
	vec4 yzzz() const;


	//// Z4
	// w3
	vec4 zwww() const;
	vec4 zwwx() const;
	vec4 zwwy() const;
	vec4 zwwz() const;
	vec4 zwxw() const;
	vec4 zwxx() const;
	vec4 zwxy() const;
	vec4 zwxz() const;
	vec4 zwyw() const;
	vec4 zwyx() const;
	vec4 zwyy() const;
	vec4 zwyz() const;
	vec4 zwzw() const;
	vec4 zwzx() const;
	vec4 zwzy() const;
	vec4 zwzz() const;

	// x3
	vec4 zxww() const;
	vec4 zxwx() const;
	vec4 zxwy() const;
	vec4 zxwz() const;
	vec4 zxxw() const;
	vec4 zxxx() const;
	vec4 zxxy() const;
	vec4 zxxz() const;
	vec4 zxyw() const;
	vec4 zxyx() const;
	vec4 zxyy() const;
	vec4 zxyz() const;
	vec4 zxzw() const;
	vec4 zxzx() const;
	vec4 zxzy() const;
	vec4 zxzz() const;

	// y3
	vec4 zyww() const;
	vec4 zywx() const;
	vec4 zywy() const;
	vec4 zywz() const;
	vec4 zyxw() const;
	vec4 zyxx() const;
	vec4 zyxy() const;
	vec4 zyxz() const;
	vec4 zyyw() const;
	vec4 zyyx() const;
	vec4 zyyy() const;
	vec4 zyyz() const;
	vec4 zyzw() const;
	vec4 zyzx() const;
	vec4 zyzy() const;
	vec4 zyzz() const;

	// z3
	vec4 zzww() const;
	vec4 zzwx() const;
	vec4 zzwy() const;
	vec4 zzwz() const;
	vec4 zzxw() const;
	vec4 zzxx() const;
	vec4 zzxy() const;
	vec4 zzxz() const;
	vec4 zzyw() const;
	vec4 zzyx() const;
	vec4 zzyy() const;
	vec4 zzyz() const;
	vec4 zzzw() const;
	vec4 zzzx() const;
	vec4 zzzy() const;
	vec4 zzzz() const;


	// dot 
	// from vec2

	// cross
	// from vec3

	// dir
	vec4 dir() const;
	vec4 dir(vec4<T> const &origin) const;

	// abs
	vec4 & abs();

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
	vec4 & pow(T const &pow);
	vec4 & pow(T const &pow_x, T const &pow_y, T const &pow_z, T const &pow_w);

	//map
	vec4 & map(T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst);
	vec4 & map(vec4<T> const &start_src, vec4<T> const &stop_src, vec4<T> const &start_dst, vec4<T> const &stop_dst);




	//normalize
	vec4 & normalize();
	static vec4 normalize(vec4<T> &target);


	// limit
	vec4 & limit(T const &max);
	// constrain
	vec4 & constrain(T const &min, T const &max);
	vec4 & constrain(vec4<T> const &min, vec4<T> const &max);

	// compare 
	// from vec2

	// rand
	vec4 & rand();
	vec4 & rand(T const &max);
	vec4 & rand(T const &min, T const &max);
	vec4 & rand(vec4<T> const &min, vec4<T> const &max);
	vec4 & rand(T const &x_min, T const &y_min, T const &z_min, T const &w_min,
						T const &x_max, T const &y_max, T const &z_max, T const &w_max);

	vec4 & rand(std::default_random_engine &generator);
	vec4 & rand(T const &max, std::default_random_engine &generator);
	vec4 & rand(T const &min, T const &max, std::default_random_engine &generator);
	vec4 & rand(vec4<T> const &min, vec4<T> const &max, std::default_random_engine &generator);
	vec4 & rand(T const &x_min, T const &y_min, T const &z_min, T const &w_min, 
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

	vec4 & operator+=(vec4<T> const &rhs);
	vec4 & operator+=(T const &rhs);
	vec4 & operator-=(vec4<T> const &rhs);
	vec4 & operator-=(T const &rhs);
	vec4 & operator*=(vec4<T> const &rhs);
	vec4 & operator*=(T const &rhs);
	vec4 & operator/=(vec4<T> const &rhs);
	vec4 & operator/=(T const &rhs);


	// info
	static void warning(bool is);
	static int get_instance();
};

#endif