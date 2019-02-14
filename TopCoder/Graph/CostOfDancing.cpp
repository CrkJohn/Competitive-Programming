	#include<bits/stdc++.h>

using namespace std;


class CostOfDancing{
	public:
		int minimum(int K, vector<int> danceCost){
				int ans = 0;
				sort(danceCost.begin(),danceCost.end());
				int len = danceCost.size();
				for(int i = 0 ; i< K ; i++){
						ans+= danceCost[i];
				}
				cerr << ans << endl;
				return ans;
		}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!


int main(){
	CostOfDancing *obj = new CostOfDancing();
	int k = 39;
	vector<int> v = {973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932,
 703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801};
	cout << obj->minimum(k,v) << endl;



	return 0;
}


