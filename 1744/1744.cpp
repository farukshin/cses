// https://cses.fi/problemset/task/1744
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve()
{
	int n,m;
	cin>>n>>m;
	int dp[n+1][m+1];

	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if(i==j)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = INT_MAX;
				for(int k=1;k<i;k++)
					dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] +1);
				for(int k=1;k<j;k++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] +1);
			}

	cout<<dp[n][m];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	//cout.setf(std::ios::fixed); cout.precision(9);

    solve();
    //int t; cin>>t; while(t--){solve();}
    return 0;
}
