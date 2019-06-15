//   CODECHEF Q4 ON JUNE COMPITITION
#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
#define ll long long int
ll inv(ll n, ll m) {
    vector<ll> modInverse(n + 1,0);
    modInverse[1] = 1;
    for(ll i = 2; i <= n; i++) {
        modInverse[i] = (-(m/i) * modInverse[m % i]) % m + m;
    }
    return modInverse[n];
}

int main(){
    int t;
    ll ans,diff,n,n5,k1;
    cin>>t;
    while(t--){
        cin>>n>>k1;
        ans=0;
        if(n>=k1){
        cout<<(k1-1)%MOD<<"\n";
        }
        else{
            n5=(k1-1)/(n-1);
            n5++;
            ans=((k1-1)+(k1-1)%(n-1));
            ans=((ans%MOD)*(n5%MOD))%MOD;
            ans=((ans%MOD)*(inv(2,MOD)%MOD))%MOD; 
            cout<<ans<<"\n";
        }
    }
}
