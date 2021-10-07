/** 
* Ejemplo que implementa una lista ligada 
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
**/

#include <iostream>
#include "LinkedList.h"


int main() {
  std::cout << "Ejemplo de listas ligadas\n";

  LinkedList<int> miLista;
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  std::cout << "Agregando 5 elementos al frente..." << std::endl;
  for (int i = 1; i < 6; i++) {
    miLista.addFirst(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << "Agregando 5 elementos al final..." << std::endl;
  for (int i = 10; i < 15; i++) {
    miLista.addLast(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  
  std::cout << "Delete 12: " << std::endl;
  miLista.deleteData(12);
  std::cout << "numElements ..: " << miLista.getNumElements() << std::endl;
  miLista.printList();
   

  std::cout << "DeleteAt 8: " << std::endl;
  miLista.deleteAt(8);
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList(); 

  std::cout << "getData(0): " << miLista.getData(0) << std::endl;
  std::cout << "getData(3): " << miLista.getData(3) << std::endl;
  std::cout << "FindData(10): " << miLista.findData(3) << std::endl;
  
  std::cout<<std::endl<<"Prueba de sobrecarga de operador ([])"<<std::endl;

  std::cout<<"Lista original"<<std::endl;
  miLista.printList();
  std::cout<<"Mostrando el valor en la posicion 5 con el operador []"<<std::endl;
  std::cout<<miLista[5].data<<std::endl;
  
  //Probando sobrecarga de operador "=" 
  std::cout<<std::endl<<"Prueba de sobrecarga de operador (=)"<<std::endl;

  LinkedList<int> segundaLista;
  for (int i = 1; i < 6; i++) {
    segundaLista.addFirst(i);
  }
  //usamos el operador
  std::cout << "Lista original antes de ser modificada: "<< std::endl;
  miLista.printList();
  std::cout << "Lista despues de ser modificada con el operador =: "<<std::endl;
  miLista = segundaLista;
  //imprimimos la lista con los valores actualizados
  miLista.printList();
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  
    
    return 0;
  }
