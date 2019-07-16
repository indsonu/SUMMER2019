// HACKER RANK PROBLEM
/*
  I APPROACH IT IN A WAY: EITHER YOU CAN INCLUDE THAT COIN OR U CANNOT 
  1. IF YOU DONT INCLUDE THAT COIN THEN SIMPLY ADD THE PREVIOUS ONES OR IF THE DENOMINATION IS LESS 
  2. ELSE U CAN ADD PREVIOUS ONE TO THE CURRENT ONE WHICH IS J-A[I] TO THE SAME ROW ENDL;
*/
#include <iostream>
using namespace std;
 long long int calci(long long int a[],long long int m,long long int n){
    long long int dp[m][n+1]={0};
    for(auto i=0;i<m;i++){
        dp[i][0]=1;
    }
    for(auto i=0;i<m;i++){
        for(auto j=0;j<n+1;j++){
            if(i==0 && j!=0){
                if(j%a[0]==0){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
    }
    for(auto i=1;i<m;i++){
        for(auto j=1;j<n+1;j++){
            if(a[i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-a[i]];
            }
        }
    }
    return dp[m-1][n];
}
int main() {
    long long int m,n;
    cin>>n>>m;
    long long int a[m];
    for(auto i=0;i<m;i++){
        cin>>a[i];
    }
    cout<<calci(a,m,n);
	return 0;
}
