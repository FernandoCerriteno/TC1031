#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Entrada{
    private:
      string  mes,dia,hora,min,seg,ip,razon,ipsd;
      int ip1,ip2,ip3,ip4,ipDP;
      int cont;

    public:
      Entrada(string mes, string dia, string hora, string min, string seg, string ip1, string ip2, string ip3, string ip4, string ipDP, string razon, int cont);
      Entrada ();
      void imprimeEntrada();
      int getIpDec();
      int getCont();
      string getMes();
      string getDia();
      string getHora();
      string getMin();
      string getSeg();
      string getIp();
      string getIpSD();
      string getRazon();
      void setCont(int cont);
};

#endif