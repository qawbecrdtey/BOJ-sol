#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    while(true){
        getline(cin,s);
        if(s=="#")return 0;
        bool b[26]={};
        for(char c:s){
            if(c>='a'&&c<='z')b[c-'a']=true;
            else if(c>='A'&&c<='Z')b[c-'A']=true;
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(b[i])cnt++;
        }
        cout<<cnt<<endl;
    }
}