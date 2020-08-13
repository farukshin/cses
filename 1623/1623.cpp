//https://cses.fi/problemset/task/1623
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
    ll sum = 0, ans = INT_MAX;
    cin >> n;
    ll arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < 1 << n; i++)
    {
        ll curSum = 0;
        for (int j = 0; j < n; j++)
            if (i & 1 << j)
                curSum += arr[j];

        ll curr = abs((sum - curSum) - curSum);
        ans = min(ans, curr);
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
