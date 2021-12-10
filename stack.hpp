#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft{
	template <class T, class Container = ft::vector<T> >
		class stack{
			public:
				typedef Container								container_type;
				typedef typename container_type::value_type		value_type;
				typedef typename container_type::size_type		size_type;
			public:
				explicit stack (const container_type& ctnr = container_type()):
					c(ctnr){
				};
				bool empty() const{
					return c.empty();
				};
				size_type size() const{
					return c.size();
				};
				value_type& top(){
					return c.back();
				};
				const value_type& top() const{
					return c.back();
				};
				void push (const value_type& val){
					c.push_back(val);
				};
				void pop(){
					c.pop_back();
				};
				~stack(){};
		protected:
				container_type c;
			template <class _T, class C>
				friend bool operator== (const stack<_T,C>& lhs, const stack<_T,C>& rhs);
			template <class _T, class C>
				friend bool operator!= (const stack<_T,C>& lhs, const stack<_T,C>& rhs);
			template <class _T, class C>
				friend bool operator<  (const stack<_T,C>& lhs, const stack<_T,C>& rhs);
			template <class _T, class C>
				friend bool operator<= (const stack<_T,C>& lhs, const stack<_T,C>& rhs);
			template <class _T, class C>
				friend bool operator>  (const stack<_T,C>& lhs, const stack<_T,C>& rhs);
			template <class _T, class C>
				friend bool operator>= (const stack<_T,C>& lhs, const stack<_T,C>& rhs);
		};
		template <class _T, class C>
			bool operator== (const stack<_T,C>& lhs, const stack<_T,C>& rhs){return lhs.c == rhs.c;};
		template <class _T, class C>
			bool operator!= (const stack<_T,C>& lhs, const stack<_T,C>& rhs){return lhs.c != rhs.c;};
		template <class _T, class C>
			bool operator<  (const stack<_T,C>& lhs, const stack<_T,C>& rhs){return lhs.c < rhs.c;};
		template <class _T, class C>
			bool operator<= (const stack<_T,C>& lhs, const stack<_T,C>& rhs){return lhs.c <= rhs.c;};
		template <class _T, class C>
			bool operator>  (const stack<_T,C>& lhs, const stack<_T,C>& rhs){return lhs.c > rhs.c;};
		template <class _T, class C>
			bool operator>= (const stack<_T,C>& lhs, const stack<_T,C>& rhs){return lhs.c >= rhs.c;};
};
#endif /* STACK_HPP */
