#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1e5;

int l[MAXN], r[MAXN], par[MAXN];

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
    for(int i=0 ; i<n ; i++)
        par[i] = i;
    inf.readEoln();
    
    int ed=0;
    for(int i=0 ; i<n ; i++){
        int v = inf.readInt(1, n, "v");v --;
        inf.readSpace();
        int l = inf.readInt(-1, n, "l");l --;
        inf.readSpace();
        int r = inf.readInt(-1, n, "r");r --;
        inf.readEoln();
        if(l>=0){
            merge(v, l);
            ed ++;
        }
        if(r>=0){
            merge(v, r);
            ed ++;
        }
    }

    ensuref(ed == n-1, "must have n-1 edges.");
    set<int> st;
    for(int i=0 ; i<n ; i++)
        st.insert(root(i));
    ensuref(st.size() == 1, "must be connected.");

    inf.readEof();
}
