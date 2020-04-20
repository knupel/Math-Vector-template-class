/**
* Rope utils function template
* v 0.0.2
* 2020-2020
*/
#include "rope.hpp"
// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <limits>
// #include <string>

/**
* set list from variadic argument
*/
template<class V, typename A, typename... T>
void set_list(std::vector<V,A> &list, T ... elem) {
	list.clear();
	list.reserve(sizeof...(elem));
	char dummy[] = { (list.push_back(elem), '0')... };
	// need to use the dummy arguments to avoid the the flag -Werror / -Wunused
	dummy[0] = 0;
}



/**
* Map function inspired from Processing code, but reached in mode template to extend it.
* line : 5068
* https://github.com/processing/processing/blob/master/core/src/processing/core/PApplet.java
*/
template <typename T>
T map(T const &arg, T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst) {
	T output = 0;
	if(std::is_integral<T>::value) {
		long double e1 = start_dst;
		long double e2 = stop_dst - start_dst;
	  long double e3 = arg - start_src;
	  long double e4 = stop_src - start_src;
	  long double res = e1 + e2 * (e3 / e4);
	  output = static_cast<T>(res);
	} else {
		T e1 = start_dst;
		T e2 = stop_dst - start_dst;
		T e3 = arg - start_src;
		T e4 = stop_src - start_src;
		output = e1 + e2 * (e3 / e4);
	}
	std::string mess = "";
	if (std::isinf(output)) {
		mess = "infinity";
	} else if((output != output) || std::isnan(output)) {
		mess = "NaN";
	}
	if(mess.length() > 0)
		std::cout << "map(" << arg << ", " << start_src << ", " << stop_src << ", " << start_dst << ", " << stop_dst<< ") result is " << mess << std::endl;
	return output;
}
