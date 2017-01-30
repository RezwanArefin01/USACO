#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out","w", stdout);
    string s[] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string,int> idx; map<int, string> rev; 
    for(int i=0; i<7; i++) idx[s[i]] = i, rev[i] = s[i];
    int n; cin>>n; vector<int> cnt(7); 
	while(n--) {
		string str; int t; cin>>str>>t;
		cnt[idx[str]] += t;
    } int Min = *min_element(cnt.begin(), cnt.end());
    int second = 1e9, x = -1;
    for(int i=0; i<7; i++) if(cnt[i] > Min && cnt[i] < second) second = cnt[i], x = i;
    if(x == -1) { cout<<"Tie"<<endl; return 0;} int nt = 0;
	for(int i=0; i<7; i++) if(cnt[i] == second) nt++;
	if(nt > 1) { cout<<"Tie"<<endl; return 0;}
	cout<<rev[x]<<endl;
}