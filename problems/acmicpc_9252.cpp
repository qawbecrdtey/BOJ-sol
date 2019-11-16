#include <iostream>
#include <string>
#include <stack>
using namespace std;
inline int max(int a,int b){return a>b?a:b;}
int main(){
    string s,t;
    cin>>s>>t;
    const int n=s.length(),m=t.length();
    int **a=new int *[n+1];
    for(int i=0;i<=n;i++){
        a[i]=new int[m+1]();
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                a[i][j]=a[i-1][j-1]+1;
            }
            else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    cout<<a[n][m]<<endl;
    stack<char> st;
    int i=n,j=m;
    while(i&&j&&a[i][j]){
        if(a[i][j]==a[i][j-1])j--;
        else if(a[i][j]==a[i-1][j])i--;
        else {st.push(s[i-1]);i--;j--;}
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    for(int i=0;i<=n;i++){
        delete[] a[i];
    }
    delete[] a;
}