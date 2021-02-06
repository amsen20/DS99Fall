#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

const int N = 1e5+100;

vector<int> vec[N];

signed main(){
    int n, m;cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        int cnt;cin >> cnt;
        for(int j=0 ; j<cnt ; j++){
            int d;cin >> d;d --;
            vec[i].push_back(d);
        }
    }
    ll ans=0;
    set<int> st;
    st.insert(0);
    int mx=0, it=1;
    while(m-- && !st.empty()){
        mx = max(mx, (int)st.size());
        int v = *st.begin();
        ans += v+1;
        st.erase(v);
        for(auto u : vec[v])
            st.insert(u);
    }
    m ++;
    if(m)
        ans = -1;
    // assert(ans > 0);
    cout << ans << "\n";
}
