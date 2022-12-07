#include<iostream>
using namespace std;

int main(){
    int var=0;
    cout<<"Ingrese el valor del cual desea comprobar si es par o no: ";cin>>var;
    if(var%2){
        cout<<"No es par"<<endl;
    }else{
        cout<<"En efecto, es par"<<endl;
    }
    system("pause");
    return 0;
}