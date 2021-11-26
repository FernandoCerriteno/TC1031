/** 
* Actividad 4.3 - Actividad Integral de Grafos 
*
* Tecnologico de Monterrey
* Programación de estructuras de datos y algoritmos fundamentales * (Gpo 12)
* 
* Fernando Cerriteño Magaña A01702790
* 22/11/2021
*
* Dr. Eduardo Arturo Rodríguez Tello
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    valgrind --leak-check=full ./main < bitacoraGrafos.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < bitacoraGrafos.txt
**/
#include <iostream>
#include "Graph.h"

int main() {
  std::cout << "--->Actividad Integradora!\n";
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf(); 
  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  std::cout<<"--->Recuperando datos\n";
  Graph g1(inputInfo);
  std::cout<<"--->Creando bitacora\n";
  g1.createBitacora();
  std::cout<<"--->Obteniendo las Ips con mas adyacencias\n";
  g1.createBitacora5();
} 