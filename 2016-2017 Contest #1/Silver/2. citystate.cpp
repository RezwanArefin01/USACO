#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int,int> ii;

int main(int argc, char const *argv[]) {
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);
	int n; cin>>n;
	map<string,int> cnt;
	for(int i=0; i<n; i++) {
		string a,b,tmp; cin>>tmp>>b; a = tmp.substr(0,2);
		string key = a+b; 
		if(a != b) cnt[key]++;
	} int ret = 0;
	for(auto key : cnt ) { 
		string a = key.first;
		string b = a.substr(2) + a.substr(0,2);
		if(cnt.count(b)) ret += key.second* cnt[b];
	} cout<<ret/2<<endl;
}