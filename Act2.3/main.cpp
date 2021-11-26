/*
Tecnológico y de Estudios Superiores de Monterrey
Actividad 1.3 - Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales

Programa creado por:
Fernando Cerriteño Magaña A01702790
15/10/2021

Algoritmos de QuickSort basado del código del usuario/a rathbhupendra

Formato de codificación UTF-8

Código para compilar
g++ -std=c++17 -o main *.cpp 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Entrada.h"
#include "dateTime.h"
#include "DoubleLinkedList.h"

using namespace std;

int main(){
  //Se crean variables que el codigo va a utilizar
  string archivotxt="bitacora.txt"; //El nombre del archivo
  string linea,esp = " "; //La variable linea, en la que se almacena la linea del texto y la variable espacio para facilitar operaciones
  ifstream archivo(archivotxt); //Se abre el aechivo
  int tam=0; //Variable para determinar el tamaño del archivo
  DoubleLinkedList<Entrada> entradas_dll;//DoubleLinkedList de tipo Entrada en donde se van a almacenar cada una de las lineas 

  while (getline(archivo,linea)){
      stringstream ss(linea);
      string mes,diast,hora,min,seg,ip,razon,razon1,razon2,razon3,razon4,razon5;
      
      //Se obtiene cada una de las variables dependiendo de lo que se requiera
      getline(ss,mes,' ');
      getline(ss,diast,' ');
      getline(ss,hora,':');
      getline(ss,min,':');
      getline(ss,seg,' ');
      getline(ss,ip,' ');
      getline(ss,razon,' ');
      getline(ss,razon1,' ');
      getline(ss,razon2,' ');
      getline(ss,razon3,' ');
      getline(ss,razon4,' ');
      getline(ss,razon5,' ');
      
      tam++;
      
      razon = razon + esp + razon1 + esp + razon2 + esp + razon3 + esp + razon4 + esp + razon5; 
      
      //Se crea la variable ent, en donde se almacena el registro de cada linea y se integra en la DoubleLinkedList entradas_dll.
      Entrada ent(mes,diast,hora,min,seg,ip,razon);
      entradas_dll.addFirst(ent);
  }

  //Ordena la lista entradas_dll con el algoritmos de ordenamiento quickSort
  entradas_dll.quickSort();

  //Crea el archivo de txt llamado bitacora_ordenada.txt con la bitacora ordenada
  entradas_dll.crearBitacora();
  
  cout<<"Ingrese el intervalo de fechas que quisiera observar"<<endl;
  
  //Variables requeridas para hacer la busqueda
  int diaif,horaif=0,minif=0,segif=0;
  string mesif;

  //Se le pide al usuario los valores de busqueda
  cout<<"Fecha inicial "<<endl;
  cout<<"Mes(Ej. Oct): "; cin>>mesif; 
  cout<<"Dia(Numero entero): "; cin>>diaif; 
  cout<<"Hora: "; cin>>horaif;
  cout<<"Minutos: "; cin>>minif;
  cout<<"Segundos: "; cin>>segif;
  cout<<endl;

  //Se crea una variable tipo dateTime para poder hacer la busqueda de una forma mas efectiva
  dateTime fechai(mesif,diaif,horaif,minif,segif);

  cout<<"Fecha final "<<endl;
  cout<<"Mes(Ej. Oct): "; cin>>mesif; 
  cout<<"Dia(Numero entero): "; cin>>diaif; 
  cout<<"Hora: "; cin>>horaif;
  cout<<"Minutos: "; cin>>minif;
  cout<<"Segundos: "; cin>>segif;
  cout<<endl;

  dateTime fechaf(mesif,diaif,horaif,minif,segif);  

  //Se obtienen las variables que indican los limites de las busquedas con el algoritmo de busqeda Binaria
  int entri=fechai.busquedaBinaria(entradas_dll,entradas_dll.getNumElements(),fechai);
  int entrf=fechaf.busquedaBinaria(entradas_dll,entradas_dll.getNumElements(),fechaf);
  
  //Se imprime el resultado de busqueda en la consola
  entradas_dll.printListEntrada_par(entri, entrf);
  return 0;
}