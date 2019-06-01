#include<iostream>
#include<stack>
using namespace std;
stack<char> S;
int callStack(string s){
    int ans=0;
    for(auto i=0;s[i];i++){
        if(s[i]=='{'){
            S.push('{');
        }
        else if(!S.empty()){
            S.pop();
        }
        else{
            S.push('{');          // MAIN IDEA IS HERE 
            ans+=1;
        }
    }
    return ans+((S.size())/2);
}
int main(){int i=1;
    string s;
    while(cin>>s){
        
        if ( s.find( '-' ) != string::npos )
            return 0;
       cout<<i++<<". "<<callStack(s)<<"\n";
       while(!S.empty()){S.pop();}
    }
    return 0;
}
