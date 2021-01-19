#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 333, INF = 1e9;

int dis[N][N];
bool mark[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, q;cin >> n >> m >> q;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++)
			dis[i][j] = INF;
		dis[i][i] = 0;
	}
	while(m --){
		int v, u, w;cin >> v >> u >> w;v --;u --;
		dis[v][u] = dis[u][v] = w;
	}
	while(q --){
		char t;cin >> t;
		if(t == '?'){
			int v, u;cin >> v >> u;v --;u --;
			cout << ((dis[v][u] >= INF || !mark[v] || !mark[u]) ? -1 : dis[v][u]) << "\n";
		} else {
			int v;cin >> v;v --;
			mark[v] = true;
            for(int k=0 ; k<n ; k++)
				if(mark[k])
					for(int i=0 ; i<n ; i++)
						for(int j=0 ; j<n ; j++)
							dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
}
