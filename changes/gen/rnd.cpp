#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

map<ii, int> mp;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int q = atoi(argv[3]);
    int w = atoi(argv[4]);

    cout << n << " " << m << " " << q << "\n";

    m -= n-1;
    for(int i=1 ; i<n ; i++){
        int to = rnd.next(i);
        mp[ii(i, to)] = rnd.next(1, w);
    }

    while(m --){
        int v = -1, u = -1;
        while(v == u || mp.count(ii(v, u)) || mp.count(ii(u, v))){
            v = rnd.next(n);
            u = rnd.next(n);
        }
        mp[ii(v, u)] = rnd.next(1, w);
    }

    for(auto P : mp)
        cout << P.first.first+1 << " " << P.first.second+1 << " " << P.second << "\n";
    
    vector<ii> qs;
    for(int i=0 ; i<n ; i++)
        qs.push_back(ii(-1, i));
    for(int i=n ; i<q ; i++){
        int v=-1, u=-1;
        while(v == u){
            v = rnd.next(n);
            u = rnd.next(n);
        }
        qs.push_back(ii(v, u));
    }
    auto it = qs.end();it --;
    shuffle(qs.begin(), it);
    for(auto i : qs){
        if(i.first == -1)
            cout << "+ " << i.second+1 << "\n";
        else
            cout << "? " << i.first+1 << " " << i.second+1 << "\n";
    }
}
