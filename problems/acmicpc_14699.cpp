#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    auto h=new int[n+1];
    auto v=new vector<int>[n+1];
    auto ind=new int[n+1]();
    auto dist=new int[n+1]();
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(h[a]>h[b]){
            v[a].push_back(b);
            ind[b]++;
        }
        else if(h[a]<h[b]){
            v[b].push_back(a);
            ind[a]++;
        }
    }
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            q.push(make_pair(-1,i));
        }
    }
    while(!q.empty()){
        auto const now=q.front();q.pop();
        dist[now.second]=-now.first;
        for(auto const next:v[now.second]){
            ind[next]--;
            if(ind[next]==0){
                q.push(make_pair(now.first-1,next));
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",dist[i]);
    }
    
    delete[] dist;
    delete[] ind;
    delete[] v;
    delete[] h;
}