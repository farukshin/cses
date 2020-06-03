//https://cses.fi/problemset/task/1667
//#tech_debt
#include <bits/stdc++.h>
using namespace std;

#define ios_b                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;

vector<vector<int>> ss;
vector<bool> used;
bool succes = false;
int n, m;
stack<pair<int, int>> st;

void dfs(int node, int count)
{
    used[node] = true;

    if (node == n)
    {
        succes = true;
    }

    for (auto chield : ss[node])
        if (!used[chield] && !succes)
        {
            st.push({node, chield});
            dfs(chield, count + 1);
        }
}

void solve()
{
    cin >> n >> m;

    used.resize(n + 1);
    ss.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ss[a].push_back(b);
        ss[b].push_back(a);
    }

    st.push({1, 1});
    dfs(1, 0);

    if (!succes)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int cur = n;
    stack<int> ans;
    do
    {
        auto top = st.top();
        st.pop();
        if (top.second == cur)
        {
            ans.push(top.second);
            cur = top.first;
        }
    } while (cur != 1);
    ans.push(1);

    cout << ans.size() << endl;
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
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
