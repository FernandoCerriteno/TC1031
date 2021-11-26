#include "dateTime.h"

dateTime::dateTime(string mes, int dia, int horas, int minutos, int segundos) {
  // Almacenar los campos de la fecha-hora en el struct tm
  dateStruct.tm_sec = segundos;
  dateStruct.tm_min = minutos;
  dateStruct.tm_hour = horas;
  dateStruct.tm_mday = dia;
  for (int i=0; i < meses.size(); i++) {
    if (meses[i]==mes)
      dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
  // Obtener el Unix timestamp a partir del struct tm anterior 
  date = mktime(&dateStruct);
}

dateTime::dateTime(){
  
}

//Algoritmo de busqueda binaria
//Complejidad temporal O(log_2(n))
int dateTime::busquedaBinaria(DoubleLinkedList<Entrada>& lista,int size,dateTime key){
  int l=0;
  int r=size-1;
  int m;
  while(l<=r){
    m=l+(r-l)/2;
    Entrada a=lista.getData(m);
    dateTime temp(a.getMes(),a.getDia(),a.getHora(),a.getMin(),a.getSeg());
    if (key==temp){
      return m;
    }
    else if (key < temp){ 
      r=m-1;
    }
    else{ 
      l=m+1;
    }
  }
  return -1;
}

bool dateTime::operator==(const dateTime &other) {
  return this->date == other.date;
}

bool dateTime::operator>(const dateTime &other) {
  return this->date > other.date;
}

bool dateTime::operator<(const dateTime &other) {
  return this->date < other.date;
}