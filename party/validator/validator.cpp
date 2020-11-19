#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1.5e5, MAXM = 1e9;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);

	int n = inf.readInt(1 , MAXN , "n");
    inf.readSpace();
    int m = inf.readInt(1, 2*MAXN, "m");
    inf.readEoln();

    set<int> st;
    while(n --){
        int l = inf.readInt(1, m);
        inf.readSpace();
        int r = inf.readInt(l, m);
        inf.readSpace();
        int c = inf.readInt(1, MAXM);
        inf.readEoln();
        ensuref(!st.count(c), "values must be unique.");
        st.insert(c);
    }
    inf.readEof();
}
