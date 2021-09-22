//https://cses.fi/problemset/task/1687
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

const int MAXARR = 2e5 + 5;
int ans[MAXARR][20];

void solve()
{
    int n, q;
    cin >> n >> q;

    memset(ans, -1, sizeof(ans));

    int cur;
    for (int i = 2; i <= n; i++)
    {
        cin >> cur;
        ans[i][0] = cur;
    }

    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= n; i++)
            if (ans[i][j - 1] != -1 && ans[ans[i][j - 1]][j - 1] != -1)
                ans[i][j] = ans[ans[i][j - 1]][j - 1];

    while (q--)
    {

        int up;
        cin >> cur >> up;

        for (int i = 19; i >= 0; i--)
            if ((1 << i) & up && cur != -1)
                cur = ans[cur][i];

        cout << cur << endl;
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
