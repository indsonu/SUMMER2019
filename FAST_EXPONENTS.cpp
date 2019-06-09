#include<iostream>
using namespace std;
long long int MOD=1000000007;
void fast(int n,int k){
    int res=1;
    while(k>1){
        if(k%2!=0){
            res=((res%MOD)*(n%MOD))%MOD;
        }
        n=((n%MOD)*(n%MOD))%MOD;
        k/=2;
    }
    cout<<((res%MOD)*(n%MOD))%MOD;
}
int main(){
    // FAST EXPONENTIATION
    int n,k;
    cin>>n>>k;
    fast(n,k);
}
