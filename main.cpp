#include "rope/vec/vec.hpp"
#include "rope/vec/vec2.hpp"
#include "rope/vec/vec3.hpp"
#include "rope/vec/vec4.hpp"



#include <iostream>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <ctime>

void print_warning() {
	bool is = true;
	vec2<int>::warning(is);
	vec2<float>::warning(is);
	vec2<double>::warning(is);
	vec2<long double>::warning(is);

	vec3<int>::warning(is);
	vec3<float>::warning(is);
	vec3<double>::warning(is);
	vec3<long double>::warning(is);

	vec4<int>::warning(is);
	vec4<float>::warning(is);
	vec4<double>::warning(is);
	vec4<long double>::warning(is);
}
void print_instance() {
	printf("num of instance vec2 int: %i\n", vec2<int>::get_instance());
	printf("num of instance vec2 float: %i\n", vec2<float>::get_instance());
	printf("num of instance vec2 double: %i\n", vec2<double>::get_instance());
	printf("num of instance vec2 long double: %i\n", vec2<long double>::get_instance());

	printf("num of instance vec3 int: %i\n", vec3<int>::get_instance());
	printf("num of instance vec3 float: %i\n", vec3<float>::get_instance());
	printf("num of instance vec3 double: %i\n", vec3<double>::get_instance());
	printf("num of instance vec3 long double: %i\n", vec3<long double>::get_instance());

	printf("num of instance vec4 int: %i\n", vec4<int>::get_instance());
	printf("num of instance vec4 float: %i\n", vec4<float>::get_instance());
	printf("num of instance vec4 double: %i\n", vec4<double>::get_instance());
	printf("num of instance vec4 long double: %i\n", vec4<long double>::get_instance());

}

int main() {
	// print_warning();

	// vec2<float> f_2;
	// std::cout << "f_2.rand(1): " << f_2.rand(1) << std::endl;


		vec2<int> i_2;
	std::cout << "i_2.rand(10): " << i_2.rand(10) << std::endl;
	// vec3<float> f_3(1);
	// std::cout << f_3 << std::endl;
	// vec4<float> f_4(1);
	// std::cout << f_4 << std::endl;
	// std::cout << f_4.rand(1) << std::endl;
	// vec4<long double> ld_4;
	// std::cout << ld_4 << std::endl;
	// std::cout << "ld_4.rand(): " << ld_4.rand(-1000,1000) << std::endl;
	// std::cout << "ld_4.abs(): " << ld_4.abs() << std::endl;
	// std::cout << "ld_4.dist(): " << ld_4.dist() << std::endl;
	// std::cout << "ld_4.normalize(): " << ld_4.normalize() << std::endl;

	// time test
	// auto start = std::chrono::system_clock::now();
	// vec4<long double> ld_4;
	// std::random_device seed;
	// std::default_random_engine generator(seed());
	// for(int i = 0 ; i < 1000000 ; i++) {
	// 	ld_4.rand(-1000,1000,generator);
	// 	// ld_4.rand(-1000,1000);
	// }
	// auto end = std::chrono::system_clock::now();
	// std::chrono::duration<double> elapsed_seconds = end-start;
	// std::cout << "elapsed time: " << elapsed_seconds.count() << std::endl;


	// print_instance();

}
