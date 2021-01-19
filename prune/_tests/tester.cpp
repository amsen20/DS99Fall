#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5+100, INF = 1e9;

vector<int> g[N];
map<ii, int> mp;
bool ok[N];
int dis[2][N];

void bfs(function<int(int, int)> f, int *dis){
    queue<int> q;
    dis[0] = 0;
    q.push(0);
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto u : g[v])
            if(f(v, u) && dis[u] > dis[v] + 1){
                dis[u] = dis[v]+1;
                q.push(u);
            }
    }
}

int main(int argc, char * argv[])
{
    try{
        ifstream test_in(argv[1]);
        ifstream test_out(argv[2]);
        ifstream user_out(argv[3]);
        int n;test_in >> n;
        int m;test_in >> m;
        for(int i=0 ; i<m ; i++){
            int v;test_in >> v;v --;
            int u;test_in >> u;u --;
            mp[ii(v, u)] = mp[ii(u, v)] = i;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        for(int i=0 ; i<n ; i++)
            dis[0][i] = dis[1][i] = INF;
        int cnt;user_out >> cnt;
        if(cnt != n-1){
            // quitf(_wa, "wrong number of edges removed.");
            return 1;
        }
        set<int> st;
        while(cnt --){
            int d;user_out >> d;d --;
            if(d < 0 || d >= m){
                // quitf(_wa, "out of bound index.");
                return 1;
            }
            if(st.count(d)){
                // quitf(_wa, "index must be unique.");
                return 1;
            }
            st.insert(d);
            ok[d] = true;
        }
        bfs([&](int v, int u){return true;}, dis[0]);
        bfs([&](int v, int u){return ok[mp[ii(v, u)]];}, dis[1]);
        for(int i=0 ; i<n ; i++)
            if(dis[0][i] != dis[1][i]){
                // quitf(_wa, "distances must be same.");
                return 1;
            }
        // quitf(_ok, "ok.");
        return 0;
    }catch(string s){
        return 1;
    }

}
