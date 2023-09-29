#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
	    T* arr;
	    int max;
	    int n;
	    static const int MINSIZE;
        // miembros privados

    public:
	    ListArray(){
		    MINSIZE = 2;
		    arr* = nullptr; //ns ben be com inicialitzarlo
		    n = 1;
		    max = 2;
	    }

	    ~ListArray(){
		    MINSIZE = 0;
		    arr* = nullptr;
		    n = 0;
		    max = 0;
	    }

	    T operator[](int pos){

	    }

	    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){

	    }

	    void resize(int new_size){

	    }


 
     	    // miembros públicos, incluidos los heredados de List<T>
    
};
