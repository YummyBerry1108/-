#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;
int n, k;
vector<int> nums;
signed main(){
	Yuan_Berry
	
	cin >> n >> k;
	nums.resize(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	unordered_map<int, set<int>> ump;
	
	int ans = 0;
	int preSum = 0, preCnt = 0; 
	for(int i = 0; i < n; i++){
		// suffix preprocessing
		preSum += nums[i];
		if(nums[i] % 2 == 1) preCnt--;
		else preCnt++;
	}
	if(preCnt == 0 && preSum <= k) ans = preSum;
	
	int sufSum = 0, sufCnt = 0;
	for(int i = n-1; i >= 0; i--){
		// suffix preprocessing
		sufSum += nums[i];
		if(nums[i] % 2 == 1) sufCnt--;
		else sufCnt++;
		ump[sufCnt].insert(-sufSum);
		
		// prefix preprocessing
		preSum -= nums[i];
		if(nums[i] % 2 == 1) preCnt++;
		else preCnt--;
		
		auto iter = ump[-preCnt].lower_bound(-(k-preSum));
		if(iter == ump[-preCnt].end()){
//			cout << "not found ";
		} 
		else{
			ans = max(ans, -(*iter) + preSum);
		}
//		cout << *iter << '\n';
		
	}
	cout << ans;
	return 0;
}

