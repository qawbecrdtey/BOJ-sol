#include <iostream>
#include <queue>
#include <string>
using namespace std;
int a[110][110];
bool b[110][110];
bool visited[110][110];
struct cmp{bool operator()(const pair<int,pair<int,int>> &x, const pair<int,pair<int,int>> &y){return x>y;}};
int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> pq;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        const auto l=s.length();
        for(int j=0;j<l;j++){
            if(s[j]=='T')b[i+1][j+1]=true;
            else pq.push(make_pair(0,make_pair(i+1,j+1)));
        }
    }
    pq.push(make_pair(0,make_pair(0,0)));
    int max=0;
    while(!pq.empty()){
        const auto now=pq.top();
        pq.pop();
        if(visited[now.second.first][now.second.second]&&(a[now.second.first][now.second.second]<=now.first))continue;
        visited[now.second.first][now.second.second]=true;
        a[now.second.first][now.second.second]=now.first;
        max=(max>=now.first?max:now.first);
        if(now.second.first&&!visited[now.second.first-1][now.second.second])pq.push(make_pair(now.first+(b[now.second.first-1][now.second.second]?1:0),make_pair(now.second.first-1,now.second.second)));
        if(now.second.second&&!visited[now.second.first][now.second.second-1])pq.push(make_pair(now.first+(b[now.second.first][now.second.second-1]?1:0),make_pair(now.second.first,now.second.second-1)));
        if(now.second.first<=n&&!visited[now.second.first+1][now.second.second])pq.push(make_pair(now.first+(b[now.second.first+1][now.second.second]?1:0),make_pair(now.second.first+1,now.second.second)));
        if(now.second.second<=m&&!visited[now.second.first][now.second.second+1])pq.push(make_pair(now.first+(b[now.second.first][now.second.second+1]?1:0),make_pair(now.second.first,now.second.second+1)));
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(max<10){
                const int x=(b[i][j]?a[i][j]:0);
                if(x==0){
                    printf("..");
                }
                else if(x<10){
                    printf(".%d",x);
                }
            }
            else{
                const int x=(b[i][j]?a[i][j]:0);
                if(x==0){
                    printf("...");
                }
                else if(x<10){
                    printf("..%d",x);
                }
                else printf(".%d",x);
            }
        }
        printf("\n");
    }
}