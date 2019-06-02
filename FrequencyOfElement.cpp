#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[]={1,3,5,6,7,8,8,8,8,9,12,34,45,67};
    int n=sizeof(a)/sizeof(int);
    auto r=equal_range(a,a+n,8);     // TELL THE NO. OF TIMES ELEMENT OCCURS
    cout<<r.second-r.first;
}
