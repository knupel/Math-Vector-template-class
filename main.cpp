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
	vec2<double>::warning(true);
	vec2<float>::warning(true);
	vec2<int>::warning(true);

	// vec2<double> a(13.03,0);
	// vec2<double> b(1.23,3.14);


	vec2<float> a(13.03f,4.01f);
	vec2<float> b(1.23f,3.14f);
	vec2<float> c;
	vec2<float> d(-1.0f,0.0f);
	// vec2<float> b(2,2);
	float f = 3.14f;
	double d1 = 12.3;
	double d2 = 4.5;


	//std::cout <<"pow: " << pow(d1,d2) << std::endl;
	// float array [a.get_size()] = a.array();
	// for(int i = 0 ; i < 100 ; i++) {
	for(int i = 0 ; i < a.get_size() ; i++) {
		std::cout <<"array[" << i << "] = " << a.array()[i] << std::endl;
		a.array()[i] = 12.0f;
	}


  //printf("pointer adress a._x: %p\n", &(a._x));
	std::cout << "list ref: " << a.list().at(0) << std::endl;
	std::cout << "list arg: " << a.list().at(0)[0] << std::endl;
	a.x(43.0f);
	std::cout << "list ref: " << a.list().at(0) << std::endl;
	std::cout << "list arg: " << a.list().at(0)[0] << std::endl;


	// std::cout <<"vec2 a: " << a << std::endl;
	// std::cout <<"vec2 b: " << b << std::endl;
	// std::cout <<"float f: " << f << std::endl;
	// std::cout <<"a.get_size(): " << a.get_size() << std::endl;


	// // std::cout <<"a.pow(d1): " << a.pow(2) << std::endl;
	// std::cout <<"a.mag(): " << a.mag() << std::endl;
	// std::cout <<"a.mag(b): " << a.mag(b) << std::endl;
  
 //  // float temp = c.dist(d);
	// std::cout <<"c.dist(d): " << c.dist(d) << std::endl;

	// std::cout <<"a.magSq(): " << b.magSq() << std::endl;
	// std::cout <<"a.magSq(b): " << b.magSq(a) << std::endl;



	// std::cout <<"a.dot(b): " << a.dot(b) << std::endl;

	// std::cout <<"a.dot(1,2): " << a.dot(d1,d2) << std::endl;



	// show_data(a);
	// a.x(2);
	// show_data(a);
  
	// vec2<float> add_vec = a + b;
	// std::cout << add_vec << " = " << a << " + " << b  << std::endl;

	// vec2<float> add_single = a + f;
	// std::cout << add_single << " = " << a << " + " << f << std::endl;

  // vec2<float> temp = add_single;
	// a -= f;
	// std::cout << "result: " << a << std::endl;

	// vec2<float> sub = a - b;
	// std::cout << sub << " = " << a << " - " << b  << std::endl;

	// vec2<float> mult = a * b;
	// std::cout << mult << " = " << a << " * " << b  << std::endl;

	// vec2<float> div = a / b;
	// std::cout << div << " = " << a << " / " << b  << std::endl;


	printf("num of instance vec2 int: %i\n", vec2<int>::get_instance());
	printf("num of instance vec2 float: %i\n", vec2<float>::get_instance());
	printf("num of instance vec2 double: %i\n", vec2<double>::get_instance());

	return (0);
}
