#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

#include "utils.hpp"
#include "tree_iterator.hpp"
#include "reverse_iterator.hpp"
#include "red_black_tree_node.hpp"
#include <memory>

namespace ft {

// Red-Black Tree =============================================================
	template <typename T, typename Compare, typename Alloc = std::allocator<T> >
	class red_black_tree {

	// typedefs ===============================================================
	
		private:
			typedef ft::rb_tree_node<T>									node_type;
			typedef ft::rb_tree_node<T>*								node_ptr;
			typedef typename Alloc::template rebind<node_type>::other	node_alloc_type;

		public:
			typedef T													value_type;
			typedef Compare												value_compare;
			typedef Alloc												allocator_type;
			typedef size_t												size_type;
			typedef ptrdiff_t											difference_type;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef ft::tree_iterator<value_type>						iterator;
			typedef ft::tree_const_iterator<value_type>					const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

	// ==========================================================================


	// private members ==========================================================
		
		private:
			value_compare	_comp;
			allocator_type	_alloc;
			node_alloc_type	_node_alloc;
			node_ptr		_meta_node;
			size_type		_size;

	// ==========================================================================


	// constructors =============================================================

		public:

			red_black_tree(value_compare const& comp, allocator_type const& alloc,
							node_alloc_type const& node_alloc = node_alloc_type())
			: _comp(comp),
			_alloc(alloc),
			_node_alloc(node_alloc),
			_meta_node(ft_nullptr),
			_size(0) {
				_meta_node = _node_alloc.allocate(1);
				_node_alloc.construct(_meta_node, node_type());
			}

	// ==========================================================================

	// iterators ================================================================

		iterator				begin() { return iterator(min_value_node(_meta_node)); }

		const_iterator			begin() const { return const_iterator(min_value_node(_meta_node)); }

		iterator				end() { return iterator(_meta_node); }

		const_iterator			end() const { return const_iterator(_meta_node); }

		reverse_iterator		rbegin() { return reverse_iterator(end()); }

		const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }

		reverse_iterator		rend() { return reverse_iterator(begin()); }

		const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

	// ==========================================================================


	// member functions =========================================================

		public:

			// capacity
			bool		empty() const { return _size == 0; }
			size_type	size() const { return _size; }
			size_type	max_size() const { return _node_alloc.max_size(); }

			// modifier
			pair<iterator, bool> insert(const value_type& value) {
				return insert_value(value);
			}


			// Todo :: position 부터 삽입하도록 변경.
			iterator insert(iterator position, const value_type& value) {
				(void) position;
				return insert_value(value).first;
			}


			// Todo :: enable if 추가하기
			template <typename InputIterator>
			void insert(InputIterator first, InputIterator last) {
				for (; first != last; ++first) {
					insert(*first);
				}
			}

	// ==========================================================================

	// private functions ========================================================

		private:

			node_ptr get_root() const {
				return _meta_node->_left;
			}

			void set_root(node_ptr node) {
				_meta_node->_left = node;
				_meta_node->_right = node;
				if (node != ft_nullptr)
					node->_parent = _meta_node;
			}

