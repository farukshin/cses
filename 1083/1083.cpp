#include <iostream>
using namespace std;
int main() {
  int n, x, i;
  cin>>n;
  long sum=0;
  for (i=0; i<n-1; i++) {
    cin>>x;
    sum+=x;
  }
  cout<<long(n)*(n+1)/2-sum<<endl;
}