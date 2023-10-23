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
	int x, n;
	cin >> x >> n;
	vector<int> l, r;
	int lmin = 200, rmax = -200;
	while(n--){
		int temp; cin >> temp;
		if(temp < x){
			l.pb(temp);
			lmin = min(lmin, temp);
		}
		else{
			r.pb(temp);
			rmax = max(rmax, temp);
		}
	}
	if(l.size() < r.size()){
		cout << r.size() << ' ' << rmax;
	}
	else{
		cout << l.size() << ' ' << lmin;
	}
	return 0;
}

