#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>

template<typename T>
class Array {
	private:
		unsigned int _size;
		T* _arr;

	public:
		int size() const {
			return _size;
		}

		T* getArr() const {
			return _arr;
		}

		class IdxOutOfRange: public std::exception {
			public:
				const char* what() const throw() {
					return "Index out of range";
				}
		};

		T& operator[](unsigned int i) const {
			if (i >= _size) {
				throw IdxOutOfRange();
			}
			return _arr[i];
		}

		Array& operator=(const Array& other) {
			if (this != &other) {
				if (_size) {
					delete[] _arr;
					_arr = NULL;
					_size = 0;
				}
				_size = other.size();
				if (_size) {
					_arr = new T[_size];
					for (unsigned int i = 0; i < _size; i++) {
						_arr[i] = other.getArr()[i];
					}
				}
			}
			return *this;
		}

		Array(): _size(0), _arr(NULL) {

		}

		Array(unsigned int size): _size(size), _arr(NULL) {
			if (size > 0)
				_arr = new T[size];
		}

		Array(const Array& other): _size(other.size()), _arr(NULL) {
			if (_size) {
				_arr = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					_arr[i] = other.getArr()[i];
				}
			}
		}

		~Array() {
			if (_size) {
				delete[] _arr;
				_arr = NULL;
			}
		}


};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		os << "[ "<< i << " ] : " << arr[i] << std::endl;
	}
	return os;
}

#endif // __ARRAY_H__