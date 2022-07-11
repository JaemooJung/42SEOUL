#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <memory>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"
#include <cstddef>


namespace ft {

	template <typename T, typename Allocator = std::allocator<T> >
	class vector {

		public:
		// Member types ======================================================================================

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

		// ===================================================================================================

		protected:
		// Member variables ==================================================================================

			pointer			_start;
			pointer			_end;
			pointer			_capa_end;
			allocator_type	_alloc;

		// ===================================================================================================

		public:
		// Constructors ======================================================================================

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

			template <typename InputIterator>
			vector(InputIterator first, InputIterator last, 
					const allocator_type& alloc = allocator_type(), 
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
				: _start(nullptr),
				_end(nullptr),
				_capa_end(nullptr),
				_alloc(alloc)
			{
				insert(_start, first, last);
			}

			vector(const vector& other)
				: _start(nullptr),
				_end(nullptr),
				_capa_end(nullptr),
				_alloc(other._alloc)
			{
				insert(_start, other.begin(), other.end());
			}

			vector& operator=(const vector& other) {
				if (this != &other)
				{
					this->clear();
					insert(_start, other.begin(), other.end());
				}
				return (*this);
			}

			~vector() {
				this->clear();
				_alloc.deallocate(_start,this->capacity());
			}

		// ===================================================================================================

		// Iterators =========================================================================================

			iterator				begin() { return (_start); }
			const_iterator			begin() const { return (_start); }
			iterator				end() { return (_end); }
			const_iterator			end() const { return (_end); }
			reverse_iterator		rbegin() { return (reverse_iterator(_end)); }
			const_reverse_iterator	rbegin() const { return (reverse_iterator(_end)); }
			reverse_iterator		rend() { return (reverse_iterator(_start)); }
			const_reverse_iterator	rend() const { return (reverse_iterator(_start)); }

		// ===================================================================================================

		// Capacity ==========================================================================================

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

			void		resize(size_type n, value_type val = value_type()) {
				if (n > this->max_size())
					throw std::length_error("ft::vector::resize: n > max_size()");
				if (this->size() == n)
					return;
				if (this->size() > n) {
					while (_start + n != _end) {
						_alloc.destroy(--_end);
					}
				}
				if (this->size() < n) {
					this->insert(_end, n - this->size(), val);
				}
			}

		// ===================================================================================================

		// Element Access ====================================================================================

			reference			operator[](size_type n) { return (_start[n]); }
			const_reference		operator[](size_type n) const { return (_start[n]); }
			reference			at(size_type n) {
				if (n >= this->size())
					throw std::out_of_range("ft::vector::at: n >= this->size()");
				return ((*this)[n]);
			}
			const_reference		at(size_type n) const {
				if (n >= this->size())
					throw std::out_of_range("ft::vector::at: n >= this->size()");
				return ((*this)[n]);
			}
			reference			front() { return (*_start); }
			const_reference		front() const { return (*_start); }
			reference			back() { return (*(_end - 1)); }
			const_reference		back() const { return (*(_end - 1)); }

		// ===================================================================================================

		// modifiers ==========================================================================================

			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr) {
				this->clear();
				size_type size = ft::distance(first, last);
				if (size <= this->capacity()) {
					for (; &*first != &*last; ++first, ++_end)
						_alloc.construct(_end, *first);
				} else {
					this->reserve(size);
					for (; &*first != &*last; ++first, ++_end)
						_alloc.construct(_end, *first);
				}
			}

			void assign(size_type n, const value_type& val) {
				this->clear();
				if (this->capaciry() < n) {
					this->reserve(n);
					while (n--)
						_alloc.construct(_end++, val);
				} else {
					while (n--)
						_alloc.construct(_end++, val);
				}
			}

			iterator insert(iterator position, const value_type& val) {
				size_type	pos = &*position - _start;
				size_type	rpos = _end - &*position;

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

			void insert(iterator position, size_type n, const value_type& val) {
				if (position > this->end() || position < this->begin())
					return;
				
				size_type	next_size = this->size() + n;
				size_type	pos = &*position - _start;
				size_type	prev_capa = this->capacity();
				pointer		new_start = nullptr;

				if (this->max_size() < next_size)
					throw std::length_error("ft::vector::insert: max_size() < this->size() + n");
				if (this->capacity() < next_size) {
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
				_end = new_start + n + this->size();
				_start = new_start;
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = nullptr) {
				if (position > this->end() || position < this->begin())
					return;
				
				size_type	num = ft::distance(first, last);
				size_type	next_size = this->size() + num;
				size_type	prev_capa = this->capacity();
				size_type	pos = &*position - _start;
				pointer		new_start = nullptr;

				if (this->max_size() < next_size)
					throw std::length_error("ft::vector::insert: max_size() < this->size() + n");
				if (this->capacity() * 2 < next_size) {
					new_start = _alloc.allocate(next_size);
					_capa_end = new_start + next_size;
				} else {
					new_start = _alloc.allocate(this->capacity() * 2);
					_capa_end = new_start + this->capacity() * 2;
				}
				for (size_type i = 0; i < pos; ++i)
					_alloc.construct(new_start + i, *(_start + i));
				for (size_type i = 0; i < num; ++i)
					_alloc.construct(new_start + pos + i, *(&*first++));
				for (size_type i = 0; i < this->size() - pos; ++i)
					_alloc.construct(new_start + pos + num + i, *(_start + pos + i));
				for (size_type i = 0; i < this->size(); ++i)
					_alloc.destroy(_start + i);
				_alloc.deallocate(_start, prev_capa);
				_end = new_start + num + this->size();
				_start = new_start;
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

			iterator erase(iterator pos) {
				return (this->erase(pos, pos + 1));
			}

			iterator erase(iterator first, iterator last) {
				pointer	prev_first = &*first;

				for (; first != last; ++first)
					_alloc.destroy(&*first);
				for (int i = 0; &*last + i != _end; ++i)
				{
					_alloc.construct(prev_first + i, *(&*last + i));
					_alloc.destroy(&*last + i);
				}
				_end -= (&*first - prev_first);
				return prev_first;
			}

			void swap(vector& other) {
				if (this == &other)
					return;
				pointer			tmp_start = _start;
				pointer			tmp_end = _end;
				pointer			tmp_capa_end = _capa_end;
				allocator_type	tmp_alloc = _alloc;

				_start = other._start;
				_end = other._end;
				_capa_end = other._capa_end;
				_alloc = other._alloc;
				other._start = tmp_start;
				other._end = tmp_end;
				other._capa_end = tmp_capa_end;
				other._alloc = tmp_alloc;
			}

			void clear() {
				while (_start != _end) {
					_alloc.destroy(--_end);
				}
			}

		// ======================================================================================================================

		// Allocator ============================================================================================================

			allocator_type get_allocator() const {
				return allocator_type();
			}

		// ======================================================================================================================
	};

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}
	
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs) {
		lhs.swap(rhs);
	}
	
} // namespace ft


#endif // __VECTOR_H__