#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    auto a=new pair<int,pair<int,int>>[n];
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a[i].first,&a[i].second.first,&a[i].second.second);
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=i-1;j>=0;j--){
            if(a[j].second.first<=a[i].second.first&&a[j].second.second>a[i].second.first){
                cnt+=a[i].first-a[j].first;
                flag=true;
                break;
            }
        }
        if(!flag){
            cnt+=a[i].first;
        }
    }
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=i-1;j>=0;j--){
            if(a[j].second.first<=a[i].second.second-1&&a[j].second.second>a[i].second.second-1){
                cnt+=a[i].first-a[j].first;
                flag=true;
                break;
            }
        }
        if(!flag){
            cnt+=a[i].first;
        }
    }
    printf("%d",cnt);
    delete[] a;
}