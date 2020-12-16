#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500;

string mat[N];
int par[N*N];

int root(int v){
	return par[v] = (par[v] == v ? v : root(par[v]));
}

void merge(int v, int u){
	v = root(v);
	u = root(u);
	par[v] = u;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m;cin >> n >> m;
	for(int i=0 ; i<n ; i++){
		cin >> mat[i];
		for(int j=0 ; j<m ; j++)
			par[i*m + j] = i*m + j;
	}
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
			if(mat[i][j] == '.')
				for(int it=0 ; it<4 ; it++){
					int nx = i + dx[it], ny = j + dy[it];
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '.')
						merge(i*m+j, nx*m+ny);
				}
	int q;cin >> q;
	while(q --){
		int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
		x1 --;y1 --;x2 --;y2 --;
		cout << (root(x1*m+y1) == root(x2*m+y2) ? "YES" : "NO") << "\n";
	}
}
