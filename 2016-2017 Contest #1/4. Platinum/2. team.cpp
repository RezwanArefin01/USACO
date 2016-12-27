#include <bits/stdc++.h>
using namespace std;

struct data {
    int val; bool isFj; data() {} 
    data(int v, bool b): val(v), isFj(b){}
    bool operator < (data const &p) const {
     	return val == p.val? (isFj && !p.isFj) : val < p.val;
    } 
};
const int MOD = 1000000009;
int main(int argc, char const *argv[]) {
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
    int n, m, k; cin>>n>>m>>k;
    vector<data> p; int tmp;
    for(int i = 0; i < n; i++) cin>>tmp, p.emplace_back(tmp,1);
    for(int i = 0; i < m; i++) cin>>tmp, p.emplace_back(tmp,0);
    sort(p.begin(), p.end());
 	long long dp[n+m+1][k+1][k+1];
    for(int i = 0; i <= k; i++) for(int j = 0; j <= k; j++) 
        dp[n+m][i][j] = (i == j && i == 0);
    for(int t = n+m-1; t>=0; t--) for(int i = 0; i <= k; i++) for(int j = 0; j <= k; j++) {
        if(j > i) {dp[t][i][j] = 0; continue; }
        if(p[t].isFj) 
        	 dp[t][i][j] = (dp[t+1][i][j] + (i > 0 ? dp[t+1][i-1][j] : 0)) % MOD;
        else dp[t][i][j] = (dp[t+1][i][j] + (j > 0 ? dp[t+1][i][j-1] : 0)) % MOD;
    } cout<<dp[0][k][k];
}