#include <stdio.h>
#include <vector>
using namespace std;
void dp(int r,int *cnt,vector<int> *v,bool *visited){
    visited[r]=true;
    if(v[r].empty()){
        cnt[r]=1;
        return;
    }
    for(int next:v[r]){
        if(!visited[next]){
            dp(next,cnt,v,visited);
            cnt[r]+=cnt[next];
        }
    }
    cnt[r]++;
}
int main() {
    int n,r,q;
    scanf("%d%d%d",&n,&r,&q);
    vector<int> *v=new vector<int>[n+1];
    int *cnt=new int[n+1]();
    bool *visited=new bool[n+1]();
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dp(r,cnt,v,visited);
    for(int i=0;i<q;i++){
        int k;
        scanf("%d",&k);
        printf("%d\n",cnt[k]);
    }
    delete[] v;
    delete[] cnt;
}