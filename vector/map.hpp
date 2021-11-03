#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include <memory>

namespace ft{
	template <class _Tp>
	struct _node{
		public:
			_Tp		Value;
			_node<_Tp> *parent;
			_node<_Tp> *left;
			_node<_Tp> *right;

			_node	&operator=(const _node	&rhs){
				this->Value = rhs.Value;
				this->parent = rhs.parent;
				this->left = rhs.left;
				this->right = rhs.right;
			}
			bool operator<(const _node &rhs){
				return (this->Value.first < rhs.Value.first);
			}
	};

	template <class Tp, class Compare, class Allocator>
	class __tree{
		public:
			typedef Tp										value_type;
			typedef typename Tp::first_type					key_value;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef	_node<value_type>						_node;
			typedef	size_t									size_type;

			typedef typename allocator_type::template rebind<_node>::other		_node_allocator; //
			typedef	__tree<value_type, key_compare, allocator_type>				_tree;
		private:
			size_type			_size;
			const key_compare	&_CompObject;
			const Allocator		&_allocator;
		public:
			_node			*_tree_root;
		public:
			__tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_CompObject(comp), _allocator(alloc), _tree_root(nullptr), _size(0) {};
			__tree(value_type _t, const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()):_tree_root(_t), _CompObject(comp), _allocator(alloc), _size(0) {};
			_node	*treeMin(_node	*_start){
				_node *StartingNode = _start;
				while (StartingNode->left != nullptr)
					StartingNode = StartingNode->left;
				return StartingNode;
			}
			_node	*treeMax(_node	*_start){
				_node *StartingNode = _start;
				while (StartingNode->right != nullptr)
					StartingNode = StartingNode->right;
				return StartingNode;
			}
			_node	*getRoot(){
				return	_tree_root;
			}
			_node	*MakeNode(value_type _t){
				_node *tmp = _node_allocator(_allocator).allocate(1);

				tmp->Value = _t;
				tmp->parent = nullptr;
				tmp->left = nullptr;
				tmp->right = nullptr;
				return	tmp;
			};
			void	AddinTree(_node	*newNode){
				_node	*TreeDriver = _tree_root;
				_node	*parent = nullptr;

				_size++;
				if	(_tree_root == nullptr)
					_tree_root = newNode;
				else
				{
					while (TreeDriver != nullptr)
					{
						parent = TreeDriver;
						if (newNode->Value.first == TreeDriver->Value.first){
							TreeDriver->Value.second = newNode->Value.second;
							_node_allocator(_allocator).deallocate(newNode ,1);
							_size--;
							break ;
						}
						else if (_CompObject(newNode->Value.first, TreeDriver->Value.first))
							TreeDriver = TreeDriver->left;
						else
							TreeDriver = TreeDriver->right;
					}
					if (_CompObject(newNode->Value.first, parent->Value.first))
						parent->left = newNode;
					else
						parent->right = newNode;
					newNode->parent = parent;
				}
			}
			void	ordred_traversal(_node	*root){
				_node	*Driver = root;
				if (Driver != nullptr){
					ordred_traversal(Driver->left);
					put(Driver->Value);
					ordred_traversal(Driver->right);
				}
			};
			size_type size(){
				return _size;
			}
		private:
			_node	*searchFrom(_node *start, const key_value& key_value){
				_node	*Driver = start;
				while (Driver != nullptr)
				{
					if (Driver->Value.first == key_value)
						return Driver;
					if (_CompObject(key_value, Driver->Value.first))
						Driver = Driver->left;
					else
						Driver = Driver->right;
				}
				return nullptr;
			}
			_node	*_deletehelper(_node	*start, const key_value& key){
				if (start == nullptr)
					return nullptr;
				else if (key < start->Value.first)
					start->left = _deletehelper(start->left, key);
				else if (key > start->Value.first)
					start->right = _deletehelper(start->right, key);
				else{
					//case 1
					if (start->left == nullptr && start->right == nullptr){
						_node_allocator(_allocator).destroy(start);	
						_node_allocator(_allocator).deallocate(start, 1);
						start = nullptr;
					}//case 2
					else if (start->left == nullptr){
						_node	*temp = start;
						start = start->right;
						_node_allocator(_allocator).destroy(temp);	
						_node_allocator(_allocator).deallocate(temp, 1);
					}
					else if (start->right == nullptr){
						_node	*temp = start;
						start = start->left;
						_node_allocator(_allocator).destroy(temp);	
						_node_allocator(_allocator).deallocate(temp, 1);
					}//case3
					else{
						_node	*temp = treeMin(start->right);
						start->Value = temp->Value;
						start->right = _deletehelper(temp, temp->Value.first);
					}
				}
				return start;
			}
		public:
			_node	*search(const key_value& key_value){
				return searchFrom(_tree_root, key_value);
			}
			void	_delete(const key_value& key)
			{
				_node *tmp = _deletehelper(_tree_root, key);
				if (tmp != nullptr)
					_size--;
			}
			// void	_delete(_node *start, const key_value& sxkey){
			// 	_node	*toDeNood;
			// 	// if ((toDeNood = search(key)))
			// 	if ((toDeNood = searchFrom(start, key)))
			// 	{
			// 		_size--;
			// 		if (toDeNood->left == nullptr && toDeNood->right == nullptr)
			// 		{
			// 			if (toDeNood < toDeNood->parent)
			// 				toDeNood->parent->left = nullptr;
			// 			else
			// 				toDeNood->parent->right = nullptr;
			// 			_node_allocator(_allocator).destroy(toDeNood);	
			// 			_node_allocator(_allocator).deallocate(toDeNood, 1);
			// 		}
			// 		else if (toDeNood->left == nullptr || toDeNood->right == nullptr){
			// 			if (toDeNood < toDeNood->parent){
			// 				if (toDeNood->left == nullptr){
			// 					toDeNood->right->parent = toDeNood->parent;
			// 					toDeNood->parent->left = toDeNood->right;
			// 				}else{
			// 					toDeNood->left->parent = toDeNood->parent;
			// 					toDeNood->parent->left = toDeNood->left;
			// 				}
			// 			}
			// 			else{
			// 				if (toDeNood->left == nullptr){
			// 					toDeNood->right->parent = toDeNood->parent;
			// 					toDeNood->parent->right = toDeNood->right;
			// 				}else{
			// 					toDeNood->left->parent = toDeNood->parent;
			// 					toDeNood->parent->right = toDeNood->left;
			// 				}
			// 			}
			// 			_size--;
			// 			_node_allocator(_allocator).destroy(toDeNood);	
			// 			_node_allocator(_allocator).deallocate(toDeNood, 1);
			// 		}
			// 		else{
			// 			_node	*tmp = treeMin(toDeNood->right);
			// 			toDeNood->Value = tmp->Value;
			// 			_delete(tmp, tmp->Value.first);
			// 			// _node_allocator(_allocator).destroy(tmp);	
			// 			// _node_allocator(_allocator).deallocate(tmp, 1);
			// 		}
			// 	}
			// }
			~__tree() {};

	};
	template < class Key,												// map::key_type
			class T,													// map::mapped_type
			class Compare = std::less<Key>,								// map::key_compare
			class Alloc = std::allocator<ft::pair<const Key, T> > >		// map::allocator_type
	class map{
		public:
			typedef		Key												key_type; 
			typedef		T												mapped_type;
			typedef		ft::pair<const key_type, mapped_type>			value_type;
			typedef		Compare											key_compare;
			typedef		Alloc											allocator_type;
			typedef		typename	allocator_type::reference			reference;
			typedef		typename	allocator_type::const_reference		const_reference;
			typedef		typename	allocator_type::pointer				pointer;
			typedef		typename	allocator_type::const_pointer		const_pointer;
			typedef		ptrdiff_t										difference_type;
			typedef		size_t											size_type;

		class value_compare
				: public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					key_compare comp;
					value_compare(key_compare c):comp(c) {};
				public:
					bool operator()(const value_type& x, const value_type& y) const{
						return comp(x.first, y.first);
					};
			};
		public:
			typedef	_node<value_type>									_node;
			typedef typename allocator_type::template rebind<_node>::other		_node_allocator; //
			typedef	__tree<value_type, value_compare, allocator_type>		_tree;
		
			explicit map (const key_compare& comp = key_compare(),
								const allocator_type& alloc = allocator_type()):_CompObject(comp), _allocator(alloc), _bst(nullptr) {};
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()):_CompObject(comp), _allocator(alloc), _bst() {};
		private:
			key_compare		_CompObject;
			allocator_type	_allocator;
			_tree			_bst;
	};
}
#endif /* MAP_HPP */
