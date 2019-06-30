#include<iostream>
using namespace std;
//#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#include<vector>
 
ll min(ll a, ll b){
	return a<=b?a:b;
}
ll max(ll a, ll b){
	return a>=b?a:b;
}
 
int main(){
	IOS;
	int q;
	cin >> q;
	ll n,s,t;
	while(q--){
 
		cin >> n >> s >> t;
 
 
		if(n==s && n== t){
			cout << 1 << endl;
		}
		else{
			cout << min(max(n-s,n-t)+1,n) << endl; 
		}
		
	}
}