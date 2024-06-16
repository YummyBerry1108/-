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
	int h, w, n;
	cin >> h >> w >> n;
	vector<vector<int>> array(h, vector<int>(w, 0));
	while(n--){
		int r, c, t, x;
		cin >> r >> c >> t >> x;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(abs(r-i) + abs(c-j) <= t) array[i][j] += x;
			}
		}
	}
	for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cout << array[i][j] << ' ';
			}
			cout << '\n';
		}
	return 0;
}

