#include "../includes/list.h"

int main( void )
{
	int a[] = {1,2,3,4,5,6};
	sc::list<int> lista_nova = {7,7,7};

	std::cout<<"Criando as listas--------------------------------"<<std::endl;
	sc::list<int> lista_def; //Construtor default;
	sc::list<int> lista_count(3); //Construtor count;
	sc::list<int> lista_it(std::begin(a),std::end(a));
	sc::list<int> lista_inicia({3,2,1}); //Construtor com lista inicializadora
	sc::list<int> lista_copy(lista_inicia); //Construtor copy
	sc::list<int> lista_op1 = lista_copy; //Construtor atibuição com outra lista
	sc::list<int> lista_op2 = {1,2,3,4,5,6,7,8,9,30}; //Construtor atribuição com uma lista inicializadora


	lista_count = lista_inicia; //Operador com copy

	lista_copy = {3, 6, 7, 8, 9, 10}; //Operador com lista
	std::cout<<"Listas criadas com sucesso------------------------"<<std::endl;
	
	
	sc::list<int>::iterator lista_copy_it(lista_op2.begin()); //Criando os iteradores
	sc::list<int>::iterator lista_copy_it2(lista_op2.begin()); //Criando os iteradores
	sc::list<int>::iterator lista_copy_it3(lista_inicia.begin());

	std::cout<<"Operação ++ com os iteradores em cima da lista copy"<<std::endl;
	lista_copy_it++;
	std::cout<<"Valor do iterator: "<<*lista_copy_it<<std::endl;
	++lista_copy_it;
	std::cout<<"Valor do iterator: "<<*lista_copy_it<<std::endl;
	std::cout<<"Operação -- com os iteradores em cima da lista copy"<<std::endl;
	lista_copy_it--;
	std::cout<<"Valor do iterator: "<<*lista_copy_it<<std::endl;
	--lista_copy_it;
	std::cout<<"Valor do iterator: "<<*lista_copy_it<<std::endl;
	std::cout<<"Fim das operações ++ e -- com os iteradores-------"<<std::endl;

	std::cout<<"Operador == entre iteradores----------------------"<<std::endl;
	std::cout<<"Os iteradores são iguais?  "<<(lista_copy_it == lista_copy_it2)<<std::endl;

	std::cout<<"Operação insert-----------------------------------"<<std::endl;
	lista_copy_it3++;
	lista_copy_it2 = lista_inicia.insert(lista_copy_it3,4);
	std::cout<<"Primeiro insert"<<std::endl;
	std::cout<<"Valor do it: "<<*lista_copy_it2<<std::endl;

	lista_copy_it2 = lista_inicia.insert(lista_copy_it3, lista_copy.begin(), lista_copy.end());
	std::cout<<"Segundo insert"<<std::endl;

	std::cout<<"Valor do it: "<<*lista_copy_it2<<std::endl;

	lista_copy_it2--;

	std::cout<<"Valor do it: "<<*lista_copy_it2<<std::endl;

	std::cout<<"Operação insert com o const_iterator-------------"<<std::endl;

	auto lista_copy_cit2 = lista_inicia.insert(lista_copy_it3, {6,8,9,10});
	std::cout<<"terceiro insert"<<std::endl;
	lista_copy_cit2--;
	std::cout<<"Valor do it: "<<*lista_copy_cit2<<std::endl;
	lista_copy_cit2--;
	lista_copy_cit2--;
	std::cout<<"Valor do it: "<<*lista_copy_cit2<<std::endl;

	std::cout<<"Operação erase-----------------------------------"<<std::endl;

	lista_copy_it2 = lista_inicia.erase(lista_copy_it2);

	std::cout<<"Valor do it: "<<*lista_copy_it2<<std::endl;

	lista_copy_it2--;

	std::cout<<"Valor do it: "<<*lista_copy_it2<<std::endl;

	lista_copy_it2 = lista_inicia.erase(lista_inicia.begin(), --(lista_inicia.end()));

	std::cout<<"Valor do it: "<<*lista_copy_it2<<std::endl;

	std::cout<<"Utilizando a função assign-----------------------"<<std::endl;
	std::cout<<lista_it.front()<<std::endl;
	lista_it.assign(3, 6);
	std::cout<<lista_it.front()<<std::endl;
	lista_it.assign(lista_nova.begin(),lista_nova.end());
	std::cout<<lista_it.front()<<std::endl;
	lista_it.assign({8,8,8,8});
	std::cout<<lista_it.front()<<std::endl;


	std::cout<<"dando push front---------------------------------"<<std::endl;
	lista_copy.push_front(2);
	std::cout<<"valor do elemento na frente: " << lista_copy.front() <<std::endl;
	std::cout<<"dando push back--------------------------------"<<std::endl;
	lista_copy.push_back(8);
	std::cout<<"valor do elemento na atras: " << lista_copy.back() <<std::endl;

	std::cout<<"dando pop front---------------------------------"<<std::endl;
	lista_copy.pop_front();
	std::cout<<"valor do elemento na frente: " << lista_copy.front() <<std::endl;
	std::cout<<"dando pop back----------------------------------"<<std::endl;
	lista_copy.pop_back();
	std::cout<<"valor do elemento na atras: " << lista_copy.back() <<std::endl;

	std::cout<<"dando o assign do list--------------------------"<<std::endl;
	lista_copy.assign(6);
	std::cout<<"valor do elemento na frente: " << lista_copy.front() <<std::endl;
	std::cout<<"valor do elemento na atras: " << lista_copy.back() <<std::endl;


	std::cout<<"Vendo se as listas são iguais-------------------"<<std::endl;
	std::cout<<(lista_copy != lista_copy)<<std::endl;

	std::cout<<"Tamanho da lista_inicia-------------------------"<<std::endl;
	std::cout<<lista_inicia.size()<<std::endl;
	std::cout<<"Limpando a lista--------------------------------"<<std::endl;
	lista_inicia.clear();
	std::cout<<"Lista limpa-------------------------------------"<<std::endl;
	std::cout<<"Verificando se a lista está vazia---------------"<<std::endl;
	std::cout<<lista_inicia.empty()<<std::endl;
	std::cout<<"Utilizando a função front-----------------------"<<std::endl;
	std::cout<<lista_inicia.front()<<std::endl;
	std::cout<<"Utilizando a função back------------------------"<<std::endl;
	std::cout<<lista_inicia.back()<<std::endl;
	std::cout<<"Verificando se as listas são iguais-------------"<<std::endl;
	std::cout<<(lista_inicia == lista_inicia)<<std::endl;

	std::cout<<"Deletando as listas..."<<std::endl;
	lista_def.~list();
	lista_inicia.~list();
	lista_copy.~list();
	lista_count.~list();
	std::cout<<"Listas deletadas"<<std::endl;
}