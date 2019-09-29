#include <stdio.h>
#include <vector>
using namespace std;
void search(int const root,int const r,vector<int> const &v){
    if(root+1>r)return;
    if(root+1==r){
        printf("%d\n",v[root]);
        return;
    }
    int const l=root+1;
    int const rtv=v[root];
    int lv=l,rv=r;
    while(lv<rv){
        int m=(lv+rv)/2;
        if(rtv>v[m])lv=m+1;
        else rv=m;
    }
    search(l,lv,v);
    search(lv,r,v);
    printf("%d\n",v[root]);
}
int main(){
    int n;
    int t;
    vector<int> v;
    while(scanf("%d",&n)!=EOF){
        v.push_back(n);
    }
    n=v.size();
    search(0,n,v);
}