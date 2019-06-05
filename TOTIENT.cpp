#include<iostream>
using namespace std;
#define MAX 1000001
long long int phi[MAX],result[MAX];
void prec(){
    for(auto i=1;i<MAX;i++)phi[i]=i;// PUTTING THE VALUES SO THAT AT THE TIME OF RESULT WE WILL MULTIPLY IT
    for(auto i=2;i<MAX;i++){
        if(phi[i]==i){
            phi[i]=i-1; // IF IT'S VALUE IS NOT UPDATED THEN ITS A PRIME NO. WITH VALUE LESS THAN ITS BY 1
            for(auto j=(i<<1);j<MAX;j+=i){
                phi[j]=(phi[j]/i)*(i-1); // FORMULA
            }
        }
    }
}
int main(){
    prec();
    for(auto i=1;i<MAX;i++)cout<<phi[i]<<" ";
}
