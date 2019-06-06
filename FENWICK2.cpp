#include<iostream>//FENWICK TREE
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
long int sum(int idx){
    int sum=0;
    while(idx>0){
        sum+=BIT[idx];   
        idx-=(idx&(-idx));  // REVERSE OF UPDATE 
    }                   //  FINDING WHOSE GOT THE RESPONSIBILITY OF WHICH INDEX
    return sum;
}    
int main(){
    int n;
    cin>>n;
    long int a[n+1];
    for(auto i=1;i<=n;i++){
        cin>>a[i];
        construct(a[i],i,n);
    }
    cout<<sum(7)-sum(2)<<" BEFORE UPDATE\n"; // RANGE QUERY BETWEEN N  - (M-1) { M-1 BECAUSE THE QUERY WILL INCLUDE Mth INDEX }
    // UPDATE THE NODE I=4 (4) => (5) AND RECOMPUTE THE SUM BTW QUERIES
    construct(-a[4],4,n);
    a[4]=5;  // NEW VALUES0
    construct(a[4],4,n);
    cout<<sum(7)-sum(2)<<" AFTER UPDATE\n";
    for(auto i=1;i<=n;i++){
        cout<<BIT[i]<<" ";
    } 

    
}
