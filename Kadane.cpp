// MAXIMUM SUBARRAY SUM
#include<iostream>
#include<climits>
using namespace std;
int BruteSum(){

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n=sizeof(a)/sizeof(int);
    int ans=INT_MIN;
    for(auto i=0;i<n;i++){         O(N^2)
        int calci=0;
        for(auto j=i;j<n;j++){        // SIMPLY LOOPING OVER ALL SUBARRAY AND FINDING THE ANSWER
            calci+=a[j];
            ans=max(ans,calci);
        }
    }
    return ans;
}
int Kadane_For_ALLNonNegative(){                      // KADANE FOR ALL NON NEGATIVE ARRAY
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};  O(N)
    int n=sizeof(a)/sizeof(int);
    int sum=0,ans=0;                             
    for(auto i=0;i<n;i++){
        sum+=a[i];                                            // IF SUM <0 THEN SUM=0     
        if(sum<0){                                            // SUM > ANS THEN ANS=SUM
            sum=0;
        }
        else if(sum>ans){
            ans=sum;
        }
    }
    return ans;
}
int Kadane_For_ALLNegative(){
  int a[] = {-1,-2,-3,-5,-7,8};                                     O(N)
  int ans=a[0],n=sizeof(a)/sizeof(int); DYNAMMIC PROGRAMMING 
  int cnt[n]={0};
  cnt[0]=a[0];                               //                       STORING THE PREVIOUS RESULT JUST LIKE PREFIX SUM BUT IN THIS 
  for(auto i=1;i<n;i++){    
        cnt[i]=max(a[i],cnt[i]+a[i]);        //  WE ARE CHECKING THE MAX BTW CURRENT ELEMENT AND PREVIOUS + CURRENT  
      ans=max(ans,cnt[i]);
  }                                           // WHOSOEVER IS MAX ARE BEING AS AN ANSWER
  return ans;
}
int main(){
    cout<<BruteSum()<<endl;
    cout<<Kadane_For_ALLNonNegative()<<endl;
    cout<<Kadane_For_ALLNegative()<<endl;
}
