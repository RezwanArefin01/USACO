#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
	int n, cnt = 0; cin>>n; char tmp; int g[n][n];
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) 
		cin>>tmp, g[i][j] = tmp-'0'; 
	for(int i=n-1; i>=0; i--) for(int j=n-1; j>=0; j--) {
		if(g[i][j]) { cnt++;
			for(int k=0; k<=i; k++) for(int l=0; l<=j; l++) 
				g[k][l] = !g[k][l];
		}
	} cout<<cnt<<endl;
}