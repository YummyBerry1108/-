#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;

string charSet;
int n;
string s;
unordered_map<string, bool> ump;

string dfs(string s){
//	cout << s << '\n';
	if(s.size() == n){
		if(!ump[s]) return s;
		else return "0";
	} 
	for(auto c : charSet){
		s += c;
		string res = dfs(s);
		if(res != "0") return res;
		s.pop_back();
	}
	return "0";
}

signed main(){
	Yuan_Berry
	cin >> charSet;
	cin >> n;
	cin >> s;
	
	int len = s.size();
	for(int i = 0; i < len-n+1; i++){
//		cout << s.substr(i, n) << '\n';
		ump[s.substr(i, n)] = true;
	}
	cout << dfs("");
	
	
	return 0;
}

