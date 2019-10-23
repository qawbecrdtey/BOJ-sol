#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        string s,t;
        cin>>s>>t;
        const string s1=s,t1=t;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){
            cout<<s1<<" & "<<t1<<" are anagrams.\n";
        }
        else{
            cout<<s1<<" & "<<t1<<" are NOT anagrams.\n";
        }
    }
}