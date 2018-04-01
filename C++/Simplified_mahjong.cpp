#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define loop(i,a,b) for(i=a;i<b;i++)

using namespace std;

typedef vector<long> vi;
int main(){
    vi numbers;
    long n,i,r;
    scanf("%ld",&n);
    loop(i,0,n){
        scanf("%ld",&r);
        numbers.pb(r);
    }
    int cont=0;
    long long res = 0;
    r=0;
    loop(i,0,n){
        //printf("Primera: %lld %d %ld\n",res,cont,numbers[i]);
        if(r==2){cont=0; r=0;}
        if(numbers[i]>0){
            if (numbers[i]%2!=0 && cont ==0){
                cont=1;
                res +=(numbers[i]/2);
                //printf("%d %d",numbers[i],res);
            }
            else if (numbers[i]%2!=0 && cont==1){
                cont=0;
                r=0;
                res +=(numbers[i]+1)/2;
                //printf("aca \n");
            }
            else if (numbers[i]%2==0 && cont==0){
                res +=numbers[i]/2;
            }else if(numbers[i]%2 == 0 && cont==1){
                res  +=(numbers[i]+1)/2;
                r=0;
            }
        }
        if (cont==1)r+=1;
        //printf("Segunda: %lld %d %ld %ld\n",res,cont,numbers[i],r);

    }
    printf("%lld",res);

    return 0;

}
