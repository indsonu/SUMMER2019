#include <iostream>
using namespace std;
const int inf=1e9;
int memo[100000];
int mSt1(int n){
    if(n==1){
        return 0;
    }
    if(memo[n]!=-1){
        return memo[n];
    }
    int  a1=inf,a2=inf,a3=inf;
    if(n%3==0) a1=1+mSt1(n/3);
    if(n%2==0) a2=1+mSt1(n/2);
    a3=1+mSt1(n-1);
    return memo[n]=min(a1,min(a2,a3));
}
int pureDP(int n){  //PURE DP
    memo[1]=memo[0]=0;
    memo[2]=memo[3]=1;
    for(int i=4;i<=n;i++){
        int a1=inf,a2=inf,a3=inf;
        if(i%3==0) a1=1+memo[i/3];
        if(i%2==0) a2=1+memo[i/2];
        a3=1+memo[i-1];
        memo[i]=min(a1,min(a2,a3));
    }
    return memo[n];
}
int main() {
    for(int i=0;i<100000;i++){
        memo[i]=-1;
    }
    int n;
    cin>>n;
    // cout<<mSt1(n)<<endl;
    cout<<pureDP(n)<<endl;
}
