#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
int main(){
    while(true){
        char c[200];
        fgets(c,200,stdin);
        if(strcmp(c,".")==0||strcmp(c,".\n")==0)break;
        auto const l=strlen(c);
        stack<char> s;
        bool flag=true;
        for(int i=0;i<l;i++){
            if(c[i]=='(')s.push('(');
            else if(c[i]=='[')s.push('[');
            else if(c[i]==')'){
                if(s.empty()||s.top()!='('){
                    flag=false;
                    break;
                }
                s.pop();
            }
            else if(c[i]==']'){
                if(s.empty()||s.top()!='['){
                    flag=false;
                    break;
                }
                s.pop();
            }
        }
        if(!flag||!s.empty()){
            printf("no\n");
        }
        else printf("yes\n");
    }
}