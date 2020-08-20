//https://cses.fi/problemset/task/1753
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve()
{
    string s, pattern;
    cin >> s >> pattern;

    int ans = 0, cur = 0, lenPattern = pattern.length();
    if (lenPattern > s.length())
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.length() - lenPattern + 1; i++)
        for (int j = 0; j < lenPattern; j++)
            if (s[i + j] == pattern[j] && j == lenPattern - 1)
                ans++;
            else if (s[i + j] != pattern[j])
                break;

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
