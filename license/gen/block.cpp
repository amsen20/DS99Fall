#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 2e5+100;

int p[N], cnt[N];

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

    int n = atoi(argv[1]);
    int blk = atoi(argv[2]);
    int m = atoi(argv[3]);

    vector<vector<ii> > v;
    for(int i=0 ; i<n ; i+=blk){
        int l=i, r=min(n, i+blk);
        vector<ii> u;
        for(int j=r-1 ; j>l ; j--)
            u.push_back(ii(j, j-1));
        reverse(u.begin(), u.end());
        v.push_back(u);
    }
    bool f = true;
    vector<ii> out;
    while(f){
        f = false;
        for(auto &vec : v){
            if(vec.empty())
                continue;
            f = true;
            out.push_back(vec.back());
            vec.pop_back();
        }
    }
    for(int i=0 ; i+blk<n ; i+=blk)
        out.push_back(ii(i, i+blk));

    for(int i=0 ; i<n ; i++){
        p[i] = i;
        cnt[i] = 1;
    }

    shuffle(p, p+n);
    for(auto &i : out){
        i.first = p[i.first];
        i.second = p[i.second];
    }

    while(out.size() > m)
        out.pop_back();

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

