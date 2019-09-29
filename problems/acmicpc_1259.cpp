#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    while(s!="0"){
        auto const l=s.length();
        bool flag=true;
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-i-1]){
                cout<<"no\n";
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"yes\n";
        }
        cin>>s;
    }
}