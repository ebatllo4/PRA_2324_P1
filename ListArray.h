//git clone https://github.com/yt-dlp/yt-dlp.git
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
		   for (int i = 0; i < n; i++){
			   new_arr[i] = arr[i];     //Cal llibera  memoria de arr
		   }
		   delete[] arr; 
		   arr = new_arr;
		   max = new_size;
	    }

    public:

	    ~ListArray(){//No se si es la manera correcta d'eliminar-ho
		   delete[] arr;		   
	    }
        

	    ListArray(){
		    arr = new T[MINSIZE];
		    n = 0;
		    max = MINSIZE;
	    }

	 
	    T operator[](int pos){
		    if (pos >= 0 && pos < n) { 
			    return arr[pos]; 
		    }else { 
			    throw std::invalid_argument("Fuera de rango!"); 
		    }

	    }

	    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		    for(int i; i < list.n; i++){
		    	out<< list.arr[i] << std::endl;
		    }
		    return out;
	    }


	     bool empty() override final{
                    return n = 0;
            }

	    void insert(int pos, T e) override final{
		    if (n == max){
			    resize(max*2);
		    }   

		    if(pos < 0 || pos > n){
			    throw std::out_of_range("Fuera de rango!");
		    }
		    if(empty()){
			    arr = new T[MINSIZE];
		    }
		    for(int i = n; i > pos; i--){
			    arr[i] = arr[i-1];
		    }
			    arr[pos] = e;
			    n++;
     	    }	   
	    


	      void append(T e) override final{
		    if (n == max){
			resize(max*2);
		    }
		    arr[n] = e;		
		    n++;
	    }


	    void prepend(T e) override final{
                    if (n == max ){
                        resize(max*2);
                    }
                    for (int i = n; i > 0; i--){
                    	arr[i] = arr[i-1];
                    }
                    arr[0] = e;
                    n++;
            }


	    T get(int pos) override final{
		    if(pos >= 0 && pos < n){
		     	    return arr[pos-1];
	    	    }else{
			    throw std::out_of_range("Fuera de rango!");
	    	    }
	    }



	    int size() override final{
		    return n;
	    }


	    T remove(int pos)override final{
		    if(pos < 0|| pos>= n){
			    throw std::out_of_range("Fuera de rango!");
		    }
		    T elem = arr[pos];
		    for(int i = pos; i < n-1; i++){
			    arr[i] = arr[i+1];
		    }
		    n--;
		    return elem;
	    }
      	    
	    int search(T e) override final {
        	for (int i = 0; i < n; i++) {
        	    if (arr[i] == e) {
        	        return i;
            	    }
		}
        	return -1; 
    	    }

};
