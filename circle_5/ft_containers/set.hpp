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
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename ft::tree_const_iterator<value_type>	iterator;
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
			
			explicit set(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(), alloc)
			{}
		
			template <class InputIterator>
			set (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(), alloc) {
				_tree.insert(first, last);
			}

			set(const set& other)
			: _comp(other._comp), _alloc(other._alloc), _tree(other._tree)
			{}

			set& operator=(const set& other) {
				if (this != &other) {
					_tree = other._tree;
				}
				return *this;
			}

			~set() {}

	// ==================================================================================================

	// Iterators ========================================================================================

		public:

			iterator begin() {
				return _tree.begin();
			}

			iterator end() {
				return _tree.end();
			}

			const_iterator begin() const {
				return _tree.begin();
			}

			const_iterator end() const {
				return _tree.end();
			}

			reverse_iterator rbegin() {
				return _tree.rbegin();
			}

			reverse_iterator rend() {
				return _tree.rend();
			}

			const_reverse_iterator rbegin() const {
				return _tree.rbegin();
			}

			const_reverse_iterator rend() const {
				return _tree.rend();
			}

	// ==================================================================================================

	// Capacity =========================================================================================

		public:
			
			bool empty() const {
				return _tree.empty();
			}

			size_type size() const {
				return _tree.size();
			}

			size_type max_size() const {
				return _tree.max_size();
			}
	
	// ==================================================================================================

	// Modifiers ========================================================================================

		public:
			
			pair<iterator, bool> insert(const value_type& value) {
				return _tree.insert(value);
			}

			iterator insert(iterator position, const value_type& value) {
				(void)position;
				return _tree.insert(value).first;
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				_tree.insert(first, last);
			}

			void erase(iterator position) {
				_tree.erase(position);
			}

			size_type erase(const key_type& key) {
				return _tree.erase(key);
			}

			void erase(iterator first, iterator last) {
				_tree.erase(first, last);
			}

			void swap(set& other) {
				_tree.swap(other._tree);
			}

			void clear() {
				_tree.clear();
			}

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
			
			iterator find(const key_type& key) {
				return _tree.find(key);
			}
			
			size_type count(const key_type& key) const {
				return _tree.count(key);
			}

			iterator lower_bound(const key_type& key) const {
				iterator it1 = this->begin();
				iterator it2 = this->end();

				while (it1 != it2) {
					if (_comp(*it1, key) == false)
						break;
					++it1;
				}
				return it1;
			}

			iterator upper_bound(const key_type& key) const {
				iterator it1 = this->begin();
				iterator it2 = this->end();

				while (it1 != it2) {
					if (_comp(key, *it1) == true)
						break;
					++it1;
				}
				return it1;
			}

			pair<iterator, iterator> equal_range(const value_type& value) const {
				return ft::make_pair(this->lower_bound(value), this->upper_bound(value));
			}

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