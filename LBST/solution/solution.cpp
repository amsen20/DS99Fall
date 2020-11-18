#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+100;

int l[N], r[N], a[N];
bool mark[N];

int sz=0;

void solve(int v){
    if(l[v] >= 0)
        solve(l[v]);
    a[v] = sz ++;
    if(r[v] >= 0)
        solve(r[v]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for(int i=0 ; i<n ; i++){
        int d, ll, rr;cin >> d >> ll >> rr;d --;ll --;rr --;
        if(ll>=0){
            l[d] = ll;
            mark[ll] = true;
        }
        if(rr>=0){
            r[d] = rr;
            mark[rr] = true;
        }
    }
    for(int i=0 ; i<n ; i++)
        if(!mark[i])
            solve(i);
    for(int i=0 ; i<n ; i++)
        cout << a[i]+1 << " \n"[i == n-1];
}
