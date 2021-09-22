//https://cses.fi/problemset/task/1070
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
    int n;
    cin >> n;

    if (n < 4)
    {
        cout << (n == 1 ? "1" : "NO SOLUTION") << endl;
        return;
    }

    for (int i = 2; i <= n; i += 2)
        cout << i << " ";
    for (int i = 1; i <= n; i += 2)
        cout << i << " ";
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
