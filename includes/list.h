#ifndef List_H
#define List_H


#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cstring>
#include <utility>
#include <iterator>

namespace sc
{
	

	/*
	
	*/
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

					
					Node(const T & d = T(), Node* p = nullptr, Node* n = nullptr) : m_data(d), m_next(n), m_prev(p)
					{
						//Empty
					}
					
			};

			/**
			*@brief Classe iterator que tem todas as funções para manipulação do iterator na lista como também de comparação
			*@param Nod * m_element
			*/

			class iterator
			{
	
				public:

					iterator( void ) : m_element(nullptr)
					{
						//Empty
					}

					iterator(Node* ponteiro) : m_element(ponteiro)
					{
						//Empty
					}

					iterator operator=( iterator rhs );

					iterator operator++();

					iterator operator++(T);

					iterator operator--();

					iterator operator--(T);

					T& operator*();

					bool operator==(iterator rhs);

					bool operator!=(iterator rhs);

					Node* m_element;
			};

			/**
			*@brief Classe iterator que tem todas as funções para manipulação do iterator na lista como também de comparação
			*@param Nod * m_element
			*/

			class const_iterator
			{
				public:

					const_iterator( void ) : m_const_element(nullptr)
					{
						//Empty
					}

					const_iterator(Node* ponteiro) : m_const_element(ponteiro)
					{
						//Empty
					}

					const_iterator operator=( const_iterator rhs ) const;

					const_iterator operator++() const;

					const_iterator operator++(T) const;

					const_iterator operator--() const;

					const_iterator operator--(T) const;

					T& operator*() const;

					bool operator==(const_iterator rhs) const;

					bool operator!=(const_iterator rhs) const;

					Node* m_const_element;
			};

			//Métodos com iterator.
			iterator begin();

			iterator end();

			iterator insert( iterator pos, const T & value);

			template <typename InItr>
			iterator insert( iterator pos, InItr first, InItr last ); 

			iterator insert( iterator pos, std::initializer_list<T> ilist );

			iterator erase( iterator pos );

			iterator erase( iterator first, iterator last ); 

			void assign( size_type count, const T& value );

			void assign( iterator first, iterator last );

			void assign( std::initializer_list<T> ilist );

			//Métodos com const iterator.
			const_iterator begin() const;

			const_iterator end() const;

			const_iterator insert( const_iterator pos, const T & value) const;

			template <typename InItr>
			const_iterator insert( const_iterator pos, InItr first, InItr last ) const; 

			const_iterator insert( const_iterator pos, std::initializer_list<T> ilist ) const;

			const_iterator erase( const_iterator pos ) const;

			const_iterator erase( const_iterator first, const_iterator last ) const; 

			void assign( size_type count, const T& value ) const;

			void assign( const_iterator first, const_iterator last )const ;

			void assign( std::initializer_list<T> ilist )const ;

		private:
			size_type m_size;
			Node m_head;
			Node m_tail;
	};

	#include "list.inl"
}

#endif