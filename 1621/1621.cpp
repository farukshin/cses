#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n=0, x=0;
    map <int, int> a;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[x]++;
    }
    cout << a.size() << endl;
    return 0;
}