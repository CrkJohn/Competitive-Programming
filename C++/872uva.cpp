#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i< b;++i)
#define LIM 26
#define LLL 26*26
#define LECT 150

using namespace std;
int Ord[LIM],mAdj[LIM][LIM],ex_N[LIM];
//Ord Nodo ya sacado del grafo
//mAdj Matriz de adjacencia i->j el Ni esta limitado por el Nj
//ex_N existe el N
char print[LIM];
int flG = 0 ;
void lim(){
    memset(Ord,0,sizeof Ord);
    memset(ex_N,0,sizeof ex_N);
    loop(i,0,26)loop(j,0,26)mAdj[i][j]=0;
}
void tps(int ini, int fin){
    if(ini==fin){
        loop(i,0,fin){
            //puts("aquiii");
            if(i==0)printf("%c",print[i]);
            else printf(" %c",print[i]);
        }
        flG= 1;
        printf("\n");
        print[fin]='\0';
        return;
    }else{
        loop(i,0,26){
            if (ex_N[i]==1 && Ord[i] == 0){
                loop(j,0,26){
                    if(mAdj[i][j]==1 && Ord[j]==1)return;
                }
                Ord[i]=1;
                print[ini] = i +'A';
                tps(ini+1,fin);
                Ord[i]=0;
            }
        }
    }
    return;
}

int main(){
     //freopen("872uva.txt","r",stdin);
     string lec;
     char u,s,v; int n,flang=0;
     stringstream ss;
     int cases;
     scanf(" %d ",&cases);
     while(cases--){
        //puts("aaa");
        getline(cin,lec);
        //cout << lec << '\n';
        if(flang)puts("");
        flang=1;
        lim();ss.clear();n=0;
        ss << lec;
        for(;ss >> u;n++)ex_N[u-'A']=1;
        getline(cin,lec);ss.clear();
        //cout << lec << '\n';
        ss << lec;
        while(ss >> u >> s >> v){
            //cout << u << '+' << s  << '+' << v << '\n';
            mAdj[u-'A'][v-'A']=1;
        }
        tps(0,n);
        if(!flG)puts("NO");
        flG = 0;
        scanf("%*c");
     }
    return 0;
}
