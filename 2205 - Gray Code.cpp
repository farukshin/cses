// https://cses.fi/problemset/task/2205
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

int g (int n) {
	return n ^ (n >> 1);
}

int rev_g (int g) {
	int n = 0;
	for (; g; g>>=1)
		n ^= g;
	return n;
}

void print2(int k)
{
	for(int i=0;i<n;i++)
	{
		cout<<( k%2==1 ? 1:0);
		k/=2;
	}
	cout<<"\n";
}


void solve()
{
	int cur=0;
	cin>>n;
	
	for(int i=0;i<(1<<n);i++)
		print2(g(i));
	
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //cout.setf(std::ios::fixed); cout.precision(2);
    
	solve();
    //int t; cin >> t; while (t--) solve();

    return 0;
}