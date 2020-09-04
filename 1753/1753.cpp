//https://cses.fi/problemset/task/1753
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void zFunction(const string s, vector<int>& z)
{
    int n = (int)s.length();
    z.resize(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

void solve()
{
    string text, pattern;
    cin >> text >> pattern;

    vector<int> z;
    zFunction(pattern + '$' + text, z);

    int ans = 0;
    for (int i = 0; i <= (int)text.length() - 1; i++)
        if (z[i + (int)pattern.length() + 1] == (int)pattern.length())
            ans++;

    cout << ans << endl;
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
