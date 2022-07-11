#ifndef __REVERSEITERATOR_H__
#define __REVERSEITERATOR_H__

#include "iterator.hpp"

namespace ft {

	template<typename Iterator>
	class reverse_iterator {

		public:
			typedef	Iterator	iterator_type;
			typedef	typename	ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef	typename	ft::iterator_traits<Iterator>::value_type			value_type;
			typedef	typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef	typename	ft::iterator_traits<Iterator>::pointer				pointer;
			typedef	typename	ft::iterator_traits<Iterator>::reference			reference;

		private:
			iterator_type	_iter;

		public:
		
			reverse_iterator() : _iter() {};
			template <typename U>
			reverse_iterator(const reverse_iterator<U>& ref) : _iter(ref.base()) {}
			explicit reverse_iterator(iterator_type iter) : _iter(iter) {} /* to prevent  -> reverse_iterator rit `=` it */
			virtual ~reverse_iterator() {}

			template <typename U>
			reverse_iterator& operator=(const reverse_iterator<U>& ref)
			{
				_iter = ref.base();
				return (*this);
			}

			iterator_type		base() const { return (_iter); }

			/* random_access_iterator */
			reverse_iterator&	operator+=(difference_type	n)			{ _iter -= n; return (*this); }
			reverse_iterator	operator+(difference_type	n) const	{ reverse_iterator itr = (*this); return (itr += n); }
			reverse_iterator&	operator-=(difference_type	n)			{ _iter += n; return (*this); }
			reverse_iterator	operator-(difference_type	n) const	{ reverse_iterator itr = (*this); return (itr -= n); }
			reference			operator[](difference_type	n)			{ return *(_iter - n - 1); }
			const reference		operator[](difference_type	n) const	{ return *(_iter - n - 1); }
			difference_type		operator-(reverse_iterator	other)		{ return (other._iter - _iter); }

			reverse_iterator&	operator--()		{ ++_iter; return (*this); }
			reverse_iterator	operator--(int)		{ reverse_iterator	itr = (*this); ++_iter; return (itr); }
			reverse_iterator&	operator++()		{ --_iter; return (*this); }
			reverse_iterator	operator++(int)		{ reverse_iterator	itr = (*this); --_iter; return (itr); }
			reference			operator*()			{ iterator_type tmp = _iter; return *(--tmp); }
			const reference		operator*()	const	{ iterator_type tmp = _iter; return *(--tmp); }
			pointer				operator->() const	{ iterator_type tmp = _iter; return &(*(--tmp)); }



};

template <typename iter>
	bool operator ==	(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (lhs.base() == rhs.base()); }
template <typename iter>
	bool operator !=	(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return !(lhs == rhs); }
template <typename iter>
	bool operator <		(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (lhs.base() > rhs.base()); }
template <typename iter>
	bool operator <=	(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return !(lhs > rhs); }
template <typename iter>
	bool operator >		(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (rhs < lhs); }
template <typename iter>
	bool operator >=	(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return !(lhs < rhs); }

template <typename iter1, typename iter2>
	bool operator ==	(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return (lhs.base() == rhs.base()); }
template <typename iter1, typename iter2>
	bool operator !=	(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return !(lhs == rhs); }
template <typename iter1, typename iter2>
	bool operator <		(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return (lhs.base() > rhs.base()); }
template <typename iter1, typename iter2>
	bool operator <=	(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return !(lhs > rhs); }
template <typename iter1, typename iter2>
	bool operator >		(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return (rhs < lhs); }
template <typename iter1, typename iter2>
	bool operator >=	(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return !(lhs < rhs); }

template <typename iter>
	reverse_iterator<iter> operator +(typename reverse_iterator<iter>::difference_type n, const reverse_iterator<iter>& rev_it) { return (rev_it + n); }
template <typename iter>
	typename reverse_iterator<iter>::difference_type
	operator -	(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (rhs - lhs); }

}

#endif // __REVERSEITERATOR_H__
