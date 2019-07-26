#include <iostream>
#include<bits/stdc++.h>
using namespace std;
ifstream f("data.in");
ofstream g("data.out");
int main()
{ // range is -10 to 10
    int n;
    f>>n;
    int a[n],x[20]={0};
    for(int i=0;i<n;i++){
        f>>a[i];
    }
    for(int i=0;i<n;i++){
        // just add 10 to every index frequency
        x[a[i]+10]++;

    }
    for(int i=0;i<20;i++){
        g<<x[i]<<" ";
    }
    return 0;
}
//  -5 -1 -4 -5 3 5 6
