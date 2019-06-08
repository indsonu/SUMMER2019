#include<iostream>
#include<algorithm>
using namespace std;

int knapsackDP(int *prize,int *pro,int s,int n){
    int dp[10000][10000];
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
        for(auto w=1;w<=n;w++){
            if(w<prize[i]){
                dp[i][w]=dp[i-1][w];
            }                             // SAME AS O/1 KNAPSACK BUT IN THIS EITHER WE SELECT ALL OR NON
            else{
              dp[i][w] = max(dp[i - 1][w],
                             ((w / prize[i]) * pro[i]) +
                                 dp[i - 1][w - (w / prize[i]) * prize[i]]);
              ans = max(ans, dp[i][w]);
            }
        }
    }
    // for(auto i=1;i<=s;i++){
    //     for(auto w=1;w<=n;w++){
    //        cout<<dp[i][w]<<" ";
    //     }
    //     cout<<endl;
    // }
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
    cout<<knapsackDP(prize,pro,s,n)<<"\n";
}
