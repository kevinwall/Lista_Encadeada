#ifndef List_H
#define List_H


#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cstring>
#include <utility>
#include <vector>


namespace sc
{
	template<typename T>
	class list
	{
		typedef T value_type;
		typedef size_t size_type;
		typedef T* pointer;
		typedef T& reference;

		public:

			list();

			explicit list( size_type count );

			template< typename InputIt >
			list( InputIt first, InputIt last );

			list( const list& other );

			list( std::initializer_list<T> ilist );

			~list();

			list& operator=( const list& other );

			list& operator=( std::initializer_list<T> ilist );

			size_type size() const;

			void clear();

			bool empty();

			void push_front( const T & value );

			void push_back( const T & value );

			void pop_back();

			void pop_front();

			const T & back() const;

			const T & front() const;

			void assign( const T & value );

			bool operator==(const list& rhs );

			bool operator!=(const list& rhs );

			class Node
			{
				public:
					T m_data;
					Node* m_next;
					Node* m_prev;
			};

		private:
			size_type m_size;
			Node* m_head;
			//Node & m_tail;
	};

	#include "list.inl"
}

#endif