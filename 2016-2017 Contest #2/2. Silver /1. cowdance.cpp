#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
vector<int> arr(0); int n,t;
bool f(int k) {
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i=0; i<k; i++) q.push(arr[i]);
	int prev =0, time = 0; int i = k;
	while(!q.empty()) {
		int next = q.top() - prev;q.pop();
		while(!q.empty() && q.top() == next) q.pop();
		prev += next;
		while(q.size() != k && i < n) q.push(arr[i++]+prev);
		time += next; 
	} if(time <= t ) return 1; else return 0;
}
int main(int argc, char const *argv[]) {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	cin>>n>>t; arr.resize(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	int hi=n,lo=1;
	while(lo +1< hi) {
		int mid = (hi+lo)/2;
		if(f(mid)) hi = mid;
		else lo = mid;
	} cout<<hi<<endl;
}