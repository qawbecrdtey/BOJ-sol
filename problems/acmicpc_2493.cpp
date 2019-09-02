#include <stdio.h>
#include <stack>
#include <utility>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    stack<pair<int,int>> s;
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        while(!s.empty()&&s.top().second<a){
            s.pop();
        }
        if(s.empty()){
            printf("0 ");
            s.push(make_pair(i,a));
            continue;
        }
        printf("%d ",s.top().first);
        s.push(make_pair(i,a));
    }
}