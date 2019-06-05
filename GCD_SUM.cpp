#include<iostream>
using namespace std;
#define MAX 1000001
long long int phi[MAX],result[MAX];
void prec(){
    for(auto i=1;i<MAX;i++)phi[i]=i;
    for(auto i=2;i<MAX;i++){
        if(phi[i]==i){
            phi[i]=i-1;
            for(auto j=(i<<1);j<MAX;j+=i){
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}
void computeSum(){
    for(auto i=1;i<MAX;i++){
        for(auto j=2;i*j<MAX;j++){//        DOING FROM THE FACT THAT D IS DIVISOR AND IF WE WILL USING THIS FORMULA 
            result[i*j]+=i*result[j];//     THEN IT WILL GIVE US THE SUM OF ALL THOSE NUMBER WHOSE GCD IS I
        }
    }
    
}
int main(){
    prec();
    for(auto i=1;i<MAX;i++)cout<<phi[i]<<" ";
}
