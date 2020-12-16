#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool mark[N][N];
string mat[N];
int col[N][N], n, m;

void dfs(int x, int y){
    mark[x][y] = true;
    for(int it=0 ; it<4 ; it++){
        int nx = x + dx[it], ny = y + dy[it];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || mat[nx][ny] == '#' || mark[nx][ny])
            continue;
        dfs(nx, ny);
    }
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> m;
	for(int i=0 ; i<n ; i++)
		cin >> mat[i];
    int sz=0;
	int q;cin >> q;
	while(q --){
		int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
		x1 --;y1 --;x2 --;y2 --;
        memset(mark, 0, sizeof mark);
        dfs(x1, y1);
		cout << (mark[x2][y2] ? "YES" : "NO") << "\n";
	}
}
