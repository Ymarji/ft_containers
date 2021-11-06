#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include "map_util.hpp"
#include <memory>

namespace ft{
	template <class _Tp>
	struct __node{
		public:
			typedef	_Tp		value_type;
		public:
			_Tp		Value;
			__node<_Tp> *parent;
			__node<_Tp> *left;
			__node<_Tp> *right;
			__node(const value_type &p):Value(p){};
			__node	&operator=(const __node	&rhs){
				this->Value = rhs.Value;
				this->parent = rhs.parent;
				this->left = rhs.left;
				this->right = rhs.right;
			}
			bool operator<(const __node &rhs){
				return (this->Value.first < rhs.Value.first);
			}
	};

	template <class _Tp, class _nodePtr>
	class	__tree_iter{
		public:
			typedef	_Tp				value_type;
			typedef	_Tp&			reference;
			typedef	_Tp*			pointer;
		private:
			_nodePtr	_node;
		public:
		__tree_iter(_nodePtr n):_node(n){};
		__tree_iter	operator++(){
			_nodePtr tmp = ft::tree_next_iter(_node);
			if (tmp != nullptr)
				_node = tmp;
			return *this;
		};
		__tree_iter	operator++(int){
			__tree_iter	tmp = *this;
			++(*this);
			return tmp;
		};
		__tree_iter	operator--(){
			_nodePtr tmp = ft::tree_prev_iter(_node);
			if (tmp != nullptr)
				_node = tmp;
			return *this;
		};
		__tree_iter	operator--(int){
			__tree_iter	tmp = *this;
			--(*this);
			return tmp;
		};
		reference	operator*(){
			return (_node->Value);
		};
		
		pointer	operator->(){
			return	&(_node->Value);
		};
		bool	operator==(__tree_iter const &rhs){
			return	( this->_node == rhs._node);
		};
		bool	operator!=(__tree_iter const &rhs){
			return	!(this->_node == rhs._node);
		};
	};

	template <class Tp, class Compare = std::less<typename Tp::first_type> , class Allocator = std::allocator<Tp> >
	class __tree{
		public:
			typedef Tp															value_type;
			typedef typename Tp::first_type										key_value;
			typedef Compare														key_compare;
			typedef Allocator													allocator_type;
			typedef	size_t														size_type;

			typedef	__node<value_type>											node;
			typedef typename allocator_type::template rebind<node>::other		node_allocator; //
			typedef	__tree<value_type, key_compare, allocator_type>				_tree;

			typedef	node*														nodePtr;
		private:
			size_type			_size;
			const key_compare	&_CompObject;
			const Allocator		&_allocator;
			node			*_tree_root;
		public:
			__tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_CompObject(comp), _allocator(alloc), _tree_root(nullptr), _size(0) {};
			__tree(value_type _t, const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()):_tree_root(_t), _CompObject(comp), _allocator(alloc), _size(0) {};
			nodePtr	Base(){return _tree_root; }
			nodePtr	treeMin(nodePtr	_start){
				node *StartingNode = _start;
				while (StartingNode->left != nullptr)
					StartingNode = StartingNode->left;
				return StartingNode;
			}
			nodePtr	treeMax(nodePtr	_start){
				node *StartingNode = _start;
				while (StartingNode->right != nullptr)
					StartingNode = StartingNode->right;
				return StartingNode;
			}
			nodePtr	getRoot(){
				return	_tree_root;
			}
			nodePtr	MakeNode(value_type _t){
				node *tmp = node_allocator(_allocator).allocate(1);
				node_allocator(_allocator).construct(tmp, _t);
				tmp->parent = nullptr;
				tmp->left = nullptr;
				tmp->right = nullptr;
				return	tmp;
			};
			void	AddinTree(nodePtr	newNode){
				nodePtr	TreeDriver = _tree_root;
				nodePtr	parent = nullptr;
				_size++;
				if	(_tree_root == nullptr)
					_tree_root = newNode;
				else
				{
					while (TreeDriver != nullptr)
					{
						parent = TreeDriver;
						if (newNode->Value.first == TreeDriver->Value.first){
							// return ;
							TreeDriver->Value.second = newNode->Value.second;
							node_allocator(_allocator).deallocate(newNode ,1);
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
			void	ordred_traversal(nodePtr	root){
				nodePtr	Driver = root;
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
			nodePtr	searchFrom(node *start, const key_value& key_value){
				nodePtr	Driver = start;
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
			nodePtr	_deletehelper(nodePtr	start, const key_value& key){
				if (start == nullptr)
					return nullptr;
				else if (key < start->Value.first)
					start->left = _deletehelper(start->left, key);
				else if (key > start->Value.first)
					start->right = _deletehelper(start->right, key);
				else{
					//case 1
					if (start->left == nullptr && start->right == nullptr){
						node_allocator(_allocator).destroy(start);	
						node_allocator(_allocator).deallocate(start, 1);
						start = nullptr;
					}//case 2
					else if (start->left == nullptr){
						nodePtr	temp = start;
						start = start->right;
						start->parent = temp->parent;
						node_allocator(_allocator).destroy(temp);	
						node_allocator(_allocator).deallocate(temp, 1);
					}
					else if (start->right == nullptr){
						nodePtr	temp = start;
						start = start->left;
						start->parent = temp->parent;
						node_allocator(_allocator).destroy(temp);	
						node_allocator(_allocator).deallocate(temp, 1);
					}//case3
					else{
						nodePtr	temp = treeMin(start->right);
						// start->Value = temp->Value;
						node_allocator(_allocator).construct(start, temp->Value);
						start->right = _deletehelper(start->right , temp->Value.first);
					}
				}
				return start;
			}
		public:
			nodePtr	search(const key_value& key_value){
				return searchFrom(_tree_root, key_value);
			}
			void	_delete(const key_value& key)
			{
				_tree_root = _deletehelper(_tree_root, key);
				if (_tree_root != nullptr)
					_size--;
			}
			nodePtr	treeSuccessor()//node *x)
			{
				nodePtr	x = _tree_root;
				if (x->right != nullptr)
					return treeMin(x->right);
				nodePtr	tmp = x->parent;
				while (tmp != nullptr && x == tmp->right)
				{
					x = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			};
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
			typedef	__node<value_type>									node;
			typedef	node*									nodePtr;
			typedef typename allocator_type::template rebind<node>::other		node_allocator; //
			typedef	const value_type											const_value_type;
			typedef	__tree<value_type, key_compare, allocator_type>			tree;
			typedef	__tree_iter<value_type, nodePtr>							iterator;
			typedef	__tree_iter<const_value_type, nodePtr>							const_iterator;
		
			explicit map (const key_compare& comp = key_compare(),
								const allocator_type& alloc = allocator_type()):_CompObject(comp), _allocator(alloc), _bst(nullptr) {};
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()):_CompObject(comp), _allocator(alloc), _bst() {};
			
			iterator begin(){
				return iterator(_bst.treeMin());
			}
		private:
			key_compare		_CompObject;
			allocator_type	_allocator;
			tree			_bst;
	};
};
#endif /* MAP_HPP */
