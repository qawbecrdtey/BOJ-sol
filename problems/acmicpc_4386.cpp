#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;
using pdd=pair<double,double>;
using pid=pair<int,double>;
double dist(const pdd &a,const pdd &b){return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));}
struct comp{bool operator()(const pid &a,const pid &b){return a.second>b.second;}};
int main(){
    int n;
    scanf("%d",&n);
    auto *p=new pdd[n];
    auto *v=new vector<pid>[n];
    for(int i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        p[i]=make_pair(x,y);
        for(int j=0;j<i;j++){
            const double d=dist(p[i],p[j]);
            v[i].push_back(make_pair(j,d));
            v[j].push_back(make_pair(i,d));
        }
    }
    priority_queue<pid,vector<pid>,comp> pq;
    pq.push(make_pair(0,0.0));
    bool *visited=new bool[n]();
    double l=0;
    while(!pq.empty()){
        const auto now=pq.top();
        pq.pop();
        if(visited[now.first])continue;
        visited[now.first]=true;
        l+=now.second;
        for(auto next:v[now.first]){
            if(visited[next.first])continue;
            pq.push(next);
        }
    }
    cout<<l;
    delete[] visited;
    delete[] v;
    delete[] p;
}