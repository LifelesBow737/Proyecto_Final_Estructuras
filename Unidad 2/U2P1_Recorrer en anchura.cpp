//Menu de una pila

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

Nodo *frente = NULL;
Nodo *final = NULL;

void menu();
void insertarNodo(Nodo *&, Nodo *&, int);
void eliminarNodo(Nodo *&, Nodo *&, int &);

bool todosVisitados(bool v[], int n){
    for (int x = 0; x < n; x++){
        if (v[x] == false){
            return false;
        }
    }
    return true;
}

int main(){

    cout<<"Unidad 2, programa No.1"<<endl;
    cout<<"Recorrido en anchura"<<endl;

    int dato;
    
    srand(time(NULL));

    cout << "Introduce la cantidad de nodos: ";
    int n;
    cin>>n;

    bool ady[20][20] = {};
    bool visitado[20] = {};

    cout << "Introduce su matriz de adyacencia: " << endl;

    // Llenamos la matriz de adyacencia
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cout<<endl<<"["<<x<<"]"<<"["<<y<<"]"<<endl;
            cout<<"El nodo "<<x<<" apunta al nodo "<<y<<"?, 1.-si 0.-no: ";
            cin >> ady[x][y];
        }
        cout << endl;
    }

    int inicio = rand()%n;
    cout << "Inicio: "<<inicio;
    visitado[inicio] = true;

    do{
        for (int x = 0; x < n; x++){
            if ((ady[inicio][x] == 1) && (visitado[x] == false)){
                visitado[x] = true;
                insertarNodo(frente, final, x);
            }
        }

        if(frente != NULL){
            inicio = frente->dato;
            cout << " -> " << frente->dato;
            //system( "read -n 1 -s -p \"Press any key to continue...\"" );
            eliminarNodo(frente, final, dato);
        }

    } while(!todosVisitados(visitado, n) || frente != NULL);

    cout << "\n";
    // Mostramos la matriz de adyacencia.
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cout << ady[x][y];
        }
        cout << endl;
    }
    system("pause");
}

void insertarNodo(Nodo *&frente, Nodo *&final, int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    
    if(frente == NULL)
    {
        frente = nuevo_nodo;
        final = nuevo_nodo;
    }
    else
    {
        final->siguiente = nuevo_nodo;
        final = nuevo_nodo;
    }
}

void eliminarNodo(Nodo *&frente, Nodo *&final, int &n)
{
    Nodo *aux_borrar;
    
    if(frente != NULL)
    {
        if(frente == final)
        {
            aux_borrar = frente;
            n = aux_borrar->dato;
            frente = frente->siguiente;
            frente = NULL;
            final = NULL;
        
            delete aux_borrar;
        }
        else
        {
            aux_borrar = frente;
            n = aux_borrar->dato;
            frente = frente->siguiente;
        
            delete aux_borrar;
        }
    }
    else
    {
    }
}
