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
			typedef ft::rb_tree_node<T*>								node_ptr;
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

	// constructors =============================================================

		red_black_tree(value_compare const& comp, allocator_type const& alloc,
						node_alloc_type const& node_alloc = node_alloc_type())
		: _comp(comp),
		_alloc(alloc),
		_node_alloc(node_alloc),
		_size(0) {
		_meta_node = _node_alloc.allocate(1);
		_node_alloc.construct(_meta_node, node_type());
		}



	// ==========================================================================

	// private members ==========================================================
		
		private:
			value_compare	_comp;
			allocator_type	_alloc;
			node_alloc_type	_node_alloc;
			node_ptr		_meta_node;
			size_type		_size;

	// ==========================================================================

	// private functions ========================================================

		node_ptr get_root() const {
			return _meta_node->left;
		}

		void set_root(node_ptr node) {
			_meta_node->left = node;
			_meta_node->_right = node;
			if (node != ft_nullptr)
				node->parent = _meta_node;
		}

		void delete_tree(node_ptr node) {
			if (node == ft_nullptr)
				return;
			delete_tree(node->left);
			delete_tree(node->right);
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
		}

		void rotate_left(node_ptr node) {
			node_ptr right_child = node->right;

			if (right_child == ft_nullptr)
				return;
			node->right = right_child->left;
			if (node->right != ft_nullptr)
				node->right->parent = node;
			right_child->parent = node->parent;
			if (get_parent(node) == ft_nullptr)
				set_root(right_child);
			else if (node == get_parent(node)->left)
				get_parent(node)->left = right_child;
			else
				get_parent(node)->right = right_child;
			right_child->left = node;
			node->parent = right_child;
		}

		void rotate_right(node_ptr node) {
			node_ptr left_child = node->left;

			if (left_child == ft_nullptr)
				return;
			node->left = left_child->right;
			if (node->left != ft_nullptr)
				node->left->parent = node;
			left_child->parent = node->parent;
			if (get_parent(node) == ft_nullptr)
				set_root(left_child);
			else if (node == get_parent(node)->left)
				get_parent(node)->left = left_child;
			else
				get_parent(node)->right = left_child;
			left_child->right = node;
			node->parent = left_child;
		}

		node_ptr min_node(node_ptr node) const {
			if (node == ft_nullptr)
				return node;
			while (node->left != ft_nullptr)
				node = node->left;
			return node;
		}

		node_ptr max_node(node_ptr node) const {
			if (node == ft_nullptr)
				return node;
			while (node->right != ft_nullptr)
				node = node->right;
			return node;
		}

		node_ptr get_parent(node_ptr node) const {
			if (node == ft_nullptr)
				return node;
			if (node == _meta_node)
				return ft_nullptr;
			return node->parent;
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
			if (node == pr->left)
				return pr->right;
			else
				return pr->left;
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
				return make_pair(iterator(node), true);
			}
			while (tmp) {

			}
		}

		pair<iterator, bool> insert_value(const value_type& val) {
			
		}


	// ==========================================================================

	};


// ============================================================================

} // namespace ft

#endif // __RED_BLACK_TREE_HPP__