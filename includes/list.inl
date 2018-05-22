#include "list.h"

/**
*@brief Construtor defaut, que cria uma lista nula.
*/
template<typename T>
list<T>::list( void ) : m_head(nullptr), m_size(0), m_tail(nullptr)
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
			atual->m_prev = prev;
			prev = prev->m_next;
		}
	}

	prev->m_next = nullptr;
	this->m_tail = prev;
	prev = this->m_head;
	prev->m_prev = nullptr;
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
	origin = ponteiro->m_head;

	//EXPERIMENTAL.
	Node* node_principal = new Node;
	copy = node_principal;
	this->m_head = copy;

	while(origin->m_next != nullptr)
	{

		Node* new_node = new Node;
		prev = copy;

		copy->m_data = origin->m_data;
		copy->m_next = new_node;


		if(copy == this->m_head)
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
	this->m_tail = copy;

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
			this->m_head = atual;
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
	this->m_tail = prev;
}

/**
*@brief Destrutor da classe.
*/
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
	std::cout<<this->m_head<<std::endl;
	if(this->m_head != nullptr)
	{
		Node* fast;
		Node* slow;
		fast = this->m_head;

		while(fast->m_next != nullptr)
		{
			slow = fast;
			fast = fast->m_next;

			if(slow != this->m_head)
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

		std::cout<<this->m_head<<std::endl;
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
	return (m_tail->m_data);
}

/**
*@brief Função front, que retorna o primeiro objeto da lista.
*/
template<typename T>
const T & list<T>::front() const
{
	return (m_head->m_data);
}

template<typename T>
bool list<T>::operator==(const list& rhs )
{
	list<T>* rhs_atual_l;
	rhs_atual_l = const_cast<list<T>*>(&rhs);

	if(this->m_size != rhs_atual_l->m_size)
	{
		return false;
	}
	else
	{
		Node* atual;
		Node* rhs_atual;

		atual = this->m_head;
		
		while(atual->m_next != nullptr)
		{
			if(atual->m_data != rhs_atual->m_data)
			{
				return false;
			}

			atual = atual->m_next;
			rhs_atual = rhs_atual->m_next;
		}

		if(atual->m_data != rhs_atual->m_data)
		{
			return false;
		}

		return true;
	}
}

//Gegeo
template <typename T>
void list<T>::push_front(const T & value){
	Node * atual = this->m_head;

	atual->m_next = nullptr;
	atual->m_data = value;
	atual->m_next = this->m_head;
	this->m_head = atual;

}

template <typename T>
void list<T>::push_back(const T & value){
	Node * atual = this->m_head;

	if(this->m_head == nullptr){
		this->m_head = atual;
	}

	Node * tail = this->m_head;

	while( tail->m_next != nullptr){
		tail = tail->m_next;
	}

	tail->m_data = value;
}

template <typename T>
void list<T>::pop_back(){
	Node * atual;

	if(this->m_head == nullptr){
		this->m_head = atual;
		delete atual;
	}

	Node * tail = this->m_head;

	while( tail->m_next != nullptr){
		tail = tail->m_next;
	}

	delete tail;
}

template <typename T>
void list<T>::pop_front(){
	Node * atual;

	if(this->m_head != nullptr){
		atual = (this->m_head)->m_next;
		(this->m_head)->m_next = atual->m_next;
		delete atual; 
	}else{
		atual = this->m_head;
		delete atual;
	}
}

template <typename T>
void list<T>::assign( const T & value){
	Node *atual = this->m_head;

	while ( atual-> m_next != nullptr){
		this->m_head = (this->m_head)->m_next;
		delete atual;
		atual = this->m_head;
	}

	while ( atual -> m_next != nullptr){
		atual -> m_data = value;
		atual = atual ->m_next;
	}
}

template <typename T>
bool list<T>::operator !=( const list& rhs){
	auto work ( rhs );

	if(work.m_size != (this->m_head).m_size){
		return true;
	}

	if( work != nullptr){

		if( work->m_data != (this->m_head)->m_data){
			return true;
		}

		work = work->m_next;
		this->m_head = (this->m_head)->m_next;
	}

	return false;
}