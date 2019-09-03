#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        auto const x=lower_bound(v.begin(),v.end(),a);
        if(x==v.end())v.push_back(a);
        else *x=a;
    }
    printf("%d",n-v.size());
}