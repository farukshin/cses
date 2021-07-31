// https://cses.fi/problemset/task/2216
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve()
{
	int n;
	cin>>n;
	vector<pair<ll, int>> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first;
		v[i].second = i+1;
	}
	sort(begin(v), end(v));

	// for(int i=0;i<n;i++)
	// 	cout<<v[i].first<<" ";
	// cout<<"\n";
	// for(int i=0;i<n;i++)
	// 	cout<<v[i].second<<" ";
	// cout<<"\n";

	int cur = v[0].second;
	ll ans = 1;
	for(int i=1;i<n;i++)
	{
		if(cur>v[i].second)
			ans++;
		cur = v[i].second;
	}

	cout<<ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	//cout.setf(std::ios::fixed); cout.precision(9);

    solve();
    //int t; cin>>t; while(t--){solve();}
    return 0;
}
