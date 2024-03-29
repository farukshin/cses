// https://cses.fi/problemset/task/1197/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct edge {
	int a, b;
	ll cost;
};
 
int n, m;
vector<edge> e;
const ll INF = 1000000000000000;

void solve()
{
	cin>>n>>m;
	e.resize(m);
	for(auto &d:e)
	{
		cin>>d.a>>d.b>>d.cost;
		--d.a,--d.b;
	}
	
	vector<ll> d (n);
	vector<int> p (n, -1);
	int x;
	for (int i=0; i<n; ++i) {
		x = -1;
		for (int j=0; j<m; ++j)
			if (d[e[j].b] > d[e[j].a] + e[j].cost) {
				d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
				p[e[j].b] = e[j].a;
				x = e[j].b;
			}
	}
 
	if (x == -1)
		cout << "NO";
	else {
		int y = x;
		for (int i=0; i<n; ++i)
			y = p[y];
 
		vector<int> path;
		for (int cur=y; ; cur=p[cur]) {
			path.push_back (cur);
			if (cur == y && path.size() > 1)  break;
		}
		reverse (path.begin(), path.end());
 
		cout << "YES\n";
		for (size_t i=0; i<path.size(); ++i)
			cout << path[i]+1 << ' ';
	}
}

int main()
{
    //ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    solve();
    //int t; cin >> t; while(t--) solve();

    return 0;
}