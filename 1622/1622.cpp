//https://cses.fi/problemset/task/1622
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
    vector<string> v;

    cin >> s;

    sort(s.begin(), s.end());
    do
    {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << v.size() << endl;
    for (string s : v)
        cout << s << endl;
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
