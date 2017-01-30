#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n; cin>>n; vector<vector<int> > cnt(4, vector<int> (4,0));
	while(n--) { int a,b; cin>>a>>b; cnt[a][b]++; }
	cout<<max(cnt[1][2] + cnt[2][3] + cnt[3][1],
			  cnt[1][3] + cnt[3][2] + cnt[2][1])<<endl;
}