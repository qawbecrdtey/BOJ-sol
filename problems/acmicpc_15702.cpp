#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;
struct str{
    int score;
    int no;
};
bool operator<(const str &a,const str &b){return a.score<b.score||(a.score==b.score&&a.no>b.no);}
int main(){
    int n,m;
    cin>>n>>m;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<str> pq;
    for(int i=0;i<m;i++){
        int no,score=0;
        cin>>no;
        string s;
        for(int j=0;j<n;j++){
            cin>>s;
            if(s=="O"){
                score+=a[j];
            }
        }
        pq.push(str{score,no});
    }
    cout<<pq.top().no<<' '<<pq.top().score;
    delete[] a;
}