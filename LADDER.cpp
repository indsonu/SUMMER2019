#include<iostream>
using namespace std;
int memo[100];
int computeLadderRecursion(int n){
    if(n==0){
        return 1;//GROUND
    }
    if(n<0){
        return 0; //UNDERGROUND
    }   // THERE IS ALWAYS POSSIBLE TO REACH FROM ALL THE WAY INFACT U CAN USE LOOP FOR Kth JUMPS
    return computeLadderRecursion(n-1)+computeLadderRecursion(n-2)+computeLadderRecursion(n-3);
}
int computeLadderDP(int n){
    if(memo[n]!=-1){
        return memo[n];
    }
    if(n==0){
        return 1;//GROUND
    }
    if(n<0){
        return 0; //UNDERGROUND
    }
    return memo[n]=computeLadderDP(n-1)+computeLadderDP(n-2)+computeLadderDP(n-3);
}
int computeLadderInLINEAR_TIME(int n){
    int dp[n+1];
    dp[1]=1;dp[2]=2;dp[3]=4;
    for(auto i=4;i<n+1;i++){
        dp[i]=dp[i-2]+dp[i-1]+dp[i-3];// SHIFTING THE WINDOW WITH CONSECUTIVE Kth TIMES 
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<computeLadderRecursion(n)<<"\n";
    for(auto i=0;i<100;i++){
        memo[i]=-1;
    }
    cout<<computeLadderDP(n)<<"\n";
    cout<<computeLadderInLINEAR_TIME(n);
}
