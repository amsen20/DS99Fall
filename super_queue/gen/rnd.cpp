#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

    int qa = atoi(argv[1]);
    int qm = atoi(argv[2]);
    int qq = atoi(argv[3]);qq --;
    int mxd = atoi(argv[4]);
    int mxt = atoi(argv[5]);

    long long sum=0;

    cout << 1 + qa + qm + qq << "\n";
    while(qa + qm + qq){
        int x = rnd.next(qa + qm + qq);
        if(x < qa){
            int t = rnd.next(1, mxt);
            cout << "+ " << rnd.next(1, mxd) << " " << t << "\n";
            sum += t;
            qa --;
            continue;
        }
        if(x < qa + qm){
            int t = rnd.wnext(0LL, min(sum, 1LL*int(1e9)), -1); 
            cout << "- " << t << "\n";
            sum -= t;
            qm --;
            continue;
        }
        cout << "?\n";
        qq --;
    }
    cout << "?\n";
    return 0;
}

