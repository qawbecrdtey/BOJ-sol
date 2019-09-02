#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct p{
    int x,y,depth;
    p(int x,int y,int depth):x(x),y(y),depth(depth){}
};
bool operator<(p const &a,p const &b){return a.depth>b.depth;}
int main(){
    int n;
    cin>>n;
    int a[50][50];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            a[i][j]=(s[j]=='1'?1:0);
        }
    }
    priority_queue<p> pq;
    pq.push(p(0,0,0));
    bool visited[50][50]={};
    while(!pq.empty()){
        auto const now=pq.top();
        pq.pop();
        if(now.x==n-1&&now.y==n-1){
            printf("%d",now.depth);
            return 0;
        }
        if(visited[now.x][now.y])continue;
        visited[now.x][now.y]=true;
        if(now.x>0&&!visited[now.x-1][now.y])pq.push(p(now.x-1,now.y,now.depth+1-a[now.x-1][now.y]));
        if(now.x<n-1&&!visited[now.x+1][now.y])pq.push(p(now.x+1,now.y,now.depth+1-a[now.x+1][now.y]));
        if(now.y>0&&!visited[now.x][now.y-1])pq.push(p(now.x,now.y-1,now.depth+1-a[now.x][now.y-1]));
        if(now.y<n-1&&!visited[now.x][now.y+1])pq.push(p(now.x,now.y+1,now.depth+1-a[now.x][now.y+1]));
    }
}