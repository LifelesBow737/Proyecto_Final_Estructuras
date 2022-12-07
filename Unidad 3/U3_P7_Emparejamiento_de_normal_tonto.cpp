#include <iostream>
#include <locale.h>

using namespace std;

int main(){
    int i=0,j=0,l;
    cout<<endl<<"ingrese la canditidad de nodos: ";
    cin>>l;
    
    int matriz[l][l],VR[l];
    
    for(i=0;i<l;i++){
        for(j=0;j<l;j++){
            matriz[i][j]=0;
        }
    }
    memset(VR, 0, sizeof(VR));
    for(i=0;i<l;i++){
        for(j=0;j<l;j++){
            if(j!=i){
                cout<<endl<<"El nodo "<<i<<" y "<<j<<" estan conectados(1-si, 0-no): ";
                cin>>matriz[i][j];
            }
        }
    }
    for(i=0;i<l;i++){
        for(j=0;j<l;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(i=0;i<l;i++){
        for(j=0;j<l;j++){
            if(matriz[i][j]==1 && VR[j]==0){
                VR[j]=1;
                cout<<"L"<<i+1<<"-R"<<j+1<<"\n";
                break; //Salir del for
            }
        }
    }
}