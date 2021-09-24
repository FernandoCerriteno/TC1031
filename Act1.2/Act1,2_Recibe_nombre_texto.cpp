/*
Tecnológico y de Estudios Superiores de Monterrey
Actividad 1.2 - Algoritmos de búsqueda y ordenamiento

Programa creado por:
Luis Ángel Alba Alfarro A01640314
Fernando Cerriteño Magaña A01702790

Formato de codificación UTF-8
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Algoritmo de ordenamiento por el metodo de Intercambio
//Complejidad temporal O(n^2)
void ordenaIntercambio(vector<int> *lista,int tam){
  int swaps,comp;
  for (int i=0;i<tam-1;i++){
    for(int j=i;j<tam;j++){
      comp++;
      if ((*lista)[i]>(*lista)[j]){
        int temp=(*lista)[i];
        (*lista)[i]=(*lista)[j];
        (*lista)[j]=temp;
        swaps++;
      }
    }
  }
  cout<<"El arreglo ordenado con intercambio es:"<<endl;
  for (int i=0; i<(*lista).size();++i) {
        cout<<(*lista)[i]<<" ";
  }
  cout<<endl;
  cout<<"Numero de intercambios realizados - "<<swaps<<endl;
  cout<<"Numero de comparaciones realizadas - "<<comp<<endl;
  
}

//Algoritmo de ordenamiento por el metodo de Burbuja
//Complejidad temporal O(n^2)
void ordenaBurbuja(vector<int> *lista,int tam){
  int swaps,comp;
  for (int i=0;i<tam-1;i++){
    for(int j=0;j<tam-1-i;j++){
      comp++;
      if ((*lista)[j]>(*lista)[j+1]){
        int temp=(*lista)[j];
        (*lista)[j]=(*lista)[j+1];
        (*lista)[j+1]=temp;
        swaps++;
      }
    }
  }
  cout<<"El arreglo ordenado con bubble es:"<<endl;
  for (int i=0; i<(*lista).size();++i) {
        cout<<(*lista)[i]<<" ";
  }
  cout<<endl;
  cout<<"Numero de intercambios realizados - "<<swaps<<endl;
  cout<<"Numero de comparaciones realizadas - "<<comp<<endl;
}

//Algoritmo de ordenamiento por fusion(Merge) Division & Fusion.
void merge(vector<int> &lista, int low, int m, int high){
  vector<int> temp;

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
void ordenaMerge(vector<int>& lista, int low, int high){
  if (low<high) {
    int m = (low + high) / 2;
    ordenaMerge(lista, low, m);
    ordenaMerge(lista, m+1, high);
    merge(lista, low, m, high);
  }
}

//Algoritmo busqueda secuencial ordenada
//Complejidad temporal O(n)
int busquedaSecuencialOrd(vector<int> lista,int n,int k,int*compara){
  *compara=0;
  for(int i=0;i<n;i++){
    (*compara)++;
    if(k<=lista[i]){
      if (k==lista[i]){
        return i+1;
      }
      else{
        return -1;
      }
    }
  }
  return -1;
}

//Algoritmo de busqueda binaria
//Complejidad temporal O(log_2(n))
int busquedaBinaria(vector<int> lista,int size,int key,int *compara){
  int low=0;
  int high=size-1;
  *compara=0;
  while(low<=high){
    int mid=low+(high-low)/2;
    (*compara)++;
    if (key==lista[mid]){
      return mid+1;
    }
    else if (key < lista[mid]){ 
      high=mid-1;
    }
    else{ 
      low=mid+1;
    }
  }
  return -1;
}


int main(){
  ifstream archivo;
  string linea,txt,stam,stipo_ord,stipo_bus,skey;
  int con,tam,tipo_ord,tipo_bus,key;
  int pos,comp;
  vector<int> lista,listaord;

  cout<<"Escribe el nombre con extension del archivo de texto que se quiera abrir"<<endl;
  cin>>txt;
  archivo.open(txt,ios::in); //Abre el archivo en modo lectura

  if (archivo.fail()){
    cout<<"No se puede abrir el archivo"<<endl;
    exit(1);
  }

  while(!archivo.eof()){ //mientras no sea final del archivo
    con++;
    if (con==1){
      getline(archivo,stam);
    } else if (con==2){
      getline(archivo,stipo_ord);
    } else if (con==3){
      getline(archivo,stipo_bus);
    } else if (con==4){
      getline(archivo,skey);
    } else{
      getline(archivo,linea);
      int temp = stoi(linea);
      lista.push_back(temp);
    }
  }
  archivo.close();//Cerramos el archivo
  
  tam=stoi(stam);
  tipo_ord=stoi(stipo_ord);
  tipo_bus=stoi(stipo_bus);
  key=stoi(skey);

  //Aqui se determina en base a los parametros del texto
  if(tipo_ord==1){
    ordenaIntercambio(&lista,tam);
  }
  else if(tipo_ord==2){
    ordenaBurbuja(&lista,tam);
  }
  else if(tipo_ord==3){
    ordenaMerge(lista,0,tam-1);
    cout<<"El arreglo ordenado con merge es:"<<endl;
    for (int i=0; i<tam;++i) {
          cout<<lista[i]<<" ";
    }
  }
  cout<<"El valor a buscar es - "<<key<<endl;
  if(tipo_bus==1){
    pos=busquedaSecuencialOrd(lista,tam,key,&comp);
  }
  else{
    pos=busquedaBinaria(lista,tam,key,&comp);
  }
  cout<<"El dato a buscar se encuentra en la posicion "<<pos<<endl;
  cout<<"El numero de comparaciones fue de - "<<comp<<endl;
  
  
  return 0;
}