#ifndef DATETIME_H
#define DATETIME_H

#include <ctime>
#include <iostream>
#include <vector>
#include "Entrada.h"

using namespace std;

class dateTime {
  private: 
    vector<string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct tm dateStruct;
    time_t date;
    
  public:
    dateTime(string mes, int dia, int horas, int minutos, int segundos);
    bool operator ==(const dateTime&);
    bool operator >(const dateTime&);
    bool operator <(const dateTime&);
    int busquedaBinaria(vector<Entrada> lista,int size,dateTime key);
};

#endif
