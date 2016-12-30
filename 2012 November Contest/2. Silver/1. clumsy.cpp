#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	freopen("clumsy.in", "r", stdin);
	freopen("clumsy.out", "w", stdout);
	string str; cin>>str; int op,cl,dis; op = cl = dis =0;
	for(int i=0; i<str.size(); i++) {
		(str[i] == '(') ? op++ : cl++;
		if(cl > op) dis++, cl--, op++;
	} dis += (op-cl)/2;
	cout<<dis<<endl;
}