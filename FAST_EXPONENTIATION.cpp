#include<iostream>
using namespace std;
#define MOD 1000000007
void fast(long long int n){
    long long int ans=1;//   HERE I M JUST TAKING BASE AS 2
    long long int b=2;
    while(n>0){
        if(n&1){
            ans=(ans*b)%MOD;
        }
        n=n>>1;
        b=(b*b)%MOD;
    }
    cout<<((ans%MOD)*(10%MOD))%MOD<<"\n";
}
int main(){
    long long int t,k;
    cin>>t;
    while(t--){
        cin>>k;
        fast(k-1);
    }
}
