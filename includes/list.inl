#include "list.h"

template<typename T>
list<T>::list( void ) : m_head(nullptr), m_size(0)
{
	/*Empty*/
}

template<typename T>
list<T>::list(typename list<T>::size_type count )
{
	m_size = count;
	/*TODO: A criação dos nodes até count... talvez...*/
}

template<typename T>
list<T>::list( const list& other )
{
	this->m_head = other->m_head;
	this->m_size = other->m_size;

	/*TODO: Cópia profunda dos nodes*/
}

template<typename T>
list<T>::list( std::initializer_list<T> ilist )
{
	
}