#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    auto const l=s.length();
    int J=0,I=0;
    for(int i=0;i<l-2;i++){
        if(s[i]=='J'&&s[i+1]=='O'&&s[i+2]=='I'){
            J++;
            continue;
        }
        if(s[i]=='I'&&s[i+1]=='O'&&s[i+2]=='I'){
            I++;
            continue;
        }
    }
    printf("%d\n%d",J,I);
}