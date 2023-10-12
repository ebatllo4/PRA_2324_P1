#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
	Node<T>* first;
	int n;

    public:

	ListLinked(){
		first = nullptr;
		n = 0;
	}


	~ListLinked(){
		while(first != nullptr){
			Node<T>* aux = first->next;
			delete first;
			first = aux;
		}
		n = 0;

	}


	void insert(int pos, T e) override{
		if(pos < 0 || pos > n){
			throw std::out_of_range("Fuera de rango!");
		}
		Node<T>* aux = first;
		Node<T>* prev = nullptr;
		for(int i = 0; i <= pos; i++){
			first = aux;
			aux = aux->next;
		}
		if(n == 0){
			first = new Node<T>*(e, first);
		}else{
			prev->next = new Node<T>*(e, aux);
		}
		n++;
	}


	void append(T e) override{
		if(n == 0){
			first = new Node<T>*(e);
		}else{
			Node<T>* aux = first;
			Node<T>* prev = nullptr;
			while(aux != nullptr){
				prev = aux;
				aux = aux->next;
			}
			aux->next = new Node<T>*(e);
		}
		n++;
	}


	void prepend(T e) override{
		if(n == 0){
			first = new Node<T>*(e);
		}else{
			first = new Node<T>*(e, first);
	
		}
	}


	T remove(int pos) override{
 		if(pos < 0 || pos > n){
			throw std::out_of_range("Fuera de rango!");
		}
		Node<T>* aux = first;
		Node<T>* prev = nullptr;
		for(int i = 0; i <= pos; i++){
			prev = aux;
			aux = aux->next;
		}
		prev->next = aux->next;
		T e = aux->data;
		delete aux;
		n--;
		return e;
	}


	T get(int pos) override{
		if(pos < 0 || pos > n){
			throw std::out_of_range("Fuera de rango!");
		}
		Node<T>* aux = first;
		Node<T>* prev = nullptr;
		for(int i = 0; i <= pos; i++){
			prev = aux;
			aux = aux->next;
		}
		return aux->data;
	}


	int search(T e) override{
		 Node<T>* aux = first;
                Node<T>* prev = nullptr;
                for(int i = 0; i <= n; i++){
                	if(aux->data == e){
				return i;
			}
		  	prev = aux;
                        aux = aux->next;
                }
		return -1;
	}


	bool empty() override{
		return n == 0;
	}


	int size() override{
		return n;
	}


	T operator[](int pos){
		if(pos == 0 || pos > n){
			throw std::out_of_range("No hay nningún elemento de la lista en la posición");
		}
		Node<T>* aux = first;
		Node<T>* prev = nullptr;
		for(int i = 0; i <= pos; i++){
			prev = aux;
			aux = aux->next;
		}
		return aux->data;
	}


	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
		Node<T>* aux = list.first;
		while(aux != nullptr){
			out<< aux.data << std::endl;
			aux = aux->next;
		}
		return out;
	}
};
