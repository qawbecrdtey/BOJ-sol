#include <stdio.h>
#include <queue>
using namespace std;
int main(){
    int n;
    queue<int> q;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop();
        auto const now=q.front();
        q.pop();
        q.push(now);
    }
    printf("%d",q.front());
}