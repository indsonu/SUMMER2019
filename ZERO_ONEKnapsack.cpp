// MAIN IDEA BEHIND THIS IS : THAT EITHER WE SELECT THE CURRENT WEIGHT OR WE SELECT THE PREVIOUS ONE 
// COIN ROW TYPES
#include<iostream>
#include<algorithm>
using namespace std;
int knapsack(int *prize,int *pro,int s,int n){
    if(n==0 || s==0){
        return 0;
    }                                                         // RECURSIVE APPROACH
    int price=0,exec=0;
    if(prize[s]<=n)
    price=pro[s]+knapsack(prize,pro,s-1,n-prize[s]);
    exec=knapsack(prize,pro,s-1,n);
    return max(exec,price);
}
int knapsackDP(int *prize,int *pro,int s,int n){
    int dp[100][100];
    for(auto i=1;i<s;i++){
        for(auto j=1;j<s;j++){
            if(prize[j]>prize[j+1]){
                swap(prize[j],prize[j+1]);
                swap(pro[j],pro[j+1]);
            }
        }
    }
    auto ans=0;
    for(auto i=1;i<=s;i++){
        for(auto w=1;w<=n;w++){                                   // DYNAMIC APPROACH
            if(w<prize[i]){
                dp[i][w]=dp[i-1][w];
            }
            else{
                dp[i][w]=max(dp[i-1][w],pro[i]+dp[i-1][w-prize[i]]);
                ans=max(ans,dp[i][w]);
            }
        }
    }
    return ans;
}
int main(){
    int s,n;
    cin>>s>>n;
    int prize[s+1],pro[s+1];
    for(auto i=1;i<=s;i++){
        cin>>prize[i];
    }
    for(auto i=1;i<=s;i++){
        cin>>pro[i];
    }
    cout<<knapsack(prize,pro,s,n)<<"\n";
    cout<<knapsackDP(prize,pro,s,n)<<"\n";
}
