#include <stdio.h>
#include <set>
using namespace std;
int main(){
    while(true){
        set<int> s;
        while(true){
            int x;
            scanf("%d",&x);
            if(x==-1)return 0;
            if(x==0)break;
            s.insert(x);
        }
        int cnt=0;
        for(auto const now:s){
            if(s.find(now*2)!=s.end()){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}