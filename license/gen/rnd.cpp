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
    int m = atoi(argv[2]);
    int sz = atoi(argv[3]);

    auto answer = get_unq(sz, n);
    answer.insert(0);
    vector<int> v, u;
    for(int i=0 ; i<n ; i++)
        if(answer.count(i))
            v.push_back(i);
        else
            u.push_back(i);
    
    auto con = [&](vector<int> vec, int cnt){
        cnt = cnt - vec.size() + 1;
        for(int i=1 ; i<vec.size() ; i++){
            int fb = (cnt ? rnd.wnext(min(i+1, cnt), 10) : 0);
            cnt -= fb;
            fb ++;
            while(fb --)
                g[ vec[rnd.wnext(i, 1)] ].push_back( vec[i] );
        }
        return cnt;
    };
    int rem = con(v, m/2);
    rem += con(u, m/2);

    for(int i=*answer.rbegin()+1 ; i<n && rem-- ; i++)
        g[0].push_back(i);

    for(int i=0 ; i<n ; i++){
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
        shuffle(g[i].begin(), g[i].end());
    }

    cout << n << " " << sz << "\n";
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

