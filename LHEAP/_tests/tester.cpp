#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+100, MAXM = 1e9;

int a[N], b[N];

int main(int argc, char * argv[])
{
    try{
        ifstream test_in(argv[1]);
        ifstream test_out(argv[2]);
        ifstream user_out(argv[3]);
        int n;test_in >> n;
        for(int i=1 ; i<=n ; i++)
            test_in >> a[i];

        int jans;test_out >> jans;
        if(jans == -1){
            int d;user_out >> d;
            if(d == -1)
                return 0;
            else
                return 1;
        }

        for(int i=1 ; i<=n ; i++){
            user_out >> b[i];
            if(b[i] < 1 || b[i] > MAXM)
                return 1;
        }

        for(int i=1 ; i<=n ; i++)
            if(a[i] > 0 && a[i] != b[i]){
                return 1;
            }
        bool f = true;
        for(int i=1 ; i<=n ; i++){
            auto ch = [&](int ind){
                if(ind <= n)
                    f &= (b[i] > b[ind]);
            };
            ch(2*i);
            ch(2*i+1);
        }
        if(!f)
            return 1;
        return 0;
    }catch(string s){
        return 1;
    }

}
