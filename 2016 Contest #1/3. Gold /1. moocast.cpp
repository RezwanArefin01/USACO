#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int,int> ii;
#define sq(a) (a*a)
struct point{ 
	int x,y;
	int dist(point &p) {return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y); }
};
struct edge{
	int u, v, w;
	edge(){} edge(int _u, int _v, int _w): u(_u), v(_v), w(_w){}
	bool operator < ( const edge &p) const { return w < p.w; }
}; vector<int> p(1100);
int find(int u) { return p[u] == u? u : (p[u] = find(p[u]));}
bool isSameSet(int u, int v) { return find(u) == find(v);}
void Union(int u, int v) { p[find(u)] = find(v);} 
int main(int argc, char const *argv[]) {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	int n; cin>>n; vector<point> v(n);
	for(int i=0; i<n; i++) cin>>v[i].x>>v[i].y;
	vector<edge> edgeList;
	for(int i=0; i<n; i++, p[i]=i) 
		for(int j=i+1; j<n; j++) 
			edgeList.emplace_back(i,j, v[i].dist(v[j]));
	sort(edgeList.begin(), edgeList.end());
	int ans =0, t = 0; for(edge i : edgeList) {
		if(!isSameSet(i.u, i.v)) {
			Union(i.u, i.v); t++;
			ans = i.w;
			if(t == n-1) break;
		}
	} cout<<ans<<endl;
}