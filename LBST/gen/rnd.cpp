#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 2e5+100;

int p[N], q[N], l[N], r[N], rt, sz;

int mxh(int v){
    if(v == -1)
        return 0;
    return 1 + max(mxh(r[v]), mxh(l[v]));
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);

    for(int i=0 ; i<n ; i++)
        p[i] = i;
    shuffle(p, p+n);
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    rt = -1;
    for(int i=0 ; i<n ; i++){       
        int *it = &rt;
        while(*it != -1){
            if(p[i] > *it)
                it = r + *it;
            else
                it = l + *it;
        }
        *it = p[i];
    }
    assert(mxh(rt) < 50);

    for(int i=0 ; i<n ; i++)
        q[i] = i;
    shuffle(q, q+n);
    
    cout << n << "\n";
    auto get = [&](int d){
        if(d>=0)
            d = q[d]+1;
        return d;
    };
    for(int i=0 ; i<n ; i++)
        cout << q[i] + 1 << " " << get(l[i]) << " " << get(r[i]) << "\n";
    return 0;
}

