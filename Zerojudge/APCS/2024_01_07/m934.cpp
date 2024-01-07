#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

const int MAX_N = 105;

signed main(){
	Yuan_Berry
	int n; cin >> n;
	vector<int> nums(n+5);
	for(int i = 1; i <= n; i++) cin >> nums[i];
	vector<vector<pair<int,int>>> dp(n+5, vector<pair<int,int>>(n+5));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(j == 1){
				dp[i][j] = {0, nums[i]};
			}
			else{
				int mn = 1e9+5;
				for(int k = 1; k < j; k++){
					mn = min(mn, abs(dp[i][k].S - dp[i-k][j-k].S) + dp[i][k].F + dp[i-k][j-k].F);
				}
				dp[i][j] = {mn, nums[i] + dp[i-1][j-1].S};
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cout << dp[i][j].F << ' ';
		}
		cout << '\n';
	}
	cout << dp[n][n].F;
	
	return 0;
}

