#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 750, W = 1e6;

int par[N];

int root(int v){
    return par[v] = (par[v] == v ? v : root(par[v]));
}

void merge(int v, int u){
    v = root(v);
    u = root(u);
    par[v] = u;
}

int main(int argc , char* argv[])
{
	registerValidation(argc, argv);

	int n = inf.readInt(1 , N);
    for(int i=0 ; i<n ; i++)
        par[i] = i;
    inf.readSpace();
    int mx = n*(n-1)/2;
    int m = inf.readInt(n-1, min(N, mx));
	inf.readEoln();

    set<ii> st;
    for(int i=0 ; i<m ; i++){
        int v = inf.readInt(1, n);v --;
        inf.readSpace();
        int u = inf.readInt(1, n);u --;
        inf.readSpace();
        int w = inf.readInt(1, W);
        inf.readEoln();
        ensuref(v != u, "self loop.");
        ensuref(!st.count(ii(v, u)) && !st.count(ii(u, v)), "multiple edges.");
        st.insert(ii(v, u));
        merge(v, u);
    }
    set<int> ver;
    for(int i=0 ; i<n ; i++)
        ver.insert(root(i));
    ensuref(ver.size() == 1, "graph should be connected.");
	inf.readEof();
}
