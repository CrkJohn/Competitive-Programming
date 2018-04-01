#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;++i)
#define mp(a,b) make_pair(a,b);


using namespace std;

typedef pair<char,char> cc;
typedef pair<cc,char> ccc;
typedef set<string> ss;
typedef ss::iterator it;
typedef vector<long> vi;
typedef map<char,vi> mapi;
typedef vi::iterator ivi;
typedef mapi::iterator imap;
ss P;

void prec(){
    int i,j,k;
    string abc[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","V","U","W","X","Y","Z"};
    loop(i,0,26){
            loop(j,0,26){
                loop(k,0,26){
                    string a = abc[i] + abc[j] + abc[k];
                    P.insert(a);
                }
            }
    }
}
int main(){
    prec();
    long n,i,I;
    it itt;
    scanf("%d",&n);
    mapi LisAdj;
    getchar();
    while (n--){
        char str[100000];
        gets(str);
        LisAdj.clear();
        loop(I,0,strlen(str)){LisAdj[str[I]].push_back(I);}
        int ans=0;
        for (itt=P.begin(); itt!=P.end() ; ++itt){
            string r  = *itt;
            int ini=-1;ivi dini;
            loop(i,0,3){
                char s = r[i];
                //printf("%c ",s);
                if((int)LisAdj[s].size()!=0){
                    if(i==0)ini = LisAdj[s][0];
                    else{
                        dini = lower_bound(LisAdj[s].begin(),LisAdj[s].end(),ini+1);
                        if(LisAdj[s][dini-LisAdj[s].begin()]<=ini || dini-LisAdj[s].begin() > ((int)LisAdj[s].size()-1))break;
                        else  ini = LisAdj[s][dini-LisAdj[s].begin()];
                    }
                    if(i==2)ans++;
                }else break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
