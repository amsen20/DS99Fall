#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;
const int N = 3e5 + 10;
int res, cnt, n, m;
vector<int> vec[N];
set<int> st;


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		int sz;	cin >> sz;
		while(sz --) {
			int x;	cin >> x;
			vec[i].push_back(x);
		}
	}
	st.insert(1);
	while(st.size()) {
		int v = *st.begin();	st.erase(v);
		cnt ++;		res += v;
		if(cnt == m)	return cout << res, 0;
		for(auto u : vec[v])
			st.insert(u);
	}
	cout << -1;
	return 0;
}
