#include <bits/stdc++.h>
using namespace std;
struct point {
    int x,y;
    point() {}
    bool operator < (point &p) {
        return x == p.x ? y < p.y : x < p.x;
    }
};
istream &operator >>(istream &oss, pair<int,int> &p) {
    cin>>p.first>>p.second;
    return oss;
}
int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int minx=1e9, miny=1e9, maxx=-1e9, maxy=-1e9;
    for(int i=0; i<4; i++) {
        int x,y; cin>>x>>y;
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y); 
    }
    int d = max( abs(maxx - minx) , abs(maxy - miny));
    cout<<d*d<<endl;
}