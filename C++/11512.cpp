#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i< b; i++)
#define MAX_N 1010

using namespace std;


typedef pair<int, int> ii;
char T[MAX_N];
int n,cont;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
int m;
int Phi[MAX_N];
int PLCP[MAX_N];
int LCP[MAX_N];



void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;
  for (i = 1; i < n; i++)
    Phi[SA[i]] = SA[i-1];
  for (i = L = 0; i < n; i++) {
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }
    while (T[i + L] == T[Phi[i] + L]) L++;
    PLCP[i] = L;
    L = max(L-1, 0);
  }
  for (i = 0; i < n; i++)LCP[i] = PLCP[SA[i]];
}


ii LRS() {                 // returns a pair (the LRS length and its index)
  int i, idx = 0, maxLCP = -1,aux_i,dLCP,dCont;
  cont = 1;
  i = 1;
  while(i < n){                    // O(n), start from i = 1
    //printf("LCP[%d] = %d\n",i,LCP[i]);
    aux_i = i;
    if (LCP[i] > maxLCP){
      dCont = 1;
      dLCP = LCP[i];
      //printf("dLCP = %d\n",dLCP);
      while(LCP[aux_i]==dLCP && aux_i<n){
        aux_i++;
      }
      //printf("Aux indx %d\n",aux_i);
      if(aux_i-i+1>=2){
		maxLCP = LCP[i], idx = i;
		cont = aux_i-i;
      }
	}
	if(aux_i>i)i = aux_i;
	else i++;
  }
  return ii(maxLCP, idx);
}



void countingSort(int k) {
  int i, sum, maxi = max(300, n);
  memset(c, 0, sizeof c);
  for (i = 0; i < n; i++)
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; i++)tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; i++)SA[i] = tempSA[i];
}

void constructSA(){
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];
	for (i = 0; i < n; i++) SA[i] = i;
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
		  tempRA[SA[i]] =  (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for (i = 0; i < n; i++)RA[i] = tempRA[i];
		if (RA[SA[n-1]] == n-1) break;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int ntc;
	scanf("%d",&ntc);
	while(ntc--){
		n = m =  0;
        scanf("%s%*c",T);
		n = (int)strlen(T) + 1;
		strcat(T,"$");
		constructSA();
		computeLCP();
		ii ans = LRS();                 // find the LRS of the first input string
		//printf("\nThe Suffix Array of string T = '%s' is shown below (O(n log n) version):\n", T);
		//printf("i\tSA[i]\tLCP\tSuffix\n");
		//for (int i = 0; i < n; i++) printf("%2d\t%2d\t%2d\t%s\n", i, SA[i],LCP[i],T + SA[i]);
		if(ans.first == 0){
			puts("No repetitions found!");
		}else {
			//printf("%d %d\n",ans.first,ans.second);
			string a = T + SA[ans.second];
			a = a.substr(0,ans.first);
			printf("%s %d\n",a.c_str() ,cont+1);
		}
	}
	return 0;
}
