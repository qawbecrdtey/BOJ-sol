#include <stdio.h>
#include <deque>
#include <utility>
#define MIN -2147483647
using namespace std;
int main(){
    using ll=long long;
    ll n,d;
    scanf("%lld%lld",&n,&d);
    deque<pair<ll,int> > dq;
    ll x;
    ll max=MIN;
    for(int i=0;i<n;i++){
        scanf("%lld",&x);
        if(!dq.empty()&&dq.front().first>0)x+=dq.front().first;
        if(!dq.empty()&&dq.front().second<=i-d){
            dq.pop_front();
        }
        while(!dq.empty()&&dq.back().first<=x){
            dq.pop_back();
        }
        max=(max>x?max:x);
        dq.push_back(make_pair(x,i));
    }
    printf("%lld",max);
}