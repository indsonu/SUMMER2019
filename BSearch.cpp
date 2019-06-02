// THE METHOD WE HAVE LEARN FOR BS IS GOOD ENOUGH 
// BUT IT HAVE MORE NO. OF OPERATION
// TO REDUCE IT I HAVE LEARNT THIS-->:)
#include<iostream>
using namespace std;
int main(){
    int a[]={1,3,5,6,7,8,9,12,34,45,67};// ELEMENT IS PRESENT IN THE SORTED ORDER
    int n=sizeof(a)/sizeof(int);
    int k=0,value=10;
    for(auto b=n/2;b>=1;b/=2){
        while(b+k<n && a[b+k]<=value){
            k+=b;
        }
    }
    if(k<n && a[k]==value){
        cout<<"Element is at "<<k+1<<" position:\n"; // K FOR INDEXING WISE
    }
    else{
        cout<<"Element not found:\n";
    }
}
