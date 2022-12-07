#include<iostream>

using namespace std;

int m[4][4] = {    {385,517,409,236},
                {389,585,234,416},
                {238,330,173,546},
                 {210,415,420,400}
};
                
int a[4][4] = {    {0,0,0},
                {0,0,0},
                {0,0,0}};
struct cost{
    int x,y,c;
};
cost aux[4];
int main(){
    cout<<"Unidad 3, Programa 5"<<endl;
    cout<<"Pareo a perfecto de un grafo bipartito"<<endl;
    int minim;
    for(int i=0;i<4;i++){
        minim=999;
        for(int j=0;j<4;j++){
            if(m[i][j]<minim){
                minim=m[i][j];
                aux[i].x=j;
                aux[i].y=i;
                aux[i].c=m[i][j];
            }
        }
    }
    
    for(int i=0;i<4;i++){
        a[aux[i].y][aux[i].x]=aux[i].c;
    }
    for(int k=0;k<4;k++){
        switch(k){
            case 0:for(int i=0;i<4;i++){
                        for(int j=0;j<4;j++){
                            if(k>=i){
                                if(a[i][j]>=1) cout<<1<<"\t";
                                else cout<<a[i][j]<<"\t";
                            }else cout<<0<<"\t";
                        }
                        cout<<"\n";
                    } break;
            case 1: for(int i=0;i<4;i++){
                        for(int j=0;j<4;j++){
                            if(k>=i){
                                if(a[i][j]>=1) cout<<1<<"\t";
                                else cout<<a[i][j]<<"\t";
                            }else cout<<0<<"\t";
                        }
                        cout<<"\n";
                    } break;
            case 2: for(int i=0;i<4;i++){
                        for(int j=0;j<4;j++){
                            if(k>=i){
                                if(a[i][j]>=1) cout<<1<<"\t";
                                else cout<<a[i][j]<<"\t";
                            }else cout<<0<<"\t";
                        }
                        cout<<"\n";
                    } break;
        }
        cout<<"\n";
    }

}