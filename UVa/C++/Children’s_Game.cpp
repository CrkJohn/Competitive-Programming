#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)

using namespace std;

bool cmp(string a, string b){
    string d1 = a+b, d2 = b+a;
    return d1>d2;
}
int main(){
    vector<string> sc;
    int lon,i;
    string lec;
    while(1){
        cin >> lon;
        sc.clear();
        if(lon==0)break;
        loop(i,0,lon){
            cin >> lec;
            sc.push_back(lec);
        }
       sort(sc.begin(),sc.end(),cmp);
       loop(i,0,lon)cout << sc[i];
       puts("");
    }
    return 0;
}
