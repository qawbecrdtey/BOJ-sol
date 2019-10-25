#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    auto *a=new pair<float,string>[n];
    for(int i=0;i<n;i++){
        cin>>a[i].second;
        a[i].first=stof(a[i].second);
    }
    sort(a,a+n);
    cout<<a[1].second;
    delete[] a;
}