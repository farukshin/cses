// https://cses.fi/problemset/task/2183
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve()
{
	int n;
	cin>>n;
	vector<ll> v(n), sm(n, 0);
	//bool ans[1000000];
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(begin(v), end(v));
	
	sm[0] = v[0];
	for(int i=1;i<n;i++)
		sm[i] = sm[i-1] + v[i];
	
	// for(int i=0;i<n;i++)
	// 	cout<<v[i]<<" ";
	// cout<<"\n";
	// for(int i=0;i<n;i++)
	// 	cout<<sm[i]<<" ";
	// cout<<"\n";
	
	int pos = 1;
	for(;pos<n;pos++)
		if(sm[pos-1] +1 < v[pos])
			break;
		
	if(v[0]!=1)
		cout<<1;
	else if(pos!=n)
		cout<<sm[pos-1]+1;
	else 
		cout<<sm[n-1]+1;
}	
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	//cout.setf(std::ios::fixed); cout.precision(9);
	
    solve();
    //int t; cin>>t; while(t--){solve();}
    return 0;
}