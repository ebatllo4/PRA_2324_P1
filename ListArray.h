#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T>{

    private:
	    T* arr;
	    int max;
	    int n;
	    static const int MINSIZE = 2;

           void resize(int new_size){
		   T* new_arr = new T[new_size];
		   for (int i = 0; i < max; i++){
			   new_arr[i] = arr[i];     //Cal eliminar arr
		   }
	    }

	    ~ListArray(){//No se si es la manera correcta d'eliminar-ho
		   delete[] arr;
		    n = 0;		   
	    }
        

    public:
	    ListArray(){
		    arr = new T[MINSIZE];
		    n = 1;
		    max = MINSIZE;
	    }

	 
	    T operator[](int pos){
		    if (pos >= 0 && pos < n) { 
			    return arr[pos]; 
		    }else { 
			    throw std::invalid_argument("MAL!!"); 
		    }

	    }

	    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		    out<< list.arr << std::endl;
		    return out;
	    }

	     bool empty() override final{
                    return arr = nullptr;
            }

	    /*void insert(int pos, T e) override final{
		    if (n == max){
			    arr->resize(max*2);
		    }   
		    if(arr->empty()){
			    arr = new T[MINSIZE];
		    }
		    /*if(pos == 0){
	  		    arr.prepend(e);
		    }
		    if(pos == n){
			    arr.append(e);
		    }*/
/*		    if(pos != 0 && pos != n){
			    for(int i = n-1; i >= pos; i--){
				    arr[i+1] = arr[i];
			    }
			    arr[pos] = e;
			    n++;
		    }	   
	    }


	    void append(T e){
		    if (arr->empty()){
			arr = new T[MINSIZE];
		    }
	 	    if (n >= max){
		    	arr->resize(max*2);
		    }
		    arr[n] = e;		
		    n++;
	    }


	    void prepend(T e) override final{
		    if (arr->empty()){
                        arr = new T[MINSIZE];
		    }
                    if (n == max ){
                        arr->resize(max*2);
                    }
                    for (int i = n-1; i >= 0; i--){
                    	arr[i+1] = arr[i];
                    }
                    arr[0] = e;
                    n++;
            }
*/

	    T get(int pos) override final{
		    return arr[pos-1];
	    }

	    int search(T e) override final{
		   for(int i = 0; i < max-1; i++){
			   if( arr[i] == e){
				   return i;
			    }
		   }
		   return -1;
	    }



	    int size() override final{
		    return n;
	    }


	    T remove(int pos){
		    for(int i = pos; i < n; i++){
			    arr[i] = arr[i+1];
		    }
		    n--;
		    return arr[pos];
	    }
      	    
};
