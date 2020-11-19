#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 1e5+100;

vector<int> g[N];

set<int> get_unq(int t, int mx){
    set<int> ret;
    do{
        int d = rnd.next(mx);
        ret.insert(d);
    }while(ret.size() < t);
    return ret;
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

    int n = atoi(argv[1]);
    int st = atoi(argv[2]);

    for(int i=st ; i<n ; i++){
        g[0].push_back(i);
        if(i>st)
            g[i-1].push_back(i);
    }

    for(int i=0 ; i<n ; i++){
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
        shuffle(g[i].begin(), g[i].end());
    }

    cout << n << " " << (n-st)/2 << "\n";
    for(int i=0 ; i<n ; i++){
        cout << g[i].size();
        if(g[i].empty()){
            cout << "\n";
            continue;
        }
        cout << " ";
        for(int j=0 ; j<g[i].size() ; j++)
            cout << 1+g[i][j] << " \n"[j+1 == g[i].size()];
    }
    return 0;
}

