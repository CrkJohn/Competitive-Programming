#include <bits/stdc++.h>

using namespace std;

bool cmp(int a ,int b){
    return (a>b)? a%2>b%2 :  false;
}
int main(){
    int arr[] = {1,2,4,5,6,1,2,3,4};
    vector<int> ar(arr,arr+9);
    sort(ar.begin(),ar.end(),cmp);
    for(int i = 0 ; i<9 ;i++)printf("%d\n",ar[i]);

    return 0;
}
