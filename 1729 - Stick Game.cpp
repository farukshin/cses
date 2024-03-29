// https://cses.fi/problemset/task/1729
#include <bits/stdc++.h>
using namespace std;
 
#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
typedef long long ll;
typedef long double ld;
 
const int MAXARR = 1e6 + 5;
int ans[MAXARR];
 
void solve()
{
    int n, k;
    cin >> n >> k;
 
    vector<int> moves(k);
    ans[0] = 0;
 
    for (int i = 0; i < k; i++)
        cin >> moves[i];
 
    for (int i = 1; i <= n; i++)
    {
        int flag = false;
        for (int j = 0; j < k; j++)
            if (i - moves[j] >= 0 && !ans[i - moves[j]])
            {
                flag = true;
                break;
            }
        ans[i] = (flag ? 1 : 0);
    }
 
    for (int i = 1; i <= n; i++)
        cout << (ans[i] ? 'W' : 'L');
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