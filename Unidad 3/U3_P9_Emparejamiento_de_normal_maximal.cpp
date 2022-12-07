#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;
int c[10][10];
int flowPassed[10][10];
vector<int> g[10];
int parList[10];
int currentPathC[10];
int bfs(int sNode, int eNode)//breadth first search
{
   memset(parList, -1, sizeof(parList));
   memset(currentPathC, 0, sizeof(currentPathC));
   queue<int> q;//declaracion de vector queue
   q.push(sNode);
   parList[sNode] = -1;//Inicializar lista de pares de nodos
   currentPathC[sNode] = 999;//Inicializar lista de pareja actual de los nodos
   while(!q.empty())// si el vector no esta vacio
   {
      int currNode = q.front();
      q.pop();
      for(int i=0; i<g[currNode].size(); i++)
      {
         int to = g[currNode][i];
         if(parList[to] == -1)
         {
            if(c[currNode][to] - flowPassed[currNode][to] > 0)
            {
               parList[to] = currNode;
               currentPathC[to] = min(currentPathC[currNode],
               c[currNode][to] - flowPassed[currNode][to]);
               if(to == eNode)
               {
                   cout<<currNode<<" a "<<to<<endl;
                  return currentPathC[eNode];
               }
               q.push(to);
            }
         }
      }
   }
   return 0;
}
int edmondsKarp(int sNode, int eNode)
{
   int maxFlow = 0;
   while(true)
   {
      int flow = bfs(sNode, eNode);
      if (flow == 0)
      {
         break;
      }
      maxFlow += flow;
      int currNode = eNode;
      while(currNode != sNode)
      {
         int prevNode = parList[currNode];
         flowPassed[prevNode][currNode] += flow;
         flowPassed[currNode][prevNode] -= flow;
         currNode = prevNode;
      }
   }
return maxFlow;
}

int main()
{
    cout<<"Unidad 3, Programa 8"<<endl;
    cout<<"Pareo a perfecto de grafo normal(edmonds)"<<endl;
    int nodCount, edCount;
    cout<<"Ingresan el numero de nodos: ";
    cin>>nodCount;
    cout<<endl<<"Ingresa el numero de conexiones: ";
    cin>>edCount;
    int source, sink;
    cout<<"Ingresa el inicio del flujo: ";
    cin>>source;
    cout<<endl<<"Ingresa el final del flujo: ";
    cin>>sink;
    for(int ed = 0; ed < edCount; ed++)
    {
       int from, to, cap;
       cout<<"Ingresa el nodo de inicio: ";
       cin>>from;
       cout<<endl<<"Ingresa el nodo final: ";
       cin>>to;
       cout<<endl<<"Ingresa el peso del camino: ";
       cin>>cap;
       //cap = 1;
       c[from][to] = cap;
       g[from].push_back(to);
       g[to].push_back(from);
   }
   int maxFlow = edmondsKarp(source, sink);
   cout<<endl<<endl<<"El flujo maximo es: "<<maxFlow<<endl;
}