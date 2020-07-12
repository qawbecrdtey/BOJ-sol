#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        auto *v=new vector<pair<int,int>>[n+1];
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            v[a].push_back(make_pair(-c,b));
            v[b].push_back(make_pair(-c,a));
        }
        int *dist=new int[n+1]();
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            int cur;
            scanf("%d",&cur);
            bool *visited=new bool[n+1]();
            priority_queue<pair<int,int>> pq;
            pq.push(make_pair(0,cur));
            while(!pq.empty()){
                auto const now=pq.top();
                pq.pop();
                if(visited[now.second])continue;
                visited[now.second]=true;
                dist[now.second]-=now.first;
                for(auto const next:v[now.second]){
                    pq.push(make_pair(now.first+next.first,next.second));
                }
            }

            delete[] visited;
        }
        int min=1;
        for(int i=2;i<=n;i++){
            if(dist[i]<dist[min]){
                min=i;
            }
        }
        printf("%d\n",min);

        delete[] dist;
        delete[] v;
    }
}