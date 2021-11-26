#include "Entrada.h"

Entrada::Entrada(string meses, string dia, string hora, string min, string seg, string ip1, string ip2, string ip3, string ip4, string ipDP, string razon, int cont){
  string ipStr = ip1+"."+ip2+"."+ip3+"."+ip4+":"+ipDP;
  this->mes = meses;
  this->dia = dia;
  this->hora = hora;
  this->min = min;
  this->seg = seg;
  this->ip = ipStr;
  this->razon = razon;
  this->cont = cont;
  this->ipsd = ip1+"."+ip2+"."+ip3+"."+ip4;
  

  this->ip1 = stoi(ip1);
  this->ip2 = stoi(ip2);
  this->ip3 = stoi(ip3);
  this->ip4 = stoi(ip4);
  this->ipDP = stoi(ipDP);
}

Entrada::Entrada(){
  this->mes="N/A";
  this->dia="N/A";
  this->hora="N/A";
  this->min="N/A";
  this->seg="N/A";
  this->ip="N/A";
  this->razon="N/A";
  this->cont = 0;

  this->ip1 = 0;
  this->ip2 = 0;
  this->ip3 = 0;
  this->ip4 = 0;
  this->ipDP = 0;
}

void Entrada::imprimeEntrada(){
  string esp=" ";
  cout<<this->mes<<esp<<this->dia<<esp<<this->hora<<":"<<this->min<<":"<<this->seg<<esp<<this->ip<<esp<<this->razon<<esp<<this->cont<<endl;
}

int Entrada::getIpDec(){
  long int ipInt = (ip1*pow(256,3))+(ip2*pow(256,2))+(ip3*pow(256,1)+(ip4*pow(256,0)));
  return ipInt;
}

int Entrada::getCont(){
  return this->cont;
}

void Entrada::setCont(int cont){
  this->cont = cont;
}

string Entrada::getMes(){
  return this->mes;
}
string Entrada::getDia(){
  return this->dia;
}
string Entrada::getHora(){
  return this->hora;
}
string Entrada::getMin(){
  return this->min;
}
string Entrada::getSeg(){
  return this->seg;
}
string Entrada::getIp(){
  return this->ip;
}
string Entrada::getIpSD(){
  return this->ipsd;
}
string Entrada::getRazon(){
  return this->razon;
}