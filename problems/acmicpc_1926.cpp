#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
bool a[500][500];
bool visited[500][500];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            a[i][j]=(x?true:false);
        }
    }
    int max=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int size=0;
            if(a[i][j]&&!visited[i][j]){
                queue<pair<int,int> > q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    auto now=q.front();
                    q.pop();
                    if(visited[now.first][now.second])continue;
                    visited[now.first][now.second]=true;
                    size++;
                    if(now.first&&a[now.first-1][now.second]&&!visited[now.first-1][now.second]){
                        q.push(make_pair(now.first-1,now.second));
                    }
                    if(now.second&&a[now.first][now.second-1]&&!visited[now.first][now.second-1]){
                        q.push(make_pair(now.first,now.second-1));
                    }
                    if(now.first<n-1&&a[now.first+1][now.second]&&!visited[now.first+1][now.second]){
                        q.push(make_pair(now.first+1,now.second));
                    }
                    if(now.second<m-1&&a[now.first][now.second+1]&&!visited[now.first][now.second+1]){
                        q.push(make_pair(now.first,now.second+1));
                    }
                }
                max=(max>size?max:size);
                cnt++;
            }
        }
    }
    printf("%d\n%d",cnt,max);
}