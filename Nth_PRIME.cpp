
#include <iostream>
using namespace std;

bool sieve[100000009];
int main() {
    sieve[0]=sieve[1]=1;
    for(int i=2;i*i<=100000009;i++)
        if(!sieve[i])
            for(int j=i*i;j<=100000009;j+=i)
                sieve[j]=1;
    int N;
    cin>>N;
    int counter=1;
    while(N>0)
    {
        counter++;
        if(!sieve[counter])
            N--;
    }
    cout<<counter;
}
