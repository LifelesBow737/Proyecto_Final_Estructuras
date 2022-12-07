#include<bits/stdc++.h>
#include<conio.h>
using namespace std;


int main(){
	unsigned int elemen;
	cout<< "Digite la cantidad de elementos que tendra el arreglo: ";
	cin>>elemen;
	
	int conjPoten = pow(2,elemen);
	char vector[elemen];
	
	
	cout<<"\n\n\tBINARIO: \n"<<endl;
	
	for(int a=0; a< conjPoten; a++){
		cout<<"\t\t";
		for(int b=0; b < elemen; b++){
			if (a & (1<<b))
				cout<< 1;
			else
				cout<< 0;
		}
		cout<< endl;
	}
	
	cout<<"\n\n\tCONJUNTO POTENCIA: \n"<<endl;
	
	for(int j=0; j<elemen; j++){
		vector[j] = j + 65;
	}
	
	//cout<<"\t\t";
	for(int k=0; k <conjPoten; k++){
		cout<<"\t\t";
		for(int l=0; l<elemen;l++){
			if (k & (1<<l))
				cout<<vector[l];
		}
		cout<<endl;
	}
	
	getch();
	return 0;
}
