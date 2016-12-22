#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int,int> ii;
struct dat {
	int coord; bool dir;
	bool operator < ( const dat& p) const {
		return coord == p.coord ? dir < p.dir : coord < p.coord;
	} dat(int a, bool b): coord(a), dir(b){}
};
struct point{ int x,y;};
int main(int argc, char const *argv[]) {
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	int n, x1,x2,y1,y2; cin>>n>>x1>>y1>>x2>>y2;
	vector<point> p(n+2); vector<int> xx,yy, xs_ofy[n+2], ys_ofx[n+2];
	p[0].x = x1, p[0].y = y1, p[n+1].x = x2, p[n+1].y = y2;
	xx.push_back(x1), xx.push_back(x2), yy.push_back(y1), yy.push_back(y2);
	for(int i=1; i<=n; i++) {
		cin>>p[i].x>>p[i].y;
		xx.push_back(p[i].x), yy.push_back(p[i].y);
	}
	sort(xx.begin(), xx.end()); sort(yy.begin(), yy.end());
	for(int i=0; i<n+2; i++) {
		p[i].x = lower_bound(xx.begin(), xx.end(), p[i].x) - xx.begin();
		p[i].y = lower_bound(yy.begin(), yy.end(), p[i].y) - yy.begin();
		xs_ofy[p[i].y].push_back(p[i].x);
		ys_ofx[p[i].x].push_back(p[i].y);
	}
	queue<dat> Q; 
	Q.push({p[0].x, 0}); Q.push({p[0].y,1});
	map<dat,int> level;
	level[dat(p[0].x,0)] = level[dat(p[0].y,1)] = 0;
	int ans = -1; 
	while(!Q.empty()) {
		dat u = Q.front(); Q.pop();
		if((u.dir && u.coord == p[n+1].y) || (!u.dir && u.coord == p[n+1].x) ) 
			{ans = level[u]; break;}
		auto data = u.dir ? xs_ofy : ys_ofx;
		for(int i : data[u.coord]) {
			dat v = {i, !u.dir}; 
			if(!level.count(v)) {
				level[v] = level[u] + 1;
				Q.push(v);
			}
		}
	} printf("%d\n", ans);
}