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

	T *i;

	for(i = (T*)ilist.begin(); i < (T*)ilist.end(); i++)
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

		T* i;

		i = (T*)ilist.begin();

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

		for(i = (T*)ilist.begin(); i < (T*)ilist.end(); i++)
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

template <typename T>
void list<T>::push_front(const T & value){
	Node * atual = new Node;

	atual->m_data = value;
	atual->m_next = this->m_head.m_next;
	this->m_head.m_next = atual;

	this->m_size++;

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

	this->m_size++;
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
*/
template<typename T>
typename list<T>::iterator list<T>::iterator::operator++(T)
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
*/
template<typename T>
typename list<T>::iterator list<T>::iterator::operator--(T)
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

/**
*@brief Função insert que insere um valor na posição anterior a pos, retornando a posição onde o valor foi inserido.
*@param iterator pos: iterador indicando a posição após o local onde o valor será inserido.
*@param const T & value: Valor que será inserido antes de pos.
*/
template<typename T>
typename list<T>::iterator list<T>::insert( iterator pos, const T & value)
{
	iterator it = pos;

	it--;

	it.m_element->m_data = value;
	return it;

}

/**
*@brief Função insert que insere um intervalo first->last a partir da posiçao anterior a pos, retornando a posição do ultimo valor inserido.
*@param iterator pos: posição logo após de onde o valor será inserido.
*@param InItr first: começo do intervalo que será inserido.
*@param InItr last: final do intervalo que será inserido.
*/
template <typename T>
template <typename InItr>
typename list<T>::iterator list<T>::insert( iterator pos, InItr first, InItr last )
{
	iterator atual = pos;

	atual--;

	while(first != last)
	{
		if(atual.m_element->m_next != nullptr)
		{
			atual.m_element->m_data = *first;
			atual++;
		}
		else
		{
			Node* new_node = new Node;

			new_node->m_data = *first;

			atual.m_element->m_next = new_node;

			new_node = atual.m_element;

			atual++;

			atual.m_element->m_prev = new_node;

			this->m_size++;
		}

		first++;
	}

	return atual;
}

/**
*@brief Função insert que insere uma lista inicializadora antes de pos e retorna a posição do ultimo elemento inserido.
*@param iterator pos: iterador para a posição após onde o valor será inserido.
*@param std::initializer_list<T> ilist: lista inicializadora que será inserida na lista.
*/
template<typename T>
typename list<T>::iterator list<T>::insert( iterator pos, std::initializer_list<T> ilist )
{
	iterator atual = pos;

	atual--;

	T* i;

	for(i = (T*)ilist.begin(); i < (T*)ilist.end(); i++)
	{
		if(atual.m_element->m_next != nullptr)
		{
			atual.m_element->m_data = *i;
			atual++;
		}
		else
		{
			Node* new_node = new Node;

			new_node->m_data = *i;

			atual.m_element->m_next = new_node;

			new_node = atual.m_element;

			atual++;

			atual.m_element->m_prev = new_node;

			this->m_size++;
		}
	}

	return atual;
}

/**
*@breif Método erase que apaga um elemento da lista indicado pela posição de pos e retorna a posição do elemento após pos antes da deleção
*@param iterator pos: iterador para a posição que será deletada.
*/
template<typename T>
typename list<T>::iterator list<T>::erase( iterator pos )
{
	iterator atual = pos;

	if(atual.m_element != nullptr)
	{
		Node* prev;

		prev = atual.m_element;

		atual.m_element = atual.m_element->m_next;

		prev->m_prev->m_next = atual.m_element;

		atual.m_element->m_prev = prev->m_prev;

		delete prev;
	}

	return atual;
}

/**
*@brief Método erase que apaga um intervalo de elementos dentro da lista e retorna a posição logo após o ultimo elemento deletado.
*@param iterator first: início do intervalo.
*@param iterator last: final do intervalo.
*/
template<typename T>
typename list<T>::iterator list<T>::erase( iterator first, iterator last )
{
	iterator prev, deletar;

	if(this->m_head.m_next == first.m_element and this->m_tail.m_prev == last.m_element)
	{
		clear();
	}
	else
	{
		do
		{
			prev = first;
			deletar = prev;

			first++;

			if(prev.m_element != this->m_head.m_next)
			{
				prev--;
			}

			prev.m_element->m_next = first.m_element;
			first.m_element->m_prev = prev.m_element;

			delete deletar.m_element;
		}
		while(first != last);
	}

	return first;
} 

/**
*@brief Função assign que substitui count valores da lista por value.
*@param size_type count: quantidade de cópias de value desejadas.
*@param const T& value: valor que será inserido.
*/
template<typename T>
void list<T>::assign( size_type count, const T& value )
{
	iterator atual = this->m_head.m_next;
	size_type j, i;

	if(count > this->m_size)
	{
		j = this->m_size;
	}
	else
	{
		j = count;
	}

	for( i = 0; i < j; i++)
	{
		atual.m_element->m_data = value;
		atual++;
	}
} 

/**
*@brief Função assign que insere um intervalo dentro da lista.
*@param iterator first: começo do intervalo.
*@param interator last: final do intervalo.
*/
template<typename T>
void list<T>::assign( iterator first, iterator last )
{
	iterator atual = this->m_head.m_next;

	while(first != last)
	{
		atual.m_element->m_data = *first;
		atual++;
		first++;
	}
}

/**
*@brief Função assign que insere uma lista inicializadora na lista
*@param std::initializer_list<T> ilist: lista inicializadora que será inserida na lista.
*/
template<typename T>
void list<T>::assign( std::initializer_list<T> ilist )
{
	iterator atual = this->m_head.m_next;

	T* i;

	for( i = (T*)ilist.begin(); i < (T*)ilist.end(); i++)
	{
		atual.m_element->m_data = *i;
		atual++; 
	}
}

/**
*@brief Método begin que retorna um const_iterator para o início da lista.
*/
template <typename T>
typename list<T>::const_iterator list<T>::begin() const
{
	return const_iterator(m_head.m_next);
}

/**
*@brief Função end do const_iterator.
*/
template<typename T>
typename list<T>::const_iterator list<T>::end() const
{
	return const_iterator(m_tail.m_prev);
}

/**
*@brief Operador = do const_iterator.
*@param const_iterator rhs: iterador a ser copiado.
*/
template<typename T>
typename list<T>::const_iterator list<T>::const_iterator::operator=( const_iterator rhs ) const
{
	this->m_const_element = rhs.m_const_element;

	return *this;
}

/**
*@brief Operador ++ do const_iterator (it++).
*/
template<typename T>
typename list<T>::const_iterator list<T>::const_iterator::operator++() const
{
	m_const_element = m_const_element->m_next;

	return *this;
}

/**
*@brief Operador ++ do const_iterator (++it).
*/
template<typename T>
typename list<T>::const_iterator list<T>::const_iterator::operator++(T) const
{
	auto it = *this;

	m_const_element = m_const_element->m_next;

	return it;
}

/**
*@brief Operador -- do const_iterator (it--).
*/
template<typename T>
typename list<T>::const_iterator list<T>::const_iterator::operator--() const
{
	m_const_element = m_const_element->m_prev;

	return *this;
}

/**
*@brief Operador -- do const_iterator (--it).
*/
template<typename T>
typename list<T>::const_iterator list<T>::const_iterator::operator--(T) const
{
	auto it = *this;

	m_const_element = m_const_element->m_prev;

	return it;
}

/**
*@brief Operador * do const_iterator, que retorna o valor armazenado na posição do iterador.
*/
template <typename T>
T& list<T>::const_iterator::operator*() const
{
	return this->m_const_element->m_data;
}

/**
*@brief Função insert que insere um valor na posição anterior a pos, retornando a posição onde o valor foi inserido.
*@param const_iterator pos: iterador indicando a posição após o local onde o valor será inserido.
*@param const T & value: Valor que será inserido antes de pos.
*/
template<typename T>
typename list<T>::const_iterator list<T>::insert( const_iterator pos, const T & value) const
{
	iterator it = pos;

	it--;

	it.m_element->m_data = value;
	return it;

}

/**
*@brief Função insert que insere um intervalo first->last a partir da posiçao anterior a pos, retornando a posição do ultimo valor inserido.
*@param const_iterator pos: posição logo após de onde o valor será inserido.
*@param InItr first: começo do intervalo que será inserido.
*@param InItr last: final do intervalo que será inserido.
*/
template <typename T>
template <typename InItr>
typename list<T>::const_iterator list<T>::insert( const_iterator pos, InItr first, InItr last ) const
{
	iterator atual = pos;

	atual--;

	while(first != last)
	{
		if(atual.m_element->m_next != nullptr)
		{
			atual.m_element->m_data = *first;
			atual++;
		}
		else
		{
			Node* new_node = new Node;

			new_node->m_data = *first;

			atual.m_element->m_next = new_node;

			new_node = atual.m_element;

			atual++;

			atual.m_element->m_prev = new_node;

			this->m_size++;
		}

		first++;
	}

	return atual;
}

/**
*@brief Função insert que insere uma lista inicializadora antes de pos e retorna a posição do ultimo elemento inserido.
*@param const_iterator pos: iterador para a posição após onde o valor será inserido.
*@param std::initializer_list<T> ilist: lista inicializadora que será inserida na lista.
*/
template<typename T>
typename list<T>::const_iterator list<T>::insert( const_iterator pos, std::initializer_list<T> ilist ) const
{
	iterator atual = pos;

	atual--;

	T* i;

	for(i = (T*)ilist.begin(); i < (T*)ilist.end(); i++)
	{
		if(atual.m_element->m_next != nullptr)
		{
			atual.m_element->m_data = *i;
			atual++;
		}
		else
		{
			Node* new_node = new Node;

			new_node->m_data = *i;

			atual.m_element->m_next = new_node;

			new_node = atual.m_element;

			atual++;

			atual.m_element->m_prev = new_node;

			this->m_size++;
		}
	}

	return atual;
}

/**
*@breif Método erase que apaga um elemento da lista indicado pela posição de pos e retorna a posição do elemento após pos antes da deleção
*@param const_iterator pos: iterador para a posição que será deletada.
*/
template<typename T>
typename list<T>::const_iterator list<T>::erase( const_iterator pos ) const
{
	iterator atual = pos;

	if(atual.m_element != nullptr)
	{
		Node* prev;

		prev = atual.m_element;

		atual.m_element = atual.m_element->m_next;

		prev->m_prev->m_next = atual.m_element;

		atual.m_element->m_prev = prev->m_prev;

		delete prev;
	}

	return atual;
}

/**
*@brief Método erase que apaga um intervalo de elementos dentro da lista e retorna a posição logo após o ultimo elemento deletado.
*@param const_iterator first: início do intervalo.
*@param const_iterator last: final do intervalo.
*/
template<typename T>
typename list<T>::const_iterator list<T>::erase( const_iterator first, const_iterator last ) const
{
	iterator prev, deletar;

	if(this->m_head.m_next == first.m_const_element and this->m_tail.m_prev == last.m_const_element)
	{
		clear();
	}
	else
	{
		do
		{
			prev = first;
			deletar = prev;

			first++;

			if(prev.m_element != this->m_head.m_next)
			{
				prev--;
			}

			prev.m_element->m_next = first.m_const_element;
			first.m_const_element->m_prev = prev.m_element;

			delete deletar.m_element;
		}
		while(first != last);
	}

	return first;
}  


/**
*@brief Função assign que substitui count valores da lista por value.
*@param size_type count: quantidade de cópias de value desejadas.
*@param const T& value: valor que será inserido.
*/
template<typename T>
void list<T>::assign( size_type count, const T& value ) const
{
	iterator atual = this->m_head.m_next;
	size_type j, i;

	if(count > this->m_size)
	{
		j = this->m_size;
	}
	else
	{
		j = count;
	}

	for( i = 0; i < j; i++)
	{
		atual.m_element->m_data = value;
		atual++;
	}
} 

/**
*@brief Função assign que insere um intervalo dentro da lista.
*@param const_iterator first: começo do intervalo.
*@param const_interator last: final do intervalo.
*/
template<typename T>
void list<T>::assign( const_iterator first, const_iterator last ) const
{
	iterator atual = this->m_head.m_next;

	while(first != last)
	{
		atual.m_element->m_data = *first;
		atual++;
		first++;
	}
}

/**
*@brief Função assign que insere uma lista inicializadora na lista
*@param std::initializer_list<T> ilist: lista inicializadora que será inserida na lista.
*/
template<typename T>
void list<T>::assign( std::initializer_list<T> ilist ) const
{
	iterator atual = this->m_head.m_next;

	T* i;

	for( i = (T*)ilist.begin(); i < (T*)ilist.end(); i++)
	{
		atual.m_element->m_data = *i;
		atual++; 
	}
}