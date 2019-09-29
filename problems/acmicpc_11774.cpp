#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> *v=new vector<int>[n+1];
    pair<int,int> *p=new pair<int,int>[n];
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        p[i]=make_pair(a,b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<pair<int,bool> > q;
    q.push(make_pair(1,false));
    bool *visited=new bool[n+1]();
    vector<int> *vv=new vector<int>[n+1];
    while(!q.empty()){
        auto const now=q.front();
        q.pop();
        if(visited[now.first])continue;
        visited[now.first]=true;
        for(int next:v[now.first]){
            if(now.second)vv[now.first].push_back(next);
            q.push(make_pair(next,!now.second));
        }
    }
    for(int i=0;i<n-1;i++){
        if(find(vv[p[i].first].begin(),vv[p[i].first].end(),p[i].second)!=vv[p[i].first].end()){
            printf("1\n");
        }
        else printf("0\n");
    }
    delete[] p;
    delete[] vv;
    delete[] v;
}