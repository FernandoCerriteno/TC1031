#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Entrada.h"
#include "MaxHeap.h"
#include "HashTable.h"

class Graph {
  private:
    int numNodes;
    int numEdges;

    // Lista de adyacencia (vector de vectores)
    std::vector<std::vector<int>> adjList;

    std::map<long int, Entrada> mapIps;

    void loadGraphList(std::istream& input);
    void split(std::string line, std::vector<int> & res);
    void split2(std::string line, std::vector<int> & res);

    void printAdjList();

  public:
    Graph(std::istream& input);
    Graph();
    ~Graph();
    void createHash();
    std::vector<std::pair<Entrada,int>> getlista();
};




#endif // __GRAPH_H_