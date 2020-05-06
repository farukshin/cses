#include <iostream>

using namespace std;

const int mod = 1000000007;

int pow(int a, int W, int m){
    
    int V = 0;
    long long S = 1, c = a;
    
    V = W;
    c = a;
    while(V != 0){
        if (V%2 != 0){
            S = (S * c) % m;            
        }
        c = (c * c) % m;
        V >>= 1;
    }
    return S;
}

int main(){
    int W = 0;
    
    cin >> W;
    cout << pow(2, W, mod) << endl;
    
    return 0;
}