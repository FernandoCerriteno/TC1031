/*
Tecnológico y de Estudios Superiores de Monterrey
Actividad 3.4

Programa creado por:
Fernando Cerriteño Magaña A01702790
02/11/2021

Formato de codificación UTF-8

Código para compilar
  g++ -std=c++17 -o main *.cpp 
Compilacion para debug:  
  g++ -std=c++17 -g -o main *.cpp 
Ejecucion con valgrind:
  valgrind --leak-check=full ./main
*/

#include "Entrada.h"
#include "MaxHeap.h"

using namespace std;

int main() {
  remove("bitacora_ordenada.txt");
  remove("ips_con_mayor_acceso.txt");
  string archivotxt="bitacoraHeap.txt"; //El nombre del archivo
  string linea,linea2,esp = " "; //La variable linea, en la que se almacena la linea del texto y la variable espacio para facilitar operaciones

  ifstream archivo(archivotxt); //Se abre el archivo
  int tam;

  while (getline(archivo,linea2)){
    tam++;
  }

  archivo.close();
  
  MaxHeap<Entrada> myHeap(tam);

  ifstream archivo2(archivotxt); //Se abre el archivo

  while (getline(archivo2,linea)){
    stringstream ss(linea);
    string mes,diast,hora,min,seg,ip1,ip2,ip3,ip4,ipDP,razon,razon1,razon2,razon3,razon4,razon5;
    
    //Se obtiene cada una de las variables dependiendo de lo que se requiera
    getline(ss,mes,' ');
    getline(ss,diast,' ');
    getline(ss,hora,':');
    getline(ss,min,':');
    getline(ss,seg,' ');
    getline(ss,ip1,'.');
    getline(ss,ip2,'.');
    getline(ss,ip3,'.');
    getline(ss,ip4,':');
    getline(ss,ipDP,' ');
    getline(ss,razon,' ');
    getline(ss,razon1,' ');
    getline(ss,razon2,' ');
    getline(ss,razon3,' ');
    getline(ss,razon4,' ');
    getline(ss,razon5,' ');
    
    razon = razon + esp + razon1 + esp + razon2 + esp + razon3 + esp + razon4 + esp + razon5; 
    
    Entrada ent(mes,diast,hora,min,seg,ip1,ip2,ip3,ip4,ipDP,razon,0);
    myHeap.push(ent);
  }
  archivo2.close();

  cout<<"--->Ordenando bitacora por ip's\n";
  
  myHeap.createBitacora("bitacora_ordenada.txt");

  cout<<"--->Bitacora ordenada\n--->La bitacora se puede encontrar en el archivo bitacora_ordenada.txt\n";
  MaxHeap<Entrada> myHeap2(tam);
  string linea3,bittxt="bitacora_ordenada.txt";
  ifstream archivo3(bittxt); //Se abre el archivo

  cout<<"\n--->Obteniendo las ip's con mayor numero de accesos\n";
  
  Entrada temp; //Variable de tipo entrada temporal para comparar el numero de accesos
  int acum=0;
  while (getline(archivo3,linea3)){
    stringstream ss(linea3);
    string mes,diast,hora,min,seg,ip1,ip2,ip3,ip4,ipDP,razon,razon1,razon2,razon3,razon4,razon5;
    
    //Se obtiene cada una de las variables dependiendo de lo que se requiera
    getline(ss,mes,' ');
    getline(ss,diast,' ');
    getline(ss,hora,':');
    getline(ss,min,':');
    getline(ss,seg,' ');
    getline(ss,ip1,'.');
    getline(ss,ip2,'.');
    getline(ss,ip3,'.');
    getline(ss,ip4,':');
    getline(ss,ipDP,' ');
    getline(ss,razon,' ');
    getline(ss,razon1,' ');
    getline(ss,razon2,' ');
    getline(ss,razon3,' ');
    getline(ss,razon4,' ');
    getline(ss,razon5,' ');
    
    razon = razon + esp + razon1 + esp + razon2 + esp + razon3 + esp + razon4 + esp + razon5; 
    
    Entrada ent(mes,diast,hora,min,seg,ip1,ip2,ip3,ip4,ipDP,razon,1);
    if (acum==0){
      temp=ent;
      acum++;
    }
    else{
      if (temp.getIpDec()==ent.getIpDec()){
        temp.setCont(temp.getCont()+1);
      }
      else{
        myHeap2.pushCont(temp);
        temp=ent;
      }
    }
  }
  archivo3.close();

  cout<<"--->Ip's obtenidas\n--->Las ip's con mayor numero de accesos se encuentran en el archivo ips_con_mayor_acceso.txt\n";

  myHeap2.createBitacora5("ips_con_mayor_acceso.txt");
  
} 