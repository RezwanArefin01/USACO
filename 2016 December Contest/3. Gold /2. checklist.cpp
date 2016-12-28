#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int,int> ii;
#define inf 1e18 
struct point{
	int x,y;
	friend istream& operator >> (istream &ss, point &p) {ss>>p.x>>p.y; return ss;
	} int dist(point &p) { return (p.x-x)*(p.x-x) + (p.y-y)*(p.y-y); }
};
int n,m; vector<point> h(1001), g(1001);
int main(int argc, char const *argv[]) {
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
	cin>>n>>m; 
	for(int i=0; i<n; i++) cin>>h[i];
	for(int i=0; i<m; i++) cin>>g[i];
	ll dp[n+1][m+1][2];
	for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) 
		for(int k=0; k<2; k++)	dp[i][j][k] = inf;
	dp[1][0][0]=0;
	for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) for(int k=0; k<2; k++) {
		if((k == 0 && i == 0) || (k == 1 && j == 0)) continue;  
		point u;
		if(!k) u = h[i-1]; else u = g[j-1];
		if(i < n ) dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + u.dist(h[i]));
		if(j < m ) dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k] + u.dist(g[j]));
	}
	cout<<dp[n][m][0]<<endl;
}