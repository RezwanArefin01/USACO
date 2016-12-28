#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("cowfind.in", "r", stdin);
	freopen("cowfind.out", "w", stdout);
	string str; cin>>str;
	vector<int> x,y; int ans = 0;
	for(int i=0; i<str.size()-1; i++) {
		if(str[i] == str[i+1]) {
			if(str[i] == '(') x.push_back(i);
			else y.push_back(i);
		}
	} for(int i=0; i<x.size(); i++) {
		ans += y.end() - lower_bound(y.begin(), y.end(), x[i]);
	} cout<<ans<<endl;
}