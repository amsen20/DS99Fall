#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1e5, MAXM = 1e9;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);

	int qs = inf.readInt(1 , MAXN , "qs");
    inf.readEoln();

    long long sum = 0;

    while(qs --){
        char c = inf.readChar();
        if(c == '+'){
            inf.readSpace();
            int d = inf.readInt(1, MAXM);
            inf.readSpace();
            int t = inf.readInt(1, MAXM);
            sum += t;
            inf.readEoln();
            continue;
        }
        if(c == '-'){
            inf.readSpace();
            int t = inf.readInt(0, min(1LL*MAXM, sum));
            sum -= t;
            inf.readEoln();
            continue;
        }
        inf.readEoln();
        ensuref(c == '?', "+ or - or ?");
    }
    inf.readEof();
}
