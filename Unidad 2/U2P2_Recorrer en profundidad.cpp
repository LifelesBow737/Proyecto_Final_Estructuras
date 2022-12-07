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

Nodo *pila = NULL;

void insertarDato(Nodo *&, int);
void sacarNodo(Nodo *&, int &);

bool todosVisitados(bool v[], int n){
    for (int x = 0; x < n; x++){
        if (v[x] == false){
            return false;
        }
    }
    return true;
}

int main(){

    cout<<"Unidad 2, programa No.2"<<endl;
    cout<<"Recorrido en profundidad"<<endl;

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
                insertarDato(pila, x);
            }
        }

        if(pila != NULL){
            inicio = pila->dato;
            cout << " -> " << pila->dato;
            //system( "read -n 1 -s -p \"Press any key to continue...\"" );
            sacarNodo(pila, dato);
        }

    } while(!todosVisitados(visitado, n) || pila != NULL);

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

void insertarDato(Nodo *&pila, int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

void sacarNodo(Nodo *&pila, int &n)
{
    if(pila != NULL)
    {
        Nodo *aux = pila;
        n = aux->dato;
        pila = aux->siguiente;
        delete aux;
      
    }
    else
    {
      
    }
}
