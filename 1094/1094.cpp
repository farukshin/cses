#include <iostream>
using namespace std;

int main(){
    long long N = 0, i = 0;
    long long a = 0, prea = 0, k = 0;

    cin >> N;
    cin >> a;
    for (i=2; i<= N; i++){
        prea = a;
        cin >> a;
        if(prea > a){
            k += prea - a;
            a = prea;
        }
    }
    cout << k;
    return 0;
}