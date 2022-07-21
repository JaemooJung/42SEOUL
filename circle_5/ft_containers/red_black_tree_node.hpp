#ifndef __RED_BLACK_TREE_NODE_HPP__
#define __RED_BLACK_TREE_NODE_HPP__

namespace ft {

// Color for RB_tree nodes ====================================================

	enum Color {
		RED,
		BLACK
	};

// ============================================================================

// Red-Black Tree node ========================================================

	template <typename T>
	struct rb_tree_node {

		T					_value;
		rb_tree_node*		_parent;
		rb_tree_node*		_left;
		rb_tree_node*		_right;
		Color				_color;

		rb_tree_node()
			: _value(),
			_parent(ft_nullptr),
			_left(ft_nullptr),
			_right(ft_nullptr),
			_color(RED) {}

		rb_tree_node(const T& value)
			: _value(value),
			_parent(ft_nullptr),
			_left(ft_nullptr),
			_right(ft_nullptr),
			_color(RED) {}

		rb_tree_node(const rb_tree_node& ref)
			: _value(ref._value),
			_parent(ref._parent),
			_left(ref._left),
			_right(ref._right),
			_color(ref._color) {}
		
		virtual ~rb_tree_node() {}
		
		rb_tree_node&	operator=(const rb_tree_node& ref) {
			if (this != &ref) {
				this->_value = ref._value;
				this->_parent = ref._parent;
				this->_left = ref._left;
				this->_right = ref._right;
				this->_color = ref._color;
			}
			return (*this);
		}

		bool	operator==(const rb_tree_node& ref) const {
			return (this->_value == ref._value);
		}

		bool	operator!=(const rb_tree_node& ref) const {
			return (this->_value != ref._value);
		}

	};

	template <class T1, class T2>
	bool operator==(const rb_tree_node<T1>& lhs, const rb_tree_node<T2>& rhs) {
		return lhs == rhs;
	}
	
	template <class T1, class T2>
	bool operator!=(const rb_tree_node<T1>& lhs, const rb_tree_node<T2>& rhs) {
		return lhs != rhs;
	}

// ============================================================================

};

#endif // __RED_BLACK_TREE_NODE_H__