#include<iostream>
using namespace std;

int main(){

	cout<<"Unidad 2, programa No.7"<<endl;
    cout<<"Grafo Matriz de adyacencia"<<endl;

	int n=5,i=0,j=0;
	//cout<<"Ingrese el numero de vertices del grafo: ";cin>>n;
	int matriz[5][5];
	cout<<"(Si existe conexion presiones 1, si no la hay, presione 0)"<<endl<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<"Exite conexion entre el nodo "<<i+1<<" y "<<j+1<<"? ";cin>>matriz[i][j];
			
		}
	}
	cout<<endl<<"Tabla de aristas"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matriz[i][j]!=0){
				cout<<i+1<<" - "<<j+1<<endl;
			}
		}
	}
	
	system("pause");
	return 0;
}
