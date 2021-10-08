/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarji <ymarji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:49:50 by ymarji            #+#    #+#             */
/*   Updated: 2021/10/08 12:37:38 by ymarji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <stdexcept>      // std::length_error

// #include <stack>
#include <iterator>
#include <vector>
#include <algorithm>
#include <memory>
#define put(x) std::cout << x << std::endl
namespace ft
{
	// template <bool Cond, class T = void>
	// typename std::enable_if<std::is_integral<T>::value,bool>::type
	// struct enable_if{
		
	// };
	
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
		public:
			typedef Category iterator_category;
			typedef T value_type;
			typedef Distance difference_type;
			typedef Pointer pointer;
			typedef Reference reference;
	};

	template <typename T>
	class vectorIterator: public iterator<typename std::random_access_iterator_tag,
			typename iterator_traits<T>::value_type,
			typename iterator_traits<T>::difference_type,
			typename iterator_traits<T>::pointer,
			typename iterator_traits<T>::reference>
	{
		public:
			typedef T															iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type       	value_type;
			typedef typename iterator_traits<iterator_type>::difference_type  	difference_type;
			typedef typename iterator_traits<iterator_type>::pointer          	pointer;
			typedef typename iterator_traits<iterator_type>::reference        	reference;

		public:
			vectorIterator( ):_ptr(NULL){
			};
			vectorIterator(pointer ptr):_ptr(ptr){
			};
			vectorIterator(vectorIterator const &rhs):_ptr(rhs._ptr){
			};
			value_type 	&operator*() const{
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

			pointer			operator->() const{
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
			pointer _ptr;
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
			
			template <class	InputIterator>
			vector<T, Alloc>(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
			{
				_size	= std::distance(first, last);
				_cap	= _size;
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
			void	Mreallocat(size_type n)//, value_type val = value_type())
			{
				size_type _cs = size();
				allocator_type _all;
				pointer _tmp;
				_tmp = _ptr;
				if (n > _cap){
					_cap = 2 * n;
					for (size_type i = 0; i < _cap; i++)
						_allocator.destroy(_ptr + i);
					_allocator.deallocate(_ptr, _cap);
					_ptr = _allocator.allocate(_cap);
				for(size_type i = 0; i < _cs; i++)
					_ptr[i] = _tmp[i];
				}
			}
			void	DestroyV()
			{
				size_type _cc = capacity();
				for (size_type i = 0; i < _CTYPE_C; i++)
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
				this->_allocator = rhs._allocator;
				this->_cap = rhs._cap;
				this->_size = rhs._size;
				_ptr = _allocator.allocate(_cap);
				for (size_type i = 0 ; i < _cap; i++)
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
		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last){
		// };
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
		private:
			size_type		_size;
			size_type		_cap;
			pointer			_ptr;
			allocator_type	_allocator;
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