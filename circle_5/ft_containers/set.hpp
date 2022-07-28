#ifndef __SET_HPP__
#define __SET_HPP__

#include "utils.hpp"
#include "red_black_tree.hpp"
#include "tree_iterator.hpp"
#include "reverse_iterator.hpp"
#include <memory>

namespace ft {

	template <class Key, class Compare = ft::less<Key>, class Alloc = std::allocator<Key> >
	class set {

	// typedefs =========================================================================================

		public:
			typedef Key												key_type;
			typedef Key												value_type;
			typedef size_t											size_type;
			typedef ptrdiff_t										difference_type;
			typedef Compare											key_compare;
			typedef Compare											value_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename ft::tree_iterator<value_type>			iterator;
			typedef typename ft::tree_const_iterator<value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> 	const_reverse_iterator;

	// ==================================================================================================

	// member variables =================================================================================

		private:
			key_compare									_comp;
			allocator_type								_alloc;
			ft::red_black_tree<value_type, key_compare>	_tree;

	// ==================================================================================================

	// constructors =====================================================================================

		public:
			


	// ==================================================================================================

	// Iterators ========================================================================================

		public:


	// ==================================================================================================

	// Capacity =========================================================================================

		public:

	
	// ==================================================================================================

	// Modifiers ========================================================================================

		public:


	// ==================================================================================================

	// Observers ========================================================================================

		public:
			
			key_compare key_comp() const {
				return _comp;
			}
			
			value_compare value_comp() const {
				return _comp;
			}

	// ==================================================================================================

	// Operations =======================================================================================

		public:


			allocator_type get_allocator () const {
				return allocator_type();
			}
	};

	template <class Key, class Compare, class Alloc>
	void swap(ft::set<Key, Compare, Alloc>& lhs, ft::set<Key, Compare, Alloc>& rhs) {
		lhs.swap(rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator==(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class Compare, class Alloc>
	bool operator!=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return rhs < lhs;
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs) {
		return !(lhs < rhs);
	}

} // namespace ft


#endif // __SET_H__