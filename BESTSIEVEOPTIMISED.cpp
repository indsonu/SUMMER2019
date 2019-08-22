#include <iostream>
using namespace std;
// TIME COMPLEXITY IS O(N*LOGLOG(N))
int main() {
    bool a[100001];
    a[0]=0;
    a[1]=0;
    a[2]=1;
    // AS WE KNOW EVEN NUMBERS ARE NOT PRIME EXCEPT 2 SO 
    // mark all odd numbers as prime
    for(int i=3;i<1001;i+=2)a[i]=1;
    for(int i=3;i<1001;i+=2){
        if(a[i]){ 
            // WE ARE STARTING FROM I*I BECAUSE THERE WLL  BE OTHER MULTIPLY WHO CUT THE PREVIOUS NUMBERS
            // SEE N = 5 SO WE START FROM 25 
            // HENCE 24 WILL HAVE DIVISORS 1 TO 12 SQRT(24) IS LESS THAN 5 SO 
            // IF 24 IS NOT PRIME THEN THERE WILL BE SOME FACTOR LESS THAN 5 WHO CUT THIS NUMBER
            for(int j=i*i;j<1001;j+=2*i){
                // WE ARE INCREMENTING WITH 2*I BECAUSE 
                // AS ODD + ODD = EVEN 
                // WHEN WE START ODD NUMBER AND INCREMENTING WITH ODD NUMBER THEN SOME CASES WILL BE EVEN LIKE
                // I= 3 THEN 9 IS I*I 
                // 9+3 =12 WHICH IS EVEN AND ALREADY CUT SO NO NEED FOR THIS
                // INSTEAD 9+6=15  WHICH IS RIGHT AND OPTIMISED FORM OF THIS
                a[j]=0;
            }
        }
    }
    for(int i=0;i<1001;i++){
        if(a[i]){
            cout<<i<<" ";
        }
    }
 }
