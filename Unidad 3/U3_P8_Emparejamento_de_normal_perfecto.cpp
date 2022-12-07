#include <iostream>
#include <string.h>
using namespace std;
// M es el n˙mero de filas
// y N son las columnas
// A sirve para verificar el n˙mero de parejas que se encontraron
#define M 10
#define N 10
int A;

// Busqueda DFS
// que regresa true si hay un emparejamiento valido
bool bpm(bool grafoBP[M][N], int u, bool visitado[], int parejaR[]){
    //Movimiento en columnas
    for (int v = 0; v < N; v++)
    {
        // Si hay una arista entre ellos y el nodo no ha sido visitado
        if (grafoBP[u][v] && !visitado[v])
        {
            // Marca v como visitado
            visitado[v] = true;
            //Funcion recursiva que marcara la pareja de v
            //Siempre y cuando no se le haya visitado antes
            //Y no tenga a alguien asignado previamente
            if (parejaR[v] < 0 || bpm(grafoBP, parejaR[v], visitado, parejaR))
            {
                parejaR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
// Regresa la mayor cantidad de parejas o matchings
int maxBPM(bool grafoBP[M][N]){
    // Utilizamos un arreglo para verificar si se le ha asignado una pareja a X aplicante
    // El valor de parejaR[i] es la empresa en la que se le ha dado un puesto (su pareja)
    // El valor de -1 indica que no se le ha asignado nadie
    int parejaR[N];
    memset(parejaR, -1, sizeof(parejaR));
   
    //Movimiento en filas
    int resultado = 0;
    for (int u = 0; u < M; u++)
    {
        // Funcion memset llena el arreglo de visitados[N] como NO visitados
        bool visitado[N];
        memset(visitado, 0, sizeof(visitado));
 
        if (bpm(grafoBP, u, visitado, parejaR))
            resultado++;
    }
   
    //Nos muestra que parejas son posibles (un ejemplo de grafo Maximo (puede haber m·s))
    for(int w=0;w<N;w++){
        if(parejaR[w]!=-1){
                cout<<"\n["<<(w)<<"] ["<<(parejaR[w])<<"]\n";
                A = A + 2;
        }
    }
    return resultado;
}
 
//Muestra los grafos
void mostrar(bool grafoBP[M][N]){
    cout<<endl;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cout<<grafoBP[i][j]<<" ";
        }
        cout<<endl;
    }
}
 
int main(){
    // Crea el grafo original
    cout<<"Unidad 3, Programa 8"<<endl;
    cout<<"Pareo a perfecto de grafo normal"<<endl;
    cout<<"Grafo original (10 vertices)"<<endl;
                        // 0  1  2  3  4  5  6  7   8  9
    bool grafoBP[M][N] = {
                          {0, 0, 0, 0, 0, 1, 0, 0 , 0, 1},  //0
                          {0, 0, 0, 0, 0, 0, 1, 1 , 0, 0},  //1
                          {0, 0, 0, 0, 0, 1, 0, 0 , 1, 0},  //2
                          {0, 0, 0, 0, 0, 0, 0, 1 , 1, 0},  //3
                          {0, 0, 0, 0, 0, 1, 0, 0 , 1, 0},  //4
                          {0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},  //5
                          {0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},  //6
                          {0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},  //7
                          {0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},  //8
                          {0, 0, 0, 0, 0, 0, 0, 0 , 0, 0},  //9
                          };
                         
   
    mostrar(grafoBP);
    cout << "\nUnas de las parejas posibles:"<<endl;
    int resultado = maxBPM(grafoBP);
    cout << "\nEl maximo de emparejamientos posibles es " << resultado <<endl;
    if(N == M && A == (N+M)/2){
            cout<<"Este emparejamiento es perfecto"<<endl;
    }
    else{
        cout<<"Este emparejamiento NO es perfecto"<<endl;
    }
    return 0;
}