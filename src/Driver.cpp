#include "../includes/list.h"

int main( void )
{
	int a[] = {1,2,3,4,5,6};

	sc::list<int> lista_def; //Construtor default;
	sc::list<int> lista_count(3); //Construtor count;
	sc::list<int> lista_it(std::begin(a),std::end(a));
	sc::list<int> lista_inicia({3,2,1}); //Construtor com lista inicializadora
	sc::list<int> lista_copy(lista_inicia); //Construtor copy
	sc::list<int> lista_op1 = lista_copy; //Construtor atibuição com outra lista
	sc::list<int> lista_op2 = {1,2,3,4,5,6,7,8,9,10}; //Construtor atribuição com uma lista inicializadora


	lista_count = lista_inicia; //Operador com copy

	lista_copy = {3, 6, 7, 8, 9, 10}; //Operador com lista

	/*
	lista_def.~list();
	lista_inicia.~list();
	lista_copy.~list();
	lista_count.~list();
	*/

<<<<<<< HEAD
<<<<<<< HEAD
	sc::list<int>::iterator lista_copy_it = lista_copy;
=======
	sc::list<int>::iterator lista_copy_it = lista_op2;
>>>>>>> c78de2f1717583f6d53d87ba97d0e7f52e1b84a8

=======
>>>>>>> Beta
	std::cout<<lista_inicia.size()<<std::endl;
	std::cout<<"Limpando a lista..."<<std::endl;
	lista_inicia.clear();
	std::cout<<"Lista limpa"<<std::endl;
	std::cout<<lista_def.empty()<<std::endl;
	std::cout<<lista_copy.front()<<std::endl;
	std::cout<<lista_copy.back()<<std::endl;
	std::cout<<(lista_inicia == lista_inicia)<<std::endl;

<<<<<<< HEAD
	/*
<<<<<<< HEAD
	std::cout<<lista_copy_it.begin()<<std::endl;
	std::cout<<lista_copy_it.end()<<std::endl;
	std::cout<<(lista_copy_it.begin())*<<std::endl;
	std::cout<<(lista_copy_it.begin() == lista_copy_it.begin())<<std::endl;
	std::cout<<(lista_copy_it.begin() != lista_copy_it.begin())<<std::endl;
	std::cout<<(lista_copy_it.begin())++<<std::endl;
	std::cout<<(lista_copy_it.begin())--<<std::endl;
	*/

=======
	
	(lista_copy.begin()).print();
	(lista_copy.end()).print();
	(lista_copy_it).print();
	std::cout<<*(lista_copy_it)<<std::endl;
>>>>>>> c78de2f1717583f6d53d87ba97d0e7f52e1b84a8
	/*
=======
>>>>>>> Beta
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