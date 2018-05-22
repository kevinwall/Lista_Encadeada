#ifndef List_H
#define List_H


#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cstring>
#include <utility>


namespace sc
{
	template<typename T>
	/**
	*@brief Classe lista que será implementada neste projeto.
	*@param	size_type m_size: Tamanho de blocos da lista.
	*@param	Node* m_head: Ponteiro para o primeiro bloco da lista.
	*@param	Node* m_tail: Ponteiro para o ultimo bloco da lista.
	*/
	class list
	{
		/**
		*@brief Alias para facilitar a manutenção da classe.
		*/
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

			/**
			*@brief Classe node que é a subclasse de list que irá representar os blocos de memória com o conteúdo da lista.
			*@param T m_data: Conteúdo do bloco.
			*@param	Node* m_next: ponteiro mostrando o local na memória onde está o proximo bloco.
			*@param Node* m_prev: ponteiro mostrando o local na memória onde está o bloco anterior.
			*/
			class Node
			{
				public:
					T m_data;
					Node* m_next;
					Node* m_prev;
			};

		private:
			size_type m_size;
			Node m_head;
			Node m_tail;
	};

	#include "list.inl"
}

#endif