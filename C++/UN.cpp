#include <bits/stdc++.h>


int main(){


   int n;
    scanf("%d",&n);
    n--;
    for (int i=0; i<n+1;i++){
        for (int j=0;j<((2*n)+3);j++){
            if (i==n and j<n+1)             printf("*");
            else if (i>=0 and i<=n and (j==0 or j==n or j==n+2 or j==(2*n+2)))         printf("*");
            else if (i==0 and j>n+2)                printf("*");
            else if (i==0 and j>n+1) printf("*");
            else printf(" ");
        }
        puts("");
    }
    return 0;
}
