#include "Entrada.h"

Entrada::Entrada(string meses, string dia, string hora, string min, string seg, string ip, string razon){
    int horat = stoi(hora), mint = stoi(min),segt = stoi(seg),diat = stoi(dia);
    fechastr.tm_mday=diat;
    fechastr.tm_hour=horat;
    fechastr.tm_min=mint;
    fechastr.tm_sec=segt;
    this->mesprint=meses;
    this->dia=dia;
    this->hora=hora;
    this->min=min;
    this->seg=seg;
    this->ip=ip;
    this->razon=razon;
    for(int i=0;i<mes.size();i++){
        if(mes[i]==meses){
            fechastr.tm_mon=i;
        }
    }
    date = mktime(&fechastr);
}

Entrada::Entrada(){
  
}

void Entrada::imprimeEntrada(){
    string esp=" ";
    cout<<this->mesprint<<esp<<this->dia<<esp<<this->hora<<":"<<this->min<<":"<<this->seg<<esp<<this->ip<<esp<<this->razon<<endl;
}

string Entrada::getMes(){
  return this->mesprint;
}

int Entrada::getDia(){
  return fechastr.tm_mday;
}

int Entrada::getHora(){
  return fechastr.tm_hour;
}

int Entrada::getMin(){
  return fechastr.tm_min;
}

int Entrada::getSeg(){
  return fechastr.tm_sec;
}

string Entrada::getDiastr(){
  return this->dia;
}

string Entrada::getHorastr(){
  return this->hora;
}

string Entrada::getMinstr(){
  return this->min;
}

string Entrada::getSegstr(){
  return this->seg;
}

string Entrada::getIp(){
  return this->ip;
}
        
string Entrada::getRazon(){
  return this->razon;
}

bool Entrada::operator<=(const Entrada &other){
  return this->date <= other.date;
}

//Algoritmo de ordenamiento por fusion(Merge) Division & Fusion.
void merge(vector<Entrada> &lista, int low, int m, int high){
  vector<Entrada> temp;

  int i, j;
  i = low;
  j = m+1;
  
  while ( i <= m && j <= high){

    if (lista[i] <= lista[j]){
      temp.push_back(lista[i]);
      i++;
    } else {
      temp.push_back(lista[j]);
      j++;
    }
  }

  while (i <= m){
      temp.push_back(lista[i]);
      i++;
  }
  while (j <= high){
      temp.push_back(lista[j]);
      j++;
  }
  for(int i = low; i<= high; i++)
    lista[i] = temp[i-low];
}

//Algoritmo de ordenamiento por fusion(Merge) 
//Complejidad temporal O(n log n)
void Entrada::ordenaMerge(vector<Entrada>& lista, int low, int high){
  if (low<high) {
    int m = (low + high) / 2;
    ordenaMerge(lista, low, m);
    ordenaMerge(lista, m+1, high);
    merge(lista, low, m, high);
  }
}
