#include<iostream>
#include<vector>
using namespace std;
int kadane(vector<int>vect,int n){
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    int cs=0,ms=0;
    for(int i=0;i<n;i++){
        cs=cs+vect[i];
        if(cs<0){
            cs=0;
        }
        ms=max(cs,ms);
    }
    return ms;
}
int main(){
    int n,sum=0;
    cin>>n;
    vector<int>vect(n,0);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    int ans1=kadane(vect,n);
    for(int i=0;i<n;i++){
        sum+=vect[i];
        vect[i]=-vect[i];
    }
    int ans2=sum+kadane(vect,n);
    ans1>ans2?cout<<ans1:cout<<ans2;
}
