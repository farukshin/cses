// https://cses.fi/problemset/task/1145
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
 
    vector<int> ans;
 
    while (n--)
    {
        int cur;
        cin >> cur;
        auto it = lower_bound(ans.begin(), ans.end(), cur);
        if (it == ans.end())
            ans.push_back(cur);
        else
            *it = cur;
    }
    cout << ans.size() << endl;
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