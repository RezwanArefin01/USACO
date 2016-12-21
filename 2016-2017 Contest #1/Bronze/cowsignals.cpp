#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int n,m,k; cin>>n>>m>>k;
    char a[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    char A[n*k][m*k];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k1 = 0; k1 <k; k1++) {
                for(int k2=0; k2 < k; k2++)
                    A[i*k + k1][j*k + k2] = a[i][j];
            }
        }
    }
    for(int i=0; i<k*n; i++, cout<<endl)
        for(int j=0; j<k*m; j++)
            cout<<A[i][j];
}
 
