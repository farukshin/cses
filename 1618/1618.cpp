#include <iostream>
using namespace std;

int main()
{
    long long n = 0, res = 0;
    cin >> n;

    while (n > 0)
    {
        n /= 5;
        res += n;
    }
    cout << res << endl;
    return 0;
}