#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(void) {
    cout<<"Unidad 1, Programa 3"<<endl;
    cout<<"Generar cadena binaria de tamaño n"<<endl;
    int cantidad;
    int decimal,datos;
    int b[100];
    int i,j,n;

    cout<<"Digite la cantidad de elementos: ";
    cin>>cantidad;
    datos = pow(2,cantidad)-1;
    //cout<<"\n-------------------------------------------------------------------------\n\n";
       cout<<"DECIMAL\t\tBINARIO\n0\t\t0\n";
    //cout<<"\n-------------------------------------------------------------------------\n\n";

    for(decimal = 1;decimal <= datos;decimal++) {
        i = 0;
        n = decimal;

        while(n > 0) {
            b[i] = n % 2;//b[0]=0, b[1]=1
            n = n / 2;//decimal=1, decimal=0
            i++;//i=1, i=2
        }

        printf("%d:\t\t",decimal);
        for(j = (i - 1);j >= 0;j--) {
            cout<<b[j];
        }

        cout<<"\n";
    }
    system("pause");
    return 0;
}

