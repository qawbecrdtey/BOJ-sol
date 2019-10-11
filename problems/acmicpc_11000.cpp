#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
struct comp{bool operator()(const pair<int,int> &a,const pair<int,int> &b){return a.second>b.second;}};
int main(){
    int n;
    scanf("%d",&n);
    auto *a=new pair<int,int>[n];
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    for(int i=0;i<n;i++){
        if(pq.empty()){
            pq.push(a[i]);
            continue;
        }
        if(pq.top().second<=a[i].first){
            const auto now=pq.top();
            pq.pop();
            pq.push(make_pair(now.first, a[i].second));
            continue;
        }
        else pq.push(a[i]);
    }
    printf("%d",pq.size());
    delete[] a;
}