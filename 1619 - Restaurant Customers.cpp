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
    int n, a, b, cur, ans = 0;
    vector<pair<int, bool>> v;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, true));
        v.push_back(make_pair(b, false));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cur += v[i].second ? 1 : -1;
        ans = max(ans, cur);
    }
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
