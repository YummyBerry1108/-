#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

unordered_map<char, vector<pair<int,int>>> movement;
vector<string> mp;
vector<vector<bool>> visited;
int n, m;

int BFS(int x, int y){
//	char temp = mp[y][x];
	int cnt = 1;
//	mp[y][x] = '0';
	queue<pair<int,int>> q;
	visited[y][x] = true;
	q.push({y, x});
	while(!q.empty()){
		int x = q.front().S, y = q.front().F; 
		q.pop();
//		cout << y << ' ' << x << '\n';
		char temp = mp[y][x];
		
		for(auto p : movement[temp]){
			if(x+p.F >= 0 && x+p.F < m && y+p.S >= 0 && y+p.S < n && mp[y+p.S][x+p.F] != '0' && !visited[y+p.S][x+p.F]){
				char next = mp[y+p.S][x+p.F];
				if(p == make_pair(1, 0) && (next == 'X' || next == 'H' || next == '7' || next == 'J')){
					q.push({y+p.S, x+p.F});
					visited[y+p.S][x+p.F] = true;
					cnt++;
				}
				else if(p == make_pair(-1, 0) && (next == 'X' || next == 'H' || next == 'L' || next == 'F')){
					q.push({y+p.S, x+p.F});
					visited[y+p.S][x+p.F] = true;
					cnt++;
				}
				else if(p == make_pair(0, -1) && (next == 'X' || next == 'I' || next == '7' || next == 'F')){
					q.push({y+p.S, x+p.F});
					visited[y+p.S][x+p.F] = true;
					cnt++;
				}
				else if(p == make_pair(0, 1) && (next == 'X' || next == 'I' || next == 'L' || next == 'J')){
					q.push({y+p.S, x+p.F});
					visited[y+p.S][x+p.F] = true;
					cnt++;
				}
			}
		}
	}
//	cout << y << ' ' << x << '\n';
	
	return cnt;
}

signed main(){
	Yuan_Berry
	movement['X'] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	movement['I'] = {{0, 1}, {0, -1}};
	movement['H'] = {{1, 0}, {-1, 0}};
	movement['F'] = {{1, 0}, {0, 1}};
	movement['7'] = {{-1, 0}, {0, 1}};
	movement['L'] = {{1, 0},{0, -1}};
	movement['J'] = {{-1, 0}, {0, -1}};
	movement['0'] = {};
	
	
	cin >> n >> m;
	mp.resize(n);
	visited.resize(n);
	for(int i = 0; i < n; i++){
		visited[i].resize(m, false);
		cin >> mp[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mp[i][j] == '0') continue;
			ans = max(ans, BFS(j, i));
		}
	}
	cout << ans;
	return 0;
}

