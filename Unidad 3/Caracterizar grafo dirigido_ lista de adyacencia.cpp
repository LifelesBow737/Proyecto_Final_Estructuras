#include <iostream>
#include <vector>

using namespace std;
 
// Function to print adjacency list
void impList(int **edges, int V)
{
    for (int i = 0; i < V; i++) {
        cout << i << " ->";
        for (int j = 0; j < V; j++) {
            if(edges[i][j] == 1)
                cout << j << "->";
        }
        cout << endl;
    }
}
 
// Driver Code
int main()
{
    int V, op, in, fin;
    
    cout<<"Ingresa la cantidad de nodos del grafo: ";
    cin>>V;
    cout<<endl<<"Ingresa la cantidad de nodos del conjunto R: ";

    // Crear grafo
    int** edges = new int*[V];
    for (int i = 0; i < V; ++i){
        edges[i] = new int[V];
    }
    
    cout<<"Grafo creado con exito"<<endl;
    do{
        cout<<endl<<"----MENU----"<<endl;
        cout<<endl<<"1.-Ingresar conexion"<<endl;
        cout<<"2.-Salir"<<endl;
        cout<<endl<<"Ingresa opcion: ";
        cin>>op;
        
        switch(op){
                case 1:
                    do{
                        cout<<"Ingrese el nodo inicial de la conexion (numeros de "<<0<<" a "<<V-1<<"): ";
                        cin>>in;
                        if(in < 0 || in > V-1){
                            cout<<"Nodo no valido"<<endl;
                        }
                    }while(in < 0 || in > V-1);
                    do{
                        cout<<"Ingresa el nodo final de la conexion (numeros de "<<0<<" a "<<V-1<<"): ";
                        cin>>fin;
                        if(fin < 0 || fin > V-1){
                            cout<<"Nodo no valido"<<endl;
                        }
                    }while(fin < 0 || fin > V-1);
                    edges[in][fin] = 1;
                    cout<<"Grafo dirigido en lista de adyacencia: "<<endl;
                    impList(edges, V);
                break;
                
            case 2:
                cout<<"Saliendo"<<endl;
            break;;
        }
    }while(op != 2);
 
    return 0;
}
