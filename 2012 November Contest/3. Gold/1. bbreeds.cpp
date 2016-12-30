#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int,int> ii;
int dp[1001][1001]; int n;
int pre[1001] = {0}; string str;
int f(int i, int a) {
	if(i == n && a == 0) return dp[i][a] = 1;
	int &ret = dp[i][a];
	if(ret != -1) return ret; ret = 0;
	if(str[i] == '(') ret += f(i+1, a+1) + f(i+1, a);
	else {
		if(a > 0) ret += f(i+1, a-1);
		if(pre[i]-a > 0) ret += f(i+1, a); 
	} return ret%2012;
}
int main(int argc, char const *argv[]) {
	freopen("bbreeds.in", "r", stdin);
	freopen("bbreeds.out", "w", stdout);
	cin>>str; n = str.size();
	memset(dp, -1, sizeof dp); 
	for(int i=1; i<n; i++) pre[i] = pre[i-1] + (str[i-1] == '(' ? 1 : -1);
	cout<<f(0,0)<<endl;
}