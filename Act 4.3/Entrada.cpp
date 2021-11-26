#include "Entrada.h"

Entrada::Entrada(int ip1, int ip2, int ip3, int ip4){
  this->ip1 = ip1;
  this->ip2 = ip2;
  this->ip3 = ip3;
  this->ip4 = ip4;
}

Entrada::Entrada(){
  ip1=0;
  ip2=0;
  ip3=0;
  ip4=0;
}

int Entrada::getIpDec(){
  long int ipInt = (ip1*pow(256,3))+(ip2*pow(256,2))+(ip3*pow(256,1)+(ip4*pow(256,0)));
  return ipInt;
}

void Entrada::imprimeIp(){
  cout<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<"\n";
}

string Entrada::getIpStr(){
  string ans = to_string(ip1) + "." + to_string(ip2) + "." + to_string(ip3) + "." + to_string(ip4);
  return ans;
}

void Entrada::setCont(int grado){
  cont = grado;
}

int Entrada::getCont(){
  return cont;
}