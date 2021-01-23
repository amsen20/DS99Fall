#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 777, INF = 1e9;

set<ii> es;
int v[N], u[N], w[N], par[N], n, m;

int root(int v){
	return par[v] = (par[v] == v ? v : root(par[v]));
}

void merge(int v, int u){
	v = root(v);
	u = root(u);
	par[v] = u;
}

int mst(){
	for(int i=0 ; i<n ; i++)
		par[i] = i;
	int ret=0;
	for(auto E : es){
		int id = E.second;
		if(root(v[id]) == root(u[id]))
			continue;
		ret += E.first;
		merge(v[id], u[id]);
	}
	return ret;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> m;
	auto add_ed = [&] (int we, int ind){
		es.erase(ii(w[ind], ind));
		es.insert(ii(we, ind));
	};
	for(int i=0 ; i<m ; i++){
		cin >> v[i] >> u[i] >> w[i];v[i] --;u[i] --;
		add_ed(w[i], i);
	}
	int mstw = mst();
	for(int i=0 ; i<m ; i++){
		add_ed(w[i]+1, i);
		if(mst() > mstw){
			cout << i+1 << "\n";
			return 0;
		}
		add_ed(w[i], i);
	}
	cout << "-1\n";
}
