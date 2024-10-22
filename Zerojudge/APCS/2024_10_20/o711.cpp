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
	int n;
	cin >> n;
	int w1, w2, h1 ,h2;
	cin >> w1 >> w2 >> h1 >> h2;
	int mx = 0;
	while(n--){
		int v;
		cin >> v;
		int res = 0;
		int dh1 = v / (w1*w1);
		if(h1 - dh1 >= 0 && h1){
			mx = max(mx, dh1);
			h1 = h1 - dh1;
		} 
		else{
			mx = max(mx, min(h1 + (v-h1*w1*w1)/(w2*w2), h1+h2));
			h1 = 0;
			h2 = h2 - min(h1 + (v-h1*w1*w1)/(w2*w2), h1+h2);
		}
	}
	cout << mx;
	return 0;
}
