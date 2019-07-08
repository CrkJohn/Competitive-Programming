#include <bits/stdc++.h>
using namespace std;

bool isp(int x){
	if (x < 2)return false;
	for (int i = 2; i * i <= x; ++i)if (x % i == 0)return false;
	return true;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("o2.txt","w",stdout);
	int x;
	while(cin >> x){
        //cerr << x << endl;
        if (isp(x - 2))printf("%d %d\n", 2, x - 2);
	    else printf("-1\n");
    }

}