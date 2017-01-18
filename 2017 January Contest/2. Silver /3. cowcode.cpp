#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
string str; ll len;
char f(ll b, ll n){
	if(b <= 1) return str[n-1];
	if(n <= len*(1ll<<(b-2))) return f(b-1,n);
	if(n == len*(1ll << (b-2))+1) return f(b-1, n-1);
	return f(b-1, n - len*(1ll<<(b-2)) -1);
}
int main(int argc, char const *argv[]) {
	freopen("cowcode.in", "r", stdin);
	freopen("cowcode.out", "w", stdout);
	cin>>str; ll n; cin>>n; len = (ll)str.size();
	ll b = ceil(log2((double)n/(double)len))+1;
	if(n <= len){ cout<<str[n-1]; return 0;}
	cout<<f(n <= len?1:b, n );
}