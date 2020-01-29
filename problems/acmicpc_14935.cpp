#include <iostream>
#include <string>
#include <vector>
using namespace std;
void f(string &s,int x){
    if(x<10){s.push_back(x+'0');return;}
    f(s,x/10);
    s.push_back(x%10+'0');
}
int main(){
    string s;
    cin>>s;
    vector<string> v;
    while(true){
        for(auto str:v){
            if(s==str)goto A;
        }
        v.push_back(s);
        int x=(s[0]-'0')*(s.length());
        string t;
        f(t,x);
        if(s==t)goto B;
        s=t;
    }
    A: printf("N");
    B: printf("FA");
}