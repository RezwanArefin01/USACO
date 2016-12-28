#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
struct point { 
	ll x,y; point () {} point(int x, int y): x(x), y(y){}
	bool operator < (const point &p) const { return y == p.y ? x < p.x : y < p.y;}
};
bool isright(point &a, point &b, point &c) { 
	return ((b.x-a.x) * (c.y-a.y) - (b.y-a.y) * (c.x-a.x)) < 0;
}
int main(int argc, char const *argv[]) {
	cin.tie(0), ios::sync_with_stdio(false);
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	int n; cin>>n; vector<point> p(n);
	for(int i=0; i<n; i++) cin>>p[i].x>>p[i].y;
	sort(p.begin(), p.end());
	bitset<301> cnt[n+1][n+1];
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) if( j != i) 
		for(int k=0; k<n; k++) if ( k!= i && k!=j) 
			if(isright(p[i], p[j], p[k])) 
				cnt[i][j][k] = 1;
	vector<int> ans(n+1);
	for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) for(int k=j+1; k<n; k++) {
		int a=i, b=j, c=k;
		if(isright(p[a], p[c], p[b])) swap(b,c);
		bitset<301> tmp = cnt[a][b] & cnt[b][c] & cnt[c][a];
		ans[tmp.count()]++;
	} for(int i=0; i<n-2; i++) cout<<ans[i]<<endl;
}