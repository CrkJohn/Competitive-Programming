#include<bits/stdc++.h>

/*
	Pick's theorem
	A = I + B/2 - 1:
	A = Area of the polygon
	I = Number of integer coordinates points inside
	B = Number of integer coordinates points on the boundary
	Polygon's vertex must have integer coordinates
	Tested: LightOJ 1418
	Complexity: O(n)
*/

typedef long long ll;
typedef complex<ll> point;
struct segment { point p, q; };

double cross(point a, point b) { return imag(conj(a) * b); }


double area2(const polygon &P)
{
	double A = 0;
	for (int i = 0, n = P.size(); i < n; ++i)
		A += cross(P[i], P[NEXT(i)]);
	return A;
}

ll points_on_segment(const segment &s)
{
	point p = s.p - s.q;
	return __gcd(abs(p.real()), abs(p.imag()));
}

pair<ll, ll> pick_theorem(polygon &P)
{
	ll A = area2(P), B = 0, I = 0;
	for (int i = 0, n = P.size(); i < n; ++i)
		B += points_on_segment({P[i], P[NEXT(i)]});
	A = abs(A);
	I = (A - B) / 2 + 1;
	return {I, B};
}


int main(){
		ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int ntc;
	cin >> ntc;
	for1(cases,ntc){
			int n;
			cin >> n;
			vector<point> pts(n);
			forn(i,n){
					ll x,y;
					cin >> x>>y;
					pts[i] = complex(x,y);
			}
			cout <<"Case "<<cases<<": "<<   pickTheorem(pts)<< endl;
	}
	return 0;
}

