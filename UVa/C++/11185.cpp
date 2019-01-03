#include <bits/stdc++.h>
#define FOR(i,b) for(int i = 0 ; i< b ; ++i)
#define loop(i,a,b) for(int i = a;  i< b ; ++i)
#define REV(i,a,b) for(int i = b-1;  i>=a ; --i)
#define LIM 10000010

using namespace std;



int main(){
    long num;
    //freopen("11185.txt","r",stdin);
    while(scanf("%ld",&num),num>=0){
        vector<int> vec;
        if(num==0)puts("0");
        else{
                 while(num>0){
            vec.push_back(num%3);
            num= num / 3;
        }

        REV(i,0,vec.size()){
            printf("%d",vec[i]);
        }
        puts("");
        }
    }
    return 0;
}
