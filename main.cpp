#include "vec.cpp"
#include "vec2.cpp"
#include "vec3.cpp"

//#include "rt_utils.cpp"

#include <iostream>
#include <cstdio>
#include <cmath>


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
	// vec2<float> b(2,2);
	// float value_f = 3.14f;
	double d1 = 100.3;
	double d2 = 32.5;
	double d3 = 8.5;
	vec2<double> e(d1,d2);
	vec2<double> f(d1,d2);

	vec3<double> a_3(0,0,0);
	vec3<double> b_3(1,1,1);
	vec3<double> f_3(d1,d2,d3);

	/**
	* Normal DIR
	*/
	// std::cout << "a:" << a << " normal a.dir(): " << a.dir() << std::endl;
	// std::cout << "a:" << a << " b:" << b << " normal a.dir(b): " << a.dir(b) << std::endl;
	// std::cout << "vec2(-2,2):" << vec2<float>(1,0) << " normal dir: " << vec2<float>(-2,2).dir() << std::endl;


	/**
	* COMPARE
	*/
	vec2<float> aa = a + 0.5f;
	std::cout << "a: " << a << std::endl;
	std::cout << "aa: " << aa << std::endl;
	std::cout << "a.compare(aa, vec2<float>(1)) > " << a.compare(aa, vec2<float>(1)) << std::endl;
	std::cout << "a.compare(aa, vec2<float>(0.25)) > " << a.compare(aa, vec2<float>(0.25)) << std::endl;
	std::cout << "a.compare(aa, vec2<float>(0.25, 2)) > " << a.compare(aa, vec2<float>(0.25, 2)) << std::endl;
	std::cout << "a.compare(aa, 1.0f) > " << a.compare(aa, 1.0f) << std::endl;
	std::cout << "a.compare(aa, 0.25f) > " << a.compare(aa, 0.25f) << std::endl;





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
	* LIMIT
	*/
	// std::cout << e << std::endl;
	// std::cout << e.limit(10) << std::endl;
	// std::cout << e << std::endl;


	/**
	* NORMALIZE
	*/
	// std::cout << e << std::endl;
	// std::cout << e.normalize() << std::endl;
	// std::cout << "vec2::normalize(vec2(100,50))" << std::endl;
	// std::cout << vec2<float>::normalize(vec2<float>(100.0f,50.0f)) << std::endl;


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



	// std::cout << f << std::endl;

	// for(int i = 0 ; i < a.get_size() ; i++) {
	// 	std::cout <<"a array()[" << i << "] = " << a.array()[i] << std::endl;
	// }

	// for(int i = 0 ; i < b.get_size() ; i++) {
	// 	std::cout <<"b array()[" << i << "] = " << b.array()[i] << std::endl;
	// }




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
	// std::cout <<"a.dot(b): " << a.dot(b) << std::endl;

	// std::cout <<"a.dot(1,2): " << a.dot(d1,d2) << std::endl;



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
