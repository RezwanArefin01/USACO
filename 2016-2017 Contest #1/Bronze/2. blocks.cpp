#include <bits/stdc++.h>
using namespace std;
int cnt[27];
int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n; cin>>n;
    while(n--) { 
        string a,b;
        cin>>a>>b;
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        vector<int> cnt1(27,0), cnt2(27,0);
        for(int i=0; i<a.size(); i++) cnt1[a[i]-'a']++;
        for(int i=0; i<b.size(); i++) cnt2[b[i]-'a']++;
        for(int i=0; i<26; i++) cnt[i] += max(cnt1[i], cnt2[i]);
    } for(int i=0; i<26; i++) cout<<cnt[i]<<endl;
}