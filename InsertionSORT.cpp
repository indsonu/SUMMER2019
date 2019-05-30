// WE ALL HAVE PLAYED CARDS JUST SIMILARLY WE HAVE TO DO IT HERE:
#include<iostream>
using namespace std;
int main(){
    int a[]={9,3,2,1,0,18,6,7};
    int n=sizeof(a)/sizeof(int); // WE ALREADY PICK ONE UNKNOWN CARD AND PLACE IT ON 
    int key,j,i=1;              // THE FIRST INDEX WHICH IS 9 HERE

    while(i<n){               // START FROM THE SECOND ELEMENT AND SEE THAT TILL THAT INDEX IS ARRAY SORTED OR NOT
        key=a[i];            // PICKING UP A CARD AND COMPARING WITH THE PREVIOUS SORTED
        j=i-1;               // ARRAY
        while(j>=0 && key<a[j]){    // ONCE WE FOUND NOT THEN PLACE AT RIGHT POSI.
            a[j+1]=a[j];        // MAKE A SPACE FOR THAT CARD TO PLACE AT THE CORRECT POSI..
            j--;
        }
        a[j+1]=key;i++;     // ONCE THE SPACE HAS BEEN GENERATED WE PUT THAT ELEMENT INTO    
    }                        // THAT INDEX
    for(auto i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
