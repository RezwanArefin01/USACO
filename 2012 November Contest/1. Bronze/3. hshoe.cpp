#include <bits/stdc++.h>
using namespace std;
int n,ans = 0; int adj[7][7], vis[7][7];
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
void dfs(int x, int y, int op, int cl, bool ending) {
	if(op == cl) { ans = max(ans, op+cl); }
	vis[x][y] = 1;
	for(int i=0; i<4; i++) {
		int xx = x+dx[i], yy = y + dy[i];
		if(xx >=0 && xx < n && yy >=0 && yy < n && !vis[xx][yy]) {
			if(adj[xx][yy]) dfs(xx,yy, op, cl+1, 1);
			else if(!ending) dfs(xx,yy, op+1, cl, 0);
		}
	} 
	vis[x][y] = 0;
}
int main(int argc, char const *argv[]) {
	freopen("hshoe.in", "r", stdin);
	freopen("hshoe.out", "w", stdout);
	cin>>n; char tmp; 
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) 
		cin>>tmp, adj[i][j] = (tmp == ')');
	if(!adj[0][0]) dfs(0,0,1,0,0);
	cout<<ans<<endl;
}