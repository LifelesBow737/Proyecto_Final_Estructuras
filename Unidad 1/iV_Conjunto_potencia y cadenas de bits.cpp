#include<iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void ConvertBinario(int);

int p;

int main()
{
    
    int i,j,n;
    string temp;
    
    cout<<"Ingrese el numero de elementos del conjunto"<<": ";
    cin>>n;
    
    string Vect[n];//Se crea un arreglo que almacene n elementos
    
    for(i=0;i<n;i++)
    {
       cout<<endl<<"Ingrese el elemento "<<i+1<<": ";
       cin>>Vect[i];
    }
    
    for(i=0; i<(n/2); i++)
    {
        temp=Vect[i];
        Vect[i]=Vect[n-1-i];
        Vect[n-1-i]=temp;
    }
    
    cout<<endl<<"\t  TABLA DE VALORES"<<endl<<endl;
    cout<<"DECIMAL\t\tBINARIO\t\tELEMENTOS"<<endl;
    
    for(i=0;i<pow(2,n);i++)
    {
        ConvertBinario(i);//Funcion para convertir a binario
        for(j=0;j<n;j++)
        {
            /*En el if (i & (1<<j)), el"1<<j" realiza el desplazamiento de 1
            para generar una máscara de bits en la que solo se establece el j-ésimo bit,
            mientras que el operador & compara cada bit de su primer operando con el bit
            correspondiente de su segundo operando. Si ambos bits son 1, el bit del resultado
            correspondiente se establece en 1.
            De lo contrario, el bit del resultado correspondiente se establece en 0.*/
            if(i & (1<<j))
            {
                cout<<"["<<Vect[j]<<"]";
            }
        }
        cout<<"\n";
    }
    system("pause");
    return 0;
 
}

void ConvertBinario(int num)
{
    int x=0, vector[50];
    
    if(num == 0)
    {
        vector[x] = 0;
        x++;
    }
    while(num > 0)
    {
        vector[x] = num%2;
        num = num/2;
        x++;
    }
    
    cout<<p<<"\t | \t";
    p++;
    for(int i = x-1; i >= 0; i--)
    {
        cout<<vector[i];
    }
    cout<<"\t | \t";
}
