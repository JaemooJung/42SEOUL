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
			node_ptr		_head_node;
			size_type		_size;

	// ==========================================================================


	// constructors =============================================================

		public:

			red_black_tree(value_compare const& comp, allocator_type const& alloc,
							node_alloc_type const& node_alloc = node_alloc_type())
			: _comp(comp),
			_alloc(alloc),
			_node_alloc(node_alloc),
			_head_node(ft_nullptr),
			_size(0) {
				_head_node = _node_alloc.allocate(1);
				_node_alloc.construct(_head_node, node_type());
			}

			red_black_tree(const red_black_tree &ref)
			: _comp(ref._comp),
			_alloc(ref._alloc),
			_node_alloc(ref._node_alloc),
			_head_node(ft_nullptr),
			_size(0) {
				_head_node = _node_alloc.allocate(1);
				_node_alloc.construct(_head_node, node_type());
				if (ref.get_root() != ft_nullptr) {
					copy_tree(ref.get_root());
				}
			}

			red_black_tree& operator=(const red_black_tree &ref) {
				if (this == &ref) {
					return *this;
				}
				this->clear();
				_comp = ref._comp;
				_alloc = ref._alloc;
				_node_alloc = ref._node_alloc;
				copy_tree(ref.get_root());
				_size = ref._size;
				return *this;
			}

			virtual ~red_black_tree() {
				this->clear();
				_node_alloc.destroy(_head_node);
				_node_alloc.deallocate(_head_node, 1);
			}

	// ==========================================================================

	// iterators ================================================================

			iterator				begin() { return iterator(min_value_node(_head_node)); }

			const_iterator			begin() const { return const_iterator(min_value_node(_head_node)); }

			iterator				end() { return iterator(_head_node); }

			const_iterator			end() const { return const_iterator(_head_node); }

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

			//	insert
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

			//	erase
			void erase(iterator position) {
				delete_value(*position);
			}

			size_type erase(const value_type& k) {
				return delete_value(k);
			}

			void erase(iterator first, iterator last) {
				for (iterator it = first; it != last; ) {
					erase(it++);
				}
			}

			void swap(red_black_tree& ref) {
				if (this == &ref) {
					return;
				}
				value_compare	tmp_comp = ref._comp;
				allocator_type	tmp_alloc = ref._alloc;
				node_alloc_type	tmp_node_alloc = ref._node_alloc;
				node_ptr		tmp_head_node = ref._head_node;
				size_type		tmp_size = ref._size;

				ref._comp = _comp;
				ref._alloc = _alloc;
				ref._node_alloc = _node_alloc;
				ref._head_node = _head_node;
				ref._size = _size;

				_comp = tmp_comp;
				_alloc = tmp_alloc;
				_node_alloc = tmp_node_alloc;
				_head_node = tmp_head_node;
				_size = tmp_size;
			}

			void clear() {
				delete_tree(get_root());
				set_root(ft_nullptr);
				_size = 0;
			}

			iterator find(const value_type& v) const {
				node_ptr tmp = get_root();
				
				while (tmp != ft_nullptr) {
					if (!_comp(tmp->_value, v) && !_comp(v, tmp->_value)) {
						break;
					} else if (_comp(tmp->_value, v)) {
						tmp = tmp->_right;
					} else {
						tmp = tmp->_left;
					}
				}
				if (tmp == ft_nullptr) {
					return (iterator(this->_head_node));
				}
				return (iterator(tmp));
			}

			size_type count(const value_type& v) const {
				iterator tmp = find(v);
				if (tmp == end()) {
					return 0;
				}
				size_type count = 0;
				for (iterator it = tmp; it != end(); ++it) {
					if (!_comp(*it, v) && !_comp(v, *it)) {
						++count;
					}
				}
				return count;
			}

	// ==========================================================================

	// private member functions =================================================

		private:

			node_ptr get_root() const {
				return _head_node->_left;
			}

			void set_root(node_ptr node) {
				_head_node->_left = node;
				_head_node->_right = node;
				if (node != ft_nullptr)
					node->_parent = _head_node;
			}

			void delete_tree(node_ptr node) {
				if (node == ft_nullptr)
					return;
				delete_tree(node->_left);
				delete_tree(node->_right);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			void copy_tree(node_ptr node) {
				if (node == ft_nullptr)
					return;
				insert_value(node->_value);
				copy_tree(node->_left);
				copy_tree(node->_right);
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
				if (node == _head_node)
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

			/* insert **********************************************************/
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
			/* insert done ***********************************************************************/

			/* delete ****************************************************************************/

			size_type	delete_value(const value_type& val) {
				node_ptr target = delete_node(get_root(), val);
				if (target == ft_nullptr)
					return (0);
				delete_fixup(target);
				this->_size--;
				return (1);
			}

			/* delete red case */
			void	delete_red_case(node_ptr& node) {
				node_ptr child = node->_left != ft_nullptr ? node->_left : node->_right;

				if (node == node->_parent->_left)
					node->_parent->_left = child;
				else
					node->_parent->_right = child;
				if (child != ft_nullptr)
					child->_parent = node->_parent;
				set_color(child, BLACK);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			/* delete root case */
			void	delete_root_case(node_ptr root) {
				if (root->_right)
					set_root(root->_right);
				else
					set_root(root->_left);
				_node_alloc.destroy(root);
				_node_alloc.deallocate(root, 1);
				set_color(get_root(), BLACK);
			}

			/* delete case 1 */
			void	delete_case1(node_ptr& s, node_ptr& p) {
				set_color(s, BLACK);
				set_color(p, RED);
				if (s == p->_right)
					rotate_left(p);
				if (s == p->_left)
					rotate_right(p);
			}

			/* delete case 2 */
			void	delete_case2(node_ptr s, node_ptr p, node_ptr& node) {
				set_color(s, RED);
				if (get_color(p) == RED)
					set_color(p, BLACK);
				else
					set_color(p, DUB_BLACK);
				node = p;
			}

			/* delete case 3 */
			void	delete_case3(node_ptr& s, node_ptr& p) {
				if (s == p->_right) {
					set_color(s->_left, BLACK);
					set_color(s, RED);
					rotate_right(s);
					s = p->_right;
				}
				if (s == p->_left) {
					set_color(s->_right, BLACK);
					set_color(s, RED);
					rotate_left(s);
					s = p->_left;
				}
			}

			/* delete case 4 */
			void	delete_case4(node_ptr& s, node_ptr& p) {
				if (s == p->_right) {
					set_color(s, get_color(p));
					set_color(p, BLACK);
					set_color(s->_right, BLACK);
					rotate_left(p);
				}
				if (s == p->_left) {
					set_color(s, get_color(p));
					set_color(p, BLACK);
					set_color(s->_left, BLACK);
					rotate_right(p);
				}
			}

			void	delete_fixup(node_ptr node) {
				if (node == ft_nullptr)
					return;
				if (node == get_root()) {
					delete_root_case(node);
					return;
				}
				if (get_color(node) == RED || get_color(node->_left) == RED|| get_color(node->_right) == RED) {
					delete_red_case(node);
					return;
				}
				node_ptr s = ft_nullptr;
				node_ptr p = ft_nullptr;
				node_ptr tmp = node;
				set_color(tmp, DUB_BLACK);
				while (tmp != get_root() && get_color(tmp) == DUB_BLACK) {
					p = tmp->_parent;
					s = (tmp == p->_left) ? p->_right : p->_left;
					if (get_color(s) == RED)
						delete_case1(s, p);
					else if (get_color(s->_left) == BLACK && get_color(s->_right) == BLACK)
						delete_case2(s, p, tmp);
					else {
						if ((tmp == p->_left && get_color(s->_right) == BLACK) 
						|| (tmp == p->_right && get_color(s->_left) == BLACK))
							delete_case3(s, p);
						delete_case4(s, p);
						break;
					}
				}
				if (node == node->_parent->_left)
					node->_parent->_left = ft_nullptr;
				else
					node->_parent->_right = ft_nullptr;
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
				set_color(get_root(), BLACK);
			}

			node_ptr	delete_node(node_ptr node, const value_type& val) {
				if (node == ft_nullptr)
					return node;
				if (_comp(node->_value, val))
					return delete_node(node->_right, val);
				if (_comp(val, node->_value))
					return delete_node(node->_left, val);
				if (node->_left == ft_nullptr || node->_right == ft_nullptr)
					return node;

				node_ptr tmp = min_value_node(node->_right);
				if (tmp->_parent == node) {
					if (node->_parent && node->_parent->_left == node)
						node->_parent->_left = tmp;
					if (node->_parent && node->_parent->_right == node)
						node->_parent->_right = tmp;
					tmp->_left = node->_left;
					node->_left->_parent = tmp;
					node->_left = ft_nullptr;
					tmp->_parent = node->_parent;
					node->_parent = tmp;
					node->_right = tmp->_right;
					tmp->_right = node;
					std::swap(tmp->_color, node->_color);
				} else {
					if (node->_parent && node->_parent->_left == node)
						node->_parent->_left = tmp;
					if (node->_parent && node->_parent->_right == node)
						node->_parent->_right = tmp;
					if (tmp->_parent->_left == tmp)
						tmp->_parent->_left = node;
					if (tmp->_parent->_right == tmp)
						tmp->_parent->_right = node;
					node_ptr tmp2 = tmp->_parent;
					node->_right->_parent = tmp;
					tmp->_parent = node->_parent;
					node->_parent = tmp2;
					tmp->_left = node->_left;
					node->_left->_parent = tmp;
					node->_left = ft_nullptr;
					tmp2 = tmp->_right;
					tmp->_right = node->_right;
					node->_right = tmp2;
					std::swap(tmp->_color, node->_color);
				}
				return delete_node(tmp->_right, val);
			}

	// ==========================================================================

	};


// ============================================================================

} // namespace ft

#endif // __RED_BLACK_TREE_HPP__