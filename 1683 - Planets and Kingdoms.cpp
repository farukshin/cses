// https://cses.fi/problemset/task/1683
#include <bits/stdc++.h>
using namespace std;
 
#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
typedef long long ll;
typedef long double ld;
 
const int MAXN = 2e5 + 5;
vector<int> forwrd[MAXN], back[MAXN], fw, bc;
vector<bool> used;
 
int korolevstvo[MAXN];
 
void dfs(int v)
{
    used[v] = true;
    for (auto chield : forwrd[v])
        if (!used[chield])
            dfs(chield);
 
    fw.push_back(v);
}
 
void dfs2(int v)
{
    used[v] = true;
    bc.push_back(v);
    for (auto chield : back[v])
        if (!used[chield])
            dfs2(chield);
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        forwrd[a].push_back(b);
        back[b].push_back(a);
    }
 
    used.assign(n + 1, false);
 
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs(i);
 
    used.assign(n + 1, false);
 
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int v = fw[n - 1 - i];
        if (used[v])
            continue;
 
        dfs2(v);
 
        ans++;
        for (int j : bc)
            korolevstvo[j] = ans;
 
        bc.clear();
    }
 
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << korolevstvo[i] << (i == n ? "\n" : " ");
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