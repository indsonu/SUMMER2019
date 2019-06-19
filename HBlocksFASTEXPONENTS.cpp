#include <iostream>
using namespace std;
void Fast(long long int a,long long int b,long long int c){
    unsigned long long int ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a)%c;
        }
        b=b>>1;
        a=(a*a)%c;
    }
    cout<<ans;
}
int main() {
    long long int a,b,c;
    cin>>a>>b>>c;
    Fast(a,b,c);
	return 0;
}
