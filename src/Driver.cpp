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

	sc::list<int>::iterator lista_copy_it(lista_op2.begin());
	sc::list<int>::iterator lista_copy_it2(lista_op2.begin());
	std::cout<<"Head da lista: "<<lista_op2.get_head()<<std::endl;
	std::cout<<"Valor no head da lista: "<<lista_op2.front()<<std::endl;

	

	lista_copy_it++;
	lista_copy_it.print();
	std::cout<<"Valor do iterator: "<<*lista_copy_it<<std::endl;
	++lista_copy_it;
	lista_copy_it.print();
	std::cout<<"Valor do iterator: "<<*lista_copy_it<<std::endl;
	lista_copy_it--;
	lista_copy_it.print();
	std::cout<<"Valor do iterator: "<<*lista_copy_it<<std::endl;

	std::cout<<"Os iteradores são iguais?  "<<(lista_copy_it == lista_copy_it2)<<std::endl;

	lista_copy_it2 = lista_copy.insert(lista_copy_it,4);

	std::cout<<"Valor do it: "<<*lista_copy_it2<<std::endl;

	/*
	std::cout<<lista_inicia.size()<<std::endl;
	std::cout<<"Limpando a lista..."<<std::endl;
	lista_inicia.clear();
	std::cout<<"Lista limpa"<<std::endl;
	std::cout<<lista_def.empty()<<std::endl;
	std::cout<<lista_copy.front()<<std::endl;
	std::cout<<lista_copy.back()<<std::endl;
	std::cout<<(lista_inicia == lista_inicia)<<std::endl;
	*/
	

	
	std::cout<<"dando push front"<<std::endl;
	lista_copy.push_front(2);
	std::cout<<"valor do elemento na frente: " << lista_copy.front() <<std::endl;
	std::cout<<"dando push back"<<std::endl;
	lista_copy.push_back(8);
	std::cout<<"valor do elemento na atras: " << lista_copy.back() <<std::endl;

	std::cout<<"dando pop front"<<std::endl;
	lista_copy.pop_front();
	std::cout<<"valor do elemento na frente: " << lista_copy.front() <<std::endl;
	std::cout<<"dando pop back"<<std::endl;
	lista_copy.pop_back();
	std::cout<<"valor do elemento na atras: " << lista_copy.back() <<std::endl;

	std::cout<<"dando o assign"<<std::endl;
	lista_copy.assign(6);
	std::cout<<"valor do elemento na frente: " << lista_copy.front() <<std::endl;
	std::cout<<"valor do elemento na atras: " << lista_copy.back() <<std::endl;



	std::cout<<(lista_copy != lista_copy)<<std::endl;
	
}