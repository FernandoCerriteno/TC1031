/*
Tecnológico y de Estudios Superiores de Monterrey

Programa creado por:
Luis Ángel Alba Alfarro A01640314
Fernando Cerriteño Magaña A01702790

Formato de codificación UTF-8
*/

#include <iostream>

using namespace std;

/*
sumaIterativa - Recibe un número entero positivo con el cual se determinara el número de 
ciclos que el comando for ejecutara para poder sumar de 1 hasta n con un metodo iterativo
Orden - O(n)
*/
int sumaIterativa(int n){
    int sum;

    for (int i=1; i<=n;i++){
        sum=i+sum;             
    }

    return sum;
}

/*
sumaRecursiva - Recibe un número entero positivo con el cual sumara de 1 hasta dicho número de 
una forma repetitiva al llamar a la misma función. 
Orden - O(n)
*/
int sumaRecursiva(int n){
    if (n<=1)
        return n;
    else {
        return n + sumaRecursiva(n-1);
    }
}

/*
sumaDirecta - Utiliza el metodo matematico de Gauss para poder obtener la suma desde 1 hasta un
número n que se asigna al inicio.
Orden - O(1)
*/
int sumaDirecta(unsigned int n){
    if (n==1){
        return 1;
    }
    else{
        int sum=(n*(n+1))/2;
        return sum;
    }
}

/*
fibonacciIterativa - Recibe un número entero positivo con el cual realiza un ciclo con sumas sigiendo
la sucesión de fibonacci e imprime la sucesión hasta el n-esimo numero.
Orden - O(n log n)
*/
int  fibonacciIterativa(unsigned int n) {
    if(n==1||n==2){
        return 1;
    }
    else{
        int  lista[n];
        lista[0]=1; lista[1]=1;
        for (int i=2;i<=n;i++){
            int num=lista[i-2]+lista[i-1];
            lista[i]=num;
            cout<<lista[i-1]<<endl;
        }
        return lista[n];
    }
}

/*
fibonacciRecursiva - Recibe un número entero positivo con el cual realiza una recursión 
llamando a la misma función para cumplir con la sucesión de fibonacci e imprime la sucesión 
hasta el n-esimo numero.
Orden - O(n)
*/
void fibonacciRecursiva(unsigned int n){
    static int n1=0, n2=1, n3;

    if(n>0){
        n3=n1+n2;
        n1=n2;
        n2=n3;
        cout<<n3<<endl;

        fibonacciRecursiva(n-1);
    }
}


int main(){
    cout<<"Metodo sumaIterativa con 20: "<<sumaIterativa(20)<<endl;
    cout<<"Metodo sumaIterativa con 50: "<<sumaIterativa(50)<<endl;
    cout<<"Metodo sumaIterativa con 100: "<<sumaIterativa(100)<<endl;
    cout<<"Metodo sumaIterativa con 1000: "<<sumaIterativa(1000)<<endl;
    cout<<endl;
    cout<<"Metodo sumaRecursiva con 20: "<<sumaRecursiva(20)<<endl;
    cout<<"Metodo sumaRecursiva con 50: "<<sumaRecursiva(50)<<endl;
    cout<<"Metodo sumaRecursiva con 100: "<<sumaRecursiva(100)<<endl;
    cout<<"Metodo sumaRecursiva con 1000: "<<sumaRecursiva(1000)<<endl;
    cout<<endl;
    cout<<"Metodo sumaDirecta con 20: "<<sumaDirecta(20)<<endl;
    cout<<"Metodo sumaDirecta con 50: "<<sumaDirecta(50)<<endl;
    cout<<"Metodo sumaDirecta con 100: "<<sumaDirecta(100)<<endl;
    cout<<"Metodo sumaDirecta con 1000: "<<sumaDirecta(1000)<<endl;
    cout<<endl;
    cout<<"Secuencia de fibonacci Iterativa hasta la posicion 5: "<<endl<<fibonacciIterativa(5)<<endl;
    cout<<"Secuencia de fibonacci Iterativa hasta la posicion 10: "<<endl<<fibonacciIterativa(10)<<endl;
    cout<<"Secuencia de fibonacci Iterativa hasta la posicion 30: "<<endl<<fibonacciIterativa(30)<<endl;
    cout<<endl;
    cout<<"Secuencia de fibonacci Recursiva hasta la posicion 5: "<<endl;
    fibonacciRecursiva(5);
    cout<<endl;
    cout<<"Secuencia de fibonacci Recursiva hasta la posicion 10: "<<endl;
    cout<<endl;
    fibonacciRecursiva(10);
    cout<<endl;
    cout<<"Secuencia de fibonacci Recursiva hasta la posicion 30: "<<endl;
    fibonacciRecursiva(30);

    return 0;
}
