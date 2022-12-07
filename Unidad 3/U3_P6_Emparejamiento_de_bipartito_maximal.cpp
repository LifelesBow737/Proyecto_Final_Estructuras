/*
EMPAREJAMIENTO MAXIMAL
*/
#include <iostream>
#define MAX 20
using namespace std;

int parejas[MAX];             //Vector que almacena las parejas
bool visitados[MAX];//Vector que guarda las posiciones visitadas
bool bloqueados[MAX];
bool matrizAdy[][5]={    //A graph with M applicant and N jobs
{1, 1, 1, 0, 0},
{1, 0, 0, 1, 0},
{1, 0, 1, 1, 1},
{0, 0, 0, 0, 1}
};
    //Matriz de Adyacencia de Grafo Dirijido
int contaParejas = 0;
//void maximal (int,bool,int,int,int);

bool parejasBipar(int posicion, bool visitados[], int parejas[],int filas,int columnas) {
   for (int itera = 0; itera < columnas; itera++)
   {
      if (matrizAdy[posicion][itera] && !visitados[itera])
      {
         visitados[itera] = true;
         if (parejas[itera] < 0 || parejasBipar(parejas[itera], visitados, parejas,filas,columnas))
         {
            parejas[itera] = posicion;
            return true;
         }
      }
   }
   return false;
}

int maxMatch(int filas,int columnas) {


   for (int posic = 0; posic < filas; posic++) {
      
      for(int i = 0; i<columnas; i++)
         visitados[i] = false;
      if (parejasBipar(posic, visitados, parejas,filas,columnas))
         contaParejas++;
   }
   return contaParejas;
}

bool maximal(int posicion, bool visitados[], int parejas[],int filas,int columnas) {
   for (int itera = 0; itera < columnas; itera++)
   {
           if(bloqueados[itera]==false){
               if (matrizAdy[posicion][itera] && !visitados[itera])
      {
         visitados[itera] = true;
         if (parejas[itera] < 0 || parejasBipar(parejas[itera], visitados, parejas,filas,columnas))
         {
             
             parejas[posicion] = posicion;
            return true;
             
                
         }
      }
           }
      
   }
   return false;
}

int maximalMatch(int filas,int columnas)
{
    for (int posic = 0; posic < filas; posic++)
    {
 
        
      if (parejasBipar(posic, visitados, parejas,filas,columnas))
         contaParejas++;
   }
   return contaParejas;
}



int main()
{
    cout<<"Unidad 3, Programa 6"<<endl;
    cout<<"Pareo a maximal de un grafo bipartito"<<endl;
    int filas=4,columnas=5,i,j,ren,col,res;
    system("CLS");
    cout<<"\n Matriz de Adyacencia\n";
    for (i = 0; i < filas; i++){
        for (j = 0; j < columnas; j++){
            cout<<matrizAdy[i][j];
        }
        cout << endl;
    }
    
    for(int i = 0; i<columnas; i++)
      parejas[i] = -1;
   contaParejas = 0;
   cout << "El numero Maximo de parejas es:" << maxMatch(filas,columnas);
   for(int w=0;w<columnas;w++)
        if(parejas[w]!=-1)
               cout<<"\n"<<(w+1)<<"-"<<(parejas[w]+1)<<" \n";
               
    cout<<"\n\tEmparejamiento Maximal\n";
    for(int i = 0; i<columnas; i++)
      parejas[i] = -1;
   contaParejas = 0;
    res=77;
    for(i=0;i<columnas;i++)
        bloqueados[i]=false;
    while (res != 0)
    {
        cout<<"\nIngrese las relaciones de nodos que desea formar antes de generar los otros emparejamientos\n";
        cout<<"\nIzquierda:";
            cin >> ren;
        cout<<"\nDerecha:";
            cin >> col;
        parejas[(ren-1)] = (col-1);
        bloqueados[(ren-1)] = true;
        //matrizAdy[(ren-1)][(col-1)] = 1;
        //contaParejas++;
        cout<<"\n Desea terminar (0-Terminar | 1-Continuar ingresando)\n";
        cin >> res;
    }
    cout << "El numero Maximo de parejas es:" << maximalMatch(filas,columnas);
   for(int w=0;w<columnas;w++)
        if(parejas[w]!=-1)
               cout<<"\n"<<(w+1)<<"-"<<(parejas[w]+1)<<" \n";
}
