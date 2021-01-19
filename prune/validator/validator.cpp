#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int MAXN = 100*1000, MAXM = 100*1000;

int par[MAXN];

int root(int v){
    return par[v] = (par[v] == v ? v : root(par[v]));
}

void merge(int v, int u){
    v = root(v);
    u = root(u);
    par[v] = u;
}

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
	int n = inf.readInt(1 , MAXN , "n");
	inf.readSpace();
	int m = inf.readInt(1 , MAXM , "m");
    inf.readEoln();
    { // first graph
        set<ii> sst;
        for(int i=0 ; i<n ; i++)
            par[i] = i;
        for(int i=0 ; i<m ; i++){
            int v = inf.readInt(1, n, "vi");
            v --;
            inf.readSpace();
            int u = inf.readInt(1, n, "ui");
            u --;
            inf.readEoln();
            merge(v, u);
            ensuref(!sst.count(ii(v, u)), "graph should be simple");
            ensuref(v != u, "graph should be simple");
            sst.insert(ii(v, u));
            sst.insert(ii(u, v));
        }
        set<int> st;
        for(int i=0 ; i<n ; i++)
            st.insert(root(i));
        ensuref(st.size() == 1, "graph should be connected");
    }
	inf.readEof();
}
