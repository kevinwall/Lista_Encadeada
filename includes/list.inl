#include "list.h"

/**
*@brief Construtor defaut, que cria uma lista nula.
*/
template<typename T>
list<T>::list( void ) : m_head(nullptr), m_size(0)
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
			this->m_head = atual;
		}
		else
		{
			atual = new_node;
			prev->m_next = atual;
			prev = prev->m_next;
		}
	}
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
	origin = ponteiro->m_head;

	//EXPERIMENTAL.
	Node* node_principal = new Node;
	copy = node_principal;
	this->m_head = copy;

	while(origin->m_next != nullptr)
	{

		Node* new_node = new Node;

		copy->m_data = origin->m_data;
		copy->m_next = new_node;

		copy = copy->m_next;
		origin = origin->m_next;
	}
	
	copy->m_data = origin->m_data;

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

	int *i;

	for(i = (int*)ilist.begin(); i < (int*)ilist.end(); i++)
	{
		Node* new_node = new Node;

		if(i == ilist.begin())
		{
			atual = new_node;
			atual->m_data = *i;

			prev = atual;
			this->m_head = atual;
			this->m_size = ilist.size();

		}
		else
		{
			atual = new_node;
			atual->m_data = *i;

			prev->m_next = atual;
			prev = prev->m_next;
		}
	}
}

template<typename T>
list<T>::~list()
{
	Node* atual;
	Node* prev;

	if( this->m_head != nullptr)
	{
		atual = this->m_head;

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

		atual = this->m_head;
		prev = ponteiro->m_head;

		while(prev->m_next != nullptr)
		{
			atual->m_data = prev->m_data;
			atual = atual->m_next;
			prev = prev->m_next;
		}

		atual->m_data = prev->m_data;

		return *this;

	}
	else
	{
		throw std::runtime_error("Erro em operator=(): As listas encadeadas não possuem tamanho igual \n");
	}
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

		atual = this->m_head;

		int* i;

		i = (int*)ilist.begin();

		while(atual->m_next != nullptr)
		{
			atual->m_data = *i;

			atual= atual->m_next;
			i++;
		
		}

		atual->m_data = *i;

		return *this;
	}
	else
	{
		throw std::runtime_error("Erro em operator=(): A lista encadeada e a lista inicializadora não possuem tamanho igual \n");
	}
}