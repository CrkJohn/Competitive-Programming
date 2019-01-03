#include<bits/stdc++.h>
using namespace std;
long long inv;
void merge_(int arr[], int l ,int m, int h){
	int lon_l = m-l+1,lon_r = h-m;
    int i=0,j=0,k=l,l_total = lon_l+lon_r;
    int L[lon_l], R[lon_r];
    for(int i_ = 0 ; i_ < lon_l ; i_++)L[i_] = arr[i_+ l ];
    for(int j_ = 0 ; j_ < lon_r ; j_++)R[j_] = arr[j_+ m +1];
    while(i<lon_l || j<lon_r){
		if(i>=lon_l)arr[k++] = R[j++];
        else if(j>=lon_r)arr[k++] = L[i++];
        else if(L[i]<=R[j])arr[k++] = L[i++];
        else {
				arr[k++] = R[j++];
				inv += (lon_l-i);
		}
    }
    return;
}


void divideAndMerge(int l,int h, int arr[]){
    if(l<h){
        int mid = (l+h)/2;

        divideAndMerge(l,mid,arr);
        divideAndMerge(mid+1,h,arr);
        merge_(arr,l,mid,h);
    }
}

int main(){
	freopen("in.txt","r",stdin);
    int ntc;
    while(1){
		scanf("%d",&ntc);
		inv = 0;
		if(!ntc)break;
		int arr[ntc];
		for(int i = 0; i<ntc;i++)scanf("%d",&arr[i]);
		divideAndMerge(0,ntc-1,arr);
		printf("%lld\n",inv);

    }
	return 0;
}
