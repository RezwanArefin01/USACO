#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("typo.in", "r", stdin);
	freopen("typo.out", "w", stdout);
	string str; cin>>str;
	int op = 0, cl = 0, bal = 0, ans;
	for(int i=0; i<str.size(); i++ ){ 
		if(str[i] == '(') op++, bal++;
		else cl++, bal--;
		if(bal <= 1) op = 0; 
		if(bal == -1) { ans = cl; break; }
	} if(bal > 0) ans = op;
	cout<<ans;
}