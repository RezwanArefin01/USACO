#include <bits/stdc++.h>
using namespace std;
struct point {
    int x,y,d;
};
inline double dist(point &a, point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}
vector<int> adj[210]; int md = -1;
int vis[210];
int dfs(int u) {
	vis[u] = 1; int ret = 1;
	for(auto v : adj[u]) if(!vis[v] ) ret += dfs(v);
	return ret;
}
int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n; cin>>n;
    vector<point> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i].x>>arr[i].y>>arr[i].d;
    for(int i=0; i<n; i++) {
        point a = arr[i];
        for(int j=0; j<n; j++) {
            point b = arr[j];
            if(dist(a,b) <= a.d) adj[i].push_back(j);
        }
    } int ans = -1;
    for(int i=0; i<n; i++) {
        memset(vis, 0, sizeof vis);
        ans = max(ans, dfs(i));
    } cout<<ans<<endl;
}

 
