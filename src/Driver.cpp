#include "../includes/list.h"

int main( void )
{
	sc::list<int> lista_def; //Construtor default;
	sc::list<int> lista_count(3); //Construtor count;
	sc::list<int> lista_inicia({3,2,1}); //Construtor com lista inicializadora
	sc::list<int> lista_copy(lista_inicia); //Construtor copy

	lista_count = lista_inicia; //Operador com copy

	lista_copy = {3, 6, 7}; //Operador com lista
	std::cout<<"Saí do retorno"<<std::endl;

	std::cout<<"Entrei na segunda lista"<<std::endl;
	lista_def.~list();
	std::cout<<"Destruí a lista"<<std::endl;
	lista_inicia.~list();
	std::cout<<"Destruí a lista"<<std::endl;
	lista_copy.~list();
	std::cout<<"Destruí a lista"<<std::endl;
	lista_count.~list();
	std::cout<<"Destruí a lista"<<std::endl;
}