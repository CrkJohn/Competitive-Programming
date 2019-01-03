#include <bits/stdc++.h>
#define FOR(i,b) for(int i=0 ; i<b ; ++i)
#define loop(i,a,b) for(int i=0 ; i<b ; ++i)
#define iter(it, a, T) for(T::iterator it=(a).begin(); it!=(a).end(); ++it)
#define len(a) ((int)a.size())
#define append(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define X first
#define Y second

using namespace std;

typedef pair<string,string> ii;


vector<string> SPL;
map<string,int> inde;
vector<ii> partidos;


struct equipos{
    string nombre;
    int P,G_D , G_M , G_V, N;
};

vector<equipos> SCORE;

bool nu(string s){
    int n;
    stringstream(s) >> n;
    if(0<=n && n<=33)return true;
    else return false;
}

bool CMP(equipos a, equipos b){
   if(a.P>b.P)return 1;
   if(a.P<b.P) return 0;
   if(a.G_D > b.G_D) return 1;
   if(b.G_D > a.G_D) return 0;
   if(a.G_D> b.G_D) return 1;
   if(b.G_D > a.G_D) return 0;
   if(a.G_V> b.G_V) return 1;
   if(b.G_V > a.G_V) return 0;
   return strcmp(a.nombre.c_str(),b.nombre.c_str()) == 1;
}

void tabla(string EA, string EB , int GA , int GB, int &c){
    //  printf("%s %s GA:%d GB:%d\n",EA.c_str(),EB.c_str(),GA,GB);
    if(!inde.count(EA)){
        equipos TEA = {EA,0,0,0,0};
        inde[EA] = c++;
        SCORE.append(TEA);
    }
    if(!inde.count(EB)){
        equipos TEB = {EB,0,0,0,0};
        inde[EB] = c++;
        SCORE.append(TEB);
    }
    int indice_a = inde[EA];
    int indice_b = inde[EB];
    if(GA == GB){
        SCORE[indice_a].P++;
        SCORE[indice_b].P++;
    }
    if(GA > GB)SCORE[indice_a].P+=3;
    if(GB > GA)SCORE[indice_b].P+=3;
    SCORE[indice_a].G_D += (GA-GB);
    SCORE[indice_b].G_D += (GB-GA);
    SCORE[indice_a].G_M += GA;
    SCORE[indice_b].G_M += GB;
    SCORE[indice_b].G_V += GB;

    if(GA>GB){partidos.append(mp(EA,EB));}
    else if(GB>GA) partidos.append(mp(EB,EA));
    //printf("AGREGUE\n");
}

void SPLIT(int &c){
    string EB,EA;
    int GA,GB, lon = len(SPL),flang=0,flang1=0;
    FOR(i,lon){
        string aux  = SPL[i];
        //printf("%s\n",aux.c_str());
        if(aux=="vs.")flang =1;
        else{
            if(!flang && !flang1 && SPL[i+1]!="vs.") EB += aux+" ";
            else if(i+2<lon && nu(aux) && SPL[i+1]=="vs."){
                stringstream(aux) >> GA;
                EA = EB.substr(0,EB.length()-1);
                EB  = "";
            }
            if(nu(aux) && flang && !flang1){
                stringstream(aux) >> GB;
                flang1 = 1;
            }else if(flang && flang1)EB += (i+1!=lon)?(aux + " ") : aux ;
        }
    }
    //printf("%s%s ",EA.c_str(),EB.c_str());
    tabla(EA,EB,GA,GB,c);
}

int main(){
    //freopen("K.txt","r",stdin);
    int line,flang=0;
    char l[115];
    while((scanf("%d",&line))!=EOF){
        getchar();
        int c  =  0;
        SCORE.clear();
        inde.clear();
        partidos.clear();
        FOR(ii,line){
            SPL.clear();
            gets(l);
            int lon  = strlen(l);
            //printf("%s\n",l);
            char *pch;
            pch = strtok(l," ");
            while(pch!= NULL){
                SPL.push_back(pch);
                pch = strtok(NULL," ");
                }
            SPLIT(c);
            }
        sort(SCORE.begin(),SCORE.end(),CMP);
        int lonS = len(SCORE), lonP = len(partidos);
        FOR(k,lonS){
            SCORE[k].N = k+1;
            inde[SCORE[k].nombre] = k+1;
            }
        int PD =0;

        FOR(i,lonP) if( SCORE[inde[partidos[i].X ]-1].N > SCORE[ inde [ partidos[i].Y ]-1].N ){
            //printf("%s %s %d %d %s %s\n",partidos[i].X.c_str(),partidos[i].Y.c_str(),inde[partidos[i].X],inde[partidos[i].Y],SCORE[inde[partidos[i].Y]].nombre.c_str(),SCORE[inde[partidos[i].Y]].nombre.c_str());
            PD++;


        }

        printf("The paradox occurs %d time(s).\n",PD);
        FOR(c,len(SCORE))printf("%d. %s\n",SCORE[c].N,SCORE[c].nombre.c_str());

    }
    return 0;
}
