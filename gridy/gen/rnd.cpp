#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int t = atoi(argv[3]);
    int q = atoi(argv[4]);
    cout << n << " " << m << "\n";
    vector<ii> v;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++){
            int r = rnd.wnext(2, t);
            cout << (r ? '#' : '.');
            if(!r)
                v.push_back(ii(i+1, j+1));
            if(j == m-1)
                cout << "\n";
        }
    cout << q << "\n";
    while(q --){
        int f = rnd.next(v.size());
        int s=f;
        while(s == f)
            s = rnd.next(v.size());
        cout << v[f].first << " " << v[f].second << " " << v[s].first << " " << v[s].second << "\n";
    }
}
