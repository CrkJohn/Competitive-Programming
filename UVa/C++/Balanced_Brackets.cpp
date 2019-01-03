#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
using namespace std;

int main(){
    int cases,i;
    scanf("%d",&cases);
    getchar();
    while (cases--){
        char str[100010];
        stack<char[1]> st;
        gets(str);
        str[strlen(str)]='\0';
        int ban = 1;
        loop(i,0,strlen(str)){
            if (str[i] == "{" || str[i]=="(" || str[i]=="["){
                st.push(str[i]);
            }else{
                char[1] s = st.top();
                if (str[i]=="}" && s!="{"){
                    ban=0;break;

                }else if (str[i]==")" && s!="("){
                    ban=0;break;
                }else if (str[i]=="]" && s!="[")
                    ban=0;break;
            }
        if (ban && !st.empty()){
            puts("YES");
        }else{
            puts("NO");
        }
        }


    }

    return 0;
}
