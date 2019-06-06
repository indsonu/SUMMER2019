#include<iostream>//FENWICK TREE OR BINARY INDEXED TREE
using namespace std;
const long long int MAX=1000005;
long long int BIT[MAX] = {0} ;
void construct(long int value, int i,int n) {
    while(i<=n){
        BIT[i]+=value;
        i+=(i&(-i));        // ADDING THE MASK TO THE LAST SET BIT 
    }                       //  1 0 1 0
                     // THIS :  0 0 1 0 (MASK) AFTER DOING & OPERATION
                        //      0 0 1 0 WE WLL GET THE POSIION OF LAST SET BIT=(2)
}     
int main(){
    int n;
    cin>>n;
    long int a[n+1];
    for(auto i=1;i<=n;i++){
        cin>>a[i];
        construct(a[i],i,n); // KEEP UPDATING THE VALUES IN THE TREE AT THE TIME OF INPUTS
    }
    for(auto i=1;i<=n;i++){
        cout<<BIT[i]<<" ";
    }
}
