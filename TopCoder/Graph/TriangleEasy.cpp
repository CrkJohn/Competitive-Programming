#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class TriangleEasy {
public:
	int find(int n, vector <int> x, vector <int> y) {
		int ans = (n == 0 ||  x.size()==0 ) ? 3 :  2;
		int len = x.size();
		int third = -1;
   		for(int k = 0 ; k < len ; k++){
				int a  =  x[k] , b = y[k];
				for(int i = 0 ; i <  len ; i++){
						if(i == k )continue;
						if((x[i] == a || y[i] == a)){
								third = (x[i] == a) ? y[i] : x[i];
								for(int j =  0 ; j < len ; j++ ){
									if(i==j || j == k)continue;
                		 			if((x[j] == third && y[j] == b)  || (y[j] == third && x[j] == b)){
											 return 0;
                  					}
								}
								ans = 1;
						}
						if((x[i] == b || y[i] == b)){
								third = (x[i] ==b ) ? y[i] : x[i];
								for(int j =  0 ; j < len ; j++ ){
									if(i==j || j == k)continue;
 					                if((x[j] == third && y[j] == a)  || (y[j] == third && x[j] == a)){
											 return 0;
                				  }
								}
								ans = 1;
						}
        	}
    	}
		return ans;
	}

};


int main(){
	 int n = 6;
	 vector<int> x = {0,0,2};
	 vector<int>  y =  {3,1,4};
	 TriangleEasy *obj = new TriangleEasy();
   int res = obj->find(n,x,y);
   cout << res << endl;
	return 0;
}

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
