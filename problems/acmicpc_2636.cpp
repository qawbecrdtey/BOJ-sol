#include <stdio.h>
#include <queue>
using namespace std;
struct p{
    int x,y,depth;
    p(int x,int y,int depth):x(x),y(y),depth(depth){}
};
bool operator<(p const &a,p const &b){return a.depth>b.depth;}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[100][100];
    bool visited[100][100]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    priority_queue<p> pq;
    pq.push(p(0,0,0));
    int max=0;
    int cnt=0;
    while(!pq.empty()){
        auto const now=pq.top();
        pq.pop();
        if(visited[now.x][now.y])continue;
        visited[now.x][now.y]=true;
        if(max<now.depth){
            max=now.depth;
            cnt=1;
        }
        else if(max==now.depth&&a[now.x][now.y]){
            cnt++;
        }
        if(now.x>0&&!visited[now.x-1][now.y])pq.push(p(now.x-1,now.y,now.depth+a[now.x-1][now.y]));
        if(now.x<n-1&&!visited[now.x+1][now.y])pq.push(p(now.x+1,now.y,now.depth+a[now.x+1][now.y]));
        if(now.y>0&&!visited[now.x][now.y-1])pq.push(p(now.x,now.y-1,now.depth+a[now.x][now.y-1]));
        if(now.y<m-1&&!visited[now.x][now.y+1])pq.push(p(now.x,now.y+1,now.depth+a[now.x][now.y+1]));
    }
    if(max==0)cnt=0;
    printf("%d\n%d",max,cnt);
}