#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include <iostream>
#include "map_util.hpp"
#include <memory>
#include <algorithm>

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
			int			balanceFactor;
			__node(const value_type &p):Value(p){};
			__node	&operator=(const __node	&rhs){
				this->Value = rhs.Value;
				this->parent = rhs.parent;
				this->left = rhs.left;
				this->right = rhs.right;
				this->balanceFactor = rhs.balanceFactor;
			}
			bool operator<(const __node &rhs){
				return (this->Value.first < rhs.Value.first);
			}
	};

	template <class _iter>
	class	__tree_reverse_iter : public ft::iterator< std::bidirectional_iterator_tag,
									typename iterator_traits<_iter>::value_type,
									typename iterator_traits<_iter>::difference_type,
									typename iterator_traits<_iter>::pointer,
									typename iterator_traits<_iter>::reference>
	{
		public:
			//REVIEW:
			// typedef	_iter					iterator;
			// typedef	iterator&				reference;
			// typedef	iterator*				pointer;
			typedef _iter													iterator;
			typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator>::difference_type  	difference_type;
			typedef typename iterator_traits<iterator>::pointer          	pointer;
			typedef typename iterator_traits<iterator>::reference        	reference;
		private:
			iterator	_iterator;
		public:
		__tree_reverse_iter(): _iterator() {};
		explicit __tree_reverse_iter(iterator n):_iterator(n) {};
		template <class Iter>
			__tree_reverse_iter (const __tree_reverse_iter<Iter>& rev_it): _iterator(rev_it.base()) {};
		iterator	base() const{
			return _iterator;
		};
		__tree_reverse_iter&	operator++(){
			--_iterator;
			return *this;
		};
		__tree_reverse_iter	operator++(int){
			__tree_reverse_iter	tmp = *this;
			++(*this);
			return tmp;
		};
		__tree_reverse_iter&	operator--(){
			++_iterator;
			return *this;
		};
		__tree_reverse_iter	operator--(int){
			__tree_reverse_iter	tmp = *this;
			--(*this);
			return tmp;
		};
		reference	operator*() const{
			return *(--base());
		};
		
		pointer	operator->() const{
			return	&(operator*());
		};

		__tree_reverse_iter operator+ (difference_type n) const{
			return __tree_reverse_iter(_iterator - n);
		};

		__tree_reverse_iter operator- (difference_type n) const{
			return __tree_reverse_iter(_iterator + n);
		};
		__tree_reverse_iter& operator+= (difference_type n){
			_iterator -= n;
			return (*this);
		};
		__tree_reverse_iter& operator-= (difference_type n){
			_iterator += n;
			return (*this);
		};
		bool	operator==(__tree_reverse_iter const &rhs){
			return	(this->base() == this->base());
		};
		bool	operator!=(__tree_reverse_iter const &rhs){
			return	!(this->base() == this->base());
		};
	};

	template <class _Tp, class _nodePtr>
	class	__tree_iter{
		public:
			typedef	_Tp								value_type;
			typedef	_Tp&							reference;
			typedef	_Tp*							pointer;
			typedef ptrdiff_t						difference_type;
			typedef	std::bidirectional_iterator_tag	iterator_category;
		private:
			_nodePtr	_node;
		public:
		__tree_iter(_nodePtr n):_node(n){};
		
		__tree_iter	operator++(){//REVIEW: Wot was i Doing
			_nodePtr tmp = ft::tree_next_iter(_node);
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
		
		// pointer	operator->(){
		// 	return	&(_node->Value);
		// };

		_nodePtr	operator->(){
			return	(_node);
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
			typedef typename Tp::second_type									mapped_type;
			typedef Compare														key_compare;
			typedef Allocator													allocator_type;
			typedef	size_t														size_type;
			typedef	ptrdiff_t														difference_type;

			typedef	__node<value_type>											node;
			typedef typename allocator_type::template rebind<node>::other		node_allocator; //
			// typedef	__tree<value_type, key_compare, allocator_type>				_tree; 
			typedef	node*														nodePtr;
		public:	//REVIEW:
			typedef	value_type	*							pointer;
			typedef	const pointer							const_pointer;
			typedef	value_type	&							referance;
		private:
			size_type			_size;
			const key_compare	&_CompObject;
			const Allocator		&_allocator;
			node			*_tree_root;
			node			*_end_node;
		public:
			__tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_CompObject(comp), _allocator(alloc), _tree_root(nullptr), _size(0) {};
			__tree(value_type _t, const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()):_tree_root(_t), _CompObject(comp), _allocator(alloc), _size(0) {};
			nodePtr	Base(){return _tree_root; }
			nodePtr end_node(){
				return node_allocator(_allocator).allocate(1);
			}
			nodePtr	begin(){
				return ft::treeMin(_tree_root);
			}
			nodePtr	end(){
				return _end_node;
			}
			size_type size() const{
				return _size;
			};
			nodePtr	getRoot(){
				return	_tree_root;
			}
			nodePtr	MakeNode(value_type _t){
				node *tmp = node_allocator(_allocator).allocate(1);
				node_allocator(_allocator).construct(tmp, _t);
				tmp->parent = nullptr;
				tmp->left = nullptr;
				tmp->right = nullptr;
				tmp->balanceFactor = 0;
				return	tmp;
			};
			nodePtr	leftRotate(nodePtr Node){
				nodePtr rootP = Node->parent;
				nodePtr	nodeB = Node->right;
				if (rootP->left == Node)
					rootP->left = nodeB;
				else{
					rootP->right = nodeB;
				}
				nodeB->parent = rootP;
				if (rootP == _end_node){
					_tree_root = nodeB;
				}
				Node->right = nodeB->left;	
				if(nodeB->left != nullptr){
					nodeB->left->parent = Node;
				}
				nodeB->left = Node;
				Node->parent = nodeB;
				Node->balanceFactor = Node->balanceFactor + 1 - std::min(0, nodeB->balanceFactor);
				nodeB->balanceFactor = nodeB->balanceFactor + 1 + std::max(Node->balanceFactor, 0);
				return nodeB;
			};
			nodePtr	rightRotate(nodePtr	nodeC){
				nodePtr rootP = nodeC->parent;
				nodePtr nodeB = nodeC->left;
				if (rootP->left == nodeC)
					rootP->left = nodeB;
				else
					rootP->right = nodeB;
				nodeB->parent = rootP;
				if (rootP == _end_node)
					_tree_root = nodeB;
				nodeC->left = nodeB->right;
				if(nodeB->right != nullptr)
					nodeB->right->parent = nodeC;
				nodeB->right = nodeC;            
				nodeC->parent = nodeB;
				nodeC->balanceFactor = nodeC->balanceFactor - 1 - std::max(nodeB->balanceFactor, 0);
				nodeB->balanceFactor = nodeB->balanceFactor - 1 + std::min(0, nodeC->balanceFactor);
				return nodeB;
			};

			void	balanceUpdate(nodePtr	node){
				if (node->balanceFactor < -1 || node->balanceFactor > 1){
					rebalance(node);
					return;
				}

				if (node->parent != _end_node && node->parent != nullptr){
					if (node == node->parent->right)
						node->parent->balanceFactor -= 1;
					else if (node == node->parent->left)
						node->parent->balanceFactor += 1;

					if (node->parent->balanceFactor != 0)
						balanceUpdate(node->parent);
				}
			};

			nodePtr	rebalance(nodePtr node){
				nodePtr	tmp;
				if (node->balanceFactor < 0){
					if (node->right->balanceFactor > 0){
						rightRotate(node->right);
						tmp = leftRotate(node);
					}
					else
						tmp = leftRotate(node);
				}
				else if (node->balanceFactor > 0)
				{
					
					if (node->left->balanceFactor < 0){
						leftRotate(node->left);
						tmp = rightRotate(node);
					}
					else{
						tmp = rightRotate(node);
					}
				}
				return tmp;
			}
			void	AddinTree(nodePtr	newNode){
				nodePtr	TreeDriver = _tree_root;
				nodePtr	parent = nullptr;
				_size++;
				if	(_tree_root == nullptr){
					_tree_root = newNode;
					_end_node = end_node();
					_end_node->parent = nullptr;
					_end_node->balanceFactor = 0;
					_tree_root->parent = _end_node;
					_end_node->left = _tree_root;
				}
				else
				{
					while (TreeDriver != nullptr)
					{
						parent = TreeDriver;
						if (newNode->Value.first == TreeDriver->Value.first){
							return ;
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

				balanceUpdate(newNode);
			}
			void	ordred_traversal(nodePtr	root){
				nodePtr	Driver = root;
				if (Driver != nullptr){
					put(Driver->Value);
					std::cout << Driver->balanceFactor << std::endl;
					ordred_traversal(Driver->left);
					ordred_traversal(Driver->right);
				}
			};
			size_type size(){
				return _size;
			}
			int	Hight(nodePtr	x){
				if (x == nullptr)
					return 0;
				size_type lH = Hight(x->left);
				size_type rH = Hight(x->right);
				return std::max(lH, rH) + 1;
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
				// nodePtr		temp = start->parent;
				if (start == nullptr)
					return nullptr;
				else if (_CompObject(key, start->Value.first))
					start->left = _deletehelper(start->left, key);
				else if (_CompObject(start->Value.first, key))
					start->right = _deletehelper(start->right, key);
				else{
					if (start->left == nullptr && start->right == nullptr){
						node_allocator(_allocator).destroy(start);	
						node_allocator(_allocator).deallocate(start, 1);
						start = nullptr;
					}
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
					}
					else{
						nodePtr	temp = ft::treeMin(start->right);
						value_type p = temp->Value;
						nodePtr X = temp->parent;
						start->right = _deletehelper(start->right , temp->Value.first);
						temp = deletBalence(X, p.first);
						node_allocator(_allocator).construct(start, p);
						if (temp != nullptr)
							start = temp;
					}
				}
				return start;
			}
		public:
			nodePtr	search(const key_value& key_value){
				return searchFrom(_tree_root, key_value);
			}
			nodePtr	deletBalence(nodePtr	node, const key_value& key)
			{

				if (node != _end_node)
				{
					if (key < node->Value.first)
							node->balanceFactor -= 1;
					else if (key > node->Value.first)
							node->balanceFactor += 1;
					if (node->balanceFactor < -1 || node->balanceFactor > 1){
							return rebalance(node);
					}
					if (node->balanceFactor == 0)
						deletBalence(node->parent, key);
				}
				return nullptr;
			}
			void	_delete(const key_value& key)
			{
				nodePtr X = this->search(key);
				nodePtr XP = X->parent;
				bool	X_Twin = true;

				if (X->left == nullptr || X->right == nullptr)
					X_Twin = false;
				_tree_root = _deletehelper(_tree_root, key);
				if (_tree_root != nullptr)
					_size--;
				if (X_Twin == false){
					deletBalence(XP, key);
					std::cout << X_Twin << std::endl;
				}
			}
			size_type max_size() const{
				return node_allocator(_allocator).max_size();
				// return  std::min(static_cast<size_t>(std::numeric_limits<size_type>::max() / sizeof(node)), static_cast<size_t>(std::numeric_limits<difference_type >::max()));
			};
			nodePtr	treeSuccessor()
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
			void prettyPrint() {
				printHelper(this->_tree_root, "", true);
			}
			void printHelper(nodePtr root,std::string indent, bool last) {
			if (root != nullptr) {
				std::cout<<indent;
				if (last) {
					std::cout<<"R----";
					indent += "     ";
				} else {
					std::cout<<"L----";
					indent += "|    ";
				}

				std::cout<<root->Value.first<<"( BF = "<<root->balanceFactor<<")"<<std::endl;
				// std::cout<<root->Value.first<<std::endl;

				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
				}
			}
			mapped_type& operator[] (const key_value& k){
				nodePtr	tmp = search(k);
				if (tmp != nullptr)
					return tmp->Value.second;
				else{
					AddinTree(MakeNode(ft::make_pair(k, mapped_type())));
					return search(k)->Value.second;
				}
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
					bool operator()(const key_type& x, const value_type& y) const{
						return comp(x, y.first);
					};
					bool operator()(const value_type& x, const key_type& y) const{
						return comp(x.first, y);
					};
			};
		public:
			typedef	__node<value_type>											node;
			typedef	node*														nodePtr;
			typedef typename allocator_type::template rebind<node>::other		node_allocator; ////REVIEW:
			typedef	const value_type											const_value_type;
			typedef	__tree<value_type, key_compare, allocator_type>				tree;
			typedef	__tree_iter<value_type, nodePtr>							iterator;
			typedef	__tree_iter<const_value_type, nodePtr>							const_iterator;
			typedef	__tree_reverse_iter<iterator>								reverse_iterator;
			typedef	__tree_reverse_iter<const_iterator>								const_reverse_iterator;
		
			explicit map (const key_compare& comp = key_compare(),
								const allocator_type& alloc = allocator_type()):_CompObject(comp), _allocator(alloc), _bst() {};
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()):_CompObject(comp), _allocator(alloc), _bst() {};
			
			iterator begin(){
				return iterator(_bst.begin());
			}
			iterator end(){
				return iterator(_bst.end());
			}
			const_iterator begin() const{
				return const_iterator(_bst.begin());
			}
			const_iterator end() const{
				return const_iterator(_bst.end());
			}
			reverse_iterator rbegin(){
				return reverse_iterator(_bst.end());
			}
			reverse_iterator rend(){
				return reverse_iterator(_bst.begin());
			}
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(_bst.end());
			}
			const_reverse_iterator rend() const{
				return const_reverse_iterator(_bst.begin());
			}

			//CAPACITY
			size_type size() const{
				return _bst.size();
			};
			bool empty() const{
				if (!this->size())
					return true;
				return false;
			};
			size_type max_size() const{
				return  _bst.max_size();
			};

			//ACCESS ELEMENT
			mapped_type& operator[] (const key_type& k){
				return _bst[k];
			};

			void prettyPrint(){
				_bst.prettyPrint();
			};
			tree			_bst;
		private:
			key_compare		_CompObject;
			allocator_type	_allocator;
	};
};
#endif /* MAP_HPP */
