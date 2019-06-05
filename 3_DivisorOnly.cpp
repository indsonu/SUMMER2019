#include <bits/stdc++.h> // MAIN LOGIC IS THAT THERE IS A NO. WHOSE SQUARE ROOT IS A PRIME THEN IT WILL DEFINITELY HAVE 3 DIVISORS
using namespace std; 
bool isPrime(int n) 
{ 
    if(n<=1){
        return false;// BOUNDARY AND VERY IMPORTANT (case)
    }
    if (n <= 3) 
        return true; 
    for (int i = 2; i * i <= n; i++) 
        if (n % i == 0) 
            return false; 
    return true; 
} 
bool isThreeDisctFactors(long long n) 
{ 
    int sq = (int)sqrt(n); 
    if (1LL * sq * sq != n) 
        return false; 
    return isPrime(sq) ? true : false; 
}
int main() 
{ 
    long long int n;
    cin>>n;
    long long int a[n];
    for(auto i=0;i<n;i++){
        cin>>a[i];
    }
    for(auto i=0;i<n;i++){
        if(isThreeDisctFactors(a[i])){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0; 
} 
