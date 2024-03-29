// https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve()
{
	int n, sm, mod = 1e9+7;
	cin>>n>>sm;
	ll v[n], dp[sm+1];
	for(auto &c:v) cin>>c;
	for(auto &c:dp) c=0;
	dp[0]=1;
	
	for(int i=1;i<=sm;i++)
		for(int j=0;j<n;j++)
			if(i-v[j]>=0)
				dp[i] = (dp[i] + dp[i-v[j]]) % mod;
	cout<<dp[sm];
}	
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	//cout.setf(std::ios::fixed); cout.precision(9);
	
    solve();
    //int t; cin>>t; while(t--){solve();}
    return 0;
}