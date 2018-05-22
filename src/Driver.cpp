#include "../includes/list.h"

int main( void )
{
	sc::list<int> lista_def; //Construtor default;
	sc::list<int> lista_count(3); //Construtor count;
	sc::list<int> lista_inicia({3,2,1}); //Construtor com lista inicializadora
	sc::list<int> lista_copy(lista_inicia); //Construtor copy

	lista_count = lista_inicia; //Operador com copy

	lista_copy = {3, 6, 7}; //Operador com lista

	/*
	lista_def.~list();
	lista_inicia.~list();
	lista_copy.~list();
	lista_count.~list();
	*/

	std::cout<<lista_inicia.size()<<std::endl;
	std::cout<<"Limpando a lista..."<<std::endl;
	lista_inicia.clear();
	std::cout<<"Lista limpa"<<std::endl;
	std::cout<<lista_def.empty()<<std::endl;
	std::cout<<lista_copy.front()<<std::endl;
	std::cout<<lista_copy.back()<<std::endl;
	std::cout<<(lista_inicia == lista_inicia)<<std::endl;

	/*
	std::cout<<"dando push front"<<std::endl;
	lista_copy.push_front(2);
	std::cout<<"dando push back"<<std::endl;
	lista_copy.push_back(8);

	std::cout<<"dando pop front"<<std::endl;
	lista_copy.pop_front();
	std::cout<<"dando pop back"<<std::endl;
	lista_copy.pop_back();

	std::cout<<"dando o assign"<<std::endl;
	lista_copy.assign(6);

	std::cout<<(lista_copy != lista_copy)<<std::endl;
	*/
}