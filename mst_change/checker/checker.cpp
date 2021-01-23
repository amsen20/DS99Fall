#include<bits/stdc++.h>
#include "testlib.h"
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
	registerChecker("mls", argc, argv);
	n = inf.readInt();
	m = inf.readInt();
	for(int i=0 ; i<m ; i++){
		e[i].v = inf.readInt()-1;
		e[i].u = inf.readInt()-1;
		e[i].w = inf.readInt();
	}
	int ind = ouf.readInt(-1, m);
	if(ind == 0)
		quitf(_wa, "0 is not ok.");
	if(ind == -1){
		if(ans.readInt() == -1)
			quitf(_ok, "ok.");
		else
			quitf(_wa, "wrong.");
	}
	ind --;
	int cur = mst();
	e[ind].w ++;
	if(cur < mst())
		quitf(_ok, "ok.");
	else
		quitf(_wa, "wrong.");
}
