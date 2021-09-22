// https://cses.fi/problemset/task/1093
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 1e9+7;

void solve()
{
	int n;
	cin>>n;
	
	int sum = n*(n+1)/2;
	if(sum%2) {cout<<0;return;}
	sum/=2;
	
	int dp[n][sum+1];
	memset(dp, 0, sizeof dp);
	
	dp[0][0] = 1;
	for(int i=1;i<n;i++)
		for(int j=0;j<=sum;j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j-i>=0)
				(dp[i][j] += dp[i-1][j-i]) %= mod;
		}
	
	cout<<dp[n-1][sum];
	
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	//cout.setf(std::ios::fixed); cout.precision(9);
	
    solve();
    //int t; cin>>t; while(t--){solve();}
    
    return 0;
}