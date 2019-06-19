#include <iostream>
#include<math.h>
using namespace std;
long int Fast(int n,int k){
    if(k==0){
        return 1;
    }
    else if(k==1){
        return n;
    }
    long int R=pow(n,k/2); //  ACTUALLY DIVIDING THE TIME COMPLEXITY FROM N TO (LOG N)
    if(n%2==0){
        return R*R; // ASWE ARE NOT CALCULATING THE OTHER HALF ONE
    }
    return R*R*n;
    
}
int main() {
    int k;
    cin>>k;
    cout<<Fast(k,10);
	return 0;
}
