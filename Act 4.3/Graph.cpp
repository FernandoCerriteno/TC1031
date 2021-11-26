#include "Graph.h"

Graph::Graph(std::istream& input) {
  loadGraphList(input);
  visited.resize(numNodes+1);
}

Graph::Graph(){
  this->numNodes=0;
  this->numEdges=0;
}

Graph::~Graph() {
  adjList.clear();
  visited.clear();
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
      Entrada iptemp0(res[0],res[1],res[2],res[3]);
      std::pair<Entrada,int> parTemp(iptemp0,0);
      listaIp.push_back(parTemp);
      i++;
      continue;
    }

    std::vector<int> res;
    std::vector<int> res2;
    split3(line, res,res2);

    Entrada iptemp1(res[0],res[1],res[2],res[3]);
    Entrada iptemp2(res2[0],res2[1],res2[2],res2[3]);

    for (int j=0;j<listaIp.size();j++){
      if (listaIp[j].first.getIpDec()==iptemp1.getIpDec()){
        adjList[j].push_back(iptemp2.getIpDec());
        listaIp[j].second=listaIp[j].second+1;
      }
    }

    //iptemp1.imprimeIp();
    //iptemp2.imprimeIp();

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

void Graph::split3(std::string line, std::vector<int> & res, std::vector<int> & res2) {
  size_t strPos = line.find(" ");
  size_t lastPos = 0;
  for(int i;i<2;i++){
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  for (int i=0;i<3;i++){
    lastPos = strPos + 1;
    strPos = line.find(".", lastPos);
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
  } 
  lastPos = strPos + 1;
  strPos = line.find(" ", lastPos);
  res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));

  while (strPos != std::string::npos) {
    lastPos = strPos + 1;
    strPos = line.find(".", lastPos);
    res2.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
  }
}

void Graph::createBitacora(){
  std::string nombreArch="grados_ips.txt";
  std::string esp = " ";
  //Se crea el archivo bitacora_ordenada.txt donde se escribe el resultado
  ofstream file;
  file.open(nombreArch);
  file<<"Ip          Grado\n";
  for (int i=0;i<listaIp.size();i++){
    file << listaIp[i].first.getIpStr() << " " << listaIp[i].second <<"\n";
  }
  file.close();
}

void Graph::createBitacora5(){
  Entrada bootmaster;
  std::string nombreArch = "mayores_grados_ips.txt";
  std::string esp = " ";
  //Se crea el archivo bitacora_ordenada.txt donde se escribe el resultado
  ofstream file;
  file.open(nombreArch);
  file << "Las cinco ip's con mayor acceso son:\n";
  MaxHeap<Entrada> myheap(numNodes);
  for (int j=0;j<listaIp.size();j++){
    listaIp[j].first.setCont(listaIp[j].second);
    myheap.pushCont(listaIp[j].first);
  }  
  for (int i=0;i<5;i++){
    if (i==0){
      bootmaster=myheap.top();
    }
    file << i+1 << " " << myheap.top().getIpStr() << ", con un numero total de accesos: " << myheap.top().getCont() <<"\n";
    myheap.popCont();
  }
  std::cout<<"Ls ip bootmaster es ";
  bootmaster.imprimeIp();

  file.close();
}