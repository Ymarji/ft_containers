/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itarator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarji <ymarji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:05:03 by ymarji            #+#    #+#             */
/*   Updated: 2021/11/06 14:15:43 by ymarji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITARATOR_TRAITS_HPP
#define ITARATOR_TRAITS_HPP

#include <cstddef>
#include <algorithm>
#include <memory>
#include <iostream>
#include <stdexcept>

namespace ft{
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

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
};

#endif /* ITARATOR_TRAITS_HPP */
