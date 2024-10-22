#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;
int m, n, q;
int blocks = 0;
int mp[505][505], visited[505][505];
vector<pair<int,int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pair<int,int> start;

bool check(int r, int c){
	if(r < 0 || c < 0 || r >= m || c >= n || mp[r][c] == -1) return false;
	else return true;
}

void bomb(pair<int,int> pos, int r){
	mp[pos.F][pos.S] = 0;
	queue<pair<pair<int,int>, int>> que;
	// pos x, pos y, radius
	map<pair<int,int>, int> selfump;
	que.push({pos, r});
	while(que.size()){
		pair<pair<int,int>, int> curr = que.front();
		que.pop();
		
		if(!visited[curr.F.F][curr.F.S]){
			blocks++;
			visited[curr.F.F][curr.F.S] = true;
		} 

		if(blocks >= q) break;
		if(mp[curr.F.F][curr.F.S] > 0) bomb({curr.F.F, curr.F.S}, mp[curr.F.F][curr.F.S]);
		if(curr.S == 0) continue;
		for(int dir = 0; dir < 4; dir++){
			int nr = curr.F.F + moves[dir].F;
			int nc = curr.F.S + moves[dir].S;
			if(!check(nr, nc) || selfump[{nr, nc}]) continue;
			que.push({{nr, nc}, curr.S - 1});
			selfump[{nr, nc}] = true;
		}
	}
}

signed main(){
	Yuan_Berry
	cin >> m >> n >> q;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> mp[i][j];
			if(mp[i][j] == -2){
				start = {i, j};
			}
		}
	}
	
	int ans = 1;
	map<pair<int,int>, int> selfump;
	queue<pair<pair<int,int>, int>> que;
	que.push({start, 0});
	while(que.size()){
		pair<pair<int,int>, int> curr = que.front();
		que.pop();
		
		ans = max(ans, curr.S);
		if(!visited[curr.F.F][curr.F.S]){
			blocks++;
			visited[curr.F.F][curr.F.S] = true;
		} 
		
		if(mp[curr.F.F][curr.F.S] > 0) bomb({curr.F.F, curr.F.S}, mp[curr.F.F][curr.F.S]);
		if(blocks >= q) break;
		for(int dir = 0; dir < 4; dir++){
			int nr = curr.F.F + moves[dir].F;
			int nc = curr.F.S + moves[dir].S;
			if(!check(nr, nc) || selfump[{nr, nc}]) continue;
			que.push({{nr, nc}, curr.S+1});
			selfump[{nr, nc}] = true;
		}
	}
	cout << ans;
	return 0;
}
