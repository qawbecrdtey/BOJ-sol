#include <stdio.h>
#include <queue>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        priority_queue<long long> pq;
        for(int i=0;i<n;i++){
            long long x;
            scanf("%lld",&x);
            pq.push(-x);
        }
        long long res=1;
        while(pq.size()>1){
            auto const a=pq.top();pq.pop();
            auto const b=pq.top();pq.pop();
            auto const c=a*b;
            res=(res*(c%1000000007))%1000000007;
            pq.push(-c);
        }
        printf("%lld\n",res);
    }
}