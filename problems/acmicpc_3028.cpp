#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool b[3]={true,false,false};
    for(auto it=s.begin();it!=s.end();it++){
        if(*it=='A'){
            bool tmp=b[0];
            b[0]=b[1];
            b[1]=tmp;
        }
        else if(*it=='B'){
            bool tmp=b[1];
            b[1]=b[2];
            b[2]=tmp;
        }
        else{
            bool tmp=b[2];
            b[2]=b[0];
            b[0]=tmp;
        }
    }
    if(b[0])printf("1");
    else if(b[1])printf("2");
    else printf("3");
}