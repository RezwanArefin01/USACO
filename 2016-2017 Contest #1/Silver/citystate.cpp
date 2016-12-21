#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int,int> ii;

int main(int argc, char const *argv[]) {
	freopen("citystate.in", "r", stdin);
	freopen("citystate.in", "w", stdout);
	int n; cin>>n;
	map<string,int> cnt;
	for(int i=0; i<n; i++) {
		string a,b,tmp; cin>>tmp>>b; a = tmp.substr(0,1);
		string key = a+b;
		cnt[key]++;
	}
}