#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Entrada.h"
#include "MaxHeap.h"

class Graph {
  private:
    int numNodes;
    int numEdges;

    // Lista de adyacencia (vector de vectores)
    std::vector<std::vector<int>> adjList;
    //Lista para la lectura de las ips con su respectivo grado
    std::vector<std::pair<Entrada,int>> listaIp;
    std::vector<bool> visited;

    void loadGraphList(std::istream& input);
    void split(std::string line, std::vector<int> & res);
    void split2(std::string line, std::vector<int> & res);
    void split3(std::string line, std::vector<int> & res,std::vector<int> & res2);
    void printAdjList();

  public:
    Graph(std::istream& input);
    Graph();
    ~Graph();
    void createBitacora();
    void createBitacora5();
    

};




#endif // __GRAPH_H_