			void delete_tree(node_ptr node) {
				if (node == ft_nullptr)
					return;
				delete_tree(node->_left);
				delete_tree(node->_right);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			void rotate_left(node_ptr node) {
				node_ptr right_child = node->_right;

				if (right_child == ft_nullptr)
					return;
				node->_right = right_child->_left;
				if (node->_right != ft_nullptr)
					node->_right->_parent = node;
				right_child->_parent = node->_parent;
				if (get_parent(node) == ft_nullptr)
					set_root(right_child);
				else if (node == get_parent(node)->_left)
					get_parent(node)->_left = right_child;
				else
					get_parent(node)->_right = right_child;
				right_child->_left = node;
				node->_parent = right_child;
			}

			void rotate_right(node_ptr node) {
				node_ptr left_child = node->_left;

				if (left_child == ft_nullptr)
					return;
				node->_left = left_child->_right;
				if (node->_left != ft_nullptr)
					node->_left->_parent = node;
				left_child->_parent = node->_parent;
				if (get_parent(node) == ft_nullptr)
					set_root(left_child);
				else if (node == get_parent(node)->_left)
					get_parent(node)->_left = left_child;
				else
					get_parent(node)->_right = left_child;
				left_child->_right = node;
				node->_parent = left_child;
			}

			node_ptr min_value_node(node_ptr node) const {
				if (node == ft_nullptr)
					return node;
				while (node->_left != ft_nullptr)
					node = node->_left;
				return node;
			}

			node_ptr max_value_node(node_ptr node) const {
				if (node == ft_nullptr)
					return node;
				while (node->_right != ft_nullptr)
					node = node->_right;
				return node;
			}

			node_ptr get_parent(node_ptr node) const {
				if (node == ft_nullptr)
					return node;
				if (node == _meta_node)
					return ft_nullptr;
				return node->_parent;
			}

			node_ptr get_grand_parent(node_ptr node) const {
				node_ptr pr = get_parent(node);
				if (pr == ft_nullptr)
					return ft_nullptr;
				return get_parent(pr);
			}

			node_ptr get_sibling(node_ptr node) const {
				node_ptr pr = get_parent(node);
				if (pr == ft_nullptr)
					return ft_nullptr;
				if (node == pr->_left)
					return pr->_right;
				else
					return pr->_left;
			}

			node_ptr get_uncle(node_ptr node) const {
				node_ptr pr = get_parent(node);
				if (pr == ft_nullptr)
					return ft_nullptr;
				return get_sibling(pr);
			}

			Color get_color(node_ptr node) const {
				if (node == ft_nullptr)
					return BLACK;
				return node->_color;
			}

			void set_color(node_ptr node, Color color) {
				if (node == ft_nullptr)
					return;
				node->_color = color;
			}

			pair<iterator, bool> insert_node(node_ptr node) {
				node_ptr tmp = get_root();
				node_ptr parent;

				if (tmp == ft_nullptr) {
					set_root(node);
					return ft::make_pair(iterator(node), true);
				}
				while (tmp) {
					if (_comp(node->_value, tmp->_value)) {
						parent = tmp;
						tmp = tmp->_left;
					}
					else if (_comp(tmp->_value, node->_value)) {
						parent = tmp;
						tmp = tmp->_right;
					}
					else
						return ft::make_pair(iterator(tmp), false);
				}
				if (_comp(parent->_value, node->_value)) {
					parent->_right = node;
					node->_parent = parent;
				} else {
					parent->_left = node;
					node->_parent = parent;
				}
				return ft::make_pair(iterator(node), true);
			}

			pair<iterator, bool> insert_value(const value_type& val) {
				node_ptr node = _node_alloc.allocate(1);
			
				_node_alloc.construct(node, node_type(val));
				pair<iterator, bool> ret = insert_node(node);
				if (ret.second == true) {
					_size++;
					insert_fixup(node);
				} else {
					_node_alloc.destroy(node);
					_node_alloc.deallocate(node, 1);
				}
				return ret;
			}

			void insert_fixup(node_ptr node) {
				node_ptr parent;
				node_ptr grand_parent;

				// if color of node itself and its parent is RED -> correction required.
				while (node != get_root() && get_color(node) == RED && get_color(get_parent(node)) == RED) {
					parent = get_parent(node);
					grand_parent = get_grand_parent(node);
					if (grand_parent == ft_nullptr)
						break;
					node_ptr uncle = get_uncle(node);
					if (get_color(uncle) == RED) {
						insert_case1(node);
					} else if (parent == grand_parent->_left) {
						if (node == parent->_right) {
							insert_case2(node, parent);
						}
						insert_case3(node, parent, grand_parent);
					} else if (parent == grand_parent->_right) {
						if (node == parent->_left) {
							insert_case2(node, parent);
						}
						insert_case3(node, parent, grand_parent);
					}
				}
				set_color(get_root(), BLACK);
			}

			/*
				rbt insert case 1 : uncle of the node is RED.
				->	Change the color of parent and uncle to BLACK,
					then change the color of grand parent to RED.
					Double RED problem could reoccur at grand parent level,
					hence it should be re-checked from grand parent.
			*/ 
			void insert_case1(node_ptr& node) {
				set_color(get_parent(node), BLACK);
				set_color(get_uncle(node), BLACK);
				set_color(get_grand_parent(node), RED);
				node = get_grand_parent(node);
			}

			/*
				rbt insert case 2 :
			*/
			void insert_case2(node_ptr& node, node_ptr& parent) {
				if (parent == get_grand_parent(node)->_left) {
					rotate_left(parent);
					node = parent;
					parent = get_parent(node);
				}
				if (parent == get_grand_parent(node)->_right) {
					rotate_right(parent);
					node = parent;
					parent = get_parent(node);
				}
			}

			/*
				rbt insert case 3 :
			*/
			void insert_case3(node_ptr& node, node_ptr parent, node_ptr g_parent) {
				if (parent == g_parent->_left) {
					rotate_right(g_parent);
				}
				if (parent == g_parent->_right) {
					rotate_left(g_parent);
				}
				std::swap(parent->_color, g_parent->_color);
				node = parent;
			}

	// ==========================================================================

	};


// ============================================================================

} // namespace ft

#endif // __RED_BLACK_TREE_HPP__