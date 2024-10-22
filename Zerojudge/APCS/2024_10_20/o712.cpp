#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

typedef long long LL;

const int L = 2, R = 0, U = 3, D = 1;
vector<pair<int,int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int m, n, k, r, c, score = 0, ans = 0, dir = R;
pair<int,int> curr;
vector<vector<int>> mp;

void move(){
	int nr, nc;
	while(true){
		nr = r + moves[dir].F;
		nc = c + moves[dir].S;
		if(nr >= m || nr < 0 || nc >= n || nc < 0 || mp[nr][nc] == -1) dir = (dir+1)%4;
		else break;
	}
	r = nr;
	c = nc;
}

signed main(){
	Yuan_Berry
	
	cin >> m >> n >> k >> r >> c;
	curr.F = r;
	curr.S = c;
	mp.resize(m);

	
	for(int i = 0; i < m; i++){
		mp[i].resize(n);
		for(int j = 0; j < n; j++){
			cin >> mp[i][j];
		}
	}
	
	while(true){
		if(mp[r][c] == 0) break;
		score += mp[r][c];
		mp[r][c]--;
		ans++;
		if(score%k == 0) dir = (dir+1)%4;
		move();
	}
	cout << ans;
	return 0;
}

