#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;++i)
using namespace std;

int main(){
    int  cases,i;
    scanf("%d",&cases);
    getchar();
    while(cases--){
        char str[91];
        gets(str);
        int rx=1,ry=0;
        int ly=0,lx=1;
        int midx=1,midy=1;
        str[strlen(str)-1]='\0';
        loop(i,0,strlen(str)){
            if (str[i]=='R'){
                ly = midy;
                lx = midx;
                midy=ly+ry;
                midx=lx+rx;
            }else{
                ry = midy;
                rx = midx;
                midy=ly+ry;
                midx=lx+rx;
            }
        }
        printf("%d/%d\n",midy,midx);

    }

    return 0;
}
