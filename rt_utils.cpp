/**
* Rope utils function template
*/
#include <iostream>
#include <vector>

template<class V, typename A, typename... T>
void set_list(std::vector<V,A> &list, T ... elem) {
	// std::cout << "je suis pas là pour des prunes" << std::endl;
	list.clear();
	list.reserve(sizeof...(elem));
	char dummy[] = { (list.push_back(elem), '0')... }; 
}
