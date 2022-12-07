#include <iostream>
#include <locale.h>

using namespace std;

int main(){
    int i=0,j=0,r,l;
    cout<<endl<<"ingrese la canditidad de nodos del subconjunto L: ";
    cin>>l;
    cout<<endl<<"ingrese la canditidad de nodos del subconjunto R: ";
    cin>>r;
    
    int matriz[l][r],VR[r];
    
    for(i=0;i<l;i++){
        for(j=0;j<r;j++){
            matriz[i][j]=0;
        }
    }
    memset(VR, 0, sizeof(VR));
    for(i=0;i<l;i++){
        for(j=0;j<r;j++){
            cout<<endl<<"El nodo L"<<i<<" y R"<<j<<" estan conectados(1-si, 0-no): ";
            cin>>matriz[i][j];
        }
    }
    for(i=0;i<l;i++){
        for(j=0;j<r;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(i=0;i<l;i++){
        for(j=0;j<r;j++){
            if(matriz[i][j]==1 && VR[j]==0){
                VR[j]=1;
                cout<<"L"<<i+1<<"-R"<<j+1<<"\n";
                break; //Salir del for
            }
        }
    }
}
