#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+100;

int a[N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=1 ; i<=n ; i++)
        cin >> a[i];
    for(int i=n ; i>=1 ; i--){
        int left = (2*i <= n ? a[2*i] : 0);
        int right = (2*i+1 <= n ? a[2*i+1] : 0);
        if(a[i] == -1)
            a[i] = max(left, right) + 1;
        else if(a[i] <= max(left, right)){
            cout << "-1\n";
            return 0;
        }
    }
    for(int i=1 ; i<=n ; i++)
        cout << a[i] << " \n"[i == n];
}
