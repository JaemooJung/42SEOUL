#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <memory>
#include "RandomAccessIterator.hpp"
#include "ReverseIterator.hpp"
#include <cstddef>


namespace ft {

	template <typename T, typename Allocator = std::allocator<T> >
	class vector {
		public:
			typedef T														value_type;
			typedef Allocator												allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename allocator_type::size_type						size_type;
			typedef ft::random_access_iterator<value_type>					iterator;
			typedef ft::random_access_iterator<const value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

		protected:
			pointer			_start;
			pointer			_end;
			pointer			_capa_end;
			allocator_type	_alloc;

		public:
		// constructors =======================================================
			explicit vector(const allocator_type& alloc = allocator_type())
				: _start(nullptr),
				_end(nullptr),
				_capa_end(nullptr),
				_alloc(alloc)
			{}

			explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
				: _start(nullptr),
				_end(nullptr),
				_capa_end(nullptr),
				_alloc(alloc)
			{
				_start = _alloc.allocate(n);
				_end = _start;
				_capa_end = _start + n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_end++, value);
			}

			~vector() {} //TODO: destructor

		// ====================================================================

		// iterators ==========================================================
			iterator				begin() { return (_start); }
			const_iterator			begin() const { return (_start); }
			iterator				end() { return (_end); }
			const_iterator			end() const { return (_end); }
			reverse_iterator		rbegin() { return (reverse_iterator(_end)); }
			const_reverse_iterator	rbegin() const { return (reverse_iterator(_end)); }
			reverse_iterator		rend() { return (reverse_iterator(_start)); }
			const_reverse_iterator	rend() const { return (reverse_iterator(_start)); }
		// ====================================================================

		// capacity ==========================================================
			bool		empty() const { return (_start == _end); }
			size_type	size() const { return (_end - _start); }
			size_type	max_size() const { return (_alloc.max_size()); }
			size_type	capacity() const { return (_capa_end - _start); }
			void		reserve(size_type n) {
				if (n > this->max_size())
					throw std::length_error("ft::vector::reserve: n > max_size()");
				if (n > this->capacity()) {
					pointer prev = _start;
					pointer prev_end = _end;
					size_type prev_capa = this->capacity();
					size_type prev_size = this->size();
					_start = _alloc.allocate(n);
					_end = _start;
					_capa_end = _start + n;
					while (prev != prev_end) {
						_alloc.construct(_end, *prev);
						_alloc.destroy(prev);
						++_end;
						++prev;
					}
					_alloc.deallocate(prev - prev_size, prev_capa);
				}
			}
		// ====================================================================

		// modifiers ==========================================================
			iterator insert(iterator position, const value_type& val) {
				size_type	pos = position - _start;
				size_type	rpos = _end - position;

				if (this->size() == 0)
					this->reserve(1);
				else if (_end == _capa_end)
					this->reserve(2 * this->size());
				for (size_type i = 0; i < rpos; i++) {
					_alloc.construct(_end - i, *(_end - i - 1));
					_alloc.destroy(_end - i - 1);
				}
				_alloc.construct(_start + pos, val);
				_end++;
				return (iterator(_start + pos));
			}

			void push_back(const value_type& val) {
				if (_end == _capa_end) {
					size_type size = this->size();
					if (size == 0)
						this->reserve(1);
					else
						this->reserve(2 * size);
				}
				_alloc.construct(_end, val);
				_end++;
			}

			void pop_back() {
				if (this->size() != 0) {
					_alloc.destroy(_end - 1);
					_end--;
				}
			}

			void insert(iterator position, size_type n, const value_type& val) {
				if (position > this->end() || position < this->begin())
					return;

				size_type	pos = position - _start;
				size_type	next_size = this->size() + n;
				size_type	prev_capa = this->capacity();
				pointer		new_start = nullptr;

				if (this->max_size() < next_size)
					throw std::length_error("ft::vector::insert: max_size() < next_size()");
				if (this->capacity() * 2 < next_size) {
					new_start = _alloc.allocate(next_size);
					_capa_end = new_start + next_size;
				} else {
					new_start = _alloc.allocate(this->capacity() * 2);
					_capa_end = new_start + this->capacity() * 2;
				}
				for (size_type i = 0; i < pos; ++i)
					_alloc.construct(new_start + i, *(_start + i));
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(new_start + pos + i, val);
				for (size_type i = 0; i < this->size() - pos; ++i)
					_alloc.construct(new_start + pos + n + i, *(_start + pos + i));
				for (size_type i = 0; i < this->size(); ++i)
					_alloc.destroy(_start + i);
				_alloc.deallocate(_start, prev_capa);
				_start = new_start;
				_end = _start + next_size;
			}
	};
} // namespace ft


#endif // __VECTOR_H__