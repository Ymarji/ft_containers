/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarji <ymarji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:49:50 by ymarji            #+#    #+#             */
/*   Updated: 2021/09/29 15:52:12 by ymarji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <stack>
#include <vector>
#include <algorithm>
#include <memory>
namespace ft
{
	template < typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
				typedef T											value_type;
				typedef value_type*									pointer;
				typedef value_type&									referance;
				typedef Alloc	/*---------------------------->*/	allocator_type;
				typedef typename allocator_type::size_type			size_type;
		public:
				vector<T, Alloc>():
				_size(0),
				_cap(0),{
					_ptr = _allocator.allocate(0);
				};
				vector(size_type n, const value_type &val = value_type(),\
						const allocator_type &alloc = allocator_type()):
				_size(n),
				_cap(n),
				_allocator(alloc)
				{
					_ptr = _allocator.allocate(_cap);
					for (size_type i = 0 ; i < _cap; i++)
						_ptr[i] = val;
				};
				template <class	InIterator>
				vector(InIterator first, InIterator last,\
						const allocator_type &alloc = allocator_type()):
				_size(std::distance(first, last)),
				_cap(_size)
				{
					_ptr = _allocator.allocate(_cap);
					for (size_t i = 0; i <= _cap; i++)
					{
						_ptr[i] = *first;
						++first;
					}
				};
				vector(vector const &rhs){
					*this = rhs;
				};
		private:
			size_type		_size;
			size_type		_cap;
			pointer			_ptr;
			allocator_type	_allocator;
	};
} 


#endif /* VECTOR_HPP */
