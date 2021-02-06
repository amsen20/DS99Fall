#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 300, Q = 1e5, W = 1e6;

int main(int argc , char* argv[])
{
	registerValidation(argc, argv);

	int n = inf.readInt(1 , N);
    inf.readSpace();
    int mx = n*(n-1)/2;
    int m = inf.readInt(1, mx);
    inf.readSpace();
    int q = inf.readInt(1, Q);
	inf.readEoln();

    set<ii> st;
    for(int i=0 ; i<m ; i++){
        int v = inf.readInt(1, n);
        inf.readSpace();
        int u = inf.readInt(1, n);
        inf.readSpace();
        int w = inf.readInt(1, W);
        inf.readEoln();
        ensuref(v != u, "self loop.");
        ensuref(!st.count(ii(v, u)) && !st.count(ii(u, v)), "multiple edges.");
        st.insert(ii(v, u));
    }
    set<int> stt;
    for(int i=0 ; i<q ; i++){
        char c = inf.readChar();
        inf.readSpace();
        if(c == '+'){
            int v = inf.readInt(1, n);
            ensuref(!stt.count(v), "freed vertex.");
            stt.insert(v);
            inf.readEoln();
        } else {
            int v = inf.readInt(1, n);
            inf.readSpace();
            int u = inf.readInt(1, n);
            ensuref(v != u, "same vertices dist.");
            inf.readEoln();
        }
    }
	inf.readEof();
}
