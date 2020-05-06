#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 0, x = 0;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1, c = 0;

    while (i <= j)
    {
        if (a[j] + a[i] > x)
        {
            j--;
        }
        else
        {
            i++;
            j--;
        }
        c++;
    }

    cout << c << endl;
    return 0;
}