#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "utils.hpp"
#include "red_black_tree.hpp"
#include <memory>

namespace ft {

	template <	typename Key,
				typename T,
				typename Compare = ft::less<Key>,
				typename Alloc = std::allocator<ft::pair<const Key, T> >
				>
	class map {

		public:
		// typedefs =========================================================================================

			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef size_t											size_type;
			typedef ptrdiff_t										difference_type;
		
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename ft::tree_iterator<value_type>			iterator;
			typedef typename ft::tree_const_iterator<value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		
		// ==================================================================================================

		// value_compare ====================================================================================

			class value_compare : public ft::binary_function<value_type, value_type, bool> {
				friend class map;
				protected:
					Compare _comp;
					value_compare(Compare const& comp) : _comp(comp) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const value_type& x, const value_type& y) const {
						return _comp(x.first, y.first);
					}
			};

		// ==================================================================================================

		// member variables =================================================================================

		private:
			key_compare														_comp;
			allocator_type													_alloc;
			ft::red_black_tree<value_type, value_compare, allocator_type>	_tree;

		// ==================================================================================================

		public:
		// constructors =====================================================================================

			//default
			explicit map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(_comp), _alloc)
			{}

			// range
			template <typename InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(_comp), _alloc)
			{
				this->insert(first, last);
			}

			//copy
			map(const map& other)
			: _comp(other._comp), _alloc(other._alloc), _tree(other._tree)
			{}

			map& operator=(const map& other) {
				if (this == &other)
					return *this;
				_tree = other._tree;
				return *this;
			}

		// ==================================================================================================

		// iterators ========================================================================================

			iterator begin() { return _tree.begin(); }
			iterator end() { return _tree.end(); }
			const_iterator begin() const { return _tree.begin(); }
			const_iterator end() const { return _tree.end(); }
			reverse_iterator rbegin() { return _tree.rbegin(); }
			reverse_iterator rend() { return _tree.rend(); }
			const_reverse_iterator rbegin() const { return _tree.rbegin(); }
			const_reverse_iterator rend() const { return _tree.rend(); }

		// member functions =================================================================================

			// capacity
			bool empty() const {
				return _tree.empty();
			}

			size_type size() const {
				return _tree.size();
			}

			size_type max_size() const {
				return _tree.max_size();
			}

			// element access
			mapped_type& operator[](const key_type& key) {
				return (*((this->insert(ft::make_pair(key, mapped_type()))).first)).second;
			}

			//modifiers

			//	insert
			pair<iterator, bool> insert(const value_type& value) {
				return _tree.insert(value);
			}

			iterator insert(iterator position, const value_type& value) {
				return _tree.insert(position, value);
			}

			template <typename InputIterator>
			void insert(InputIterator first, InputIterator last) {
				_tree.insert(first, last);
			}

			//	erase



			//	swap
			void swap(map& x) {
				_tree.swap(x._tree);
			}

			//	clear
			void clear() {
				_tree.clear();
			}

			// Observers
			key_compare key_comp() const {
				return key_compare();
			}

			value_compare value_comp() const {
				return value_compare(key_compare());
			}

			// Operations
			iterator find(const key_type& key) {
				return _tree.find(ft::make_pair(key, mapped_type()));
			}

			const_iterator find(const key_type& key) const {
				return _tree.find(ft::make_pair(key, mapped_type()));
			}

			size_type count(const key_type& key) const {
				return _tree.count(ft::make_pair(key, mapped_type()));
			}

			iterator lower_bound(const key_type& key) {
				iterator it1 = this->begin();
				iterator it2 = this->end();
				while (it1 != it2) {
					if (_comp(it1->first, key) == false)
						break;
					++it1;
				}
				return it1;
			}

			const_iterator lower_bound(const key_type& key) const {
				const_iterator it1 = this->begin();
				const_iterator it2 = this->end();
				while (it1 != it2) {
					if (_comp(it1->first, key) == false)
						break;
					++it1;
				}
				return it1;
			}

			iterator upper_bound(const key_type& key) {
				iterator it1 = this->begin();
				iterator it2 = this->end();
				while (it1 != it2) {
					if (_comp(key, it1->first) == true)
						break;
					++it1;
				}
				return it1;
			}

			const_iterator upper_bound(const key_type& key) const {
				const_iterator it1 = this->begin();
				const_iterator it2 = this->end();
				while (it1 != it2) {
					if (_comp(key, it1->first) == true)
						break;
					++it1;
				}
				return it1;
			}

			pair<iterator, iterator> equal_range(const key_type& key) {
				iterator it1 = this->lower_bound(key);
				iterator it2 = this->upper_bound(key);
				return ft::make_pair(it1, it2);
			}

			pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
				const_iterator it1 = this->lower_bound(key);
				const_iterator it2 = this->upper_bound(key);
				return ft::make_pair(it1, it2);
			}

			allocator_type get_allocator() const {
				return allocator_type();
			}

		// ==================================================================================================
	};

}; // namespace ft

#endif // __MAP_H__
