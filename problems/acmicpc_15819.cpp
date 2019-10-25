#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    auto *a=new string[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[k-1];
}