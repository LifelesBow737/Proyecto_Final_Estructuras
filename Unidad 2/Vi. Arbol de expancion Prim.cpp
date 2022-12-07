// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// numero de nodos del grafo
#define V 5

int precio[20];

int pesoTotal;
//Cantidad de dias
int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};

int main() {
    
    //int** MatrizAdy = NULL, CantNodos, op;
    //string Ni, Nf;
    vector<string> NombreNodos;

    
    int no_edge;  // numero de nodos
    pesoTotal = 0;

    // crear un arreglo para tratar
    int selected[V];
    memset(selected, false, sizeof(selected));

    // colocar numero de nodos en 0
    no_edge = 0;

    // seleccionar marcar el grafo inicial como 0
    selected[0] = true;

    int x;  //  numero de fila
    int y;  //  numero de columna

    // Imprimir cada nodo y su peso
    cout << "Persona   :    Dinero de ganancia";
    cout << endl;
    while (no_edge < V - 1) {

    int max = -9999;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
        if (selected[i]) {
            for (int j = 0; j < V; j++) {
                if (!selected[j] && G[i][j]) {//no ha sido seleccionado y existe el nodo
                    if (max < G[i][j]) {
                        max = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
    }
    pesoTotal += G[x][y];
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
    }
    cout<<"El peso total del recorrido fue: "<<pesoTotal<<endl;

    return 0;
}
