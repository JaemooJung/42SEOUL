#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end()) {
		throw std::runtime_error("Element not found");
	}
	return it;
}

#endif // __EASYFIND_H__