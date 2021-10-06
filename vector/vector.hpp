/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarji <ymarji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:49:50 by ymarji            #+#    #+#             */
/*   Updated: 2021/10/06 10:10:56 by ymarji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
// #include <stack>
#include <iterator>
// #include <vector>
#include <algorithm>
#include <memory>
#define put(x) std::cout << x << std::endl
namespace ft
{

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename  std::random_access_iterator_tag iterator_category;
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
	class iterator
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
		public:
			vector<T, Alloc>():
			_size(0),
			_cap(0){
				_ptr = _allocator.allocate(0);
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
		public:
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