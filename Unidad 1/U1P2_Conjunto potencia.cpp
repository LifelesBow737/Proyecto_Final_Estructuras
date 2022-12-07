/*
Hecho por Diego LÛpez Mendoza
IngenierÌa en ComputaciÛn Inteligente Tercer Semestre.
Fecha: 18 de Agosto del 2022
Objetivo: Obtener el superconjunto de un grupo de elementos n.
*/
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

//DeclaraciÛn de variables globales
string arr[30];
int x=0;

//Funcion que convierte el numero a binario.
void binario(int);


int main(){
    //Se obtiene el numero de elementos del comnjunto
    cout<<"Unidad 1, programa 2"<<endl;
    cout<<"Conjunto Potencia"<<endl;
    int num=0;
    cout<<"Ingrese el numero de elementos del conjunto: ";cin>>num;

    //Pide los caracteres a usar.
    cout<<endl<<"Ingrese los caracteres del conjunto: "<<endl;
    for(int j=0;j<num;j++){
        cout<<"Ingrese el elemento "<<j+1<<": ";cin>>arr[j];
    }
    
    //Ciclo que recorre los datos y ejecuta la funciÛn.
    num=(pow(2,num))-1;
    for(int j=0;j<=num;j++){
        cout<<j<<" : \t";
        binario(j);
        cout<<endl;
    }
    system("pause");
}

void binario(int n){
    x=0;
    
    cout<<"{";
    while(n!=0){
        if(n%2==1){
            cout<<arr[x];
        }
        x++;
        n/=2;
    }
    cout<<"}";
}

