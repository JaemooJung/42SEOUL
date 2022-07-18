#ifndef __TREE_ITERATOR_HPP__
#define __TREE_ITERATOR_HPP__

#include "utils.hpp"
#include "iterator.hpp"
#include "red_black_tree_node.hpp"

namespace ft {

	template <typename T>
	class tree_const_iterator;

	template <typename T>
	class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
		
		private:
			typedef	ft::rb_tree_node<T>			node;
			typedef	ft::rb_tree_node<T*>		node_ptr;
		
		public:
			typedef	bidirectional_iterator_tag		iterator_category;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;
			typedef	std::ptrdiff_t					difference_type;

		private:
			node_ptr								_node;

		public:
			tree_iterator()
				: _node(ft_nullptr) {}
			
			tree_iterator(const tree_iterator& ref)
				: _node(ref._node) {}

			tree_iterator(node_ptr node)
				: _node(node) {}
			
			~tree_iterator() {}

			tree_iterator& operator=(const tree_iterator& ref) {
				if (this != &ref)
					_node = ref._node;
				return (*this);
			}

			node_ptr base() const { return (_node); }

			reference operator++() {
				if (_node->right != ft_nullptr) {
					_node = min_value_node(_node->right);
					return (*this);
				}
				while (_node->parent != ft_nullptr && _node != _node->parent->left)
					_node = _node->parent;
				if (_node->parent != ft_nullptr)
					_node = _node->parent;
				return (*this);
			}

			reference operator--() {
				if (_node->left != ft_nullptr) {
					_node = max_value_node(_node->left);
					return (*this);
				}
				while (_node->parent != ft_nullptr && _node != _node->parent->right)
					_node = _node->parent;
				if (_node->parent != ft_nullptr)
					_node = _node->parent;
				else 
					_node = ft_nullptr;
				return (*this);
			}

		private:
			node_ptr min_value_node(node_ptr node) {
				if (node->left == ft_nullptr)
					return (node);
				return (min_value_node(node->left));
			}

			node_ptr max_value_node(node_ptr node) {
				if (node->right == ft_nullptr)
					return (node);
				return (max_value_node(node->right));
			}
	};
};


#endif // __TREE_ITERATOR_HPP__