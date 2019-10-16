#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int main(){
    using ll=long long;
    ll a,b;
    scanf("%lld%lld",&a,&b);
    priority_queue<pair<ll,ll>> pq;
    pq.push(make_pair(1,a));
    while(!pq.empty()){
        auto const now=pq.top();
        pq.pop();
        if(now.second==b){
            printf("%d",now.first);
            return 0;
        }
        if(now.second*2<=b)pq.push(make_pair(now.first+1,now.second*2));
        if(now.second*10+1<=b)pq.push(make_pair(now.first+1,now.second*10+1));
    }
    printf("-1");
}