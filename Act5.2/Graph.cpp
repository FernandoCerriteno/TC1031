#include "Graph.h"

Graph::Graph(std::istream& input) {
  loadGraphList(input);
}

Graph::Graph(){
  this->numNodes=0;
  this->numEdges=0;
}

Graph::~Graph() {
  adjList.clear();
  mapIps.clear();
}

void Graph::loadGraphList(std::istream& input) {
  std::string line;
  int i = 0;
  
  while (std::getline(input, line)) {
    if (i == 0) {
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[1];
      // Reservar memoria para la lista de adyacencia
      adjList.resize(numNodes+1);
      i++;
      continue; 
    }
    
    else if(i < numNodes+1){
      std::vector<int> res;
      split2(line, res);
      Entrada iptemp0(res[0],res[1],res[2],res[3],i);
      mapIps.insert({iptemp0.getIpDec(),iptemp0});
      i++;
      continue;
    }

    std::vector<int> res;
    std::vector<int> res2;

    std::size_t found = line.find(":", 15);
    std::string ip1 = line.substr(15, found-15);
    std::size_t found2 = line.find(" ", found+1);
    std::size_t found3 = line.find(":", found2+1);
    std::string ip2 = line.substr(found2, found3-found2);

    std::string delimiter = ".";
    std::size_t pos=0;
    std::size_t pos1=0;

    while((pos = ip1.find(delimiter)) != string::npos){
      res.push_back(std::stoi(ip1.substr(0, pos)));
      ip1.erase(0, pos + delimiter.length());
    }
    res[3]=std::stoi(ip1.substr(0,pos));

    while((pos1 = ip2.find(delimiter)) != string::npos){
      res2.push_back(std::stoi(ip2.substr(0, pos1)));
      ip2.erase(0, pos1 + delimiter.length());
    }
    res2[3]=std::stoi(ip2.substr(0,pos));
    

    Entrada iptemp1(res[0],res[1],res[2],res[3],0);
    Entrada iptemp2(res2[0],res2[1],res2[2],res2[3],0);

    std::map<long int, Entrada>::iterator it1;
    std::map<long int, Entrada>::iterator it2;

    it1 = mapIps.find(iptemp1.getIpDec());
    int nodoU=-1,nodoV=-1;
    if(it1 != mapIps.end()){
      nodoU=it1->second.getIndex();
    }
    it2 = mapIps.find(iptemp2.getIpDec());
    if(it2 != mapIps.end()){
      nodoV=it2->second.getIndex();
    }
    if(nodoU != -1 && nodoV !=-1){
      adjList[nodoU].push_back(nodoV);
      it1->second.updateSalida();
      it2->second.updateEntrada();
    }
    i++;
  }
}

void Graph::split(std::string line, std::vector<int> & res) {
  size_t strPos = line.find(" ");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::split2(std::string line, std::vector<int> & res) {
  size_t strPos = line.find(".");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(".", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::createHash(){
  HashTable<long int, Entrada> myHash(13381);

  std::map<long int, Entrada>::iterator it1;
  for (it1=mapIps.begin(); it1!=mapIps.end(); ++it1){
    myHash.add(it1->first,it1->second);
  }
  myHash.getIPSummary();

}