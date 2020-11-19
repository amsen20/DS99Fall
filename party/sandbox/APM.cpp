#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

const int N = 3e5+100;

int mx[N];

signed main(){
    int n, m;cin >> n >> m;
    while(n --){
        int l, r, c;cin >> l >> r >> c;l --;
        for(int i=l ; i<r ; i++)
            mx[i] = max(mx[i], c);
    }
    for(int i=0 ; i<m ; i++)
        cout << mx[i] << " \n"[i == m-1];
}
