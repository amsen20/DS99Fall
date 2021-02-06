#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

const int N = 2e5+100;

int nxt[N], st[N], en[N];

signed main(){
    int n, m;cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        st[i] = en[i] = i;
        nxt[i] = -1;
    }
    while(m --){
        int v, u;cin >> v >> u;v --;u --;
        if(st[v] == -1)
            continue;
        if(st[u] != -1){
            nxt[ en[u] ] = st[v];
            en[u] = en[v];
        }else{
            st[u] = st[v];
            en[u] = en[v];
        }
        st[v] = en[v] = -1;
    }
    int ind;cin >> ind;ind --;
    if(st[ind] == -1){
        cout << "0\n";
        return 0;
    }
    int it = st[ind];
    vector<int> ans;
    while(it != -1){
        ans.push_back(it);
        it = nxt[it];
    }
    cout << ans.size() << " ";
    for(auto i : ans)
        cout << 1+i << " ";
    cout << "\n";
}
