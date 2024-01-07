#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.F*a.F+a.S*a.S > b.F*b.F+b.S*b.S;
}

signed main(){
	Yuan_Berry
	int n; cin >> n;
	vector<pair<int,int>> temp;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		temp.pb({a, b});
	}
	sort(temp.begin(), temp.end(), cmp);
	cout << temp[1].F << ' ' << temp[1].S;
	return 0;
}

