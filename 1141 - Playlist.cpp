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
    int n, a = 0, b = 0, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    set<int> s;
    while (b < n)
    {
        if (s.count(v[b]))
        {
            ans = max(ans, b - a);
            while (v[a] != v[b])
            {
                s.erase(v[a++]);
            }
            a++;
        }
        else
            s.insert(v[b]);
        b++;
    }
    ans = max(ans, b - a);
    cout << ans << endl;
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
