#include "list.h"

/**
*@brief Construtor defaut, que cria uma lista nula.
*/
template<typename T>
list<T>::list( void ) : m_size(0), m_head(), m_tail()
{
	/*Empty*/
}


/**
*@brief Construtor Count que cria Count quantiades de nodes com um valor T padrão.
*@param size_type count: Quantidade de nodes que o usuário deseja criar.
*/
template<typename T>
list<T>::list(typename list<T>::size_type count )
{
	this->m_size = count;
	Node* atual;
	Node* prev;
	
	size_type i;

	for(i = 0; i < count; i++)
	{
		Node* new_node = new Node; //Em teste

		if(i == 0)
		{
			atual = new_node;
			prev = atual;
			m_head.m_next = atual;
		}
		else
		{
			atual = new_node;
			prev->m_next = atual;
			atual->m_prev = prev;
			prev = prev->m_next;
		}
	}

	prev->m_next = nullptr;
	m_tail.m_prev = prev;
	prev = m_head.m_next;
	prev->m_prev = nullptr;
}

/**
*@brief Construtor range que recebe um intervalo para inserir na lista.
*@param InputIt first: Início do intervalo a ser inserido.
*@param InputIt last: Final do intervalo a ser inserido.
*/
template<typename T>
template< typename InputIt >
list<T>::list( InputIt first, InputIt last )
{
	Node* atual;
	Node* prev;
	InputIt first_f = first;

	while(first_f != last)
	{
		Node* new_node = new Node;

		if(first == first_f)
		{
			m_head.m_next = new_node;
			atual = new_node;
			atual->m_data = *first_f;

			first_f++;
		}
		else
		{
			prev = atual;
			atual->m_next = new_node;
			atual = atual->m_next;
			atual->m_prev = prev;

			atual->m_data = *first_f;

			first_f++;
		}
	}

	m_tail.m_prev = atual;
}

/**
*@brief Construtor Cópia que cria uma "cópia profunda" de outra lista passada como parâmetro.
*@param const list& other: Referência para a lista que se deseja copiar.
*/
template<typename T>
list<T>::list( const list& other )
{
	list<T> *ponteiro;
	ponteiro = const_cast<list<T>*>(&other);

	this->m_size = ponteiro->m_size;

	Node* origin; 
	Node* copy;
	Node* prev;
	origin = ponteiro->m_head.m_next;

	//EXPERIMENTAL.
	Node* node_principal = new Node;
	copy = node_principal;
	m_head.m_next = copy;

	while(origin->m_next != nullptr)
	{

		Node* new_node = new Node;
		prev = copy;

		copy->m_data = origin->m_data;
		copy->m_next = new_node;


		if(copy == m_head.m_next)
		{
			copy->m_prev = nullptr;
			copy = copy->m_next;
			origin = origin->m_next;
		}
		else
		{
			copy = copy->m_next;
			origin = origin->m_next;
			copy->m_prev = prev;
		}
	}
	
	copy->m_data = origin->m_data;
	copy->m_prev = prev;
	m_tail.m_prev = copy;

}

/**
*@brief Construtor com a lista inicializadora, que copia todos os elementos da lista inicializadora e os coloca na lista encadeada.
*@param std::initializer_list<T> ilist: lista que śerá utilizada para a cópia.
*/
template<typename T>
list<T>::list( std::initializer_list<T> ilist )
{
	Node* prev;
	Node* atual;
	Node* prev_2;

	int *i;

	for(i = (int*)ilist.begin(); i < (int*)ilist.end(); i++)
	{
		Node* new_node = new Node;

		if(i == ilist.begin())
		{
			atual = new_node;
			atual->m_data = *i;

			prev = atual;
			m_head.m_next = atual;
			this->m_size = ilist.size();
			atual->m_prev = nullptr;
		}
		else
		{
			atual = new_node;
			atual->m_data = *i;

			prev->m_next = atual;
			prev_2 = prev;
			prev = prev->m_next;
			prev->m_prev = prev_2;
		}
	}

	prev->m_prev = prev_2;
	prev->m_next = nullptr;
	m_tail.m_prev = prev;
}

/**
*@brief Destrutor da classe.
*/
template<typename T>
list<T>::~list()
{
	Node* atual;
	Node* prev;

	if( m_head.m_next != nullptr)
	{
		atual = m_head.m_next;

		while(atual->m_next != nullptr)
		{

			prev = atual;
			atual = atual->m_next;

			delete prev;
		}

		delete atual;
	}
}

