#include "../../vec.cpp"
#include "../../vec2.cpp"
#include "../../vec3.cpp"
#include "../../vec4.cpp"

//#include "rt_utils.cpp"

#include <iostream>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <ctime>


// c++11 methode
template<typename Base, typename T>
inline bool instanceof(const T&) {
   return std::is_base_of<Base, T>::value;
}

template <class T>
void show_data(vec<T> &v) {
	vec2<T> &temp = dynamic_cast<vec2<T>&>(v);
	std::cout << "v.x(): " << temp.x() << std::endl;
	std::cout << "v.y(): " << temp.y() << std::endl;
}




int main() {
	// set static warning to display info about Constructor and destructor
	// vec2<double>::warning(true);
	// vec2<float>::warning(true);
	// vec2<int>::warning(true);
	// vec3<double>::warning(true);
	// vec3<float>::warning(true);
	// vec3<int>::warning(true);

	// vec2<double> a(13.03,0);
	// vec2<double> b(1.23,3.14);


	vec2<float> a(13.03f,1.0f);
	vec2<float> b(1.23f,3.14f);
	vec2<float> c(0.0f,0.0f);
	vec2<float> d(2.0f,2.0f);
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	float f1 = 100.3f;
	float f2 = 32.5f;
	float f3 = 8.5f;
	double d1 = 100.3;
	double d2 = 32.5;
	double d3 = 8.5;
	vec2<double> e(123,34);
	vec2<double> f(13.5,-32.7);

	vec3<double> a_3(0,1,0);
	vec3<double> b_3(1,1,1);
	vec3<float> f_3(d1,d2,200);

	vec4<long double> ld_4(10);
	vec4<double> d_4(10);




  /**
  * DISPLAY
  */

  // printf("ptr a: %p\n", &a);
  // std::cout << a << std::endl;
  // //a.set(1);
  // printf("ptr a.rand(1): %p\n", &a.rand(1));
  // printf("ptr a: %p\n", &a);
  // std::cout << a << std::endl;
  // std::cout << "a: " << a << std::endl;
  // std::cout << "a_3: " << a_3 << std::endl;
	// std::cout << "a.xy(): " << a.xy() << std::endl;
	// std::cout << "a.yx(): " << a.yx() << std::endl;
 //  std::cout << "a.xx(): " << a.xx() << std::endl;
 //  std::cout << "a.yy(): " << a.yy() << std::endl;

 //  std::cout << "a.xy().angle(): " << a.xy().angle() << std::endl;
	// std::cout << "a.yx().angle(): " << a.yx().angle() << std::endl;
 //  std::cout << "a.xx().angle(): " << a.xx().angle() << std::endl;
 //  std::cout << "a.yy().angle(): " << a.yy().angle() << std::endl;


	// std::cout << "f_3.xxx(): " << f_3.xxx() << std::endl;
	// std::cout << "f_3.zz(): " << f_3.zz() << std::endl;
	// std::cout << "f_3.xy(): " << f_3.xy() << std::endl;
	// std::cout << "f_3.yx(): " << f_3.yx() << std::endl;
 //  std::cout << "f_3.xx(): " << f_3.xx() << std::endl;
 //  std::cout << "f_3.yy(): " << f_3.yy() << std::endl;
	// std::random_device seed;
	// std::default_random_engine generator(seed());
	// std::cout << "ld_4.get_type(): " << ld_4.get_type() << std::endl;
	// std::cout << "ld_4.rand(-10,10): " << ld_4.rand(-10,10) << std::endl;

	// std::cout << "d_4.rand(-10,10): " << d_4.rand(-10,10) << std::endl;
	// std::cout << "d_4.wzyx(): " << d_4.wzyx() << std::endl;
	// std::cout << "d_4.zzzx(): " << d_4.zzzx() << std::endl;
	// std::cout << "d_4.xxx(): " << d_4.xxx() << std::endl;
	// std::cout << "d_4.zz(): " << d_4.zz() << std::endl;
	// std::cout << "d_4.xy(): " << d_4.xy() << std::endl;
	// std::cout << "d_4.yx(): " << d_4.yx() << std::endl;
 //  std::cout << "d_4.xx(): " << d_4.xx() << std::endl;
 //  std::cout << "d_4.yy(): " << d_4.yy() << std::endl;



  // std::cout << "vec4<long double> ld_4: " << ld_4 << std::endl;

  // SET
  // std::cout << "ld_4.set(0,1,2,3): " << ld_4.set(0,1,2,3) << std::endl;
  // std::cout << "ld_4.hue(255): " << ld_4.hue(255) << std::endl;
  // std::cout << "ld_4.alp(255): " << ld_4.alp(255) << std::endl;

  // std::cout << "a: " << a << std::endl;
  // std::cout << "a.min(2): " << a.min(2) << std::endl;
  // std::cout << "a.max(10): " << a.max(10) << std::endl;
  // std::cout << "a.min(0).max(1): " << a.min(0).max(1) << std::endl;

  // std::cout << "f_3: " << f_3 << std::endl;
  // std::cout << "f_3.red(255): " << f_3.red(255) << std::endl;
  // std::cout << "f_3.gre(255): " << f_3.gre(255) << std::endl;
  // std::cout << "f_3.blu(255): " << f_3.blu(255) << std::endl;

  // std::cout << "f_3.min(): " << f_3.min() << std::endl;
  // std::cout << "f_3.min(0): " << f_3.min(0) << std::endl;
  // std::cout << "f_3.hue(): " << f_3.hue() << std::endl;






	/**
	* TIME
	*/
	// auto start = std::chrono::system_clock::now();

	// end
	// auto end = std::chrono::system_clock::now();
	// std::chrono::duration<double> elapsed_seconds = end-start;
	// std::cout << "elapsed time: " << elapsed_seconds.count() << std::endl;




	/**
	* Normal DIR
	*/
	// std::cout << "a:" << a << " normal a.dir(): " << a.dir() << std::endl;
	// std::cout << "a:" << a << " b:" << b << " normal a.dir(b): " << a.dir(b) << std::endl;
	// std::cout << "vec2(-2,2):" << vec2<float>(1,0) << " normal dir: " << vec2<float>(-2,2).dir() << std::endl;

	// std::cout << "vec3(-2,2,1).dir(): " << vec3<float>(-2,2,1).dir() << std::endl;
	// std::cout << "vec3(-2,2,1).dir(a):" << vec3<float>(-2,2,1).dir(f_3) << std::endl;

 	// std::cout << "ld_4.dir(): " << ld_4.dir() << std::endl;
 	// std::cout << "ld_4.dir(vec4<long double>(1,2,3,4)): " << ld_4.dir(vec4<long double>(1,2,3,4)) << std::endl;
	/**
	* CROSS
	*/
	// std::cout << "a_3.cross(b_3): " << a_3.cross(b_3) << std::endl;

	// std::cout << "ld_4.cross(vec4<long double>(1,2,3,4)): " << ld_4.cross(vec4<long double>(1,2,3,4)) << std::endl;

	// std::cout << "ld_4: " << ld_4 << std::endl;
	// vec4 <long double> ld_5 = ld_4;
	// float step = 0.1;
	// float max = 50000.0f;
	// int n = 0;
	// // for(float f = 0 ; f < max ; f += step) {
	// // 	n++;
	// // 	// std::cout << "ld_4.rotate(1.4): " << ld_4.rotate(step) << std::endl;
	// // 	ld_4.rotate(step);
	// // }

	// auto end = std::chrono::system_clock::now();
	// std::chrono::duration<double> elapsed_seconds = end-start;
	// std::cout << "loop: " << n << " | elapsed time: " << elapsed_seconds.count() << std::endl;

	// n = 0;
	// start = std::chrono::system_clock::now();
	// for(float f = 0 ; f < max ; f += step) {
	// 	n++;
	// 	// std::cout << "ld_5.xy().rotate(1.4): " << ld_5.xy().rotate(1.4) << std::endl;
	// 	ld_5.xy().rotate(step);
	// }

	// end = std::chrono::system_clock::now();
	// elapsed_seconds = end-start;
	// std::cout << "loop: " << n << " | elapsed time: " << elapsed_seconds.count() << std::endl;

	/**
	* TAN
	*/
	// std::cout << "vec2<int>(3,3).tan(): " << vec2<int>(3,3).tan() << std::endl;
	// std::cout << "vec2<float>(3,3).tan(): " << vec2<float>(3.0f,3.0f).tan() << std::endl;
	// std::cout << "vec2<long double>(3,3).tan(): " << vec2<long double>(3.0,3.0).tan() << std::endl;

	// std::cout << "vec2<int>(0,1).angle(): " << vec2<int>(0,1).angle() << std::endl;
	// std::cout << "a: " << a.set(0.1f,0.25f) << std::endl;
	// std::cout << "vec2<float>(0,1).angle(a): " << vec2<float>(0,1).angle(a) << std::endl;
	// std::cout << "vec2<float>(0,0).angle(): " << vec2<float>(0,0).angle() << std::endl;
	// std::cout << "vec2<long double>(1,1).angle(): " << vec2<long double>(1,1).angle() << std::endl;

	// std::cout << "vec3<int>(3).tan(): " << vec3<int>(3).tan() << std::endl;
	// std::cout << "vec3<float>(3).tan(): " << vec3<float>(3.0f).tan() << std::endl;
	// std::cout << "vec3<long double>(3).tan(): " << vec3<long double>(3.0).tan() << std::endl;

	// std::cout << "vec4<long double>(3).tan(): " << vec4<long double>(3.0).tan() << std::endl;




	/**
	* WAVE
	*/
	// a.set(10);
	// b.set(0.1);
	// auto start = std::chrono::system_clock::now();
	// for(float i = 0 ; i < 100 ; i += 1.0f) {
	// 	//a.cos_wave(i,b.x(),b.y());
	// 	std::cout << f_3.cos_wave(i,b.x(),b.y(), 3.5) << std::endl; 
	// 	// std::cout << (a.cos_wave(i,b.x(),b.y())) << std::endl; 
	// }
	// auto end = std::chrono::system_clock::now();
	// std::chrono::duration<double> elapsed_seconds = end-start;
	// std::cout << "elapsed time: " << elapsed_seconds.count() << std::endl;


	// vec4<long double> ratio(0.1,0.2,0.3,0.4);
	// auto start = std::chrono::system_clock::now();
	// for(float i = 0 ; i < 1000000 ; i += 1.0f) {
	// 	//a.cos_wave(i,b.x(),b.y());
	// 	ld_4.wave(i,ratio.x(),ratio.y(), ratio.z(), ratio.w());
	// 	// std::cout << ld_4.wave(i,ratio.x(),ratio.y(), ratio.z(), ratio.w()) << std::endl; 
	// 	// std::cout << (a.cos_wave(i,b.x(),b.y())) << std::endl; 
	// }
	// auto end = std::chrono::system_clock::now();
	// std::chrono::duration<double> elapsed_seconds = end-start;
	// std::cout << "elapsed time: " << elapsed_seconds.count() << std::endl;




	/**
	* LIMIT
	*/
	// std::cout << "e: " << e << std::endl;
	// std::cout << "e.limit(10): " << e.limit(10) << std::endl;
	// std::cout << e << std::endl;

	// std::cout << "f_3: " << f_3 << std::endl;
	// std::cout << "f_3.limit(10): " << f_3.limit(10) << std::endl;


	// std::cout << "ld_4.set(10): " << ld_4.set(10) << std::endl;
	// std::cout << "ld_4.limit(10): " << ld_4.limit(10) << std::endl;


	/**
	* CONSTRAIN
	*/
	// a.set(-10, 12);
	// std::cout << a.rand(-15, 15) << std::endl;
	// std::cout << a.constrain(-10,10) << std::endl;
	// std::cout << a.rand(-20, 20) << std::endl;
  
 //  vec3<float> min_f(0);
 //  vec3<float> max_f(100);
 //  std::cout << f_3.constrain(min_f,max_f) << std::endl;
	// std::cout << f_3.constrain(-10,10) << std::endl;
	// std::cout << f_3 << std::endl;
  
 //  vec2<float> *a_truc = new vec2<float>(0);
	// std::cout << "rand a_truc: " << a_truc->rand(-1000, 1000) << std::endl;
	// printf("%p %p > ref a_truc \n", &a_truc->ref().at(0),  &a_truc->ref().at(1));
	// // vec2<float> a_min(-100,-100);
	// vec2<float> *a_min = new vec2<float>(-100,-100);
	// printf("%p %p > ref a_min\n", &a_min->ref().at(0),  &a_min->ref().at(1));
	// vec2<float> *a_max = new vec2<float>(100,100);
	// // vec2<float> a_max(100,100);
	// // printf("%p %p > ref a_min\n", &a_min.ref().at(0),  &a_min.ref().at(1));
	// printf("%p %p > ref a_max\n", &a_max->ref().at(0),  &a_max->ref().at(1));
	// std::cout << a_truc->constrain(*a_min,*a_max) << std::endl;
	// printf("%p %p > ref a_truc\n", &a_truc->ref().at(0),  &a_truc->ref().at(1));
	// std::cout << "a_max: " << *a_max << std::endl;
	// std::cout << "a_truc: " << *a_truc << std::endl;
	// delete a_min;
	// delete a_max;
	// delete a_truc;



	// printf("%p %p > ref a \n", &a.ref().at(0),  &a.ref().at(1));
	// vec2<float> a_min(-100,-100);
	// printf("%p %p > ref a_min\n", &a_min.ref().at(0),  &a_min.ref().at(1));
	// vec2<float> a_max(100,100);
	// // printf("%p %p > ref a_min\n", &a_min.ref().at(0),  &a_min.ref().at(1));
	// printf("%p %p > ref a_max\n", &a_max.ref().at(0),  &a_max.ref().at(1));
	// // std::cout << a.constrain(a_min,a_max) << std::endl;
	// printf("%p %p > ref a\n", &a.ref().at(0),  &a.ref().at(1));




	/**
	* MAP
	*/
	// std::cout << d << std::endl;
	// std::cout << d.map(0,10,0,100) << std::endl;
	// std::cout << d.map(	vec2<float>(0), vec2<float>(1), 
	// 										vec2<float>(10), vec2<float>(100,1000)) << std::endl;

	// std::cout << f_3.map(0,10,0,100) << std::endl;






	/**
	* random ec generator
	*/
	// // time
	// std::cout << "a: " << a << " type: " << a.get_type() << " random: " << a.rand(0,1) <<std::endl;
	// auto start = std::chrono::system_clock::now();

	// SLOW with a lot of instance
	// for(int i = 0 ; i < 100000 ; i++) {
	// 	a.rand(0,1);
	// 	// std::cout << a.rand(0,1000) <<std::endl; 
	// }
	// FASTER
	// std::random_device seed;
	// std::default_random_engine generator(seed());
	// for(int i = 0 ; i < 100000 ; i++) {
	// 	a.rand(0,1,generator);
	// 	// std::cout << a.rand(0,1000,generator) <<std::endl; 
	// }

  // // time
	// auto end = std::chrono::system_clock::now();
	// std::chrono::duration<double> elapsed_seconds = end-start;
	// std::cout << "elapsed time: " << elapsed_seconds.count() << std::endl;

	// std::cout << "e: " << e << " type: " << e.get_type() << " random: " << e.rand(-10,10) << std::endl;
	// test time

	// std::cout << f_3.set(1,2,3) << std::endl;
	// std::cout << f_3.z(8) << std::endl;
	// std::cout << f_3.rand(0,1000,generator) <<std::endl; 




	/**
	* GET TYPE
	*/
	// std::cout << "a: " << a << " type: " << a.get_type() << std::endl;
	// std::cout << "e: " << e << " type: " << e.get_type() << std::endl;




	/**
	* COMPARE
	*/
	// vec2<float> aa = a + 0.5f;
	// std::cout << "a: " << a << std::endl;
	// std::cout << "aa: " << aa << std::endl;
	// std::cout << "a.compare(aa, vec2<float>(1)) > " << a.compare(aa, vec2<float>(1)) << std::endl;
	// std::cout << "a.compare(aa, vec2<float>(0.25)) > " << a.compare(aa, vec2<float>(0.25)) << std::endl;
	// std::cout << "a.compare(aa, vec2<float>(0.25, 2)) > " << a.compare(aa, vec2<float>(0.25, 2)) << std::endl;
	// std::cout << "a.compare(aa, 1.0f) > " << a.compare(aa, 1.0f) << std::endl;
	// std::cout << "a.compare(aa, 0.25f) > " << a.compare(aa, 0.25f) << std::endl;
 
	// vec3<float> fff = f_3 + 0.1f;
	// std::cout << "f_3.compare(fff, 0.25f) > " << f_3.compare(fff, 0.25f) << std::endl;



	/**
	* COMPARE ANGLE
	*/
	// float area = 0.2;
	// vec2<float> target = a;
	// vec2<float> range;
	// range.rand(-0.5,0.5);
	
	// std::cout << "target: " << target << std::endl;
	// std::cout << "a += range: " << (a += range) << std::endl;
	// std::cout << "a.angle(): " << a.angle() << std::endl;
	// std::cout << "target.angle(): " << target.angle() << std::endl;
	// std::cout << "range: " << range << std::endl;
	// std::cout << "area: " <<  area << std::endl;
	// std::cout << "a is aligne with target " << a.compare_angle(target, area) << std::endl;







  /**
  * OPERATOR
  */
  // std::cout << " a == a > " << (a == a) << std::endl;
  // std::cout << " a == b > " << (a == b) << std::endl;

  // std::cout << " a != a > " << (a != a) << std::endl;
  // std::cout << " a != b > " << (a != b) << std::endl;

  // std::cout << " vec2(1) == vec2(0,1) > " << (vec2<int>(1) == vec2<int>(0,1)) << std::endl;
  // std::cout << " vec2(1) == 1 > " << (vec2<int>(1) == 1) << std::endl;
  // std::cout << " vec2(1,0) != 1 > " << (vec2<int>(1,0) != 1) << std::endl;
  // std::cout << " vec2(1,1) != 1 > " << (vec2<int>(1) != 1) << std::endl;


  // std::cout << "a == a > " << (a == a) << std::endl;
  // std::cout << "a == b > " << (a == b) << std::endl;

  // std::cout << "f_3 == f_3 > " << (f_3 == f_3) << std::endl;
  // std::cout << "a_3 == b_3 > " << (a_3 == b_3) << std::endl;



  // vec2<float> dup;
  // dup = a;
  // printf("ref a: %p\n",&a);
  // printf("ref dup: %p\n",&dup);
  // std::cout << "a: " << a << " dup: " << dup << std::endl;
  // a += dup;
  // std::cout << "a += dup: " << a << std::endl;
  // a += 10;
  // std::cout << "a += 10: " << a << std::endl;

	// vec2<float> add_vec = a + b;
	// std::cout << add_vec << " = " << a << " + " << b  << std::endl;
	// std::cout << "a: " << a << std::endl;

	// vec2<float> add_single = a + f1;
	// std::cout << add_single << " = " << a << " + " << f1 << std::endl;

 //  vec2<float> temp = add_single;
	// a -= f1;
	// std::cout << "result: " << a << std::endl;

	// vec2<float> sub = a - b;
	// std::cout << sub << " = " << a << " - " << b  << std::endl;

	// vec2<float> mult = a * b;
	// std::cout << mult << " = " << a << " * " << b  << std::endl;

	// vec2<float> div = a / b;
	// std::cout << div << " = " << a << " / " << b  << std::endl;






	/**
	* DISTANCE / MAG
	*/
	// std::cout << c << d << std::endl;
	// std::cout <<"c.dist(d): " << c.dist(d) << std::endl;
	// std::cout << a_3 << b_3 << std::endl;
	// std::cout << "a_3.dist(b_3): " << a_3.dist(b_3) << std::endl;
	// std::cout << "a_3.mag(): " << a_3.mag() << std::endl;
	// std::cout << "b_3.mag(): " << b_3.mag() << std::endl;

	// std::cout <<"a.mag(): " << a.mag() << std::endl;
	// std::cout <<"a.mag(b): " << a.mag(b) << std::endl;
  
	// std::cout <<"a.mag_sq(): " << b.mag_sq() << std::endl;
	// std::cout <<"a.mag_sq(b): " << b.mag_sq(a) << std::endl;



	/**
	* SUM & AVERAGE
	*/
	// std::cout << e << std::endl;
	// std::cout << e.sum() << std::endl;
	// std::cout << e.average() << std::endl;
	// std::cout << f_3 << std::endl;
	// std::cout << f_3.sum() << std::endl;
	// std::cout << f_3.average() << std::endl;
	// std::cout << "sum int: " << vec3<int>(2,2,1).sum() << std::endl;
	// std::cout << "sum int: " << vec3<int>(i1,i2,i3).sum() << std::endl;
	// std::cout << "average int: " << vec3<int> (2,1,1).average() << std::endl;
	// std::cout << "average float: " << vec3<float> (2,1,3).average() << std::endl;


	/**
	* BARYCENTER
	*/
	// a.set(1);
	// b.set(3);
	// std::cout << "a.barycenter(b): " << a.barycenter(b) << std::endl;
	// std::cout << "a: " << a << std::endl;
	// std::cout << "b: " << b << std::endl;

	// a_3.set(1);
	// b_3.set(3);
	// std::cout << "a_3.barycenter(b_3): " << a_3.barycenter(b_3) << std::endl;
	// std::cout << "a_3: " << a << std::endl;
	// std::cout << "b_3: " << b << std::endl;


	// vec4<long double> ld_5 = ld_4;
	// std::cout << "ld_5 after copy: " << ld_5 << std::endl;



	/**
	* ABS
	*/
	std::cout << "a.rand(-1,1): " << a.rand(-1,1) << std::endl;
	std::cout << "a.abs(): " << a.abs() << std::endl;

	std::cout << "f_3.rand(-1,1): " << f_3.rand(-1,1) << std::endl;
	std::cout << "f_3.abs(): " << f_3.abs() << std::endl;

	std::cout << "ld_4.rand(-1,1): " << ld_4.rand(-1,1) << std::endl;
	std::cout << "ld_4.abs(): " << ld_4.abs() << std::endl;





	/**
	* NORMALIZE
	*/
	// std::cout << e << std::endl;
	// std::cout << "e.normalize():" << e.normalize() << std::endl;
	// std::cout << "vec2::normalize(vec2(100,50))" << std::endl;
	// std::cout << vec2<float>::normalize(vec2<float>(100.0f,50.0f)) << std::endl;

	// std::cout << "f_3.normalize():" << f_3.normalize() << std::endl;


  /**
  * LIST
  */
	// for(int i = 0 ; i < e.get_size() ; i++) {
	// 	std::cout <<"e array()[" << i << "] = " << e.array()[i] << std::endl;
	// }

	// std::cout << "e min: " << e.min() << std::endl;
	// std::cout << "e max: " << e.max() << std::endl;

	// for(int i = 0 ; i < f.get_size() ; i++) {
	// 	std::cout <<"f array()[" << i << "] = " << f.array()[i] << std::endl;
	// }
	// std::cout << "f min: " << f.min() << std::endl;
	// std::cout << "f max: " << f.max() << std::endl;

	// for(size_t i = 0 ; i < f.get_size() ; i++) {
	// 	std::cout <<"f list().at(" << i << ") = " << f.list().at(i) << std::endl;
	// }

	// for(size_t i = 0 ; i < f.get_size() ; i++) {
	// 	std::cout <<"f ref().at(" << i << ") = " << f.ref().at(i) << std::endl;
	// }


  /**
  * POW
  */
	//std::cout <<"pow: " << pow(d1,d2) << std::endl;
	// float array [a.get_size()] = a.array();
	// for(int i = 0 ; i < 100 ; i++) {

	// for(int i = 0 ; i < f.get_size() ; i++) {
	// 	std::cout <<"f array()[" << i << "] = " << f.array()[i] << std::endl;
	// }




	/**
	* ARRAY
	*/
	// std::cout << f << std::endl;

	// for(int i = 0 ; i < a.get_size() ; i++) {
	// 	std::cout <<"a array()[" << i << "] = " << a.array()[i] << std::endl;
	// }

	// for(int i = 0 ; i < b.get_size() ; i++) {
	// 	std::cout <<"b array()[" << i << "] = " << b.array()[i] << std::endl;
	// }



	/**
	* LIST
	*/
  //printf("pointer adress a._x: %p\n", &(a._x));
	// std::cout << "list ref: " << a.list().at(0) << std::endl;
	// std::cout << "list arg: " << a.list().at(0)[0] << std::endl;
	// a.x(43.0f);
	// std::cout << "list ref: " << a.list().at(0) << std::endl;
	// std::cout << "list arg: " << a.list().at(0)[0] << std::endl;


	// std::cout <<"vec2 a: " << a << std::endl;
	// std::cout <<"vec2 b: " << b << std::endl;
	// std::cout <<"float f: " << f << std::endl;
	// std::cout <<"a.get_size(): " << a.get_size() << std::endl;


	// // std::cout <<"a.pow(d1): " << a.pow(2) << std::endl;





	/**
	* DOT
	*/
	// std::cout << "a: " << a << std::endl;
	// std::cout << "b: " << b << std::endl;
	// std::cout <<"a.dot(b): " << a.dot(b) << std::endl;
	// std::cout << "d1: " << d1 << std::endl;
	// std::cout << "d2: " << d2 << std::endl;
	// std::cout <<"a.dot(d1,d2): " << a.dot(d1,d2) << std::endl;

	// vec3<float> ff(10);
	// std::cout <<"f_3.dot(ff): " << f_3.dot(ff) << std::endl;
	// std::cout <<"f_3.dot(1,2,3): " << f_3.dot(1,2,3) << std::endl;



	// show_data(a);
	// a.x(2);
	// show_data(a);
  



	printf("num of instance vec2 int: %i\n", vec2<int>::get_instance());
	printf("num of instance vec2 float: %i\n", vec2<float>::get_instance());
	printf("num of instance vec2 double: %i\n", vec2<double>::get_instance());
	printf("num of instance vec3 int: %i\n", vec3<int>::get_instance());
	printf("num of instance vec3 float: %i\n", vec3<float>::get_instance());
	printf("num of instance vec3 double: %i\n", vec3<double>::get_instance());

	return (0);
}
