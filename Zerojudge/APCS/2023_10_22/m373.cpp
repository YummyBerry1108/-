#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

signed main(){
	Yuan_Berry
	int n, k;
	cin >> n >> k;
	int ans = 0;
	vector<int> nums(n+1, 0);
	vector<vector<int>> dp(k+1, vector<int>(n+1, -2e9-5));
	for(int i = 1; i <= n; i++){
		cin >> nums[i];
		dp[0][i] = max(nums[i], dp[0][i-1]+nums[i]);
		ans = max(ans, dp[0][i]);
	}
	for(int i = 1; i <= k; i++){
		dp[i][0] = max(dp[i][0], 0);
		for(int j = 1; j <= n; j++){
			dp[i][j] = max(dp[i-1][j-1], dp[i][j-1] + nums[j]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}

