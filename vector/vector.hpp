/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarji <ymarji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:49:50 by ymarji            #+#    #+#             */
/*   Updated: 2021/10/22 12:04:42 by ymarji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <stdexcept>      // std::length_error
#include "enable_if.hpp"
// #include <stack>
// #include <iterator>
#include <vector>
#include <algorithm>
#include <memory>
#define put(x) std::cout << x << std::endl
namespace ft
{
	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2){
					while (first1!=last1){
						if (!(*first1 == *first2))
							return false;
					++first1; ++first2;
					}
					return true;
				};
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool equal (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, BinaryPredicate pred){
					while (first1!=last1){
						if (!pred(*first1,*first2))
							return false;
					++first1; ++first2;
					}
					return true;
				};

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2){
			while (first1!=last1)
			{
				if (first2==last2 || *first2<*first1) return false;
				else if (*first1<*first2) return true;
				++first1; ++first2;
			}
			return (first2!=last2);
		}
	template <class InputIterator1, class InputIterator2, class Compare>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, 
			InputIterator2 first2, InputIterator2 last2,
			Compare comp){
			while (first1!=last1)
			{
				if (first2==last2 || comp(*first2, *first1)) return false;
				else if (comp(*first1, *first2)) return true;
				++first1; ++first2;
			}
			return (first2!=last2);
		};
	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename std::random_access_iterator_tag iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};


	template <class Category,			  // iterator::iterator_category
			  class T,					  // iterator::value_type
			  class Distance = ptrdiff_t, // iterator::difference_type
			  class Pointer = T *,		  // iterator::pointer
			  class Reference = T &		  // iterator::reference
			>
	struct iterator
	{
			typedef Category iterator_category;
			typedef T value_type;
			typedef Distance difference_type;
			typedef Pointer pointer;
			typedef Reference reference;
	};

	template <typename Iter>
	class	vreverse_iterator: public iterator<typename std::random_access_iterator_tag,
			typename iterator_traits<Iter>::value_type,
			typename iterator_traits<Iter>::difference_type,
			typename iterator_traits<Iter>::pointer,
			typename iterator_traits<Iter>::reference>
	{
		public:
			typedef Iter														iterator;
			typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator>::value_type       	value_type;
			typedef typename iterator_traits<iterator>::difference_type  	difference_type;
			typedef typename iterator_traits<iterator>::pointer          	pointer;
			typedef typename iterator_traits<iterator>::reference        	reference;

		public:
			vreverse_iterator( ):_iter(){
			};
			vreverse_iterator(iterator iter):_iter(iter){
			};
			iterator base() const{
				return _iter;
			};
			reference operator*() const{
				return *_iter;
			}
			vreverse_iterator operator+ (difference_type n) const{
				vreverse_iterator tmp(_iter - n);
				return tmp;
			}
			vreverse_iterator& operator++(){
				--_iter;
				return (*this);
			};
			vreverse_iterator  operator++(int){
				vreverse_iterator temp = *this;
				++(*this);
				return temp;
			};
			vreverse_iterator& operator+= (difference_type n){
				_iter -= n;
				return (*this);
			};
			vreverse_iterator operator- (difference_type n) const{
				vreverse_iterator tmp(_iter - n);
				return tmp;
			};
			vreverse_iterator& operator--(){
				++_iter;
				return (*this);
			};
			vreverse_iterator  operator--(int){
				vreverse_iterator temp = *this;
				--(*this);
				return temp;
			};
			vreverse_iterator& operator-= (difference_type n){
				_iter += n;
				return (*this);
			};
			pointer operator->() const {
				return &(operator*());
			}
			reference operator[] (difference_type n) const{
				return base()[-n-1];
			};
			~vreverse_iterator(){};
		private:
			iterator	_iter;
	};

	template <class Iterator>
	vreverse_iterator<Iterator> operator+ (
		typename vreverse_iterator<Iterator>::difference_type n,
		const vreverse_iterator<Iterator>& rev_it){
			rev_it += n;
			return rev_it;
		};
	template <class Iterator>
	vreverse_iterator<Iterator> operator- (
		typename vreverse_iterator<Iterator>::difference_type n,
		const vreverse_iterator<Iterator>& rev_it){
			rev_it -= n;
			return rev_it;
		};
		template <class iter>
			bool operator== (const vreverse_iterator<iter>& lhs,
				const vreverse_iterator<iter>& rhs){ return lhs.base() == rhs.base();};
		template <class iter>
			bool operator!= (const vreverse_iterator<iter>& lhs,
				const vreverse_iterator<iter>& rhs){ return lhs.base() != rhs.base();};
		template <class iter>
			bool operator< (const vreverse_iterator<iter>& lhs,
				const vreverse_iterator<iter>& rhs){ return lhs.base() > rhs.base();};
		template <class iter>
			bool operator<= (const vreverse_iterator<iter>& lhs,
				const vreverse_iterator<iter>& rhs){ return lhs.base() >= rhs.base();};
		template <class iter>
			bool operator> (const vreverse_iterator<iter>& lhs,
				const vreverse_iterator<iter>& rhs){ return lhs.base() < rhs.base();};
		template <class iter>
			bool operator>= (const vreverse_iterator<iter>& lhs,
				const vreverse_iterator<iter>& rhs){ return lhs.base() <= rhs.base();};
	template <typename T>
	class vectorIterator: public iterator<typename std::random_access_iterator_tag,
			typename iterator_traits<T>::value_type>
	{
		public:
			typedef T															iterator_type;
			typedef typename iterator_traits<iterator_type>::difference_type  	difference_type;
			typedef typename iterator_traits<iterator_type>::pointer          	pointer;
			typedef typename iterator_traits<iterator_type>::reference        	reference;

		public:
			vectorIterator( ):_ptr(NULL){
			};
			vectorIterator(iterator_type ptr):_ptr(ptr){
			};
			vectorIterator(vectorIterator const &rhs):_ptr(rhs._ptr){
			};
			iterator_type base() const{
				return _ptr;
			};
			reference operator*() const{
				return *_ptr;
			};
			vectorIterator operator++(int){
				vectorIterator tmp = *this;
				++_ptr;
				return tmp;
			};
			vectorIterator	operator++(){
				++_ptr;
				return *this;
			};
			vectorIterator	operator--(int){
				vectorIterator tmp = *this;
				--_ptr;
				return tmp;
			};
			vectorIterator	operator--(){
				--_ptr;
				return *this;
			};
			vectorIterator operator+=(difference_type n){
				_ptr += n;
				return *this;
			};
			vectorIterator operator-=(difference_type n){
				_ptr -= n;
				return *this;
			};
			vectorIterator	operator+(difference_type n) const{
				vectorIterator tmp(*this);
				tmp += n;
				return tmp;
			};
			vectorIterator	operator-(difference_type n)const{
				vectorIterator tmp(*this);
				tmp -= n;
				return tmp;
			};
			iterator_type			operator->() const{
				return _ptr;
			};
			reference operator[] (difference_type n) const{
				return _ptr[n];
			};
			bool			operator==(vectorIterator const &rhs){
				return (this->_ptr == rhs._ptr);
			};
			bool			operator!=(vectorIterator const &rhs){
				return (this->_ptr != rhs._ptr);
			};
			~vectorIterator(){};
		private:
			iterator_type _ptr;
	};
			template <typename iter>
			vectorIterator<iter>	operator+(typename vectorIterator<iter>::difference_type n, vectorIterator<iter> &out){
				out += n;
				return out;
			};
				template <typename iter>
			vectorIterator<iter>	operator-(typename vectorIterator<iter>::difference_type n, vectorIterator<iter> &out){
				out -= n;
				return out;
			};
			template <class iter>
				bool operator== (const vectorIterator<iter>& lhs,
					const vectorIterator<iter>& rhs){ return lhs.base() == rhs.base();};
			template <class iter>
				bool operator!= (const vectorIterator<iter>& lhs,
					const vectorIterator<iter>& rhs){ return lhs.base() != rhs.base();};
			template <class iter>
				bool operator< (const vectorIterator<iter>& lhs,
					const vectorIterator<iter>& rhs){ return lhs.base() < rhs.base();};
			template <class iter>
				bool operator<= (const vectorIterator<iter>& lhs,
					const vectorIterator<iter>& rhs){ return lhs.base() <= rhs.base();};
			template <class iter>
				bool operator> (const vectorIterator<iter>& lhs,
					const vectorIterator<iter>& rhs){ return lhs.base() > rhs.base();};
			template <class iter>
				bool operator>= (const vectorIterator<iter>& lhs,
					const vectorIterator<iter>& rhs){ return lhs.base() >= rhs.base();};

	template < typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename 	allocator_type::pointer						pointer;
			typedef typename 	allocator_type::const_pointer				const_pointer;
			typedef typename 	allocator_type::reference					reference;
			typedef typename 	allocator_type::const_reference				const_reference;
			typedef typename 	allocator_type::difference_type				difference_type;
			typedef 			vectorIterator<pointer>						iterator;
			typedef 			vreverse_iterator<iterator>						reverse_iterator;
			typedef 			vectorIterator<const_pointer>				const_iterator;
			typedef typename 	allocator_type::size_type					size_type;
		public: /* class Constructor and destructor */
			vector<T, Alloc>():
			_size(0),
			_cap(0){
				_ptr = _allocator.allocate(0);
				_ptr = nullptr;
			};
			
			vector<T, Alloc>(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()):
			_size(n),
			_cap(n),
			_allocator(alloc)
			{
				_ptr = _allocator.allocate(_cap);
				for (size_type i = 0 ; i < _cap; i++)
					_ptr[i] = val;
			};
			// typename ft::enable_if<std::is_class<InputIterator>::value>::type
			// typename std::enable_if<std::__is_random_access_iterator<InputIterator>::value>::type
			template <class	InputIterator>
			vector<T, Alloc>(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
			{
				_size	= std::distance(first, last);
				_cap	= _size;
				_allocator = alloc;
				_ptr	= _allocator.allocate(_cap);
				int	j	= 0;
				for (InputIterator it = first; it != last; it++)
				{
					_ptr[j++] = *it;
				}
			};
			vector(vector const &rhs){
				*this = rhs;
			};
			~vector(){
				_allocator.deallocate(_ptr, _cap);
			};
		private: /* utile funstion */
		template <typename _Iter>
			size_type	distance(_Iter first, _Iter end){
				size_type _dis(0);
				for (_Iter i = first; i < end; i++)
				{
					_dis++;
				}
				return _dis;
			};
			void	Mreallocat(size_type n)//, value_type val = value_type())
			{
				size_type _cs = size();
				allocator_type _all;
				pointer _tmp = _allocator.allocate(_cap);
				for (size_t i = 0; i < _cs; i++)
					_tmp[i] = _ptr[i];
				if (n > _cap){
					for (size_type i = 0; i < _cap; i++)
						_allocator.destroy(_ptr + i);
					_allocator.deallocate(_ptr, _cap);
					_cap = n; // here
					_ptr = _allocator.allocate(_cap);
				for(size_type i = 0; i < _cs; i++)
					_ptr[i] = _tmp[i];
				}
			}
			void	DestroyV()
			{
				size_type _cc = capacity();
				for (size_type i = 0; i < _cc; i++)
					_allocator.destroy(_ptr + i);
				_allocator.deallocate(_ptr, _cc);
			}
		public: /* iterator Function */
			iterator begin(){
				return iterator(_ptr);
			};
			const_iterator begin() const{
				return const_iterator(_ptr);
			};
			reverse_iterator rbegin(){
				return reverse_iterator(end() - 1);
			};
			reverse_iterator rend(){
				return reverse_iterator(begin() - 1);
			};
			iterator end(){
				return iterator(_ptr + _size);
			};
			const_iterator end() const{
				return const_iterator(_ptr + _size);
			};
		public: /* Capacity Function */
			size_type size() const{
				return _size;
			};
			size_type max_size() const{
				return _allocator.max_size();
			}
			size_type capacity() const{
				return _cap;
			};
			bool empty() const{
				return ((_size != 0)? false : true);
			};
			void resize (size_type n, value_type val = value_type()){
				if (n < _size){
					for (size_type i = n; i < _size; i++)
						_allocator.destroy(_ptr + i);
					_size = n;
					}
				else if(n > _size)
				{
					Mreallocat(n);//, val);
					size_type _cs = size();
					if (n > _cs)
						for (size_type i = _cs; i < n; i++)
						{
							_ptr[i] = val;
						}
					_size = n;
				}
			};
			void reserve (size_type n){
				size_type _cs = size();
				size_type _ccap = capacity();
				if (n > max_size())
					throw std::length_error("Size beyond Max_size");
				else if(n > _ccap)
					Mreallocat(n);
			};
		public: /* Vector Operators */
			vector& operator= (const vector& rhs){
				if(_cap != 0)
					_allocator.deallocate(_ptr, _cap);
				this->_allocator = rhs._allocator;
				this->_cap = rhs._cap;
				this->_size = rhs._size;
				_ptr = _allocator.allocate(_cap);
				for (size_type i = 0 ; i < _size; i++)
					_ptr[i] = rhs._ptr[i];
				return *this;
			};
			reference operator[] (size_type n){
				return _ptr[n];
			};
			const_reference operator[] (size_type n) const{
				return _ptr[n];
			};
			reference at (size_type n){
				return _ptr[n];
			};
			const_reference at (size_type n) const{
				return _ptr[n];
			};
			reference front(){
				return _ptr[0];
			};
			const_reference front() const{
				return _ptr[0];
			};
			reference back(){
				return _ptr[_size - 1];
			};
			const_reference back() const{
				return _ptr[_size - 1];
			};
		public: /* Modifiers Functions */
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type assign (InputIterator first, InputIterator last){
			size_type _rs = std::distance(first, last);
			if (_rs > max_size())
					throw std::length_error("Size beyond Max_size");
			if (_rs > _cap){
				DestroyV();
				_cap = _rs * 2;
				_size = _rs;
				_ptr = _allocator.allocate(_cap);
				for (size_type i = 0; i < _size; i++)
					_ptr[i] = *(first++);
			}else{
				for (size_type i = _rs; i < _size; i++)
					_allocator.destroy(_ptr + i);
				_size = _rs;
				for (size_type i = 0; i < _size; i++)
					_ptr[i] = *(first++);
			}
		};
		void assign (size_type n, const value_type& val){
			if (n > max_size())
					throw std::length_error("Size beyond Max_size");
			if (n > _cap){
				DestroyV();
				_cap = n * 2;
				_size = n;
				_ptr = _allocator.allocate(_cap);
				for (size_type i = 0; i < _size; i++)
				{
					_ptr[i] = val;
				}
			}
			else
			{
				for (size_type i = n; i < _size; i++)
					_allocator.destroy(_ptr + i);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					_ptr[i] = val;
			}
		};
		void push_back (const value_type& val){
			size_type _cs = size();
			if (_cs < _cap)
			{
				_ptr[_cs] = val;
				_size++;
			}
			else{
				_cap = ((_cap == 0)? 1 : _cap * 2);
				pointer tmp = _allocator.allocate(_cap);
				for (size_type i = 0; i < _size; i++)
				{
					tmp[i] = _ptr[i];
					_allocator.destroy(_ptr + i);
				}
				_allocator.deallocate(_ptr, _cap / 2);
				_ptr = tmp;
				_ptr[_size] = val;
				_size++;
			}
		};
		void pop_back(){
			_allocator.destroy(_ptr + --_size);
		};
		iterator insert (iterator position, const value_type& val){
			size_type _pos = distance(begin(), position);
			size_type _csz = size();
			size_type _ccp = capacity();
			if (_csz != 0){
				if (_csz >= _ccp)
					Mreallocat(_csz * 2);
				for (size_type i = size(); i > _pos; i--)
					_ptr[i] = _ptr[i - 1];
				_ptr[_pos] = val;
				_size++;
			}
			else
				push_back(val);
			return iterator(&_ptr[_pos]);
		}
		void insert (iterator position, size_type n, const value_type& val){	
			int i = 0;
			while (i < n){
				insert(position, val);
				i++;
			}
		};
		
		template <class InputIterator>
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type insert (iterator position, InputIterator first, InputIterator last){
				size_type _dis = distance(first, last); //todo
				typename InputIterator::pointer _tmp = _allocator.allocate(_dis);
				int cp = 0;
				for (InputIterator i = first; i != last; i++)
				{
					_tmp[cp] = *i;
					cp++;
				}
				int i = _dis - 1;
				while ( i >= 0)
				{
					insert(position, _tmp[i]);
					i--;
				}
				_allocator.deallocate(_tmp, _dis);
			};
			iterator erase (iterator position){
				size_type _dis = distance(begin(), position);
				_allocator.destroy(_ptr + _dis);
				--_size;
				for (size_type i = _dis; i < size(); i++)
					_ptr[i] = _ptr[i + 1];
				return (_ptr + _dis);
			};
			iterator erase (iterator first, iterator last){
				size_type _dis = distance(begin(), first);
				size_type _n = distance(first, last);
				for (size_type i = _dis; i < _n; i++)
					_allocator.destroy(_ptr + i);
				_size -= _n;
				for (size_type i = _dis; i < size(); i++)
					_ptr[i] = _ptr[i + _n];
				return (_ptr + _dis);
			};
			void swap (vector& x){
				vector<T> tmp;
				tmp = *this;
				*this = x;
				x = tmp;
			};
			void clear(){
				for (size_t i = 0; i < _size; i++)
					_allocator.destroy(_ptr + i);
				_size = 0;
			};
			
			/* Get_allocator*/
			allocator_type get_allocator() const{
				return _allocator;
			};
		private:
			size_type		_size;
			size_type		_cap;
			pointer			_ptr;
			allocator_type	_allocator;
	};
	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return (lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		};
		
	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return !(lhs == rhs);
		};
	template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return	ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		};
	template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return (rhs > lhs)
		};
	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return !(rhs < lhs);
		};
}

