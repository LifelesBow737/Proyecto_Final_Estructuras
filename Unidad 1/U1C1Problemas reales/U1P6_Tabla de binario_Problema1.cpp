/*Programa 1.-
	Programa conjunto potencia con matriz binaria, correspondencia de columnas y conjunto.
	(Capturar los elementos del conjunto de un vector
	Hacer la tabla binaria este en una matriz 
	La columna corresponde a un elemento del conjunto)
 */
 
 // Autor: Gregory Gustavo Richarte Pérez
 // Fecha: 25 de agosto de 2022
 // Estructuras computacionales
 
#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

void Convertir(int numero){
	int vector[100], x = 0;
	
	while(numero != 0){
		vector[x]= numero%2;
		numero /= 2;
		x++;
	}
	
	cout<<"Numero binario: ";
	
	for(int i= x-1; i>=0; i--){
		cout<<vector[i];
	}
	cout<<endl;
}

//Capturar el conjunto en un vector
//Crear matriz de tabla binaria de 2 a la n elementos del conjunto
//Imprimir conjunto potencia en base al punto 1 y 2.

int main(){
	//Varibles
	unsigned int elementos, numero;
	int x=0,y;
	
	//1.- Capturar el conjunto en un vector
	cout<<"Digite la cantidad de elementos en el vector: ";
	cin>>elementos;
	
	char eleConj[elementos];
	int vector[elementos];
	
	for(int i=0;i<elementos;i++){
		cout<<"Digite elemento "<<i+1<<" : ";
		cin>>eleConj[i];
	} 
	
	//2.- Generar la tabla binaria en una matriz
	int fila = pow(2,elementos);
	int tablaBin[fila][elementos]; //FILAS Y COLUMNAS
	//asignar ceros a la matriz
	for(int r=0;r<fila;r++){
		for(int c=0; c<elementos; c++){
			tablaBin[r][c] = 0;
		}
	}
	
	//Crear tabla binaria
	for(int var=1; var<fila; var++){
		numero = var; 
		x=0;
		while(numero != 0){
			vector[x] = numero%2;
			numero /= 2;
			x++; //Vamos aumentando una posición en el vector 
		}
		
		y= elementos-1;
		
		for(int i=0;i<x;i++){
			tablaBin[var][y]=vector[i];
			y--;
		}
	}
	
	
	//3.- Imprimir el conjunto potencia usando el vector y matriz
	for(int r=0;r<fila;r++){
		for(int c=0; c<elementos; c++){
			cout<<tablaBin[r][c];
		}
		cout<<endl;
	}
	
	//Imprimir el conjunto potencia usando el vector y matriz
	getch();
	return 0;
}


