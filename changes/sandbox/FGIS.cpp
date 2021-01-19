#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 333, INF = 1e9;

int n, m, q;
int dis[N];
bool mark[N];
vector<ii> g[N];

int dij(int rt, int en){
    for(int i=0 ; i<n ; i++)
        dis[i] = INF;
    set<ii> st;
    if(mark[rt]){
        st.insert(ii(0, rt));
        dis[rt] = 0;
    }
    while(!st.empty()){
        int v = st.begin()->second;
        st.erase(st.begin());
        if(!mark[v])
            continue;
        if(v == en)
            return dis[v];
        for(auto U : g[v]){
            int u = U.first, w = U.second;
            if(!mark[u])
                continue;
            if(dis[u] > dis[v] + w){
                st.erase(ii(dis[u], u));
                dis[u] = dis[v] + w;
                st.insert(ii(dis[u], u));
            }
        }
    }
    return -1;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> m >> q;
	while(m --){
		int v, u, w;cin >> v >> u >> w;v --;u --;
		g[v].push_back(ii(u, w));
        g[u].push_back(ii(v, w));
	}
	while(q --){
		char t;cin >> t;
		if(t == '?'){
			int v, u;cin >> v >> u;v --;u --;
			cout << dij(v, u) << "\n";
		} else {
			int v;cin >> v;v --;
			mark[v] = true;
		}
	}
}
