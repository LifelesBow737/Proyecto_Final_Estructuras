#include <iostream>
#include <vector>

using namespace std;

// Añadir nodo
void agregarNodo(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

// Imprimir lista
void imprimirGrafo(vector<int> adj[], int V, int L) {
    for (int d = 0; d < L; ++d) {
        cout<<"\n Nodo "<<d<<":";
        for (auto x : adj[d]){
            cout << " - " << x;
        }
        printf("\n");
    }
}

int main() {
    int L, R, op, in, fin;
    
    cout<<"Ingresa la cantidad de nodos del conjunto L: ";
    cin>>L;
    cout<<endl<<"Ingresa la cantidad de nodos del conjunto R: ";
    cin>>R;

    int V = L*R;
    // Crear grafo
    vector<int> adj[V];
    
    cout<<"Grafo creado con exito"<<endl;
    do{
        cout<<endl<<"----MENU----"<<endl;
        cout<<endl<<"1.-Ingresar conexion"<<endl;
        cout<<"2.-Salir"<<endl;
        cout<<endl<<"Ingresa opcion: ";
        cin>>op;
        
        switch(op){
            case 1:
                // Add edges
                do{
                    cout<<"Ingrese el nodo inicial del grupo 1 (numeros de "<<0<<" a "<<L-1<<"): ";
                    cin>>in;
                    if(in < 0 || in > L-1){
                        cout<<"Nodo no valido"<<endl;
                    }
                }while(in < 0 || in > L-1);
                do{
                    cout<<"Ingresa el nodo donde termina del grupo 2 (numeros de "<<L<<" a "<<V-1<<"): ";
                    cin>>fin;
                    if(fin < L || fin > V-1){
                        cout<<"Nodo no valido"<<endl;
                    }
                }while(fin < L || fin > V-1);
                agregarNodo(adj, in, fin);
                cout<<"Grafo de adyacencia en lista de adyacencia: "<<endl;
                imprimirGrafo(adj, V, L);
            break;
                
            case 2:
                cout<<"Saliendo"<<endl;
            break;
        }
    }while(op != 2);
}