/**
*@brief Operador de atribuição cópia, que cria uma cópia do conteúdo de uma lista encadeada passada como parâmetro.
*@param const list& other: Lista a ser copiada.
*/
template<typename T>
list<T> & list<T>::operator=( const list& other )
{
	//TESTE
	list<T> *ponteiro;
	ponteiro = const_cast<list<T>*>(&other);

	if(this->m_size == ponteiro->m_size)
	{
		Node* atual; 
		Node* prev;

		atual = m_head.m_next;
		prev = ponteiro->m_head.m_next;

		while(prev->m_next != nullptr)
		{
			atual->m_data = prev->m_data;
			atual = atual->m_next;
			prev = prev->m_next;
		}

		atual->m_data = prev->m_data;
		m_tail.m_prev = atual;
	}
	else
	{
		clear();

		list<T> *ponteiro;
		ponteiro = const_cast<list<T>*>(&other);

		this->m_size = ponteiro->m_size;

		Node* origin; 
		Node* copy;
		Node* prev;
		origin = ponteiro->m_head.m_next;

		//EXPERIMENTAL.
		Node* node_principal = new Node;
		copy = node_principal;
		m_head.m_next = copy;

		while(origin->m_next != nullptr)
		{

			Node* new_node = new Node;
			prev = copy;

			copy->m_data = origin->m_data;
			copy->m_next = new_node;


			if(copy == m_head.m_next)
			{
				copy->m_prev = nullptr;
				copy = copy->m_next;
				origin = origin->m_next;
			}
			else
			{
				copy = copy->m_next;
				origin = origin->m_next;
				copy->m_prev = prev;
			}
		}
	
		copy->m_data = origin->m_data;
		copy->m_prev = prev;
		m_tail.m_prev = copy;
	}

	return *this;
}

/**
*@brief Operador de atribuição cópia que copia o conteúdo de uma lista inicializadora para a lista encadeada.
*@param std::initializer_list<T> ilist: Lista com os valores a serem copiados.
*/
template<typename T>
list<T> & list<T>::operator=( std::initializer_list<T> ilist )
{
	if(this->m_size == ilist.size())
	{
		Node* atual;
		Node* prev;

		atual = m_head.m_next;

		int* i;

		i = (int*)ilist.begin();

		while(atual->m_next != nullptr)
		{
			prev = atual;
			atual->m_data = *i;

			atual= atual->m_next;
			atual->m_prev = prev;
			i++;
		
		}

		atual->m_prev = prev;
		atual->m_data = *i;
		m_tail.m_prev = atual;
	}
	else
	{
		clear();

		Node* prev;
		Node* atual;
		Node* prev_2;

		int *i;

		for(i = (int*)ilist.begin(); i < (int*)ilist.end(); i++)
		{
			Node* new_node = new Node;

			if(i == ilist.begin())
			{
				atual = new_node;
				atual->m_data = *i;

				prev = atual;
				m_head.m_next = atual;
				this->m_size = ilist.size();
				atual->m_prev = nullptr;
			}
			else
			{
				atual = new_node;
				atual->m_data = *i;

				prev->m_next = atual;
				prev_2 = prev;
				prev = prev->m_next;
				prev->m_prev = prev_2;
			}
		}

		prev->m_prev = prev_2;
		prev->m_next = nullptr;
		m_tail.m_prev = prev;

	}
	
	return *this;
}

/**
*@brief Função size que retorna a quantidade de nodes(blocos com informação) existentes na lista.
*/
template<typename T>
typename list<T>::size_type list<T>::size() const
{
	return this->m_size;
}

/**
*@brief Função clear que limpa (Fisicamente) a lista.
*/
template<typename T>
void list<T>::clear()
{
	if(m_head.m_next != nullptr)
	{
		Node* fast;
		Node* slow;
		fast = m_head.m_next;

		while(fast->m_next != nullptr)
		{
			slow = fast;
			fast = fast->m_next;

			if(slow != m_head.m_next)
			{
				delete slow;
			}
			else
			{
				slow->m_data.~T();
				slow->m_next = nullptr;
			}
			
		}

		delete fast;
		m_tail.m_prev = m_head.m_next;
	}
}

/**
*@brief Função empty, que retorna true caso a lista seja vazia e false caso contrário.
*/
template<typename T>
bool list<T>::empty()
{
	return (this->m_size == 0);
}


/**
*@brief Função back, que retorna o ultimo objeto da lista.
*/
template<typename T>
const T & list<T>::back() const
{
	return (m_tail.m_prev->m_data);
}

/**
*@brief Função front, que retorna o primeiro objeto da lista.
*/
template<typename T>
const T & list<T>::front() const
{
	return (m_head.m_next->m_data);
}

/**
*@brief Operador == utilizado para comparar as listas.
*@param const list& rhs: Lista a ser comparada com a this.
*/
template<typename T>
bool list<T>::operator==(const list& rhs )
{
	

	if(this->m_size != rhs.m_size)
	{
		return false;
	}
	else
	{
		Node* atual;
		Node* rhs_atual;

		rhs_atual = rhs.m_head.m_next;
		atual = m_head.m_next;
		
		while(atual != nullptr)
		{
			if(atual->m_data != rhs_atual->m_data)
			{
				return false;
			}

			atual = atual->m_next;
			rhs_atual = rhs_atual->m_next;
		}

		return true;
	}
}

