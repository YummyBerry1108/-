#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.S == b.S) return a.F < b.F;
	else return a.S < b.S;
}

int n, m, p, ans = 0;
vector<pair<int,int>> busRange;
vector<int> ways;

int checkl(int x, int i){
	if(busRange[x].S >= busRange[i].F) return x;
	else return -1;
}
int checkr(int x, int i){
	if(busRange[x].S < busRange[i].S) return x;
	else return -1;
}

signed main(){
	Yuan_Berry
	
	cin >> n >> m >> p;
	busRange.resize(n);
	ways.resize(n+1);
	
	for(int i = 0; i < n; i++){
		cin >> busRange[i].F;
	}
	for(int i = 0; i < n; i++){
		cin >> busRange[i].S;
	}
	sort(busRange.begin(), busRange.end(), cmp);
	for(int i = 0; i < n; i++){
		if(busRange[i].F == 0) ways[i+1] = 1;
		
		int l = 0, r = i, idl = -1, idr = -1;
		while(l <= r){
			if(l == r){
				idl = checkl(r, i);
				break; 
			}
			if(l == r-1){
				idl = checkl(l, i);
				if(idl != -1) break;
				idl = checkl(r, i);
				break;
			}
			int mid = (l+r)/2;
			idl = checkl(mid, i);
			if(idl == -1) l = mid+1;
			else r = mid;
		}
		if(idl == -1) continue;
		l = 0; 
		r = i;
		while(l <= r){
			if(l == r){
				idr = checkr(r, i);
				break; 
			}
			if(l == r-1){
				idr = checkr(r, i);
				if(idr != -1) break;
				idr = checkr(l, i);
				break;
			}
			int mid = (l+r)/2;
			idr = checkr(mid, i);
			if(idr == -1) r = mid-1;
			else l = mid;
		}
		if(idr == -1) continue;
		ways[i+1] += ((ways[idr+1]-ways[idl])%p+ways[i]);
	}
	for(int i = 0; i < n; i++){
		if(busRange[i].S == m){
			ans = (ans+ways[i+1]-ways[i])%p;
		} 
	}
	cout << ans;
	
	return 0;
}
