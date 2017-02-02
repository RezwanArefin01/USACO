#include <bits/stdc++.h>
using namespace std;
int dp[100100][25][3]; vector<int> mv(0);
set<pair<int,int> > tmp; 
int win(int a, int b) { return tmp.find({a,b}) != tmp.end();}
int main(int argc, char const *argv[]) {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	tmp.insert({{0,2}, {2,1}, {1,0}});
	int n,k; cin>>n>>k; mv.resize(n+1);
	for(int i=1; i<=n; i++) {
		char ch; cin>>ch; 
		if(ch == 'H') mv[i] = 0;
		else if(ch == 'P') mv[i] = 1;
		else mv[i] = 2;
	} 
	for(int i=0; i<=n; i++) for(int j=0; j<=k; j++) for(int st =0; st < 3; st++) {
		if(!i) dp[i][j][st] = 0;
		else if(!j) dp[i][j][st] = dp[i-1][j][st] + win(st, mv[i]);
		else dp[i][j][st] = max({dp[i-1][j][st], 
								 dp[i-1][j-1][(st+1)%3], 
								 dp[i-1][j-1][(st+2)%3]}) 
			  				+ win(st, mv[i]);
	} cout<<max({dp[n][k][0], dp[n][k][1], dp[n][k][2]});
}