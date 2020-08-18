//https://cses.fi/problemset/task/1752
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, d;
vector<vector<int>> ss;
vector<bool> used, curUsed;
stack<int> ans;
queue<pair<int, int>> q;

int getAnUsedCity(int n)
{
    for (int i = 1; i <= n; i++)
        if (!used[i])
            return i;
    return 0;
}

int dfsLastNode(int start)
{
    q.push({ start, 0 });

    fill(curUsed.begin(), curUsed.end(), false);
    curUsed[start] = true;
    int curDist = 0, lastNode = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (auto chield : ss[cur.first])
            if (!used[chield] && !curUsed[chield])
            {
                curUsed[chield] = true;
                q.push({ chield, cur.second + 1 });
                if (curDist < cur.second + 1)
                {
                    curDist = cur.second + 1;
                    lastNode = chield;
                }
            }
    }

    return lastNode;
}

void closeDistrict(int start, int curD = 0)
{
    if (curD > d || used[start])
        return;

    if (curD == 0)
        ans.push(start);

    used[start] = true;
    for (auto chield : ss[start])
        closeDistrict(chield, curD + 1);
}

void solve()
{
    cin >> n >> d;
    ss.resize(n + 1);
    used.resize(n + 1, false);
    curUsed.resize(n + 1, false);
    d--;

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        ss[a].push_back(b);
        ss[b].push_back(a);
    }

    int anUsedCity = getAnUsedCity(n);

    while (anUsedCity)
    {
        int last1 = dfsLastNode(anUsedCity);
        int last2 = dfsLastNode(last1);

        // if (last1 == 0 || last2 == 0)
        //     break;

        closeDistrict(last2);
        closeDistrict(last1);

        anUsedCity = getAnUsedCity(n);
    }

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
