#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int qs;cin >> qs;
    queue<ii> q;
    while(qs --){
        char c;cin >> c;
        if(c == '?'){
            if(q.empty()){
                cout << "empty\n";
                continue;
            }
            cout << q.front().first << "\n";
            continue;
        }
        if(c == '+'){
            int d, t;cin >> d >> t;
            if(!q.empty() && q.back().first == d)
                q.back().second += t;
            else
                q.push(ii(d, t));
        }
        if(c == '-'){
            int t;cin >> t;
            while(t && q.front().second <= t){
                t -= q.front().second;
                q.pop();
            }
            if(t)
                q.front().second -= t;
        }
    }
}
