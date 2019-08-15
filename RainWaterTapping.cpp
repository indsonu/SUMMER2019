#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>vect(n,0),left(n,0),right(n,0);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    // PRECOMPUTE THE RIGHT MOST AND LEFT MOST HIGHEST BUILDING TO THE CURRENT BUILDING 
    // SO IT WILL BE EASY TO SOLVE IN LINEAR TIME 
    left[0]=vect[0];
    int cs=left[0];
    for(int i=1;i<n;i++){
        cs=max(cs,vect[i]);
        left[i]=cs;
        // cout<<left[i]<<" ";
    }
    right[n-1]=vect[n-1];
    cs=right[n-1];
    for(int i=n-1;i>=0;i--){
        cs=max(cs,vect[i]);
        right[i]=cs;
        // cout<<right[i]<<" ";
    }
    int ct=0;
    for(int i=0;i<n;i++){
        ct+=min(left[i],right[i])-vect[i]; // FIND FOR THE SINGLE BUILDING AND ADDING FOR ALL 
    }
    cout<<ct<<" ";
	return 0;
}
