#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    while(true){
        scanf("%d",&n);
        if(!n)return 0;
        scanf("\n");
        string s;
        int cur=0;
        for(int i=0;i<n;i++){
            getline(cin,s);
            for(;cur<s.length()&&s[cur]!=' '&&s[cur]!='\n';cur++);
        }
        cout<<cur+1<<endl;
    }
}