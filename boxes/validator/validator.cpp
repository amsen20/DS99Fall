#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 2e5, MAXM = 2e5;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);

	int n = inf.readInt(1 , MAXN , "n");
    inf.readSpace();
    int m = inf.readInt(1, MAXM, "m");
    inf.readEoln();

    while(m --){
        int v = inf.readInt(1, n);
        inf.readSpace();
        int u = inf.readInt(1, n);
        inf.readEoln();
        ensuref(v != u, "start and end must not be equal");
    }
    int ind = inf.readInt(1, n);
    inf.readEoln();
    inf.readEof();
}
