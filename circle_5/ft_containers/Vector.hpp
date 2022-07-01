#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <memory>

namespace ft {
	template <typename T, typename Allocator = std::allocator<T> >
	class vector {
		public:
			typedef T			value_type;
			typedef Allocator	allocator_type;
			typedef size_t		size_type;
			typedef ptrdiff_t	difference_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

		protected:
			allocator_type		_allocator;
			size_type			_size;
			size_type			_capacity;
			value_type*			_array;

		public:
			// constructors ===================================================
			vector(const allocator_type& allocator = allocator_type())
				: _allocator(allocator), _size(0), _capacity(0), _array(0) {}
			

			vector(size_type n, const value_type& value = value_type(),
				const allocator_type& allocator = allocator_type())
			: _allocator(allocator), _size(n), _capacity(n), _array(0) {
				_array = _allocator.allocate(n);
				for (size_type i = 0; i < n; ++i) 
					_allocator.construct(&_array[i], value);
			}

			// ================================================================
			
			// iterators ======================================================

			// ================================================================

			// capacity =======================================================

			size_type size() const { return _size; }
			size_type max_size() const { return _allocator.max_size(); }
			size_type capacity() const { return _capacity; }
			bool empty() const { return _size == 0; }
			void reserve(size_type n) {
				if (n == 0) {
					_array = _allocator.allocate(1);
					_capacity = 1;
					_size = 0;
				} else if (n > _capacity) {
					value_type* tmp = _allocator.allocate(n);
					size_type tmp_size = _size;
					for (size_type i = 0; i < _size; ++i) {
						_allocator.construct(&tmp[i], _array[i]);
					}
					clear();
					_allocator.deallocate(_array, _capacity);
					_array = tmp;
					_capacity = n;
					_size = tmp_size;
				}
			}
			void resize(size_type n, value_type val = value_type()) {
				while (_size < n) {
					pop_back();
				}
				if (n > _capacity) {
					reserve(n);
				}
				while (_size < n) {
					push_back(val);
				}
			}
		
			// ================================================================

			// modifiers ======================================================
			void assign()

			void push_back() {
				if (_size == _capacity) {
					reserve(_capacity * 2);
				}
				_allocator.construct(&_array[_size], value_type());
				++_size;
			}
			void pop_back() {
				if (_size > 0) {
					_allocator.destroy(&_array[_size - 1]);
					--_size;
				}
			}

			void insert()

			void erase()

			void swap()

			void clear() {
				while (_size > 0) {
					pop_back();
				}
			}
			// ================================================================


	};
} // namespace ft


#endif // __VECTOR_H__