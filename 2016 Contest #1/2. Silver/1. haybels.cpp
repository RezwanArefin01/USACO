#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("haybales.in","r", stdin);
    freopen("haybales.out","w", stdout);
    int n,q; cin>>n>>q;
    long long arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n);
    while(q--) {
        int a,b; cin>>a>>b;
        cout<<upper_bound(arr,arr+n, b) - lower_bound(arr,arr+n, a)<<endl;
    }
}