template<typename T>
typename list<T>::Node* list<T>::get_head()
{
	return (this->m_head.m_next);
}

template <typename T>
void list<T>::push_front(const T & value){
	Node * atual = new Node;

	atual->m_data = value;
	atual->m_next = this->m_head.m_next;
	this->m_head.m_next = atual;

}

template <typename T>
void list<T>::push_back(const T & value){
	Node * atual = new Node;

	if(this->m_head.m_next == nullptr){
		this->m_head.m_next = atual;
	}

	atual->m_data = value;
	atual->m_prev = m_tail.m_prev;
	m_tail.m_prev = atual;
}

template <typename T>
void list<T>::pop_back(){
	Node * atual;

	if(m_tail.m_prev != nullptr){
		atual = m_tail.m_prev;
		m_tail.m_prev = atual->m_prev;
		delete atual;
	}

}

template <typename T>
void list<T>::pop_front(){
	Node * atual;

	if(m_head.m_next != nullptr){
		atual = m_head.m_next;
		m_head.m_next = atual -> m_next;
		delete atual;
	}
}

template <typename T>
void list<T>::assign( const T & value){
	Node *atual = m_head.m_next;

	while ( atual -> m_next != nullptr){
		atual->m_data = value;
		atual = atual->m_next;
	}

	atual->m_data = value;
}


template <typename T>
bool list<T>::operator !=( const list& rhs){
	if(this->m_size != rhs.m_size){
		return true;
	}else{
		Node *atual = m_head.m_next;
		Node *atualrhs = rhs.m_head.m_next;
		
		while( atual != nullptr){
			if( atual->m_data != atualrhs->m_data){
				return true;
			}
			atual = atual->m_next;
			atualrhs = atualrhs->m_next;
		}
	}

	return false;

}

/**
*@brief Método para printar o iterator atual.
*/
template<typename T>
void list<T>::iterator::print()
{
	std::cout<<"Valor do iterator: "<<m_element<<std::endl;
}
/**
*@brief Função begin do iterator.
*/
template <typename T>
typename list<T>::iterator list<T>::begin()
{
	return iterator(m_head.m_next);
}

/**
*@brief Função end do iterator.
*/
template<typename T>
typename list<T>::iterator list<T>::end()
{
	return iterator(m_tail.m_prev);
}

/**
*@brief Operador = do iterator.
*@param iterator rhs: iterador a ser copiado.
*/
template<typename T>
typename list<T>::iterator list<T>::iterator::operator=( iterator rhs )
{
	this->m_element = rhs.m_element;

	return *this;
}

/**
*@brief Operador ++ do iterator (it++).
*/
template<typename T>
typename list<T>::iterator list<T>::iterator::operator++()
{
	m_element = m_element->m_next;

	return *this;
}

/**
*@brief Operador ++ do iterator (++it).
*@param iterator it: iterador que será avançado. 
*/
template<typename T>
typename list<T>::iterator list<T>::iterator::operator++(int)
{
	auto it = *this;

	m_element = m_element->m_next;

	return it;
}

/**
*@brief Operador -- do iterator (it--).
*/
template<typename T>
typename list<T>::iterator list<T>::iterator::operator--()
{
	m_element = m_element->m_prev;

	return *this;
}

/**
*@brief Operador -- do iterator (--it).
*@param iterator it: iterador a ser regredido.
*/
template<typename T>
typename list<T>::iterator list<T>::iterator::operator--(int)
{
	auto it = *this;

	m_element = m_element->m_prev;

	return it;
}

/**
*@brief Operador * do iterator, que retorna o valor armazenado na posição do iterador.
*/
template <typename T>
T& list<T>::iterator::operator*()
{
	return this->m_element->m_data;
}

/**
*@brief Operador == do iterator, que compara os valores dos iteradores e veem se são iguais.
*@param iterator rhs: segundo iterador para comparar com o this.
*/
template<typename T>
bool list<T>::iterator::operator==(iterator rhs)
{
	return (this->m_element == rhs.m_element);
}

/**
*@brief Operador != do iterator, que compara os valores dos iteradores e veem se são diferentes.
*@param iterator rhs: segundo iterador para comparar com o this.
*/
template<typename T>
bool list<T>::iterator::operator!=(iterator rhs)
{
	return (this->m_element != rhs.m_element);
}

template<typename T>
typename list<T>::iterator list<T>::insert( iterator pos,const T & value){
	iterator it = pos;

	it--;

	it.m_element->m_data = value;
	return it;

}
