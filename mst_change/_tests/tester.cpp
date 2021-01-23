#include<bits/stdc++.h>
using namespace std;

const int N = 750;

struct ed{
	int v, u, w;
	ed():
		v(-1), u(-1), w(-1) {}
	ed(int v, int u, int w):
		v(v), u(u), w(w) {}
} e[N];

int n, m, par[N];

int root(int v){
	return par[v] = (v != par[v] ? root(par[v]) : v);
}

int mst(){
	for(int i=0 ; i<n ; i++)
		par[i] = i;
	vector<ed> es;
	for(int i=0 ; i<m ; i++)
		es.push_back(e[i]);
	sort(es.begin(), es.end(), [&](const ed &A, const ed &B){
		return A.w < B.w;
	});
	
	int ret=0;
	for(int i=0 ; i<m ; i++){
		int v = root(es[i].v), u = root(es[i].u);
		
		if(v == u)
			continue;
		par[v] = u;
		ret += es[i].w;
	}
	return ret;
}

int main(int argc, char * argv[])
{
	try{
        ifstream test_in(argv[1]);
        ifstream test_out(argv[2]);
        ifstream user_out(argv[3]);
		test_in >> n >> m;
		for(int i=0 ; i<m ; i++){
			test_in >> e[i].v;
			e[i].v --;
			test_in >> e[i].u;
			e[i].u --;
			test_in >> e[i].w;
		}
		int ind;
		user_out >> ind;
		if(ind < -1 || ind > m)
			return 1;
		if(ind == 0)
			return 1;//quitf(_wa, "0 is not ok.");
		if(ind == -1){
			int jans;test_out >> jans;
			if(jans == -1)
				return 0;//quitf(_ok, "ok.");
			else
				return 1;//quitf(_wa, "wrong.");
		}
		ind --;
		int cur = mst();
		e[ind].w ++;
		if(cur < mst())
			return 0;
		else
			return 1;
	}catch(string s){
        return 1;
    }
}
