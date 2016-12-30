#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int,int> ii;
int n,a,b; int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
struct node{
	int x, y; ll dist; node(){} 
	node(int _x, int _y , int _dist):x(_x), y(_y), dist(_dist){}
	bool operator < ( const node &p) const { return dist > p.dist;}
};
int main(int argc, char const *argv[]) {
	freopen("distant.in", "r", stdin);
	freopen("distant.out", "w", stdout);
	cin.tie(0), ios::sync_with_stdio(false);
	int n,a,b; cin>>n>>a>>b; char adj[n+1][n+1];
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>adj[i][j];
	ll Max = 0;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		bool vis[n+1][n+1]; memset(vis,0,sizeof vis); 
		priority_queue<node> Q; Q.push(node(i,j,0));
		while(!Q.empty()){
			node u = Q.top(); Q.pop();
			if(!vis[u.x][u.y]) {
				vis[u.x][u.y] = 1;
				for(int k=0; k<4; k++) {
					int xx = u.x + dx[k], yy = u.y + dy[k];
					if(xx < n && yy < n && xx >=0 && yy >=0) 
						Q.push(node(xx,yy, u.dist + (adj[u.x][u.y] == adj[xx][yy] ? a : b)));
				}Max = max(Max, u.dist);
			}  
		}
	} cout<<Max<<endl;
}