#ifndef __WHATEVER_H__
#define __WHATEVER_H__

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b) {
	return (a < b) ? a : b;
}

template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}


#endif // __WHATEVER_H__