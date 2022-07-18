#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "iterator.hpp"

namespace ft {

// enable_if ==============================================================
	
	template <bool cond, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

// ========================================================================

// is_input_iter ==========================================================

	template <bool is_valid, typename T>
	struct is_input_iter_base {
		typedef T type;
		const static bool value = is_valid;
	};

	template <typename iter>
	struct is_input_iter : public is_input_iter_base<false, iter> {};
	
	template<>
	struct is_input_iter<ft::random_access_iterator_tag>
		: public is_input_iter_base<true, ft::random_access_iterator_tag> {};
	
	template<>
	struct is_input_iter<ft::bidirectional_iterator_tag>
		: public is_input_iter_base<true, ft::bidirectional_iterator_tag> {};
	
	template<>
	struct is_input_iter<ft::forward_iterator_tag>
		: public is_input_iter_base<true, ft::forward_iterator_tag> {};

	template <>
	struct is_input_iter<ft::input_iterator_tag>
		: public is_input_iter_base<true, ft::input_iterator_tag> {};

// ========================================================================

// is_integral ============================================================

	template <bool is_integral, typename T>
	struct is_integral_base {
		typedef T type;
		const static bool value = is_integral;
	};

	template <typename>
	struct is_integral : public is_integral_base<false, void> {};

	template <>
	struct is_integral<bool> : public is_integral_base<true, bool> {};

	template <>
	struct is_integral<char> : public is_integral_base<true, char> {}; 

	template <>
	struct is_integral<signed char> : public is_integral_base<true, signed char> {};

	template <>
	struct is_integral<unsigned char> : public is_integral_base<true, unsigned char> {};

	template <>
	struct is_integral<short> : public is_integral_base<true, short> {};

	template <>
	struct is_integral<unsigned short> : public is_integral_base<true, unsigned short> {};

	template <>
	struct is_integral<int> : public is_integral_base<true, int> {};

	template <>
	struct is_integral<unsigned int> : public is_integral_base<true, unsigned int> {};

	template <>
	struct is_integral<long> : public is_integral_base<true, long> {};

	template <>
	struct is_integral<unsigned long> : public is_integral_base<true, unsigned long> {};

	template <>
	struct is_integral<long long> : public is_integral_base<true, long long> {};

	template <>
	struct is_integral<unsigned long long> : public is_integral_base<true, unsigned long long> {};

	template <>
	struct is_integral<wchar_t> : public is_integral_base<true, wchar_t> {};

	template <>
	struct is_integral<char16_t> : public is_integral_base<true, char16_t> {};

	template <>
	struct is_integral<char32_t> : public is_integral_base<true, char32_t> {};

// ========================================================================

// distance ===============================================================

	template <typename InputIt>
	typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last) {
		typename ft::iterator_traits<InputIt>::difference_type n = 0;
		while (first != last) {
			++first;
			++n;
		}
		return n;
	}

// ========================================================================

// lexicographical compare ================================================

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1,*first2))
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

// ========================================================================

// equal ==================================================================

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1!=last1) {
			if (!pred(*first1,*first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

// ========================================================================

// Pair =======================================================================

	template <class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;

		pair() : first(), second() {}
		
		template<class U, class V>
		pair(const pair<U,V>& p) : first(p.first), second(p.second) {}

		pair(const first_type& a, const second_type& b) : first(a), second(b) {}

		pair& operator=(const pair& other) {
			if (this != &other) {
				this->first = other.first;
				this->second = other.second;
			}
			return *this;
		}
	};

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) { return (pair<T1,T2>(x,y)); }

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs < lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); }

// ============================================================================

// ft_nullptr =================================================================

	static class nullptr_t {
		
		public:
			template <class T>
			operator T*() const {
				return 0;
			}

			template <class C, class T>
			operator T C::*() const {
				return 0;
			}

		private:
			void operator&() const;

	} ft_nullptr = {};

// ============================================================================

} // namespace ft

#endif // __UTILS_HPP__