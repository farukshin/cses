// https://cses.fi/problemset/task/1097
#include <bits/stdc++.h>
using namespace std;
 
#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
typedef long long ll;
typedef long double ld;
 
const int MAXARR = 5e3 + 5;
ll user1[MAXARR][MAXARR];
ll user2[MAXARR][MAXARR];
 
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> user1[0][i];
 
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
        {
            ll maxScore = user1[0][j] + user1[i - 1][j + 1] + user2[i - 1][j + 1];
            user1[i][j] = max(user1[0][j] + user2[i - 1][j + 1], user1[0][j + i] + user2[i - 1][j]);
            user2[i][j] = maxScore - user1[i][j];
        }
 
    cout << user1[n - 1][0] << endl;
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