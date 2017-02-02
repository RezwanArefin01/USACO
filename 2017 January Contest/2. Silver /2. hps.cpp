#include <bits/stdc++.h>
using namespace std;
int win(char a, char b) {
	if(a == 'H' && b == 'S') return 1;
	if(a == 'S' && b == 'P') return 1;
	if(a == 'P' && b == 'H') return 1;
	return 0;
} int ans = 0,n,k; vector<char> fj;
int main(int argc, char const *argv[]) {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	cin>>n>>k; fj.resize(n); 
	for(int i=0; i<n; i++) cin>>fj[i];
	vector<int> h(n+1,0), p(n+1,0), s(n+1,0);
	for(int i=1; i<=n; i++) {
		h[i] = win('H', fj[i-1]) + h[i-1];
		p[i] = win('P', fj[i-1]) + p[i-1];
		s[i] = win('S', fj[i-1]) + s[i-1];
	} 
	int ans = max(h[n], max(s[n],p[n]));
	for(int i=1; i<=n; i++) {
		ans = max(ans, h[i] + p[n] - p[i]);
		ans = max(ans, h[i] + s[n] - s[i]);
		ans = max(ans, s[i] + p[n] - p[i]);
		ans = max(ans, s[i] + h[n] - h[i]);
		ans = max(ans, p[i] + s[n] - s[i]);
		ans = max(ans, p[i] + h[n] - h[i]);
	} cout<<ans<<endl;
}	
