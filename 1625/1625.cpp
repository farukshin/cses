//https://cses.fi/problemset/task/1625
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

int ans = 0;
string s;

struct at
{
    int x;
    int y;
    int step;
};

void dfs(at st)
{
    ;
}

void solve()
{
    cin >> s;
    stack<int> st;
    dfs(at{0, 0, 0});
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
