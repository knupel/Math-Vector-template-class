/**
* Rope utils function template
* v 0.0.1
* 2020-2020
*/
#include <iostream>
#include <vector>

template<class V, typename A, typename... T>
void set_list(std::vector<V,A> &list, T ... elem) {
	list.clear();
	list.reserve(sizeof...(elem));
	char dummy[] = { (list.push_back(elem), '0')... };
	// need to use the dummy arguments to avoid the the flag -Werror / -Wunused
	dummy[0] = 0;
}
