#ifndef __ITER_H__
#define __ITER_H__

template<typename T>
void iter(T *arr, int lenght, void (*f)(T const &)) {
	for (int i = 0; i < lenght; i++) {
		f(arr[i]);
	}
}

#endif // __ITER_H__