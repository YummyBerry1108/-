#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define Yuan_Berry ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long LL;
const int IN = 0, GATE = 1, OUT = 2;

int gate_result(vector<int> &input, int type){
	if(type == 1){
		return input[0] & input[1];
	}
	if(type == 2){
		return input[0] | input[1];
	}
	if(type == 3){
		return input[0] ^ input[1];
	}
	if(type == 4){
		return !input[0];
	}
}

signed main(){
	Yuan_Berry
	int input, gate, output, edges;
	cin >> input >> gate >> output >> edges;
	int total = input+gate+output;
	vector<pair<int,int>> nodes(total+1);
	vector<int> gates_type(total+1);
	int i = 1;
	vector<int> indegree(total+1, 0);
	
	// first -> type, second -> output
	for(i; i <= input; i++){
		int op; cin >> op;
		nodes[i] = {IN, op};
	}
	for(i; i <= input+gate; i++){
		int op; cin >> op;
		gates_type[i] = op;
		nodes[i] = {GATE, 0};
	}
	for(i; i <= input+gate+output; i++){
		nodes[i] = {OUT, 0};
	}
	
	// build graph
	vector<vector<int>> g(total+1);
	while(edges--){
		int u, v; 
		cin >> u >> v;
		indegree[v]++;
		g[u].pb(v);
	}
	
	queue<pair<int,int>> q;
	for(int i = 1; i <= total; i++){
		if(indegree[i] == 0){
			q.push({i, 0});
		}
	}
	
	// first -> index, second -> length
	int mx = 0;
	vector<vector<int>> gate_input(total+1);
	while(q.size()){
		pair<int,int> curr = q.front(); q.pop();
		for(auto node : g[curr.F]){
			indegree[node]--;
			if(nodes[node].F == OUT){
				mx = max(mx, curr.S);
				// some logic gates might not connect to output port
				nodes[node].S = nodes[curr.F].S;
			}
			else if(nodes[node].F == GATE){
				gate_input[node].pb(nodes[curr.F].S);
			}
			if(indegree[node] == 0){
				if(nodes[node].F == GATE){
					nodes[node].S = gate_result(gate_input[node], gates_type[node]);
				}
				q.push({node, curr.S+1});
			}
		}
	}
	cout << mx << '\n';
	for(int i = input+gate+1; i <= total; i++){
		cout << nodes[i].S << ' ';
	}
	return 0;
}

