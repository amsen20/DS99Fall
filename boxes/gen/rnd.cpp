#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 2e5+100;

int p[N], cnt[N];

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    for(int i=0 ; i<n ; i++)
        cnt[i] = 1;

    vector<ii> out;
    for(int i=0 ; i<m ; i++){
        int v=-1, u=-1;
        while(v == u){
            v = rnd.next(n);
            u = rnd.next(n);
        }
        out.push_back(ii(v, u));
    }

    for(auto i : out){
        cnt[i.second] += cnt[i.first];
        cnt[i.first] = 0;
    }
    int ind = max_element(cnt, cnt+n) - cnt;

    cout << n << " " << out.size() << "\n";
    for(auto i : out)
        cout << i.first+1 << " " << i.second+1 << "\n";
    cout << ind+1 << "\n";
    return 0;
}

