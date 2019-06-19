#include<bits/stdc++.h>
#define fi first
#define se second
#define fore(i,a,b) for(int i = a ; i <= b ; ++i)

using namespace std;

const double sqrt32 = sqrt(3)/2;


typedef pair<double,double> pii;

pii solve(int n){
    if (n == 0)return {0,0};
    int i = 0 , nvl = 0, maxValueFigure;
    while (1){
        i = i + (nvl+1);
        maxValueFigure = (i)*6;
        if(n<=maxValueFigure)break;
        nvl++;
    }
    nvl++;
    double cx = 0.5*nvl , cy = -sqrt32*nvl;
    int identifyVertex = 1;
    fore(i,1,6){
        if (maxValueFigure-nvl<n  && n <=maxValueFigure){
            identifyVertex = i;
            break;
        }
        maxValueFigure-=nvl;
    }
    if (identifyVertex == 1){
        if (n == maxValueFigure)return {cx,cy};
        cx = -cx;
        cx += ((n-(maxValueFigure-nvl)));
        return {cx,cy};
    }
    //vertex2
    if (identifyVertex == 2){
        if(n == maxValueFigure) {
            return {-cx,cy};
        }
        cx = -cx+(-0.5*(maxValueFigure-n));
        cy += ((maxValueFigure-n)*sqrt32);
        return {cx,cy};
    }
    //vertex3
    if(identifyVertex == 3){
        if(n == maxValueFigure){
            return {-nvl,0};
        }
        cx = -cx + (-0.5*(n-(maxValueFigure-nvl)));
        cy = -cy - ( (n-(maxValueFigure-nvl)) * sqrt32);
        return {cx,cy};
    }
    //vertex4
    if(identifyVertex == 4){
        if (n == maxValueFigure)return {-cx,-cy};
        cx = cx - (n-(maxValueFigure-nvl));
        return {cx,-cy};

    }
    //vertex5
    if(identifyVertex == 5){
        if(n == maxValueFigure){
            return {cx,-cy};
        }
        cx = nvl - (0.5* (n-(maxValueFigure-nvl)));
        cy = sqrt32 * (n-(maxValueFigure-nvl));
        return {cx,cy};
    }
    //vertex6
    if( identifyVertex == 6){
        if(n == maxValueFigure)return {nvl,0};
        cx = nvl - (0.5* (maxValueFigure-n));
        cy = sqrt32 * (maxValueFigure-n);
        return {cx,-cy};
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(3);
    cout << fixed;
    int a , b;
    while(cin >> a >> b){
        pii ax = solve(a);
        pii bx = solve(b);
        double ab =  abs(b-a);
        cout << ab << " " << hypot((ax.se-bx.se),(ax.fi-bx.fi)) << endl;

    }
}
