#include "Entrada.h"

Entrada::Entrada(int ip1, int ip2, int ip3, int ip4, int indice){
  this->ip1 = ip1;
  this->ip2 = ip2;
  this->ip3 = ip3;
  this->ip4 = ip4;
  index=indice;
  gEntrada=0;
  gSalida=0;
}

Entrada::Entrada(){
  ip1=0;
  ip2=0;
  ip3=0;
  ip4=0;
  index=0;
  gEntrada=0;
  gSalida=0;
}

long int Entrada::getIpDec(){
  long int ipInt = (ip1*pow(256,3))+(ip2*pow(256,2))+(ip3*pow(256,1)+(ip4*pow(256,0)));
  return ipInt;
}

void Entrada::imprimeIp(){
  cout<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<"\n";
}

string Entrada::getIpStr(){
  string ans = to_string(ip1) + "." + to_string(ip2) + "." + to_string(ip3) + "." + to_string(ip4)+" con un numero de Salidas "+to_string(gSalida)+" y un numero de entradas "+to_string(gEntrada);
  return ans;
}

void Entrada::updateEntrada(){
  gEntrada++;
}

int Entrada::getEntrada(){
  return gEntrada;
}

void Entrada::updateSalida(){
  gSalida++;
}

int Entrada::getSalida(){
  return gSalida;
}

int Entrada::getIndex(){
  return index;
}