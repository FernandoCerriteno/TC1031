#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Entrada{
  private:
    int ip1,ip2,ip3,ip4;
    int gEntrada=0, gSalida=0, index;

  public:
    Entrada(int ip1, int ip2, int ip3, int ip4,int indice);
    Entrada();
    void imprimeIp();
    long int getIpDec();
    string getIpStr();
    int getIndex();
    void updateEntrada();
    int getEntrada();
    void updateSalida();
    int getSalida();
};

#endif