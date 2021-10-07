#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

  #include <climits>
  #include "Nodo.h"

  template <class T>
  class LinkedList {
      private:
        Nodo<T>* head;
        int numElements;

      public:
        LinkedList();
        ~LinkedList();
        int getNumElements();
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);
        void printList();
        T findData(T value);
        Nodo<T> operator [](const int& a);
        void operator =(LinkedList<T>& nuevaLista);
      
  };

  //Constructor
  template<class T>
  LinkedList<T>::LinkedList() {
      std::cout << "---Creando una lista vacia---" << std::endl;
      head = NULL;
      numElements = 0;
  }
  //Destructor
  template<class T>
  LinkedList<T>::~LinkedList() {
    std::cout << "---Liberando memoria de la lista---" << std::endl;
    Nodo<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    numElements = 0;
  }
 
  template<class T>
  int LinkedList<T>::getNumElements() {
    return numElements;
  }
  template<class T>
  void LinkedList<T>::printList() {
    Nodo<T> *ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template<class T>
  void LinkedList<T>::addFirst(T value) {
    Nodo<T> *newNode = new Nodo<T>(value);
    newNode->next = head;
    head = newNode;
    numElements++;
  }
  
  template<class T>
  void LinkedList<T>::addLast(T value) {
    if (head == NULL) {
      addFirst(value);
    }
    else {
      Nodo<T> *newNode = new Nodo<T>(value);
      Nodo<T> *p;
      p = head;
      while (p->next != NULL) {
        p = p->next;
      }
      newNode->next = NULL;
      p->next = newNode;
      numElements++;
    }    
  } 
  template<class T>
  bool LinkedList<T>::deleteData(T value) {
    Nodo<T> *p, *prev;
    p = head;
    prev = NULL;
    // head existe y contiene el valor a borrar
    if (p != NULL && p->data == value) {
      head = p->next;
      delete p;
      numElements--;
      return true;
    }
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value) {
        prev = p;
        p = p->next;
      }
      // Si no existe value
      if (p == NULL)
        return false;
      // Si existe value
      prev->next = p->next;
      delete p;
      numElements--;
      return true;
    }
  }
  
  template<class T>
  bool LinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return false;
    }
    else {
      Nodo<T> *p = head, *prev;
      // Si se debe borrar head
      if (position == 0) {
        head = p->next;
        delete p;
        numElements--;
        return true;
      }
      // Si se debe borrar algun otro nodo
      // Encontrar el nodo previo
      p = head;
      prev = NULL;
      int index = 0;
      // buscar value en la lista
      while (index != position) {
        prev = p;
        p = p->next;
        index++;
      }
      prev->next = p->next;
      delete p;
      numElements--;
      return true;     
    }     
  }
  
  template<class T>
  T LinkedList<T>::getData(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return -1;
    }
    else {
      if (position == 0)
        return head->data;
      Nodo<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }
      return -1;
    }
  }

//metodos de la Actividad 2.1
  template<class T>
  T LinkedList<T>::findData(T value){
      Nodo<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (p->data == value)
          return index;
        index++;
        p = p->next;
      }
    return -1;
  }

  template <class T>
  Nodo<T> LinkedList<T>::operator [](const int& a){
    Nodo<T> *p = head;
    int i=0;
    while(p != NULL){
      if(i==a){
        return *p;
      }
      i++;
      p=p->next;
    }
    std::cout<<"Out_Of_Range"<<std::endl;
    return *p;
  }

  template <class T>
  void LinkedList<T>::operator =(LinkedList<T>& nuevaLista){
    Nodo<T> *p, *q;
    //Elimina a la lista original 
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    numElements = 0;

    for(int i=0;i<nuevaLista.numElements;i++){
      addLast(nuevaLista[i].data);
    }

}

#endif // _LINKEDLIST_H_