#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

vector<pair<int,int>> moves = {{-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, 0}};

int r, c, move_times;

bool check(int y, int x){
	if(y > r-1 || y < 0 || x >= (r-y-1) + c || x < (r-y-1)) return false;
	return true;
}

signed main(){
	Yuan_Berry
	
	cin >> r >> c >> move_times;
	vector<string> mp;
	for(int i = r-1; i >= 0; i--){
		string pre;
		for(int j = 0; j < i; j++){
			pre.pb('-');
		}
		string req;
		cin >> req;
		mp.pb(pre+req);
	}
	set<char> s;
	int y = r-1, x = 0;
	while(move_times--){
		int op; cin >> op;
		int dy = y + moves[op].F;
		int dx = x + moves[op].S;
		if(check(dy, dx)){
			y = dy;
			x = dx;
		}
		cout << mp[y][x];
		s.insert(mp[y][x]);
	}
	cout << '\n';
	cout << s.size();
	
	return 0;
}

