//https://cses.fi/problemset/task/1752
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, d;
vector<vector<int>> ss;
vector<bool> used;
stack<int> ans;
map<int, int> freeLeaves;

void closeDistrict(int start, int curD = 0)
{
    if (curD > d)
        return;

    if (curD == 0)
        ans.push(start);

    used[start] = true;

    freeLeaves[start]--;
    if (freeLeaves[start] == 0)
        freeLeaves.erase(start);

    for (auto chield : ss[start])
        closeDistrict(chield, curD + 1);
}

void updateLeaves(int node)
{
    if (!freeLeaves[node]) {
        if (ss[node].size() == 1)
            freeLeaves[node]++;
    }
    else {
        if (ss[node].size() != 1)
            freeLeaves.erase(freeLeaves.find(node));
    }
}

int minCountFreeCity(int start, int curD)
{

    if (curD > d)
        return 0;

    int res = 1;

    for (auto chield : ss[start])
        res += (used[chield] ? 1 : 0) + minCountFreeCity(chield, curD + 1);

    return res;
}

int bestCity()
{
    int res = 0, minCount = n;
    for (auto node : freeLeaves)
    {
        int cur = minCountFreeCity(node.first, 0);
        if (cur < minCount)
            minCount = cur, res = node.first;
    }
    return res;
}

void solve()
{
    cin >> n >> d;
    ss.resize(n + 1);
    used.resize(n + 1, false);
    d--;

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        ss[a].push_back(b);
        ss[b].push_back(a);
        updateLeaves(a);
        updateLeaves(b);
    }

    while (!freeLeaves.empty())
        closeDistrict(bestCity());

    cout << ans.size() << endl;
    while (!ans.empty())
    {
        int cur = ans.top();
        ans.pop();
        cout << cur << (ans.empty() ? "\n" : " ");
    }
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
