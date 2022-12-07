#include <iostream>

using namespace std;

// almacenar elementos
struct adjNode {
    int val, cost;
    adjNode* next;
};
// estructura para almazenar nodos
struct graphEdge {
    int start_ver, end_ver, weight;
};
class DiaGraph{
    // inserte nuevos nodos en la lista de adyacencia del gráfico dado
    adjNode* getAdjListNode(int value, int weight, adjNode* head)   {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;
         
        newNode->next = head;   // apuntar el nuevo nodo al encabezado actual
        return newNode;
    }
    int N;  // Numero de nodos en el grafo
public:
    adjNode **head;  //lista de adyacencia como matriz de punteros
    // Constructor
    DiaGraph(graphEdge edges[], int n, int N){
        // alojar nuevo nodo
        head = new adjNode*[N]();
        this->N = N;
        // inicializar puntero de cabeza para todos los vértices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;
        // construir un gráfico dirigido agregándole aristas
        for (unsigned i = 0; i < n; i++){
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;
            // insertar en el principio
            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
             
            // apuntar el puntero de la cabeza al nuevo nodo
            head[start_ver] = newNode;
             }
    }
      // Destructor
     ~DiaGraph() {
    for (int i = 0; i < N; i++)
        delete[] head[i];
        delete[] head;
     }
};
// imprime todos los vértices adyacentes de un vértice dado
void display_AdjList(adjNode* ptr, int i)
{
    while (ptr != nullptr) {
        if(ptr->cost > 0){
            cout<<"("<<i<<", "<<ptr->val<<", "<<ptr->cost<<") ";
        }
        ptr = ptr->next;
    }
    cout << endl;
}

// implementacion del grafo
int main()
{
    int L,R,i,j,op,cont;
    cout<<"Representacion de un grafo bipartido como una lista de aristas con sus pesos respectivos"<<endl<<endl;
    cout<<"Las filas son el subconjunto de nodos L y las columnas el subconjunto de nodos R"<<endl;
    
    cout<<"Ingresa la catidad de nodos del conjunto L: ";
    cin>>L;
    cout<<endl<<"Ingresa la cantidad de nodos del conjunto R: ";
    cin>>R;
    int S = L*R;
    graphEdge edges[S];
    
    for(i=0; i<L; i++){
        for(j=0; j<R; j++){
            cout<<"Ingresa el peso de la conexion entre "<<i<<" y el "<<j+L<<"(ingresa 0 si no hay conexion): ";
            cin>>op;
            edges[cont] = {i,j+L,op};
            cont++;
        }
    }
    int N = R+L;      // Numero de vertices en el grafo
    // calcular numero de aristas
    int n = sizeof(edges)/sizeof(edges[0]);
    // constructor del grafo
    DiaGraph diagraph(edges, n, N);
    // imprecion de las  conexiones
    cout<<"Grafo en lista de adyacencia "<<endl<<endl;
    cout<<"Distribucion de los parentecis, estas son conexiones no dirigidas"<<endl;
    cout<<"(nodo inicial, nodo final, peso):"<<endl<<endl;
    for (int i = 0; i < N; i++)
    {
        // imprimir las vertice del vertices i
        display_AdjList(diagraph.head[i], i);
    }
    return 0;
}