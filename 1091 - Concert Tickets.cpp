#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, m = 0, x = 0;
    cin >> n >> m;
    multiset<int, greater<int>> h;
    while (n--)
    {
        cin >> x;
        h.insert(x);
    }
    while (m--)
    {
        cin >> x;
        auto it = h.lower_bound(x);
        if (it == h.end())
            cout << "-1\n";
        else
        {
            cout << *it << endl;
            h.erase(it);
        }
    }

    return 0;
}