#endif /* VECTOR_HPP */

	// template<class T>
	// struct iterator_traits<const T*>
	// {
	// 	typedef ptrdiff_t difference_type;
	// 	typedef T value_type;
	// 	typedef T* pointer;
	// 	typedef T& reference;
	// 	typedef std::random_access_iterator_tag iterator_category;
	// };

	// template <typename Vector>
	// class vectorIterator{
	// 	public:
    // 		typedef typename Vector::pointer	                               iterator_type;
	// 	    typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
	// 		typedef typename iterator_traits<iterator_type>::value_type        value_type;
	// 		typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
	// 		typedef typename iterator_traits<iterator_type>::pointer           pointer;
	// 		typedef typename iterator_traits<iterator_type>::reference         reference;
	// 		// typedef ptrdiff_t difference_type;
	// 		// typedef	typename Vector::value_type value_type;
	// 		// typedef value_type*		pointer;
	// 		// typedef value_type&		referance;
	// 	public:
	// 		vectorIterator(pointer ptr):_ptr(ptr){
	// 		};

	// 		// vectorIterator(vectorIterator const & rhs){
	// 		// 	*this = rhs;
	// 		// };
			
	// 		// vectorIterator &operator=(vectorIterator const &rhs){
	// 		// 	this->_ptr = rhs._ptr;
	// 		// 	return *this;
	// 		// }
			
	// 		value_type &operator*(){
	// 			return *_ptr;
	// 		}
	// 		vectorIterator operator++(int){
	// 			vectorIterator tmp = *this;
	// 			++_ptr;
	// 			return tmp;
	// 		}
	// 		vectorIterator	operator++(){
	// 			++_ptr;
	// 			return *this;
	// 		}
	// 		vectorIterator	operator--(int){
	// 			vectorIterator tmp = *this;
	// 			--_ptr;
	// 			return tmp;
	// 		}
	// 		vectorIterator	operator--(){
	// 			--_ptr;
	// 			return *this;
	// 		}
	// 		pointer			operator->(){
	// 			return _ptr;
	// 		}
	// 		bool			operator==(vectorIterator const &rhs){
	// 			return (this->_ptr == rhs._ptr);
	// 		}
	// 		bool			operator!=(vectorIterator const &rhs){
	// 			return (this->_ptr != rhs._ptr);
	// 		}
	// 		~vectorIterator(){};
	// 	private:
	// 		pointer _ptr;
	// };