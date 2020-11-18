#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+100;

int a[N], dp[2][N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    reverse(a, a+n);
    int ans=0;
    for(int i=0 ; i<n ; i++){
        int t = 1000;
        for(int j=i-1 ; j>=0 && t ; j--, t--){
            if(a[i] >= a[j])
                dp[0][i] = max(dp[0][i], dp[1][j]);
            if(a[i] <= a[j])
                dp[1][i] = max(dp[1][i], dp[0][j]);
        }
        dp[0][i] ++;
        dp[1][i] ++; 
    }
    cout << *max_element(dp[0], dp[0]+n) << "\n";
}
