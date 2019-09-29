#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    queue<string> q;
    q.push("");
    int cnt=0;
    int const m=(a<(b/2)?(b/2):a);
    while(cnt<m){
        string const now=q.front();
        q.pop();
        if(now.length()&&now.length()<16){
            printf("%s ",now.c_str());
            cnt++;
        }
        if(q.size()<b)
        for(char i='a';i<='z';i++){
            q.push(now+i);
        }
    }
}