#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    int c[26]={};
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        c[s[0]-'a']++;
    }
    bool flag=false;
    for(int i=0;i<26;i++){
        if(c[i]>=5){
            cout<<(char)(i+'a');
            flag=true;
        }
    }
    if(!flag)cout<<"PREDAJA";
}