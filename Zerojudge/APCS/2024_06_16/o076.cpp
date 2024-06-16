#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

signed main(){
	Yuan_Berry
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	int ans = 1, cnt = 1;
	int nxt = -1;
	int curr = -1;
	for(int i = 0; i < n-1; i++){
		nxt = nums[i+1];
		curr = nums[i];
		if(curr > nxt) cnt++;
		else{
			
			cnt = 1;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}

