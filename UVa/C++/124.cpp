#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i< b;++i)
#define LIM 26
#define LECT 150

using namespace std;
int Ord[LIM],mAdj[LIM][LIM],ex_N[LIM];
//Ord Nodo ya sacado del grafo
//mAdj Matriz de adjacencia i->j el Ni esta limitado por el Nj
//ex_N existe el N
char print[LIM];

void lim(){
    memset(Ord,0,sizeof Ord);
    memset(ex_N,0,sizeof ex_N);
    loop(i,0,26)loop(j,0,26)mAdj[i][j]=0;
}
    void tps(int ini, int fin){
        if(ini==fin){
            print[fin]='\0';
            puts(print);
            return;
        }else{
            loop(i,0,26){
                if (ex_N[i]==1 && Ord[i] == 0){
                    loop(j,0,26){
                        if(mAdj[i][j]==1 && Ord[j]==1)return;
                    }
                    Ord[i]=1;
                    print[ini] = i +'a';
                    tps(ini+1,fin);
                    Ord[i]=0;
                }
            }
        }
        return;
    }

int main(){
     string lec;
     char u,v; int n,flang=0;
     stringstream ss;
     while (getline(cin,lec)){
        if(flang)puts("");
        flang=1;
        lim();ss.clear();n=0;
        ss << lec;
        for(;ss >> u;n++)ex_N[u-'a']=1;
        getline(cin,lec);ss.clear();
        ss << lec;
        while(ss >> u >> v)mAdj[u-'a'][v-'a']=1;
        tps(0,n);
     }
    return 0;
}
