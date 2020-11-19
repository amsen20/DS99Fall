#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 2e5+100;

int a[N], sz;

set<int> get_unq(int t, int l, int r){
    set<int> ret;
    do{
        int d = rnd.next(l, r);
        ret.insert(d);
    }while(ret.size() < t);
    return ret;
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int t = atoi(argv[3]);

    set<int> st = get_unq(n, 1, m);
    vector<int> vec;
    for(auto i : st)
        vec.push_back(i);
    shuffle(vec.begin(), vec.end());

    auto push = [&](int d){
        a[++ sz] = d;
        int it = sz;
        while(it>1){
            if(a[it] < a[it/2])
                break;
            swap(a[it], a[it/2]);
            it /= 2;
        }
    };
    for(auto i : vec)
        push(i);
    
    int e=0;
    do{
        e = rnd.wnext(1, n, t);
    }while(!e);
    
    set<int> ers = get_unq(e, 1, n);
    for(auto i : ers)
        a[i] = -1;
    for(int i=1 ; i<=n ; i++)
        if(a[i] > 0 && rnd.next(2)){
            a[i] = max(1, a[i]/2);
            break;
        }
    cout << n << "\n";
    for(int i=1 ; i<=n ; i++)
        cout << a[i] << " \n"[i == n];
    return 0;
}
