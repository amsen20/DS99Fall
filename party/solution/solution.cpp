#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

const int N = 3e5+100;

vector<int> add[N], rem[N];

signed main(){
    int n, m;cin >> n >> m;
    while(n --){
        int l, r, c;cin >> l >> r >> c;l --;
        add[l].push_back(c);
        rem[r].push_back(c);
    }
    set<int> st;
    for(int i=0 ; i<m ; i++){
        for(auto j : add[i])
            st.insert(j);
        for(auto j : rem[i])
            st.erase(j);
        cout << (st.empty() ? 0 : *st.rbegin()) << " \n"[i == m-1];
    }
}
