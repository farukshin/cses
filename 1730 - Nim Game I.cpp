// https://cses.fi/problemset/task/1730
#include <bits/stdc++.h>
using namespace std;
 
#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
typedef long long ll;
typedef long double ld;
 
void solve()
{
    int t, n, cur, ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0;
        while (n--)
        {
            cin >> cur;
            ans ^= cur;
        }
 
        cout << (ans ? "first" : "second") << endl;
    }
}
 
int main()
{
    ios_b;
#ifdef _DEBUG
    freopen("input-1.txt", "r", stdin);
    //freopen("output-1.txt", "w", stdout);
#endif
    solve();
    return 0;
}