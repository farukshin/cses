// https://cses.fi/problemset/task/1631
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void solve()
{
    int n;
    cin >> n;
    ll sum = 0, mx = 0;
    while (n--)
    {
        ll cur;
        cin >> cur;
        mx = max(cur, mx);
        sum += cur;
    }
 
    cout << (mx > (sum - mx) ? 2 * mx : sum) << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
 
#ifdef _DEBUG
    freopen("input-1.txt", "r", stdin);
    //freopen("output-1.txt", "w", stdout);
#endif
 
    solve();
    //int t; cin >> t; while(t--) solve();
 
    return 0;
}