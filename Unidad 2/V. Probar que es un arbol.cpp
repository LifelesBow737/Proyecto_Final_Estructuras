#include<iostream>
#define NODE 5
using namespace std;

int graph[NODE][NODE] = {
   {0,0,0,0,1},
   {0,0,0,0,1},
   {0,0,0,0,1},
   {0,0,0,0,1},
   {1,1,1,1,0}
};
                                                               
bool isCycle(int u, bool visited[], int parent) {
   visited[u] = true;    //Marcar u como visitado
   for(int v = 0; v<NODE; v++) {
      if(graph[u][v] == 1) {
         if(visited[v] == false) {     //Cuando el nodo adyacente v no es visitado
            if(isCycle(v, visited, u) == true) {
               return true;
            }
         } else if(v != parent) {    //Cuando el nodo ayacente es visitado pero no hay padre
            return true;    //Hay un ciclo
         }
      }
   }
   return false;
}

bool isTree() {
   bool *vis = new bool[NODE];

   for(int i = 0; i<NODE; i++)
      vis[i] = false;    //Un no nodo es visitado
         
   if(isCycle(0, vis, -1) == true)    //Verificar si existe un ciclo
      return false;
         
   for(int i = 0; i<NODE; i++) {
      if(!vis[i])    //Si un nodo iniciado no es visitado, no es un arbol
         return false;
   }
   return true;
}

int main() {
   if(isTree() == true)
      cout << "El grafo es un arbol."<<endl;
   else
      cout << "El grafo no es un arbol."<<endl;
}
