#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include <memory>

namespace ft{
	template <class _Tp>
	struct _node{
		public:
			_Tp		Value;
			_node<_Tp> *left;
			_node<_Tp> *right;
			// bool operator<(const _node &rhs){
			// 	return (this->Value.first < rhs.Value.first; );
			// }
	};

	template <class Tp, class Compare, class Allocator>
	class __tree{
		public:
			typedef Tp										value_type;
			typedef typename Tp::first_type					key_value;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef	_node<value_type>								_node;
			typedef		size_t											size_type;

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
			_node	*treeMin(){
				_node *StartingNode = _tree_root;
				while (StartingNode->left != nullptr)
					StartingNode = StartingNode->left;
				return StartingNode;
			}
			_node	*treeMax(){
				_node *StartingNode = _tree_root;
				while (StartingNode->right != nullptr)
					StartingNode = StartingNode->right;
				return StartingNode;
			}
			_node	*MakeNode(value_type _t){
				// _node *tmp = _allocator.allocate(sizeof(_node)); // todo
				_node *tmp = _node_allocator(_allocator).allocate(1);

				tmp->Value = _t;
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
					{
						parent->left = newNode;
					}
					else
						parent->right = newNode;
				}
			}
			size_type size(_node	*startingNode){
				return _size;
			}
			_node	*search(const key_value& key_value){
				_node	*Driver = _tree_root;
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
