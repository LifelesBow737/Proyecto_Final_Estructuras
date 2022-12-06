
// C++ program para encontrar si un
// grafo es bipartido o no
#include <iostream>
#include <queue>
#define V 4
 
using namespace std;
 
// Esta funcion devuelve true si
// G[V][V] es Bipartite, si no false
bool isBipartite(int G[][V], int src)
{
    // Crear un arreglo de colores
    // El valor -1 en colorArr[i]
    // Se usa para indicar sin color
    // El valor 0 para indicar un color
    // El valor 1 para indicar otro color
    int colorArr[V];
    for (int i = 0; i < V; ++i){
        // Marcar todos los nodos como incloros
        colorArr[i] = -1;
    }
 
    // Asignar color al nodo inicial
    colorArr[src] = 1;
 
    // Crear un queue (FIFO) de nodos
    queue <int> q;
    q.push(src);
 
    // Seguir mientras alla nodos en la pila(queue)
    while (!q.empty())
    {
        // u es igual al nodo ingresado en queue
        int u = q.front();
        q.pop();
 
        // Devolver falso si un grafo apunta a si mismo
        if (G[u][u] == 1){
            return false;
        }
 
        //Encontrar todos los nodos adyacentes que aun no tienen color
        for (int v = 0; v < V; ++v)
        {
            // Existe un camino de u a v y
            // el destino v no tiene color
            if (G[u][v] && colorArr[v] == -1)
            {
                // Se asigna el color opuesto y se introduce en queue
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
 
            // Existe un camino de u a v y
            // el destino v tiene el mismo color
            else if (G[u][v] && colorArr[v] == colorArr[u]){
                return false;
            }
        }
    }
    // Si llegamos hasta aqui entonces todos los nodos cumplen las condiciones
    // los nodos adyacentes pueden ser coloreados con colores diferentes
    return true;
}
 
//Funcion principal para creando una matriz
int main()
{
    int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
 
    isBipartite(G, 0) ? cout << "Yes" : cout << "No";
    return 0;
}
