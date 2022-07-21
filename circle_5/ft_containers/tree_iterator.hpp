#ifndef __TREE_ITERATOR_HPP__
#define __TREE_ITERATOR_HPP__

#include "utils.hpp"
#include "iterator.hpp"
#include "red_black_tree_node.hpp"

namespace ft {

// tree iterator ================================================================================================

	template <typename T>
	class tree_const_iterator;

	template <typename T>
	class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
		
		private:
			typedef	ft::rb_tree_node<T>				node;
			typedef	ft::rb_tree_node<T>*			node_ptr;
		
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

			tree_iterator& operator++() {
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

			tree_iterator& operator--() {
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

			reference operator*() const { return (_node->value); }
			
			pointer operator->() const { return (&(_node->value)); }
			
			tree_iterator operator++(int) {
				tree_iterator tmp(*this);
				++(*this);
				return (tmp);
			}

			tree_iterator operator--(int) {
				tree_iterator tmp(*this);
				--(*this);
				return (tmp);
			}

			bool operator==(const tree_iterator& ref) const { return (_node == ref._node); }

			bool operator!=(const tree_iterator& ref) const { return (_node != ref._node); }

			bool operator==(const tree_const_iterator<T>& ref) const { return (_node == ref._node); }
			
			bool operator!=(const tree_const_iterator<T>& ref) const { return (_node != ref._node); }

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

// ==============================================================================================================

// tree const iterator ==========================================================================================

	template <typename T>
	class tree_const_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
		
		private:
			typedef	ft::rb_tree_node<T>				node;
			typedef	ft::rb_tree_node<T>*			node_ptr;
		
		public:
			typedef	bidirectional_iterator_tag		iterator_category;
			typedef	T								value_type;
			typedef	const T*						pointer;
			typedef	const T&						reference;
			typedef	std::ptrdiff_t					difference_type;

		private:
			node_ptr								_node;
		
		public:
			tree_const_iterator()
				: _node(ft_nullptr) {}
			
			tree_const_iterator(const tree_const_iterator& ref)
				: _node(ref._node) {}

			tree_const_iterator(const tree_iterator<T>& ref)
				: _node(ref.base()) {}

			tree_const_iterator(node_ptr node)
				: _node(node) {}
			
			virtual ~tree_const_iterator() {}
			
			tree_const_iterator& operator=(const tree_const_iterator& ref) {
				if (this != &ref)
					_node = ref._node;
				return (*this);
			}

			tree_const_iterator& operator=(const tree_iterator<T>& ref) {
				if (this != &ref)
					_node = ref.base();
				return (*this);
			}
			
			node_ptr base() const { return (_node); }
			
			tree_const_iterator& operator++() {
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

			tree_const_iterator& operator--() {
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

			tree_const_iterator operator++(int) {
				tree_const_iterator tmp(*this);
				++(*this);
				return (tmp);
			}

			tree_const_iterator operator--(int) {
				tree_const_iterator tmp(*this);
				--(*this);
				return (tmp);
			}

			reference operator*() const { return (_node->value); }
			pointer operator->() const { return (&(_node->value)); }

			bool operator==(const tree_const_iterator& ref) const { return (_node == ref._node); }
			bool operator!=(const tree_const_iterator& ref) const { return (_node != ref._node); }
			bool operator==(const tree_iterator<T>& ref) const { return (_node == ref.base()); }
			bool operator!=(const tree_iterator<T>& ref) const { return (_node != ref.base()); }

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

// ==============================================================================================================

}; // namespace ft


#endif // __TREE_ITERATOR_HPP__