#ifndef STACK_HPP
#define STACK_HPP

#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
	class stack{
		public:
			typedef Container								container_type;
			typedef typename container_type::value_type		value_type;
			// C++11
			// typedef typename container_type::reference       reference;
			// typedef typename container_type::const_reference const_reference;
			typedef typename container_type::size_type		size_type;
		public:
			stack():c(){
			};
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
	};
	template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){lhs == rhs};
	template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){lhs != rhs};
	template <class T, class Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){lhs < rhs};
	template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){lhs <= rhs};
	template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){lhs > rhs};
	template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){lhs >= rhs};
#endif /* STACK_HPP */
