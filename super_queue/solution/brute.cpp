#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int qs;cin >> qs;
    queue<int> q;
    while(qs --){
        char c;cin >> c;
        if(c == '?'){
            if(q.empty()){
                cout << "empty\n";
                continue;
            }
            cout << q.front() << "\n";
            continue;
        }
        if(c == '+'){
            int d, t;cin >> d >> t;
            while(t --)
                q.push(d);
        }
        if(c == '-'){
            int t;cin >> t;
            while(t --)
                q.pop();
        }
    }
}
