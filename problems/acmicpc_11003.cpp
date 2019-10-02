#include <stdio.h>
#include <deque>
#include <utility>
using namespace std;
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    deque<pair<int,int> > dq;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        while(!dq.empty()&&dq.back().first>=x){
            dq.pop_back();
        }
        dq.push_back(make_pair(x,i));
        if(!dq.empty()&&dq.front().second<=i-l){
            dq.pop_front();
        }
        printf("%d ",dq.front().first);
    }
}