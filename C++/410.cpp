#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i<b;i++)
#define REV(i,a,b) for(int i = a-1 ; i>(a-b-1);i--)
#define pb push_back
#define masa first
#define indice second

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;

int cmp1(ii a ,ii b){
	return a.masa < b.masa;
}

int cmp2(iiii a, iiii b){
	return a.first.first < b.first.first;
}

int main(){
	int c,m,con,cont=1;
	while(scanf("%d %d",&c,&m)==2){
		vector<ii> animales,animales_;
		double promedio = 0;
		double balance = 0;
		int nth = 0;
		loop(i,0,m){
			scanf("%d",&con);
			animales.pb(ii(con,i));
			promedio +=((double)con);
		}
		promedio= promedio/c;
		printf("Set #%d\n",cont++);
		int solos;
		if(m>c){
			solos= (c*2)-m;
			sort(animales.begin(),animales.end(),cmp1);
			if(solos>0)for(int i = m-solos;i<m;i++){printf(" %d: %d\n",nth++,animales[i].first);
				balance+=abs(((double)animales[i].first)-promedio);
			}
			loop(i,0,m-solos) animales_.pb(animales[i]);
			int lon = animales_.size();
			vector<iiii> result;
			loop(i,0,lon/2){
				result.pb(iiii(animales_[i],animales_[lon-1-i]));
			}
			sort(result.begin(),result.end(),cmp2);
			loop(i,0,result.size()){
				double d = (double)result[i].first.first + (double)result[i].second.first;
				balance+=abs(d-promedio);
				if((result[i].first.second < result[i].second.second)){
				printf(" %d: %d %d\n",nth++,result[i].first.first , result[i].second.first);
				}else{
					printf(" %d: %d %d\n",nth++, result[i].second.first,result[i].first.first);

				}
			}
            loop(i,nth,c){
				printf(" %d:\n",i);
				balance+=promedio;
			}
			printf("IMBALANCE = %.5lf\n\n",balance);
		}else{
            loop(i,0,c){
				if(i<m){
					printf(" %d: %d\n",nth++,animales[i].first);
					balance+=abs((double)animales[i].first-promedio);
				}
				else{ printf(" %d:\n",nth++);
					balance+=promedio;
				}
			}
			printf("IMBALANCE = %.5lf\n\n",balance);
		}
	}

	return 0;
}

