#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 1e5+100;

int p[N], par[N];

vector<ii> build_graph(int n, int m, int t){
    vector<ii> eds;
    int deg = (m + n-1)/n;
    for(int i=1 ; i<n ; i++){
        int cur = min(deg, m) + 1;
        if(i == n-1)
            cur = m + 1;
        cur = min(cur, i);
        set<int> st;
        do{
            st.insert(rnd.next(i));
        }while(st.size() < cur);
        m -= cur-1;
        for(auto j : st)
            eds.push_back(ii(i, j));
    }
    return eds;
}

vector<ii> shuffle_vertices(int n, const vector<ii> &eds){
    vector<ii> ret;
    for(int i=0 ; i<n ; i++)
        p[i] = i;
    shuffle(p, p+n);
    for(auto e : eds)
        ret.push_back(ii(p[e.first], p[e.second]));
    shuffle(ret.begin(), ret.end());
    return ret;
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int t = atoi(argv[3]);

    auto graph = build_graph(n, m, t);
    auto g = shuffle_vertices(n, graph);

    cout << n << " " << g.size() << "\n";
    for(auto ed : g)
        cout << ed.first + 1 << " " << ed.second + 1 << "\n";
}
