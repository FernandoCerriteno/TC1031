#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

  template<class T>
  class MaxHeap {
    private:
      // contiene los elementos del heap
      std::vector<T> data; 
      // capacidad maxima del heap
      int maxSize;
      // tamaño actual del heap   
      int size;   

      int parent(int i);
      int left(int i);
      int right(int i);

    public:
      MaxHeap(int capacity);
      ~MaxHeap();
      bool isEmpty();
      int getSize();
      int getCapacity();
      void printMaxHeapEntrada();
      void pushCont(T key);
      void popCont();
      void MaxHeapifyCont(int i);
      T top();
  };

  template <class T> 
  MaxHeap<T>::MaxHeap(int capacity) {
      std::cout << "--->Creando un MaxHeap: " <<  this << std::endl;
      size = 0;
      maxSize = capacity;
      data.resize(maxSize);
  }

  template <class T> 
  MaxHeap<T>::~MaxHeap() {
      std::cout << "--->Liberando memoria del MaxHeap: " <<  this << std::endl;
      data.clear();
  }
  
  template <class T> 
  bool MaxHeap<T>::isEmpty() {
    return (size <= 0);
  }

  template <class T> 
  int MaxHeap<T>::getSize() {
    return size;
  }

  template <class T> 
  int MaxHeap<T>::getCapacity() {
    return maxSize;
  }


  template <class T> 
  void MaxHeap<T>::printMaxHeapEntrada() {
    for (int i=0; i < size; i++)
      data[i].imprimeIp();
    std::cout << std::endl;
  }

  template <class T> 
  int MaxHeap<T>::parent(int i) {
    return (i-1)/2; 
  }
  
  template <class T> 
  int MaxHeap<T>::left(int i) {
    return (2*i + 1); 
  }

  template <class T> 
  int MaxHeap<T>::right(int i) {
    return (2*i + 2);
  }


  template <class T> 
  void MaxHeap<T>::pushCont(T key) {
    if (size > maxSize) {
        std::cout << "Overflow: no se puede insertar la llave: " << std::endl;
        return;
    }
    // Insertamos la nueva llave al final del vector
    int i = size;
    data[i] = key;
    size++;   
    // Reparar las propiedades del max heap si son violadas
    while (i != 0 && data[parent(i)].getCont() < data[i].getCont()) {
       std::swap(data[i], data[parent(i)]);
       i = parent(i);
    }
  }
  template <class T>
  void MaxHeap<T>::popCont(){
    if (size > maxSize) {
      std::cout << "Index esta fuera de rango" << std::endl;
      return;
    }
    if (size == 1)
    {
        size--;
        data.erase(data.begin());
        return;
    }
    
    T root = data[0];
    size--;
    data[0] = data[size];
    Entrada ent;
    MaxHeapifyCont(0);

    return;
  }

  template <class T> 
  void MaxHeap<T>::MaxHeapifyCont(int i) {
    int l = left(i);
    int r = right(i);
    int max = i;
    if (l < size && data[l].getCont() > data[i].getCont()){
      max = l;
    }
    if (r < size && data[r].getCont() > data[max].getCont()){
      max = r;
    }
    if (max != i){
      std::swap(data[i], data[max]);
      MaxHeapifyCont(max);
    }
  }
  
  template <class T> 
  T MaxHeap<T>::top() {
    T result;
    if (isEmpty()) {
        std::cout << "El MaxHeap está vacio" << std::endl;
        return result;          
    }
    return data[0];
  }


#endif // __MAXHEAP_H_