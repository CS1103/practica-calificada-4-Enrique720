#include <iostream>
#include <vector>
#include <thread>
using namespace std;
template <typename T>
void buscar(vector<T> array,int num_thread,T*valor ,int id){
    int limitesup = (id+1)*(array.size())/num_thread;
    int limiteinf =  (id)*(array.size())/num_thread;
    for(int i = limiteinf; i < limitesup; i++){
        if(array[i]>*valor)
              *valor = array[i];
    }
}


template  <typename T>
T buscar_mayor(vector<T>array,int num_threads){
    auto retorno = new T(0);
    vector<thread> hilos;
    for(int i = 0; i < num_threads; i++){
         hilos.emplace_back(ref(buscar<T>),ref(array),ref(num_threads),retorno,ref(i));
    }
    for(int i = 0; i < num_threads; i++){
        hilos[i].join();
    }
    return *retorno;
}

int main(){
    vector<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(1);

    cout << buscar_mayor(a,2);

}
