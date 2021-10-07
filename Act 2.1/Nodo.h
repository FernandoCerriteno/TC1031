#ifndef NODO_H
#define NODO_H

  #include<iostream>

  template <class T>
  class Nodo { 
  public: 
      T data; 
      Nodo<T>* next;
      Nodo();
      Nodo(T);        
  }; 

  template<class T>
  Nodo<T>::Nodo(){
      data = 0;
      next = NULL;
  }
  template<class T>
  Nodo<T>::Nodo(T valor){
      data = valor;
      next = NULL;
  }

#endif // _NODE_H_