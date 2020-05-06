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
    int n, a, b, cur = 0, ans = 0;
    vector<pair<int, int>> v;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(), v.end());
    for (auto mov : v)
    {
        if (mov.second >= cur)
        {
            cur = mov.first;
            ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_b;
    solve();
    return 0;
}