#include<iostream>
using namespace std;

int main(){
    int n=0;
    cout<<"Ingrese el numero de vertices del grafo. ";cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){   
            if(i!=j){
            cout<<"ingrese el peso de la arista entre el vertice "<<i+1<<" y "<<j+1<<": ";cin>>mat[i][j];
            }else{
                mat[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){   
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}