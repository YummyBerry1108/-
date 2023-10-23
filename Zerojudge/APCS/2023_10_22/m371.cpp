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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> cards(n, vector<int>(m));
	vector<vector<bool>> used(n, vector<bool>(m, false));
	unordered_map<int, vector<pair<int,int>>> ump;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> cards[i][j];
			ump[cards[i][j]].pb({i, j});
		}
	}
	
	int times = 405;
	int ans = 0;
	while(times--){
		for(auto v : ump){
			
			int y1 = v.S[0].F;
			int x1 = v.S[0].S;
			int y2 = v.S[1].F;
			int x2 = v.S[1].S;
			
			if(used[y1][x1] || used[y2][x2]) continue;
			bool flag = false;
			if(y1 == y2){
				for(int i = min(x1,x2)+1; i < max(x1,x2) && !flag; i++){
					if(!used[y1][i]) flag = true;
				}
			}
			else if(x1 == x2){
				for(int i = min(y1,y2)+1; i < max(y1,y2) && !flag; i++){
					if(!used[i][x1]) flag = true;
				}
			}
			else flag = true;
			if(!flag){
				ans += cards[y1][x1];
				used[y1][x1] = true;
				used[y2][x2] = true;
			}
		}
		
	}
	cout << ans;
	return 0;
}

