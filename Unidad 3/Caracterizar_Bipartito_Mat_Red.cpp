//  main.cpp
//  Caracterizar bipartido_Matriz reducida
//  Created by Hector Robles Pérez on 11/11/2022.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int L,R,i,j,op;
    cout<<"Representacion de un grafo bipartito como una matriz donde"<<endl;
    cout<<"Las filas son el subconjunto de nodos L y las columnas el subconjunto de nodos R"<<endl;
    cout<<"(Nota: este acomoda toma por echo que este es un grafo no dirigido)"<<endl;
    
    cout<<"Ingresa la catidad de nodos del conjunto L: ";
    cin>>L;
    cout<<endl<<"Ingresa la cantidad de nodos del conjunto R: ";
    cin>>R;
    
    int matriz[L][R];
    
    for(i=0; i<L; i++){
        for(j=0; j<R; j++){
            do{
                cout<<endl<<"El nodo "<<i<<" esta conectado con el nodo "<<j<<"(1.-Si, 2.-No): ";
                cin>>op;
                if(op == 1)
                    matriz[i][j] = 1;
                else if(op == 0)
                    matriz[i][j] = 0;
                else
                    cout<<"opcion no valida ingrsa otra"<<endl;
            }while(op != 1 && op != 2);
        }
    }
    cout<<"El grafo representativo es :"<<endl;
    cout<<"  ";
    for(j=0; j<R; j++){
        cout<<j<<" ";
    }
    cout<<endl;
    for(i=0; i<L; i++){
        char temp = 65+i;
        cout<<temp<<" ";
        for(j=0; j<R; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
