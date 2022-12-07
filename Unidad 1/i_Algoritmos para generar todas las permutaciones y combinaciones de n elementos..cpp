/*
Hecho por Diego L�pez Mendoza
Ingenier�a en Computaci�n Inteligente Tercer Semestre.
Fecha: 15 de Agosto del 2022
Objetivo: An�lisis de como sacar la tabla de Permutaciones y la tabla de Combinaciones a partir de n y r dado por el usuario
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int Factorial(int);
void Imprime_Permutacion(int [], int );
void Permutacion_Heap(int [], int , int );
void Obtener_Combinaciones(int [], int , int ,int , int [], int );
void Imprime_Combinacion(int [], int , int );

int main(){
	
	//Declaraci�n de las variables
	int Num_Elementos=0,Num_Elegidos=0,Numero_x=0,Permutacion=0,Combinacion=0,Size=0;
	int a[]={1,2,3,4,5,6,7,8,9};

		do{
			cout<<"Ingrese el numero de elementos que tendra el conjunto dentro de 2-9: ";cin>>Num_Elementos;
			system("cls");
		}while(Num_Elementos<=2 ||Num_Elementos>9);
		
	do{
		cout<<"Ingrese el numero de elementos con los que desea trabajar: ";cin>>Num_Elegidos;
		system("cls");
	}while(Num_Elegidos<2 ||Num_Elegidos>Num_Elementos);
	
	Permutacion=Factorial(Num_Elementos)/(Factorial(Num_Elementos-Num_Elegidos));
	Combinacion=Factorial(Num_Elementos)/((Factorial(Num_Elementos-Num_Elegidos))*(Factorial(Num_Elegidos)));
		
	cout<<"Numero de permutaciones: "<<Permutacion<<endl<<"Tabla de permutaciones:"<<endl;
	Permutacion_Heap(a,Num_Elementos,Num_Elegidos);
	cout<<"Numero de combinaciones: "<<Combinacion<<endl<<"Tabla de combinaciones:"<<endl;
	Imprime_Combinacion(a,Num_Elementos,Num_Elegidos);

	
	system("pause");
	return 0;
}

int Factorial(int x){
	int aux=1;
	for(int i=1;i<=x;i++){
		aux=aux*i;
	}
	return aux;
}

void Imprime_Permutacion(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	printf("\n");
}

void Permutacion_Heap(int a[], int Size, int n)
{
	if (Size == 1) {
		Imprime_Permutacion(a, n);
		return;
	}

	for (int i = 0; i < Size; i++) {
		Permutacion_Heap(a, Size - 1, n);

		if (Size % 2 == 1)
			swap(a[0], a[Size - 1]);

		else
			swap(a[i], a[Size - 1]);
	}
}

void Imprime_Combinacion(int arr[], int n, int r)
{
    int data[r];
    Obtener_Combinaciones(arr, n, r, 0, data, 0);
}

void Obtener_Combinaciones(int arr[], int n, int r,int index, int data[], int i)
{
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }
    if (i >= n)
        return;
    data[index] = arr[i];
    Obtener_Combinaciones(arr, n, r, index+1, data, i+1);
    Obtener_Combinaciones(arr, n, r, index, data, i+1);
}
