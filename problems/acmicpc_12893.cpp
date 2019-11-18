#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    auto *v=new vector<int>[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    auto *visited=new pair<bool,bool>[n+1]();
    for(int i=1;i<=n;i++){
        if(!visited[i].first){
            queue<pair<int,bool>> q;
            q.push(make_pair(i,false));
            while(!q.empty()){
                auto now=q.front();
                q.pop();
                if(visited[now.first].first){
                    if(visited[now.first].second!=now.second){
                        printf("0");
                        return 0;
                    }
                    else continue;
                }
                visited[now.first].first=true;
                visited[now.first].second=now.second;
                for(auto next:v[now.first]){
                    q.push(make_pair(next,!now.second));
                }
            }
        }
    }
    printf("1");
}