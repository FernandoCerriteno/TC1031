/*
Tecnológico y de Estudios Superiores de Monterrey
Actividad 1.3 - Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales

Programa creado por:
Fernando Cerriteño Magaña A01702790
21/09/2021

Formato de codificación UTF-8
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include "Entrada.h"
#include "dateTime.h"

using namespace std;

int main(){
    //Se crean variables que el codigo va a utilizar
    string archivotxt="bitacora.txt"; //El nombre del archivo
    string linea,esp = " "; //La variable linea, en la que se almacena la linea del texto y la variable espacio para facilitar operaciones
    ifstream archivo(archivotxt); //Se abre el aechivo
    int tam=0; //Variable para determinar el tamaño del archivo
    vector <Entrada> entradas; //Vector de tipo Entrada en donde se van a almacenar cada una de las lineas 

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
        
        //Se crea la variable ent, en donde se almacena el registro de cada linea y se integra en el vector entradas.
        Entrada ent(mes,diast,hora,min,seg,ip,razon);
        entradas.push_back(ent);
    }

    //Ordena el vector entradas con el algoritmos de ordenamiento Merge
    entradas[0].ordenaMerge(entradas,0,entradas.size()-1);
    
    //Se crea el archivo bitacora_ordenada.txt donde se escribe el resultado
    ofstream file;
    file.open("bitacora_ordenada.txt");

    for (int i=0;i<entradas.size();i++){
      file <<entradas[i].getMes()<<esp<<entradas[i].getDiastr()<<esp<<entradas[i].getHorastr()<<":"<<entradas[i].getMinstr()<<":"<<entradas[i].getSegstr()<<esp<<entradas[i].getIp()<<esp<<entradas[i].getRazon()<<"\n";
    }
    
    file.close();



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
    int entri=fechai.busquedaBinaria(entradas,entradas.size(),fechai),
        entrf=fechaf.busquedaBinaria(entradas,entradas.size(),fechaf);

    //Se imprime el resultado de busqueda en la consola
    for(int i=entri;i<=entrf;i++){
      entradas[i].imprimeEntrada();
    }
    return 0;
}
