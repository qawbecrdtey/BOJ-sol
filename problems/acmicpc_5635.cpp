#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct s{
    string name;
    int day,month,year;
};
bool operator<(const s &a,const s &b){return a.year>b.year||(a.year==b.year&&a.month>b.month)||(a.year==b.year&&a.month==b.month&&a.day>b.day);}
int main(){
    int n;
    scanf("%d",&n);
    s *a=new s[n];
    for(int i=0;i<n;i++){
        cin>>a[i].name>>a[i].day>>a[i].month>>a[i].year;
    }
    sort(a,a+n);
    cout<<a[0].name<<endl;
    cout<<a[n-1].name;
}