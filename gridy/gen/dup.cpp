#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 550;

char pat[N][N];

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int t = atoi(argv[3]);
    int a = atoi(argv[4]);
    int b = atoi(argv[5]);
    int q = atoi(argv[6]);
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            pat[i][j] = ((rnd.wnext(2, t) || i == n-1 || j == m-1) ? '#' : '.');
    cout << n*a << " " << m*b << "\n";
    vector<ii> v;
    for(int i=0 ; i<n*a ; i++)
        for(int j=0 ; j<m*b ; j++){
            cout << pat[i%n][j%m];
            if(pat[i%n][j%m] == '.')
                v.push_back(ii(i+1, j+1));
            if(j == m*b-1)
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
