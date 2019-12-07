#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int *t=new int[n+1]();
    auto *v=new std::vector<int>[n+1];
    int *deg=new int[n+1]();
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
        int a;
        A:
        scanf("%d",&a);
        if(a==-1)continue;
        v[a].push_back(i);
        deg[i]++;
        goto A;
    }
    int *ans=new int[n+1];
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++){
        if(!deg[i])pq.push(make_pair(-t[i],i));
    }
    while(!pq.empty()){
        const auto now=pq.top();
        pq.pop();
        ans[now.second]=-now.first;
        for(const int next:v[now.second]){
            if(--deg[next]==0){
                pq.push(make_pair(now.first-t[next],next));
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    delete[] ans;
    delete[] deg;
    delete[] v;
    delete[] t;
}