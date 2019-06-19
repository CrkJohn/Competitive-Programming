#include<bits/stdc++.h>
#define intVa(x) (x-'A')


using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    int ntc;
    cin >> ntc;
    for (int i = 0; i < ntc; i++){
        int n , m ; 
        cin >> n >> m;
        string s1,s2,s3; 
        cin >> s1 >> s2 >> s3;
        int high = max(intVa(s1[0]),intVa(s2[0]));
        int lowest = min(intVa(s1[0]),intVa(s2[0]));
        int shift = high - lowest;
        cout << "Case #" << (i+1) << ": ";
        for(char c : s3){
            int xshift = intVa(c);
            if(xshift<shift){
            //    cout << 26 - shift - xshift << endl;
                char val = (26 - shift - xshift)+'A';
                cout << val;
            }else{
                char val = (xshift-shift)+'A';
                cout << val;
            }
        }
        cout << endl;
    }
    return 0;
}