#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
pair<int,int> dp[10010];
bool visited[10010];
inline int max(int a,int b){return a>b?a:b;}
pair<int,int> value(int node,int *const a,vector<int> *const v){
    if(visited[node])return dp[node];
    int unchecked=0,checked=a[node];
    visited[node]=true;
    for(int x:v[node]){
        if(visited[x])continue;
        auto const p=value(x,a,v);
        unchecked+=max(p.first,p.second);
        checked+=p.first;
    }
    return dp[node]=make_pair(unchecked,checked);
}
void dfs(int node,vector<int> &vv,vector<int> *const v,int root,bool b){
    if(!b&&dp[node].first<dp[node].second){
        vv.push_back(node);
        b=true;
    }
    else b=false;
    for(int x:v[node]){
        if(x==root)continue;
        dfs(x,vv,v,node,b);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int *a=new int[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    vector<int> *v=new vector<int>[n+1];
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    auto const p=value(1,a,v);
    printf("%d\n",max(p.first,p.second));
    vector<int> vv;
    dfs(1,vv,v,0,false);
    sort(vv.begin(),vv.end());
    for(int x:vv){
        printf("%d ",x);
    }
    delete[] v;
    delete[] a;
}