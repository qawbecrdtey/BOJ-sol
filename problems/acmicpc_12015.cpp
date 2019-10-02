#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(v.empty()){
            v.push_back(x);
            continue;
        }
        auto p=lower_bound(v.begin(),v.end(),x);
        if(p==v.end())v.push_back(x);
        else *p=x;
    }
    printf("%d",v.size());
}