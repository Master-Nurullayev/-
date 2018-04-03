#include <bits/stdc++.h>
#define lld long long int
#define pb push_back
#define pp pop_back
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int r,t=0,j,jj;
    vector<int>m;
    r=max(a.size(),b.size());
    if(r==b.size()) swap(a,b);
    j=min(a.size(),b.size())-1;

    for(int i=r-1;i>=0;i--){
        if(j>=0){
        t+=(int)a[i]-48+(int)b[j]-48;
        m.pb(t%10);
        t=t/10;
        j--;
        }else{
            t+=(int)a[i]-48;
        m.pb(t%10);
        t=t/10;
        }
     
    } if(t!=0) m.pb(t);
    for(int i=m.size()-1;i>=0;i--){
        cout<<m[i];
    }
    return 0;
}
