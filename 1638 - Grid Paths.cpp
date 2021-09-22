// https://cses.fi/problemset/task/1638
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
const int MOD = 1e9+7;

void solve()
{
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	vector<vector<ll>> dp(n, vector<ll>(n,0));
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(j==0 && i==0)
				dp[0][0]= (v[i][j]=='.' ? 1 : 0);
			else if(j==0)
				dp[i][j] = (v[i][j]=='.' ? dp[i-1][j] : 0)%MOD;
			else if(i==0)
				dp[i][j] = (v[i][j]=='.' ? dp[i][j-1] : 0)%MOD;
			else
				dp[i][j] = (v[i][j]=='.' ? dp[i][j-1] + dp[i-1][j] : 0)%MOD;
		}
	cout<<dp[n-1][n-1];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //cout.setf(std::ios::fixed); cout.precision(2);
    
	solve();
    //int t; cin >> t; while (t--) solve();

    return 0;
}