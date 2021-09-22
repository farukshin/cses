//https://cses.fi/problemset/task/1732
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
    string s;
    cin >> s;

    int a = 0, b = 0;
    int n = s.size();
    vector<int> v(n), ans;
    for (int i = 1; i < n; i++)
    {
        v[i] = max(0, min(v[i - a], b - i));
        while (v[i] + i < n && s[v[i]] == s[v[i] + i])
            v[i]++;

        if (v[i] + i > b)
        {
            a = i;
            b = v[i] + i;
        }

        if (v[i] + i == n)
            ans.push_back(v[i]);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << endl;
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
