#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+5;

// 


vector<int> primes;
int n, k;
void gen_primes(){
	vector<bool> is_prime(N, true);
	is_prime[1] = true;
	for(int i = 2; i*i <= N; i++){
		if(!is_prime[i]) continue;
		
		int temp = i*i;
		while(temp <= N){
			is_prime[temp] = false;
			temp += i; 
		} 
	}
	for(int i = 2; i<=N; i++){
		if(is_prime[i] && i >= k) primes.push_back(i);
	}
	
}

signed main()
{
	cin >> n >> k;
	gen_primes();
	
	
	int mn = 1e18+5;
	int mx = 0;
	int sum = 0;
	vector<int> nums(n);
//	for(int i = 0; i < n; i++){
//	 	cin >> nums[i];
//	 	mx = max(mx, nums[i]);
//	 	sum += nums[i];
//	} 
	int i = 0;
	while(primes[i] <= n){
		nums[i] = primes[i];
		mx = max(mx, nums[i]);
		sum += nums[i];
		i++;
	}
	
//	cout << "sum : " << sum << '\n';
	i=0;
	
	while(primes[i] <= mx){
		int p = primes[i];
//		cout << p << ' ';
		int temp = 0;
		for(int j = 0; j < n; j++){
			temp += nums[j]%p;
//			if(temp >= mn) break;
		}
//		cout << temp << ' ';
		mn = min(mn, temp);
		i++;
		cout << "k=" << p << " : " << temp << '\n';
	}
	cout << sum-mn;
	 
	return 0;
}

