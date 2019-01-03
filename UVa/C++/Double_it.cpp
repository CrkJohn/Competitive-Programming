#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<a;i++)

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    stack<char> q;
    while(1){
        if (n%2 ==0 ){
                q.push('B');
                n = (n-2)/2;
        }
        else {
                q.push('A');
                n = (n-1)/2;
            }

        if (n==0)break;

    }
    while (!q.empty()){
        printf("%c",q.top());
        q.pop();
    }

    return 0;
}
