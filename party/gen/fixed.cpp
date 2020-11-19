#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

struct dat{
    int l, r, c;
    dat(int l, int r, int c):
        l(l), r(r), c(c) {}
};

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int cmx = atoi(argv[3]);

    set<int> st;

    vector<dat> vec;
    while(n --){
        int l = rnd.next(m/2), r = rnd.next(m/2, m-1);
        if(l>r)
            swap(l, r);
        int c = 0;
        do{
            c = rnd.next(cmx);
        }while(st.count(c));
        st.insert(c);
        vec.emplace_back(l, r, c);
    }
    shuffle(vec.begin(), vec.end());

    cout << vec.size() << " " << m << "\n";
    for(auto i : vec)
        cout << i.l+1 << " " << i.r+1 << " " << i.c+1 << "\n";
    return 0;
}
