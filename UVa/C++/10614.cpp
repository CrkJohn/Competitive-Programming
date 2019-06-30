#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define pb push_back
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)
#define si(a) ((int)a.size())

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pi64;
typedef double ld;

ostream & operator<< (ostream &out, const pii &c){
	out << "x =" << c.fi << ",y = " << c.se << ";";
    return out;
}

struct vec{
    
    double x, y, z;

    vec (double X = 0  , double Y = 0 , double Z = 0){
        x = X;
        y = Y;
        z = Z;
    }

    vec operator + (const vec a ) const {
        return vec(x+ a.x, y + a.y , z + a.z);
    }

    vec operator -(const vec a ) const {
        return vec(x- a.x, y - a.y , z - a.z);
    }

    vec operator *(const  double k){return vec(x*k , y*k , z*k);}

    vec operator *(const  vec a){
        return  vec(y* a.z -z * a.y , 
                    z* a.x - x * a.z,
                    x * a.y - y * a.x);
    }

    double dot(const vec a ) const {
        return x * a.x + y * a.y + z * a.z;
    }

};

ostream & operator<< (ostream &out, const vec &c){
	out << "{" << c.x << ";" << c.y << ";" << c.y << "}" << endl;
    return out;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(1);
    cout << fixed;

    
    cout << (vec(1,2,3).dot(vec(4,15,6)*(2-1*1))) << endl;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
