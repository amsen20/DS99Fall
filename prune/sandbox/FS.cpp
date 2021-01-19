#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5+100, INF = 1e9;

int dis[N];
vector<int> g[N];
map<ii, int> mp;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;cin >> n >> m;
    for(int i=0 ; i<n ; i++)
        dis[i] = INF;
    for(int i=0 ; i<m ; i++){
        int v, u;cin >> v >> u;v --;u --;
        mp[ii(v, u)] = mp[ii(u, v)] = i+1;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    vector<int> ans;
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto u : g[v])
            if(dis[u] > dis[v] + 1){
                ans.push_back(mp[ii(v, u)]);
                dis[u] = dis[v] + 1;
                q.push(u);
            }
    }
    cout << ans.size() << "\n";
    for(auto i : ans)
        cout << i << " ";
    cout << "\n";
}
