#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, c = 0;
    while (i < n && j < m)
    {
        if (a[i] + k < b[j])
            i++;
        else if (a[i] - k > b[j])
            j++;
        else
        {
            i++;
            j++;
            c++;
        }
    }
    cout << c << endl;

    return 0;
}