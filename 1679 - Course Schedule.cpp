// https://www.e-olymp.com/ru/problems/4019
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void dfs(const int node, vector<vector<int>> &ss, vector<int> &used, vector<int> &ans, bool &success)
{
    used[node] = 1;
    for (auto chield : ss[node])
    {
        if (used[chield] == 1)
            success = false;
 
        if (used[chield] == 0)
            dfs(chield, ss, used, ans, success);
    }
    used[node] = 2;
    ans.push_back(node);
}
 
void topologicSort(vector<vector<int>> &ss, vector<int> &ans, bool &success)
{
    auto n = ss.size();
    ans.clear();
    fill(ans.begin(), ans.end(), -1);
    success = true;
 
    vector<int> used(n, 0);
 
    for (int i = 0; i < n && success; i++)
        if (!used[i])
            dfs(i, ss, used, ans, success);
 
    reverse(ans.begin(), ans.end());
}
 
void solve()
{
    // cout.setf(std::ios::fixed);
    // cout.precision(2);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> ss(n);
    vector<int> ans(n);
    bool success;
 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ss[a].push_back(b);
    }
 
    topologicSort(ss, ans, success);
 
    if (!success)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
 
    for (auto s : ans)
        cout << s + 1 << " ";
    cout << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
 
#ifdef _DEBUG
    freopen("input-1.txt", "r", stdin);
    //freopen("output-1.txt", "w", stdout);
#endif
 
    solve();
    //int t; cin >> t; while(t--) solve();
 
    return 0;
}