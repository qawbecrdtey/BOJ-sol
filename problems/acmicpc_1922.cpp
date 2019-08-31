#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
struct p{
    int first,second;
    p(int x,int y):first(x),second(y){}
};
bool operator<(p const &a, p const &b){return a.first>b.first;}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<p> *v=new vector<p>[n];
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a-1].push_back(p(c,b-1));
        v[b-1].push_back(p(c,a-1));
    }
    priority_queue<p> pq;
    pq.push(p(0,0));
    bool *visited=new bool[n]();
    int ans=0;
    while(!pq.empty()){
        auto const now=pq.top();
        pq.pop();
        if(visited[now.second])continue;
        visited[now.second]=true;   
        ans+=now.first;
        for(auto const &next:v[now.second]){
            if(!visited[next.second]){
                pq.push(next);
            }
        }
    }
    printf("%d",ans);
    delete[] visited;
    delete[] v;
}