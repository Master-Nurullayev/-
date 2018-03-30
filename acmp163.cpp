#include <bits/stdc++.h>
#define lld long long int
#define pb push_back
#define pp pop_back
using namespace std;
int main(){
    string a;
    cin>>a;
    bool n;
    int v,g;
    if(a[0]=='x'){
        if(a[1]=='+'){
            v=(int)a[4]-(int)a[2];
        }else
        {
            v=(int)a[2]-48+(int)a[4]-48;
        }
         
    }
    else{
    v=(int)a[4]-(int)a[0];
    if(a[1]=='-') v=v*(-1);
    }
    cout<<v;
    return 0;
}
