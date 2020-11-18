#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

const int N = 2e5+100;

vector<int> v[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;cin >> n >> m;
    for(int i=0 ; i<n ; i++)
        v[i].push_back(i+1);
    int tr=0;
    for(int i=0 ; i<m ; i++){
        int a, b;cin >> a >> b;a --;b --;
        for(auto i : v[a])
            v[b].push_back(i);
        v[a].clear();
    }
    int ind;cin >> ind;ind --;
    if(v[ind].empty()){
        cout << "0\n";
        return 0;
    }
    cout << v[ind].size() << " ";
    for(auto i : v[ind])
        cout << i << " ";
    cout << "\n";
}
