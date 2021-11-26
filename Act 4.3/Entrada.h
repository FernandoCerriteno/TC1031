#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Entrada{
  private:
    int ip1,ip2,ip3,ip4;
    int cont=0;

  public:
    Entrada(int ip1, int ip2, int ip3, int ip4);
    Entrada();
    void imprimeIp();
    int getIpDec();
    string getIpStr();
    void setCont(int grado);
    int getCont();
};

#endif