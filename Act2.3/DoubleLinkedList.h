#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

  #include <climits>
  #include "Stack.h"
  #include "Node.h"
  #include "Entrada.h"
  #include <iostream>
  #include <fstream>
  #include <sstream>

  template <class T>
  class DoubleLinkedList {
      private:
        Node<T>* head;
        Node<T>* tail;
        int numElements;

      public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        int getNumElements();
        void printList();
        void printListEntrada();
        void printListEntrada_par(int min, int max);
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);
        bool compara1(Node<T> *sig, Node<T> *comp);

        void clear();
        void crearBitacora();
        void quickSort();
        void _quickSort(Node<T>* l, Node<T> *h);
        void swapnode ( T &a, T &b );
        Node<T>* partition(Node<T> *l, Node<T> *h);

  };

  template<class T>
  DoubleLinkedList<T>::DoubleLinkedList() {
      std::cout << "--->Creando una lista vacia " << this << std::endl;
      head = NULL;
      tail = NULL;
      numElements = 0;
  }
  
  template<class T>
  DoubleLinkedList<T>::~DoubleLinkedList() {
    std::cout << "--->Liberando memoria de la lista " << this << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
  }
 
  template<class T>
  int DoubleLinkedList<T>::getNumElements() {
    return numElements;
  }
  
  template<class T>
  void DoubleLinkedList<T>::printList() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template<class T>
  void DoubleLinkedList<T>::printListEntrada() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
      ptr->data.imprimeEntrada();
      ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template<class T>
  void DoubleLinkedList<T>::printListEntrada_par(int min, int max){
    std::string esp = " "; 
    Node<T> *p = head;
    int cont=0;
    ofstream file;
    file.open("resultado_busqueda.txt");
    while (p != NULL) {
      if (cont >= min && cont <= max){
        p->data.imprimeEntrada();
        file <<p->data.getMes()<<esp<<p->data.getDiastr()<<esp<<p->data.getHorastr()<<":"<<p->data.getMinstr()<<":"<<p->data.getSegstr()<<esp<<p->data.getIp()<<esp<<p->data.getRazon()<<"\n";
        p = p->next;
      }
      else{
        p = p->next;
      }
      cont++;
    }
    std::cout << std::endl;
  }

  template<class T>
  void DoubleLinkedList<T>::addFirst(T value) {
    Node<T> *newNode = new Node<T>(value);
    // Si la lista esta vacia 
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    }
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    numElements++;
  }
  
  template<class T>
  void DoubleLinkedList<T>::addLast(T value) {
    // La lista esta vacia
    if (head == NULL) {
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      numElements++;
    }    
  }
  
  template<class T>
  bool DoubleLinkedList<T>::deleteData(T value) {
    Node<T> *p, *q;
    p = head;
    q = NULL;
    // Si la lista esta vacia 
    if (p == NULL) {
      return false;
    }
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value) {
        q = p;
        p = p->next;
      }
      // Si no existe value en la lista
      if (p == NULL)
        return false;
      // Si debe borrarse el primer elemento
      if (p->prev == NULL) {
        head = p->next;
        if (head != NULL)
          head->prev = NULL;
      }
      else if (p->next == NULL) { 
        // Si debe borrarse el último elemento
        q->next = NULL;
        tail = q;
      }
      else {
        // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  template<class T>
  bool DoubleLinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return false;
    }
    else if (position == 0) { // Si debe borrarse el primer elemento
      Node<T> *p = head;
      // Si la lista contiene solo un nodo
      if (head != NULL && head->next == NULL) {
        head = NULL;
        tail = NULL;  
      }
      else {
        head = p->next;
        head->prev = NULL;
      }
      delete p;
      numElements--;
      return true; 
    }
    else { 
      Node<T> *p = head, *q = NULL;
      int index = 0;
      while (index != position) {
        q = p;
        p = p->next;
        index++;
      }
      // Si debe borrarse el último elemento
      if (p->next == NULL) {
        q->next = NULL;
        tail = q;
      }
      else { // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }
  
  template<class T>
  T DoubleLinkedList<T>::getData(int position) {
    T err;
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return err;
    }
    else {
      if (position == 0)
        return head->data;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }
      return err;
    }
  }

  template<class T>
  bool DoubleLinkedList<T>::compara1(Node<T> *sig, Node<T> *comp){
    while (sig != NULL){
      if (sig==comp){
        return true;
      }
      sig = sig->next;
    }
    return false;
  }

  template<class T>
  void DoubleLinkedList<T>::clear(){
    Node<T> *p = head;
    while(p != NULL){
      p=NULL;
      numElements--;
    }
    head=NULL;
    tail=NULL;
    
  }

  template <class T>
  void DoubleLinkedList<T>::crearBitacora(){
    Node<T> *p = head;
    std::string esp = " "; 
    //Se crea el archivo bitacora_ordenada.txt donde se escribe el resultado
    ofstream file;
    file.open("bitacora_ordenada.txt");
    while(p != NULL){
      file <<p->data.getMes()<<esp<<p->data.getDiastr()<<esp<<p->data.getHorastr()<<":"<<p->data.getMinstr()<<":"<<p->data.getSegstr()<<esp<<p->data.getIp()<<esp<<p->data.getRazon()<<"\n";
      p = p->next;
    }
    file.close();
  }

  template <class T>
  void DoubleLinkedList<T>::swapnode ( T &a, T &b ){ 
    T te = a; 
    a = b; 
    b = te; 
  }

  template <class T>
  Node<T>* DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h){
  T x = h->data;
  Node<T> *i = l->prev;
  for (Node<T> *j = l; j != h; j = j->next){
    if (j->data <= x){
      i = (i == NULL)? l : i->next;
      swapnode(i->data, j->data);
    }
  }
  i = (i == NULL)? l : i->next; // Similar to i++
  swapnode(i->data, h->data);
  return i;
  }
  
  /* A recursive implementation
  of quicksort for linked list */
  template <class T>
  void DoubleLinkedList<T>::_quickSort(Node<T>* l, Node<T> *h){
    Stack<Node<T> *> aux;
    // Los nodos de la clase Stack son distintos a los de la DoubleLinkedList
    aux.push(l);
    aux.push(h);

    while(aux.isEmpty() != true){
      h=aux.pop();
      l=aux.pop();
      
      Node<T>* part = partition(l,h);

      if (compara1(part->prev,l)==false){
        aux.push(l);
        aux.push(part->prev);
      }

      if (compara1(part->next,h)==true){
        aux.push(part->next);
        aux.push(h);
      }
    }
  }

  template<class T>
  void DoubleLinkedList<T>::quickSort(){
    _quickSort(head,tail);
  }


#endif // _DOUBLELINKEDLIST_H_