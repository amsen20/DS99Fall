#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

struct ed{
    int v, u, w;
    ed(int v, int u, int w):
        v(v), u(u), w(w){}
};

vector<ed> build(int n, int m, int w){
    map<ii, int> mp;
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
    vector<ed> ret;
    for(auto P : mp)
        ret.emplace_back(P.first.first, P.first.second, P.second);
    return ret;
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int cnt = atoi(argv[3]);
    int w = atoi(argv[4]);

    cout << n << " " << m << "\n";

    vector<ed> f, s;
    if(cnt > 1){
        assert(m%2 == 0);
        assert(n%2 == 0);
        int hm = (m-4)/2;
        f = build(n/2, hm, w);
        s = build(n/2, hm, w);
        m -= hm*2;
        auto find = [&](){
            return ii(rnd.next(n/2), n/2+rnd.next(n/2));
        };
        auto ans = find();
        f.emplace_back(ans.first, ans.second, 5);
        m --;
        while(m --){
            auto ed = find();
            f.emplace_back(ed.first, ed.second, 12);
        }
    } else
        f = build(n, m, w);

    for(auto e : f)
        cout << e.v+1 << " " << e.u+1 << " " << e.w << "\n";
    for(auto e : s)
        cout << n/2 + e.v+1 << " " << n/2 + e.u+1 << " " << e.w << "\n";
}
