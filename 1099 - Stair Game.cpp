// https://cses.fi/problemset/task/1099
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, cur;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> cur;
            if (i & 1)
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