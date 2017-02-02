#include <bits/stdc++.h>
using namespace std;
int tree[int(1e5)+ 10];
void update(int i, int val) { i++;
	for(; i<=1e5; i+= (i & -i)) tree[i] += val;
} 
int query(int i) { i++;
	int ret = 0;
	for(; i>0; i -= (i & -i)) ret += tree[i];
	return ret;
}
int main(int argc, char const *argv[]) {
	freopen("bphoto.in", "r", stdin);
	freopen("bphoto.out", "w", stdout);
	int n; cin>>n; vector<pair<int,int> > arr(n);
	for(int i=0; i<n; i++) 
		cin>>arr[i].first, arr[i].second = i;
	sort(arr.begin(), arr.end(), greater<pair<int,int> >());
	int ans, seen; ans = seen = 0;
	for(int i=0; i<n; i++) { 
		int left = query(arr[i].second);
		int right = seen - left;
		if(max(left, right) > 2*min(left, right)) ans ++;
		seen++; update(arr[i].second, 1);
	} cout<<ans<<endl;
}