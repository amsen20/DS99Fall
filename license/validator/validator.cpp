#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);

	int n = inf.readInt(1 , MAXN , "n");
    inf.readSpace();
    int m = inf.readInt(1, n, "m");
    inf.readEoln();
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        int cnt = inf.readInt(0, MAXM);
        sum += cnt;
        ensuref(sum <= MAXM, "too much licenses.");
        if(!cnt){
            inf.readEoln();
            continue;
        }
        inf.readSpace();
        set<int> st;
        for(int j=0 ; j<cnt ; j++){
            int d = inf.readInt(i+1, n);
            st.insert(d);
            if(j < cnt-1)
                inf.readSpace();
            else
                inf.readEoln();
        }
        ensuref(cnt == st.size(), "all must be unique");
    }
    inf.readEof();
}
