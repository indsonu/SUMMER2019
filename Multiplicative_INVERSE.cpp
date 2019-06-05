#include <iostream>
using namespace std;
const long long int MOD=1000000007;
long long modInverse(long long int a) {
  a = a % MOD;
  for (auto x = 1; x < MOD; x++)
    if (((a%MOD)*(x%MOD)) % MOD == 1)
      return x;
    
    return 0;
}

// Driver Program
int main() {
  long long int a;
  cin>>a;
  cout << modInverse(a);
  return 0;
}
