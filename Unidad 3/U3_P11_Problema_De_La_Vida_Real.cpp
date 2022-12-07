#include <iostream>
#include <stdio.h>
#define SINGLE 0
using namespace std;

int main()
{
    cout<<"Unidad 3, Programa 11"<<endl;
    cout<<"Problema de la vida real, formar parejas de matrimonios perfectos"<<endl;
    int wList[5][5] = {{0, 0, 0, 0, 0},
                       {1, 4, 3, 1, 2},
                       {2, 2, 1, 3, 4},
                       {3, 1, 3, 4, 2},
                       {4, 4, 3, 1, 2}}; // ejemplo mList[4][3] el hombre 4 prefiere a la mujer 3
    int mList[5][5] = {{0, 0, 0, 0, 0},
                       {1, 3, 2, 4, 1},
                       {2, 2, 3, 1, 4},
                       {3, 3, 1, 2, 4},
                       {4, 3, 2, 4, 1}};
    int manCurrentMatch[5] = {0, 0, 0, 0, 0};   // Almacena el compromiso actual de cada hombre, o lo establece en 0 si actualmente esta soltero
    int womanCurrentMatch[5] = {0, 0, 0, 0, 0}; // Almacena el compromiso actual de cada mujer, o lo establece en 0 si actualmente esta soltero
    int manNextProposal[5] = {1, 1, 1, 1, 1};   // indica que mujer indexada propondra este hombre a continuacion en su lista de preferencias

    // Algoritmo
    bool hombreDisponible = true;
    int m = 1;
    while (hombreDisponible)
    {
        hombreDisponible = false;
        int w = mList[m][manNextProposal[m]++];
        if (womanCurrentMatch[w] == SINGLE)
        {
            // w esta soltero, comprometerse (m y w)...
            womanCurrentMatch[w] = m;
            manCurrentMatch[m] = w;
        }
        else
        {
            // w esta comprometida...
            bool esUnaMejorPropuesta = false; // verifica si es una mejor propuesta
            // verifica su lista de preferencias
            for (int i = 1; i <= 4; i++)
            {
                if (wList[w][i] == womanCurrentMatch[w])
                {
                    esUnaMejorPropuesta = false;
                    break;
                }
                if (wList[w][i] == m)
                {
                    esUnaMejorPropuesta = true;
                    break;
                }
            }
            if (esUnaMejorPropuesta)
            {
                // si es mejor propuesta, entonces comprometerse (m y w), y establecer el anterior compaÃ±ero de w como soltero...
                manCurrentMatch[womanCurrentMatch[w]] = SINGLE;
                womanCurrentMatch[w] = m;
                manCurrentMatch[m] = w;
            }
        }
        // Busca un hombre soltero
        for (int j = 1; j <= 4; j++)
        {
            if (manCurrentMatch[j] == SINGLE)
            {
                m = j;
                hombreDisponible = true;
                break;
            }
        }
    }
    cout << "\t"
         << "Algoritmo Gale-Shapley" << endl;
    // Imprime el resultado
    cout << "Matriz de Preferencias de los Hombres: " << endl;
    for (int g = 1; g <= 4; g++)
    {
        for (int d = 0; d <= 5; d++)
        {
            cout << mList[g][d] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Matriz de Preferencias de las Mujeres: " << endl;
    for (int h = 1; h <= 4; h++)
    {
        for (int u = 0; u <= 5; u++)
        {
            cout << wList[h][u] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "\tMatrimonios Estables" << endl;
    for (int k = 1; k <= 4; k++)
    {
        cout << "Hombre " << k << " y Mujer " << manCurrentMatch[k] << endl;
    }
    system("pause");
    return 0;
}