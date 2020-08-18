//https://cses.fi/problemset/task/1630
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct task
{
    int duration;
    int deadline;
};

void solve()
{
    int n;
    cin >> n;
    vector<task> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i].duration >> arr[i].deadline;

    sort(arr.begin(), arr.end(), [](task a, task b) { return a.duration < b.duration; });

    ll curTime = 0, ans = 0;
    for (auto task : arr)
        ans += task.deadline - (task.duration + curTime), curTime += task.duration;

    cout << ans << endl;
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
